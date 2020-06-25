#ifndef CHANGEINFORMATIONDIALOG_H
#define CHANGEINFORMATIONDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QtSql>
#include <QSql>
#include <QSqlTableModel>
#include <QInputDialog>
#include <QMessageBox>

namespace Ui {
class ChangeInformationDialog;
}

class ChangeInformationDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ChangeInformationDialog(QWidget *parent = 0);
    ~ChangeInformationDialog();
    
private slots:
    void on_Add3_clicked();

    void on_Delete3_clicked();

    void on_Add2_clicked();

    void on_Delete2_clicked();

    void on_Add1_clicked();

    void on_Delete1_clicked();

private:
    Ui::ChangeInformationDialog *ui;

    QSqlTableModel *ClassTeacherModel;
     QSqlTableModel *SubjectModel;
      QSqlTableModel *SpecialityModel;
       void load_main_settings();


};

#endif // CHANGEINFORMATIONDIALOG_H
