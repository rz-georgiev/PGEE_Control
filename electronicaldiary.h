#ifndef ELECTRONICALDIARY_H
#define ELECTRONICALDIARY_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <QSql>
#include <QSqlDatabase>
#include <QTableView>
#include <QSqlRelationalTableModel>
#include <QSortFilterProxyModel>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class ElectronicalDiary;
}

class ElectronicalDiary : public  QDialog
{
    Q_OBJECT

public:
    explicit ElectronicalDiary(QWidget *parent = 0);
    ~ElectronicalDiary();





private slots:



    void on_ClassBox_currentTextChanged(const QString &arg1);

    void on_ClassLBox_currentTextChanged(const QString &arg1);

    void on_StudentNameBox_currentTextChanged(const QString &arg1);

    void on_SubjectBox_currentTextChanged(const QString &arg1);

    void on_FiltrationToggle_clicked();

    void on_NameLine_textChanged(const QString &arg1);



    void on_NameFiltrationToggle_clicked();

    void on_RefreshButton_clicked();


private:
    Ui::ElectronicalDiary *ui;

          QSqlQuery newQuery;
           QSqlTableModel *ListModel;
            QSortFilterProxyModel *ProxyModel;
             QStringList StudentsList, SubjectsList;

              void FilterInformation(QString class_x, QString class_word);
              void FilterStudentsForAppendingList(QString class_a, QString class_word_a);
              void load_main_settings();



};

#endif // ELECTRONICALDIARY_H
