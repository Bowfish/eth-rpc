#ifndef ETHRPCSENDRAWTRANSACTION_H
#define ETHRPCSENDRAWTRANSACTION_H

#include <QObject>

#include "EthRpcRequest.h"

class EthRpcSendRawTransaction : public EthRpcRequest
{
    Q_OBJECT

public:
    explicit EthRpcSendRawTransaction(QObject *parent = nullptr);

    inline void setTransactionData(const QString &valueTransactionData) { m_valueTransactionData = valueTransactionData; }

    virtual void sendRequest() override;

private:
    QJsonValue m_valueTransactionData;

};

#endif // ETHRPCSENDRAWTRANSACTION_H
