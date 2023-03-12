#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegularExpression regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regExp, this));

    connect(ui->okButton, SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->cancelButton, SIGNAL(clicked()),this,SLOT(reject()));
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_changed()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

