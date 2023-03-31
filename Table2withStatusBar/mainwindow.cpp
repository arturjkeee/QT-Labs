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



