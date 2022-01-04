#include "EthRpcSendRawTransaction.h"

EthRpcSendRawTransaction::EthRpcSendRawTransaction(QObject *parent) : EthRpcRequest(parent)
{
    this->setMethod("eth_sendRawTransaction");
}

void EthRpcSendRawTransaction::sendRequest()
{
    // Reimplemented function of EthRpcRequest
    QJsonArray paramsArray;

    paramsArray.append(m_valueTransactionData);

    this->setParams(paramsArray);

    EthRpcRequest::sendRequest();
}
