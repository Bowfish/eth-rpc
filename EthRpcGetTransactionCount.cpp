#include "EthRpcGetTransactionCount.h"

EthRpcGetTransactionCount::EthRpcGetTransactionCount(QObject *parent) : EthRpcRequest(parent)
{
    this->setMethod("eth_getTransactionCount");
}

void EthRpcGetTransactionCount::sendRequest()
{
    // Reimplemented function of EthRpcRequest
    QJsonArray paramsArray;

    paramsArray.append(m_valueAddress);
    paramsArray.append(m_valueQuantity);

    this->setParams(paramsArray);

    EthRpcRequest::sendRequest();
}
