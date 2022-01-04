#include "EthRpcGetTransactionByHash.h"

EthRpcGetTransactionByHash::EthRpcGetTransactionByHash(QObject *parent) : EthRpcRequest(parent)
{
    this->setMethod("eth_getTransactionByHash");
}

void EthRpcGetTransactionByHash::sendRequest()
{
    // Reimplemented function of EthRpcRequest
    QJsonArray paramsArray;

    paramsArray.append(m_valueTransactionHash);

    this->setParams(paramsArray);

    EthRpcRequest::sendRequest();
}
