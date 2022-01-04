#ifndef ETHRPCGETTRANSACTIONBYHASH_H
#define ETHRPCGETTRANSACTIONBYHASH_H

#include <QObject>

#include "EthRpcRequest.h"

class EthRpcGetTransactionByHash: public EthRpcRequest
{
    Q_OBJECT

public:
    explicit EthRpcGetTransactionByHash(QObject *parent = nullptr);

    inline void setTransactionHash(const QString &valueTransactionHash) { m_valueTransactionHash = valueTransactionHash; }

    virtual void sendRequest() override;

private:
    QJsonValue m_valueTransactionHash;

};

#endif // ETHRPCGETTRANSACTIONBYHASH_H
