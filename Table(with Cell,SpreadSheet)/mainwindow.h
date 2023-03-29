#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
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

    QString curFile;
    QStringList RecentFile;
    void createContextMenu();

    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);

    QString strippedName(QString &fullFileName);
    void setCurrentFileName(const QString &fileName);
    void updateRecentFileActions();

    bool okToContinue();
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

    void updateRecentFiles();
};

#endif // MAINWINDOW_H
