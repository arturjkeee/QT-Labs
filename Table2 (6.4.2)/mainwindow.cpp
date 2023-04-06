#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "spreadSheet.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    spreadSheet = new SpreadSheet;
    setCentralWidget(spreadSheet);

    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    createStatusBar();
}

void MainWindow::createStatusBar()
{
    locationLabel = new QLabel("W999");
    locationLabel->setAlignment(Qt::AlignCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());
    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);
    ui->statusBar->addWidget(locationLabel);
    ui->statusBar->addWidget(formulaLabel, 1);
    connect(spreadSheet, SIGNAL(currentCellChanged(int,int,int,int)), this, SLOT(updateStatusBar()));
    connect(spreadSheet, SIGNAL(modified()), this, SLOT(spreadSheetModified()));
    updateStatusBar();
}

void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadSheet->currentLocation());
    formulaLabel->setText(spreadSheet->currentFormula());
}

void MainWindow::spreadSheetModified()
{
    setWindowModified(true);
    updateStatusBar();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::newFile()
{

}
void MainWindow::open()
{

}
bool MainWindow::save()
{
    return true;
}
bool MainWindow::saveAs()
{
    return true;
}
void MainWindow::find()
{

}

void MainWindow::goToCell()
{

}

void MainWindow::about()
{

}
void MainWindow::aboutQt()
{

}

void MainWindow::sort()
{

}



