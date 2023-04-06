#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class SpreadSheet;
class QAction;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SpreadSheet *spreadSheet;
    enum {maxRecentFile = 5};
    QAction *recentFilesActions[maxRecentFile];
    QAction *addSeparator;

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void goToCell();
    void about();
    void aboutQt();
    void sort();
};

#endif // MAINWINDOW_H
