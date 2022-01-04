#include "EthRpcGetBalance.h"

EthRpcGetBalance::EthRpcGetBalance(QObject *parent) : EthRpcRequest(parent)
{
    this->setMethod("eth_getBalance");
}

void EthRpcGetBalance::sendRequest()
{
    // Reimplemented function of EthRpcRequest

    QJsonArray paramsArray;

    // Create and set
    paramsArray.append(m_valueAddress);
    paramsArray.append(m_valueQuantity);

    this->setParams(paramsArray);

    EthRpcRequest::sendRequest();
}
