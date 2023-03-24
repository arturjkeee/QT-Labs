#include "cell.h"
#include <QtGui>

Cell::Cell()
{
    setDirty();
}

Cell::~Cell()
{

}

void Cell::setDirty()
{
    cacheIsDirty = true;
}

QTableWidgetItem *Cell::clone() const
{
    return new Cell(*this);
}

void Cell::setFormula(QString &formula)
{
    return setData(Qt::EditRole, formula);
}

void Cell::setData(int role, const QVariant &value)
{
    QTableWidgetItem::setData(role, value);
    if (role == Qt::EditRole) setDirty();
}

QVariant Cell::data(int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (value().isValid()) return value().toString();
        else return "####";
    }
    else if (role== Qt::TextAlignmentRole)
    {
        if(value().type() == QVariant::String) return int(Qt::AlignLeft | Qt::AlignVCenter);
        else return (Qt::AlignRight | Qt::AlignVCenter);
    }
    else return QTableWidgetItem::data(role);
}

const QVariant Invalid;

QVariant Cell::value() const
{
    if (cacheIsDirty)
    {
        cacheIsDirty = false;
        QString formulaStr = formula();
        if (formulaStr.startsWith('\'')) cachedValue = formulaStr.mid(1);
        else if(formulaStr.startsWith('\='))
        {
            //cachedValue = Invalid;
            QString exp = formulaStr.mid(1);
            exp.replace(" ","");
            exp.append(QChar::Null);
            int pos = 0;
            cachedValue = evalExpression(exp, pos);
            if (exp['pos'] != QChar::Null) cachedValue = Invalid;
        }
        else
        {
            bool ok;
            double d = formulaStr.toDouble(&ok);
            if (ok) cachedValue = d;
            else cachedValue = formulaStr;
        }
    }
    return cachedValue;
}

QString Cell::formula() const
{
    return data(Qt::EditRole).toString();
}

QVariant Cell::evalExpression(const QString &str, int &pos) const
{
    return 0;
}
QVariant Cell::evalTerm(const QString &str, int &pos) const
{
    return 0;
}
QVariant Cell::evalFactor(const QString &str, int &pos) const
{
    return 0;
}

