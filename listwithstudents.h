#ifndef LISTWITHSTUDENTS_H
#define LISTWITHSTUDENTS_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlTableModel>

#include <QSqlQuery>
#include <QMessageBox>
#include <QStyle>
#include <QStyleFactory>
#include <QSortFilterProxyModel>
#include <QButtonGroup>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QToolTip>

#include <QAbstractPrintDialog>
#include <QPageSetupDialog>
#include <QPrintDialog>
#include <QPrintEngine>
#include <QPrintPreviewDialog>
#include <QPrintPreviewWidget>
#include <QPrinter>
#include <QPrinterInfo>
#include <QFileDialog>
#include <QVariant>
#include <QTableWidget>
#include <QStringList>
#include <QTime>

#include <QPainter>




namespace Ui {
class ListWithStudents;
}

class ListWithStudents : public QDialog
{
    Q_OBJECT
    
public:
    explicit ListWithStudents(QWidget *parent = 0);
    ~ListWithStudents();


    QString PersonalInformationForThePrinter[30];

private slots:

    void print(QPrinter *p);

    void on_RefreshAndSaveButton_clicked();

    void on_DeleteButton_clicked();

    void on_PrintButton_clicked();

    void on_NamesBox_currentTextChanged(const QString &arg1);

    void on_FiltrationLine_textChanged(const QString &arg1);

    void on_FiltrationToggle_clicked();

    void on_tableView_clicked(const QModelIndex &index);



    void on_tableView_entered(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);








private:
    Ui::ListWithStudents *ui;

    QSqlTableModel *ListModel;
     QSortFilterProxyModel *ProxyModel;
      QSqlQuery NamesQuery;
       QString FilterOption;
        QStringList AllFirstNames;
         QSqlQuery NameQuery;
          QStringList NameList;

          void load_main_settings();




};

#endif // LISTWITHSTUDENTS_H
