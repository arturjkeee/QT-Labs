#ifndef SORT_H
#define SORT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Sort; }
QT_END_NAMESPACE

class Sort : public QDialog
{
    Q_OBJECT

public:
    Sort(QWidget *parent = nullptr);
    ~Sort();
    int getIndexFirst();
    int getFirstOrder();
    int getIndexSecond();
    int getSecondOrder();
    int getIndexThird();
    int getThirdOrder();

    void setColumnRange(QChar first, QChar last);

private:
    Ui::Sort *ui;
};
#endif // SORT_H
