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

