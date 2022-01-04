#ifndef ETHRPCESTIMATEGAS_H
#define ETHRPCESTIMATEGAS_H

#include <QObject>

#include "EthRpcRequest.h"

class EthRpcEstimateGas : public EthRpcRequest
{
    Q_OBJECT

public:
    explicit EthRpcEstimateGas(QObject *parent = nullptr);

    void setValue(const QString value);

    inline void setFrom(const QString &valueFrom) { m_valueFrom = valueFrom; }
    inline void setTo(const QString &valueTo) { m_valueTo = valueTo; }
    inline void setGas(const QString &valueGas) { m_valueGas = valueGas; }
    inline void setGasPrice(const QString &valueGasPrice) { m_valueGasPrice = valueGasPrice; }
    inline void setGasData(const QString &valueGasData) { m_valueData = valueGasData; }

    virtual void sendRequest() override;

private:
    QJsonValue m_valueFrom;
    QJsonValue m_valueTo;
    QJsonValue m_valueGas;
    QJsonValue m_valueGasPrice;
    QJsonValue m_valueTxValue;
    QJsonValue m_valueData;

};

#endif // ETHRPCESTIMATEGAS_H
