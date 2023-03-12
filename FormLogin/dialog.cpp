#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegularExpression regName("[A-Z]{1}[a-z]{2,15}");
    ui->lineEditName->setValidator(new QRegularExpressionValidator (regName, this));

    QRegularExpression regMail("^[a-z0-9_][a-z0-9_\.-]*[a-z0-9_]@([a-z0-9]+[a-z0-9_-]*[a-z0-9]\.)+[a-z0-9]{2,}$");
    ui->lineEditMail->setValidator(new QRegularExpressionValidator (regMail, this));

    QRegularExpression regPassword("[0-9a-zA-Z!@#$%^&*]{6}");
    ui->lineEditPassword->setValidator(new QRegularExpressionValidator (regPassword, this));

    connect(ui->registerButton, SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->cancelButton, SIGNAL(clicked()),this,SLOT(reject()));
}

Dialog::~Dialog()
{
    delete ui;
}
