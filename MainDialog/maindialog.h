#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QCheckBox;
class QPushButton;

class maindialog : public QDialog
{
    Q_OBJECT
public:
    explicit maindialog(QWidget *parent = nullptr);

signals:
    void add(const QString &str);
    void clear(const QString &str);
private slots:
    void addClicked();
    void clearClicked();

private:
    QLabel *labelСonstantValue;
    QLabel *labelFormula;
    QLabel *labelNumberValue;
    QLineEdit *lineEditСonstantValue;
    QLineEdit *lineEditFormula;
    QLineEdit *lineEditNumberValue;
    QPushButton *addButton;
    QPushButton *clearButton;
};

#endif // MAINDIALOG_H
