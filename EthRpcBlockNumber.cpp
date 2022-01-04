#include "EthRpcBlockNumber.h"

EthRpcBlockNumber::EthRpcBlockNumber(QObject *parent) : EthRpcRequest(parent)
{
    this->setMethod("eth_blockNumber");
}

void EthRpcBlockNumber::sendRequest()
{
    // Reimplemented function of EthRpcRequest
    EthRpcRequest::sendRequest();
}
