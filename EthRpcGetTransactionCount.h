#ifndef ETHRPCGETTRANSACTIONCOUNT_H
#define ETHRPCGETTRANSACTIONCOUNT_H

#include <QObject>

#include "EthRpcRequest.h"

class EthRpcGetTransactionCount : public EthRpcRequest
{
    Q_OBJECT

public:
    explicit EthRpcGetTransactionCount(QObject *parent = nullptr);

    inline void setAddress(const QString &valueAddress) { m_valueAddress = valueAddress; }
    inline void setQuantity(const QString &valueQuantity) {m_valueQuantity = valueQuantity; }

    virtual void sendRequest() override;

private:
    QJsonValue m_valueAddress;
    QJsonValue m_valueQuantity;

};

#endif // ETHRPCGETTRANSACTIONCOUNT_H
