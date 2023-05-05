#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    QSize PicSize(350,350);
    splash->setPixmap(QPixmap(":/images/pixmap.png").scaled(PicSize,Qt::KeepAspectRatio));
    splash->show();
    a.processEvents();
    QEventLoop loop;
    QTimer::singleShot(3000, &loop, SLOT(quit()));
    loop.exec();

    MainWindow *w= new MainWindow;
    w->show();

    splash->finish(w);
    return a.exec();
}
