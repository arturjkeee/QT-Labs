#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

class SpreadSheet;
class QAction;

class QLabel;

class FindDialog;

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
    QAction *separatorAction;
    QAction *addSeparator;
    QAction *actionExit;
    QAction *actionClose;
    QLabel *locationLabel;
    QLabel *formulaLabel;
    void createStatusBar();

    QString curFile;
    QStringList recentFiles;
    QString strippedName(const QString &fullFileName);

    FindDialog *findDialog;
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);

    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    void createContextMenu();
    void createActions();
    void createMenus();

    void writeSettings();
    void readSettings();
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void openRecentFile();

    void find();
    void goToCell();

    void about();
    void sort();

    void updateStatusBar();
    void spreadSheetModified();
};

#endif // MAINWINDOW_H
