#include <QApplication>
#include <QLabel>
#include <QTextCodec>
int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    QTextCodec *codec = QTextCodec::codecForName("CP1251");
    //1QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    //1QLabel *label = new QLabel(QString::fromLocal8Bit("Привет Qt"));
    //QLabel *label = new QLabel("Привет Qt 2");
    QLabel *label = new QLabel(QObject::tr("<h2><i>Привет<\i><font color=red> Qt 2<\font color=red><\h2>"));
    label->show();
    label->resize(175,175);
    return app.exec();
}

