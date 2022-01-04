#ifndef ETHRPCBLOCKNUMBER_H
#define ETHRPCBLOCKNUMBER_H

#include <QObject>

#include "EthRpcRequest.h"

class EthRpcBlockNumber : public EthRpcRequest
{
    Q_OBJECT

public:
    explicit EthRpcBlockNumber(QObject *parent = nullptr);

    virtual void sendRequest() override;

};

#endif // ETHRPCBLOCKNUMBER_H
