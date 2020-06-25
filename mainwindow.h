#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QStringList>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QInputDialog>
#include <QTimer>

#include "logonmenu.h"
#include "nstudentdialog.h"
#include "cameraclass.h"
#include "listwithstudents.h"
#include "electronicaldiary.h"
#include "notesforstudents.h"
#include "electronicaldiary_write.h"
#include "forpgee.h"
#include "changeinformationdialog.h"
#include "timerencryptiondialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_action_triggered(); //new student

    void on_action_2_triggered();  //print

    void on_action_3_triggered();  //notes for students

    void on_action_4_triggered();  //list with students

    void on_action_15_triggered(); //exit

    void on_action_17_triggered(); //electronical diary

    void on_action_18_triggered(); //camera

    void on_action_5_triggered();  //electronical diary [write mode]

    void on_action_PGEE_Control_triggered();

    void on_action_6_triggered();

    void CheckToLockScreen();

    void CheckIfRubikIsVisible();



private:

    Ui::MainWindow *ui;

    NStudentDialog *nDialog;

     CameraClass *cameraClass;

      ElectronicalDiary *newDiary;

       Electronicaldiary_write *newWriteDiaryDialog;

        ListWithStudents *newListWithStudents;

         NotesForStudents *NotesForStudentsDialog;

          ForPGEE *ForPgeeDialog;

           ChangeInformationDialog *NewChangeDialog;

            TimerEncryptionDialog NewEncryptionDialog;

            QTimer *LockingTimer;

             QTimer *SecondLockingTimer;

             void show_nDialog();

             int CursorPositionAtX;
              int CursorPositionAtY;
               int LockingCounter;
                int SecondLockingCounter;

                QString LockingTimerPassword;

                void load_main_settings();


};

#endif // MAINWINDOW_H

