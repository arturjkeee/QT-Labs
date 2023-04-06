#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

class SpreadSheet;
class QAction;

class QLabel;


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

    QLabel *locationLabel;
    QLabel *formulaLabel;
    void createStatusBar();


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

    void updateStatusBar();
    void spreadSheetModified();
};

#endif // MAINWINDOW_H
