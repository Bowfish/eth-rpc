#ifndef ETHRPCGASPRICE_H
#define ETHRPCGASPRICE_H

#include <QObject>

#include "EthRpcRequest.h"

class EthRpcGasPrice : public EthRpcRequest
{
    Q_OBJECT

public:
    explicit EthRpcGasPrice(QObject *parent = nullptr);

    virtual void sendRequest() override;

};

#endif // ETHRPCGASPRICE_H
