#include "EthRpcRequest.h"

EthRpcRequest::EthRpcRequest(QObject *parent) : QObject(parent)
{
    // This is the connection to the ASUS workstation in the local home network
    this->setEndPointUrl("http://192.168.1.111:8545");

    // Set the JSON version
    this->setJsonRpc("2.0");

    // Set a unique id for the request
    this->setId(QUuid::createUuid().toString(QUuid::WithoutBraces));

    // Create a new network manager object
    m_networkManager = new QNetworkAccessManager(this);

    // Create the request
    m_networkRequest.setUrl(this->endPointUrl());
    // Set the header of the request
    m_networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
}

QUrl EthRpcRequest::endPointUrl() const
{
    return m_endPointUrl;
}

void EthRpcRequest::setEndPointUrl(const QString &endPointUrl)
{
    m_endPointUrl = QUrl(endPointUrl);
}

QString EthRpcRequest::jsonRpc() const
{
    return m_jsonRpc;
}

void EthRpcRequest::setJsonRpc(const QString &jsonRpc)
{
    m_jsonRpc = jsonRpc;
}

QString EthRpcRequest::method() const
{
    return m_method;
}

void EthRpcRequest::setMethod(const QString &method)
{
    m_method = method;
}

QString EthRpcRequest::id() const
{
    return m_id;
}

void EthRpcRequest::setId(const QString &id)
{
    m_id = id;
}

QJsonArray EthRpcRequest::params() const
{
    return m_params;
}

void EthRpcRequest::setParams(const QJsonArray &params)
{
    m_params = params;
}

QByteArray EthRpcRequest::replyData() const
{
    return m_replyData;
}

void EthRpcRequest::setReplyData(const QByteArray &replyData)
{
    m_replyData = replyData;
}

QJsonDocument EthRpcRequest::replyJsonDocument()
{
    return QJsonDocument::fromJson(this->replyData());
}

void EthRpcRequest::sendRequest()
{
    QJsonObject requestObj;
    // Initialize the request JSON Object
    requestObj.insert("id", this->id());
    requestObj.insert("jsonrpc", this->jsonRpc());
    requestObj.insert("method", this->method());
    requestObj.insert("params", this->params());

    // Convert the JSON Object to a JSON Document
    QJsonDocument requestDoc(requestObj);

    qDebug().noquote() << Qt::endl;
    qDebug().noquote() << Q_FUNC_INFO;
    qDebug().noquote() << "request:";
    qDebug().noquote() << requestDoc.toJson(QJsonDocument::Indented);

    // Send a post request with the network manager and
    // post will return a network reply object
    QNetworkReply *networkReply = m_networkManager->post(m_networkRequest, requestDoc.toJson(QJsonDocument::Compact));

    // Execute setReplyData if the network reply is QNetworkReply::readyRead
    connect(networkReply, &QNetworkReply::readyRead,
        this, [networkReply, this] () {
            this->setReplyData(networkReply->readAll());
        }
    );

    // Create a JSON Doc with the error message if the network reply is QNetworkReply::errorOccurredyy
    connect(networkReply, &QNetworkReply::errorOccurred,
        this, [networkReply, this] (QNetworkReply::NetworkError error) {
            Q_UNUSED(error)

            QJsonDocument replyDoc = QJsonDocument::fromJson(this->replyData());
            QJsonObject errorObj = replyDoc.object();
            QJsonValue errorVal = errorObj.value("error");

            if (errorVal.isUndefined()) {
                emit this->replyFailed(networkReply->errorString());

            } else {
                emit this->replyFailed(
                    QString(networkReply->errorString()) +
                    QString(" ") +
                    QString(errorVal.toObject().value("message").toString())
                );
            }

            networkReply->deleteLater();
        }
    );

    // Create a JSON Doc with the reply if the network reply is QNetworkReply::finished
    connect(networkReply, &QNetworkReply::finished,
        this, [networkReply, this] () {
            if (networkReply->error() == QNetworkReply::NoError) {
                QJsonDocument replyDoc = QJsonDocument::fromJson(this->replyData());

                QJsonObject replyObj = replyDoc.object();
                QJsonValue resultVal = replyObj.value("result");
                QJsonValue errorVal = replyObj.value("error");

                if (!resultVal.isUndefined()) {
                    emit this->replySuccessful(resultVal);

                } else if (!errorVal.isUndefined()) {
                    emit this->replyFailed(errorVal.toObject().value("message").toString());
                }

            } else {
                emit this->replyFailed(networkReply->errorString());
            }

            networkReply->deleteLater();
        }
    );
}
