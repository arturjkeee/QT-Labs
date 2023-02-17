#include "mainwindow.h"
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTextCodec *codec = QTextCodec::codecForName("CP1251");
    QTextCodec::setCodecForTr(codec);
    setWindowTitle(tr("<h2>Привет 123!</h2>"));
    resize(500,500);
}

MainWindow::~MainWindow()
{

}
