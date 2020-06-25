#ifndef NSTUDENTDIALOG_H
#define NSTUDENTDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QtSql>
#include <QSql>
#include <QSqlQuery>

#include <QStringList>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>
#include <QDate>
#include <QPlainTextEdit>
#include <QKeyEvent>

namespace Ui {
class NStudentDialog;
}

class NStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NStudentDialog(QWidget *parent = 0);
    ~NStudentDialog();


    
private slots:



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_EGNLine_textChanged(const QString &arg1);

    void on_CommunityLine_currentTextChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_AutoRefillButton_clicked();

private:
    Ui::NStudentDialog *ui;

      QSqlDatabase db;
       QString setDirectory, EGN , a , b , c , ImagePath , gender_choose , year[20] , month[20] , day[20] ;
        QStringList RegionList , TeachersList , SubjectsList , SpecialtyList , ClassesList, ClassesListByString, TypeGuardianList;
         QStringList ClassTeachersList, NewSubjectsList, SpecialityListNew;

           int  final_year , final_month , final_day , final_gender;
             int current_year , current_month , current_day;
               int  this_year,this_month,this_day,second_month;

                int auto_refill_button_counter;



    void loadCurrentRegion(QString current_region);
    void load_main_settings();
    void load_first_region();
    void clean_all_line_edits();
    void fill_boxes();
    void checkIfEverythingIsSuccessful();
    void reject();


};

#endif // NSTUDENTDIALOG_H
