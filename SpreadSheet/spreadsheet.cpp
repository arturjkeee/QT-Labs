#include "spreadsheet.h"
#include "cell.h"
SpreadSheet::SpreadSheet(QTableWidget *parent)
    : QTableWidget(parent)
{
    autoRecalc = true;
    //setItemPrototype(new Cell);
    setSelectionMode(ContiguousSelection);

    connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(someThingChaned()));
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
        c->setFormula(formula);
        updateCell(row, col);
    }
    else
    {
        setitem(row, col, new Cell(this, formula));
    }
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
    if (autoRecalc)
    {
        recalculate();
        emit modified();
    }
}
