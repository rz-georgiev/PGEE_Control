#ifndef NOTESFORSTUDENTS_H
#define NOTESFORSTUDENTS_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QPrinter>
#include <QPrintPreviewDialog>

namespace Ui {
class NotesForStudents;
}

class NotesForStudents : public QDialog
{
    Q_OBJECT
    
public:
    explicit NotesForStudents(QWidget *parent = 0);
    ~NotesForStudents();
    
private:
    Ui::NotesForStudents *ui;

    void load_main_settings();

private slots:

    void print(QPrinter *p);

    void on_TypeOfListBox_currentIndexChanged(int index);


    void on_checkBox_clicked();
    void on_checkBox_2_clicked();
    void on_checkBox_3_clicked();
    void on_checkBox_4_clicked();
    void on_checkBox_5_clicked();
    void on_checkBox_6_clicked();
    void on_checkBox_9_clicked();
    void on_checkBox_8_clicked();
    void on_checkBox_7_clicked();
    void on_checkBox_10_clicked();
    void on_checkBox_11_clicked();
    void on_checkBox_12_clicked();
    void on_checkBox_13_clicked();
    void on_checkBox_14_clicked();
    void on_checkBox_15_clicked();
    void on_checkBox_16_clicked();
    void on_checkBox_17_clicked();
    void on_checkBox_18_clicked();
    void on_checkBox_19_clicked();
    void on_checkBox_20_clicked();
    void on_checkBox_21_clicked();
    void on_checkBox_22_clicked();
    void on_checkBox_23_clicked();
    void on_checkBox_24_clicked();
    void on_checkBox_25_clicked();
    void on_checkBox_26_clicked();
    void on_checkBox_27_clicked();
    void on_checkBox_28_clicked();
    void on_checkBox_29_clicked();
    void on_checkBox_30_clicked();
    void on_checkBox_31_clicked();
    void on_checkBox_32_clicked();
    void on_checkBox_33_clicked();
    void on_checkBox_34_clicked();
    void on_checkBox_35_clicked();
    void on_checkBox_36_clicked();
    void on_checkBox_37_clicked();
    void on_checkBox_38_clicked();
    void on_checkBox_39_clicked();
    void on_checkBox_40_clicked();
    void on_checkBox_41_clicked();
    void on_checkBox_42_clicked();
    void on_checkBox_43_clicked();
    void on_checkBox_44_clicked();
    void on_checkBox_45_clicked();
    void on_checkBox_46_clicked();
    void on_checkBox_47_clicked();
    void on_checkBox_48_clicked();
    void on_checkBox_49_clicked();
    void on_checkBox_50_clicked();
    void on_checkBox_51_clicked();
    void on_checkBox_52_clicked();
    void on_checkBox_53_clicked();
    void on_checkBox_54_clicked();
    void on_PrintButton_clicked();

};

#endif // NOTESFORSTUDENTS_H
