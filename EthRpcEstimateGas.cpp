#include "EthRpcEstimateGas.h"

EthRpcEstimateGas::EthRpcEstimateGas(QObject *parent) : EthRpcRequest(parent)
{
    this->setMethod("eth_estimateGas");
}

void EthRpcEstimateGas::setValue(const QString value)
{
    QString valueTrimmed = value;

    // Remove leading 0 of the value hex string
    while (valueTrimmed.startsWith("0x0")) {
        valueTrimmed.remove(2, 1);
    }

    m_valueTxValue = valueTrimmed;
}

void EthRpcEstimateGas::sendRequest()
{
    // Reimplemented function of EthRpcRequest

    QJsonObject paramsObj;

    // Create and set the paramters of the request
    if (!m_valueFrom.isNull()) paramsObj.insert("from", m_valueFrom);
    if (!m_valueTo.isNull()) paramsObj.insert("to", m_valueTo);
    if (!m_valueGas.isNull()) paramsObj.insert("gas", m_valueGas);
    if (!m_valueGasPrice.isNull()) paramsObj.insert("gasPrice", m_valueGasPrice);
    if (!m_valueTxValue.isNull()) paramsObj.insert("value", m_valueTxValue);
    if (!m_valueData.isNull()) paramsObj.insert("data", m_valueData);

    QJsonArray parmasArr;
    parmasArr.append(paramsObj);

    // Set the paramters of the request
    this->setParams(parmasArr);

    EthRpcRequest::sendRequest();
}
