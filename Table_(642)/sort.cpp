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
int Sort::getIndexFirst()
{
    return ui->firstColumnBox->currentIndex();
}
int Sort::getFirstOrder()
{
    return ui->firstOrderBox->currentIndex();
}
int Sort::getIndexSecond()
{
    return ui->secondColumnBox->currentIndex();
}
int Sort::getSecondOrder()
{
    return ui->secondOrderBox->currentIndex();
}
int Sort::getIndexThird()
{
    return ui->thirdColumnBox->currentIndex();
}
int Sort::getThirdOrder()
{
    return ui->thirdOrderBox->currentIndex();
}

void Sort::setColumnRange(QChar first, QChar last)
{
    QChar ch = first;
    while (ch<=last)
    {
        ui->firstColumnBox->addItem(QString(ch));
        ui->secondColumnBox->addItem(QString(ch));
        ui->thirdColumnBox->addItem(QString(ch));
        ch = QChar(ch.unicode()+1);
    }
}

