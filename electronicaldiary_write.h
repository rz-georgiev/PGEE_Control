#ifndef ELECTRONICALDIARY_WRITE_H
#define ELECTRONICALDIARY_WRITE_H

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
#include <QStandardItemModel>
#include <QLabel>


namespace Ui {
class Electronicaldiary_write;
}

class Electronicaldiary_write : public QDialog
{
    Q_OBJECT

public:
    explicit Electronicaldiary_write(QWidget *parent = 0);
    ~Electronicaldiary_write();

private slots:


    void on_SubjectBox_currentTextChanged(const QString &arg1);

    void on_IDEdit_textChanged(const QString &arg1);

private:
    Ui::Electronicaldiary_write *ui;

    QStringList SubjectsList;
     QSqlTableModel *ListModel;
      QSortFilterProxyModel *ProxyModel;

      void load_main_settings();
};

#endif // ELECTRONICALDIARY_WRITE_H
