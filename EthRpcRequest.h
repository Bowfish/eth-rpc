#ifndef ETHRPCREQUEST_H
#define ETHRPCREQUEST_H

#include <QObject>
#include <QDebug>
#include <QUrl>
#include <QUuid>
#include <QUrlQuery>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class EthRpcRequest : public QObject
{
    Q_OBJECT

public:
    explicit EthRpcRequest(QObject *parent = nullptr);

    QByteArray replyData() const;
    void setReplyData(const QByteArray &replyData);

    QJsonDocument replyJsonDocument();

protected:
    QUrl endPointUrl() const;
    void setEndPointUrl(const QString &endPointUrl);

    QString jsonRpc() const;
    void setJsonRpc(const QString &jsonRpc);

    QString method() const;
    void setMethod(const QString &method);

    QString id() const;
    void setId(const QString &id);

    QJsonArray params() const;
    void setParams(const QJsonArray &params);

    virtual void sendRequest();

private:
    QNetworkAccessManager *m_networkManager = nullptr;

    QNetworkRequest m_networkRequest;

    QUrl m_endPointUrl;

    QString m_jsonRpc;
    QString m_method;
    QString m_id;

    QJsonArray m_params;

    QByteArray m_replyData;

signals:
    void replySuccessful(const QJsonValue &resultVal);
    void replyFailed(const QString &errorMessage);

private slots:

};

#endif // ETHRPCREQUEST_H
