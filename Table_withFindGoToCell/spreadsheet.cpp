#include "spreadsheet.h"
#include "cell.h"

#include <QFile>
#include <QMessageBox>
#include <QtGui>
#include <QApplication>

SpreadSheet::SpreadSheet(QTableWidget *parent)
    : QTableWidget(parent)
{
    autoRecalc = true;
    setItemPrototype(new Cell);
    setSelectionMode(ContiguousSelection);

    connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(someThingChanged()));
    clear();
}

SpreadSheet::~SpreadSheet()
{

}

void SpreadSheet::clear()
{
    setRowCount(0);
    setColumnCount(0);
    setRowCount(RowCount);
    setColumnCount(ColumnCount);
    for (int i=0;i<columnCount();i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString(QChar('A'+i)));
        setHorizontalHeaderItem(i, item);
    }
    setCurrentCell(0, 0);
}

Cell *SpreadSheet::cell(int row, int column) const
{
    return (Cell *) item(row, column);
}

QString SpreadSheet::formula(int row, int col) const
{
    Cell *c = cell(row,col);
    if (c)
    {
        return c->formula();
    }
    else
    {
        return "";
    }
}
void SpreadSheet::setFormula(int row, int col, const QString &formula)
{
    Cell *c = cell(row,col);
    if (!c)
    {
        c = new Cell;
        setItem(row, col, c);
    }
    c->setFormula(formula);
}

QString SpreadSheet::currentLocation()
{
    return QChar('A' + currentColumn()) + QString::number(currentRow()+1);
}

QString SpreadSheet::currentFormula()
{
    return formula(currentRow(), currentColumn());
}
void SpreadSheet::someThingChanged()
{
    /*
    if (autoRecalc)
    {
        recalculate();

    }
    */
    emit modified();
}
bool SpreadSheet::writeFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, tr("SpreadSheet"),tr("Cannot write file %1:\n%2.").arg(file.fileName()).arg(file.errorString()));
        return false;
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_8);
    out<<quint32(MagicNumber);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    for (int row = 0; row < RowCount; ++row)
    {
        for (int column = 0; column < ColumnCount; ++column)
        {
            QString str = formula(row,column);
            if (!str.isEmpty())
            {
                out<<quint16(row)<<quint16(column)<<str;
            }
        }
    }
    QApplication::restoreOverrideCursor();
    return true;
}
bool SpreadSheet::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,tr("SpreadSheet"), tr("Cannot read file %1:\n%2.").arg(file.fileName()).arg(file.errorString()));
        return false;
    }
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_8);
    quint32 magic;
    in >> magic;
    if (magic != MagicNumber)
    {
        QMessageBox::warning(this,tr("SpreadSheet"),tr("The file is not a SpreadSheet file."));
        return false;
    }
    clear();
    quint16 row;
    quint16 column;
    QString str;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    while(!in.atEnd())
    {
        in>>row>>column>>str;
        setFormula(row, column, str);
    }
    QApplication::restoreOverrideCursor();
    return true;
}

void SpreadSheet::findNext(const QString &str, Qt::CaseSensitivity cs)
{
    int row = currentRow();
    int column = currentColumn();
    while (row<RowCount)
    {
        while (column<ColumnCount)
        {
            if (formula(row,column).contains(str,cs))
            {
                clearSelection();
                setCurrentCell(row,column);
                activateWindow();
                return;
            }
            ++column;
        }
        column = 0;
        ++row;
    }
    QApplication::beep();
}
void SpreadSheet::findPrev(const QString &str, Qt::CaseSensitivity cs)
{
    int row = currentRow();
    int column = currentColumn();
    while (row>=0)
    {
        while (column>=0)
        {
            if (formula(row,column).contains(str,cs))
            {
                clearSelection();
                setCurrentCell(row,column);
                activateWindow();
                return;
            }
            --column;
        }
        column = ColumnCount - 1;
        --row;
    }
    QApplication::beep();
}
