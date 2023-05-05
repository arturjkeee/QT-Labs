#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>

class Cell;
class SpreadSheetCompare;

class SpreadSheet : public QTableWidget
{
    Q_OBJECT

public:
    SpreadSheet(QTableWidget *parent = nullptr);
    ~SpreadSheet();

    QString currentLocation();
    QString currentFormula();
    QTableWidgetSelectionRange selectedRange() const;

    void clear();

    bool readFile(const QString &fileName);
    bool writeFile(const QString &fileName);

    void sort(SpreadSheetCompare &compare);

public slots:

    void cut();
    void copy();
    void paste();
    void del();
    void selectCurrentRow();
    void selectCurrentColumn();
    void recalculate();
    void setAutoRecalculate(bool on);

    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrev(const QString &str, Qt::CaseSensitivity cs);

signals:
    void modified();

private slots:
    void someThingChanged();
private:
    enum { MagicNumber = 0x7F51C882, RowCount = 999, ColumnCount = 26 };
    bool autoRecalc;
    Cell *cell(int row, int column) const;
    void setFormula(int row, int column, const QString &formula);
    QString formula(int row,int column) const;
};

class SpreadSheetCompare
{
public:
    bool operator()(const QStringList &row1, const QStringList &row2) const;
    enum{NumKeys = 3};
    int keys[NumKeys];
    bool ascending[NumKeys];

};

#endif // SPREADSHEET_H
