#include "EthRpcGasPrice.h"

EthRpcGasPrice::EthRpcGasPrice(QObject *parent) : EthRpcRequest(parent)
{
    this->setMethod("eth_gasPrice");
}

void EthRpcGasPrice::sendRequest()
{
    // Reimplemented function of EthRpcRequest
    EthRpcRequest::sendRequest();
}
