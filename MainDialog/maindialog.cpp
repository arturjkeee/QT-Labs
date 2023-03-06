#include "maindialog.h"
#include <QtWidgets>
#include <iostream>
maindialog::maindialog(QWidget *parent)
    : QDialog{parent}
{
    labelСonstantValue = new QLabel(tr("Постоянная величина"));
    lineEditСonstantValue = new QLineEdit;
    labelСonstantValue->setBuddy(lineEditСonstantValue);

    labelFormula = new QLabel(tr("Формула или обозначение"));
    lineEditFormula = new QLineEdit;
    labelFormula->setBuddy(lineEditFormula);

    labelNumberValue = new QLabel(tr("Числовое значение"));
    lineEditNumberValue = new QLineEdit;
    labelNumberValue->setBuddy(lineEditNumberValue);

    addButton = new QPushButton(tr("&Добавить"));
    clearButton = new QPushButton(tr("&Очистить"));

    addButton->setDefault(true);
    addButton->setEnabled(true);

    connect(addButton, SIGNAL(clicked()),this,SLOT(addClicked()));
    connect(clearButton, SIGNAL(clicked()),this,SLOT(clearClicked()));

    QVBoxLayout *firstLayout = new QVBoxLayout;
    firstLayout->addWidget(labelСonstantValue);
    firstLayout->addWidget(lineEditСonstantValue);

    QVBoxLayout *secondLayout = new QVBoxLayout;
    secondLayout->addWidget(labelFormula);
    secondLayout->addWidget(lineEditFormula);

    QVBoxLayout *thirdLayout = new QVBoxLayout;
    thirdLayout->addWidget(labelNumberValue);
    thirdLayout->addWidget(lineEditNumberValue);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(clearButton);
    buttonsLayout->addWidget(addButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(secondLayout);
    mainLayout->addLayout(thirdLayout);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);

    setWindowTitle(tr("MainDialog"));
    setFixedHeight(sizeHint().height());
}

void maindialog::addClicked()
{
    QString textСonstantValue = lineEditСonstantValue->text();
    emit add(textСonstantValue);
    QString textFormula = lineEditFormula->text();
    emit add(textFormula);
    QString textNumberValue = lineEditNumberValue->text();
    emit add(textNumberValue);
    close();
}

void maindialog::clearClicked()
{
    lineEditСonstantValue->clear();
    lineEditFormula->clear();
    lineEditNumberValue->clear();
}

