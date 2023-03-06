#include <QApplication>
#include <maindialog.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
        maindialog *dialog = new maindialog;
        dialog->show();
    return app.exec();
}
