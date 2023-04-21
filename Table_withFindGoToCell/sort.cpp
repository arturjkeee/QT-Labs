#include "sort.h"
#include "ui_sort.h"

Sort::Sort(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Sort)
{
    ui->setupUi(this);
    ui->secondGroupBox->setVisible(false);
    ui->thirdGroupBox->setVisible(false);

}
Sort::~Sort()
{
    delete ui;
}
void Sort::setColumnRange(QChar first, QChar last)
{
    QChar ch = first;
    while (ch<=last)
    {
        ui->firstColumnBox->addItem(QString(ch));
        ui->secondColumnBox->addItem(QString(ch));
        ui->thirdColumnBox->addItem(QString(ch));
        ch = ch.unicode()+1;
    }
}
int Sort::getIndexFirst()
{
    return ui->firstColumnBox->currentIndex();
}

