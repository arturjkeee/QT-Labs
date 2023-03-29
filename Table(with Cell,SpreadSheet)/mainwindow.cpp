#include <QtGui>
#include <QLabel>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "spreadSheet.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    spreadSheet = new SpreadSheet;
    createStatusBar();
    createContextMenu();
    setCurrentFileName("");
    setCentralWidget(spreadSheet);

    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->action_New, SIGNAL(triggered()),this, SLOT(newFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createStatusBar()
{
    locationLabel = new QLabel("W999");
    locationLabel->setAlignment (Qt::AlignCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);

    ui->statusBar->addWidget(locationLabel);
    ui->statusBar->addWidget(formulaLabel, 1);

    connect(spreadSheet, SIGNAL(currentCellChanged(int,int,int,int)), this, SLOT(updateStatusBar()));
    connect(spreadSheet, SIGNAL(modified()), this, SLOT(spreadSheetModified()));

    updateStatusBar();
}
void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadSheet->currentLocation());
    formulaLabel->setText(spreadSheet->currentFormula());
}

void MainWindow::spreadSheetModified()
{
    setWindowModified(true);
    updateStatusBar();
}
void MainWindow::createContextMenu()
{
    spreadSheet->addAction(ui->action_Cut);
    spreadSheet->addAction(ui->action_Copy);
    spreadSheet->addAction(ui->action_Paste);
    spreadSheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::setCurrentFileName(const QString &fileName)
{
    curFile = fileName;
    setWindowModified(false);
    QString showName = "Untitled";
    if (!curFile.isEmpty())
    {
        showName = strippedName(curFile);
        RecentFile.removeAll(curFile);
        RecentFile.prepend(showName);
        updateRecentFileActions();
    }
    setWindowTitle(tr("%1*-%2").arg(showName).arg(tr("SpreadSheet")));
}

bool MainWindow::okToContinue()
{
    if (isWindowModified())
    {
        int r = QMessageBox::warning(this, "SpreadSheet", tr("Window was modified\n"
                                                             "Are you want to save this? "),QMessageBox::Yes | QMessageBox::Default,
                                     QMessageBox::No,
                                     QMessageBox::Cancel | QMessageBox::Escape);
        if (r == QMessageBox::Yes) return save();
        if (r == QMessageBox::Cancel) return false;
        return true;
    }
}
void MainWindow::newFile()
{
    if (okToContinue())
    {
        spreadSheet->clear();
        setCurrentFileName("");
    }

}
void MainWindow::open()
{

}
bool MainWindow::save()
{
    return true;
}
bool MainWindow::saveAs()
{
    return true;
}
void MainWindow::find()
{

}

void MainWindow::goToCell()
{

}

void MainWindow::about()
{

}
void MainWindow::aboutQt()
{

}

void MainWindow::sort()
{

}




