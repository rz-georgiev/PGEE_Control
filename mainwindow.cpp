#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    load_main_settings();


}

MainWindow::~MainWindow()
{

 delete ui;

}


void MainWindow::on_action_triggered() // open new
{
    show_nDialog();
}


void MainWindow::on_action_2_triggered() // go to list with students and choose, who do you want to print out
{
    newListWithStudents->show();
}


void MainWindow::on_action_3_triggered() // notes for students
{
    NotesForStudentsDialog->show();
}


void MainWindow::on_action_4_triggered()  // open list with students
{
    newListWithStudents->show();
}


void MainWindow::on_action_15_triggered() // close this dialog
{
    this->close();
    qApp->exit();
}


void MainWindow::on_action_17_triggered() // open the electronical diary reader
{
    newDiary->show();
}


void MainWindow::on_action_18_triggered() // start camera dialog
{
    cameraClass->show();
}


void MainWindow::show_nDialog()  // start rubiks animation and dialog
{

    for(int i = 0; i <= 35; i++)
    {
        QString string = ":/rubik/MainResources/rubiks/tumble_cube_slow-.png";
        string.insert(46,QString::number(i));

        QApplication::setOverrideCursor(QCursor(QPixmap(string)));
        Sleep(20);


    }

    for(int i = 0; i <= 35; i++)
    {
        QApplication::restoreOverrideCursor();
    }

    nDialog->show();

}

void MainWindow::load_main_settings()
{
    update();

    QApplication::setStyle(QStyleFactory::create("fusion"));

    this->setWindowTitle("Главно меню");
     this->setWindowIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));
      ui->action_PGEE_Control->setIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));

    nDialog = new NStudentDialog(this); // registration for new student
    cameraClass = new CameraClass(this); // open camera menu
    newDiary = new ElectronicalDiary(this); // open Electronical diary for reading
    newWriteDiaryDialog = new Electronicaldiary_write(this); // open Electronical diary for writing
    newListWithStudents = new ListWithStudents(this); // open dialog with all students and the information for them
    NotesForStudentsDialog = new NotesForStudents(this); // open dialog for printing information of student
    ForPgeeDialog = new ForPGEE(this); // open dialog for information for PGEE
    NewChangeDialog = new ChangeInformationDialog(this); // open dialog for editing Information


    LockingCounter = 0;
    SecondLockingCounter = 0;

    LockingTimer = new QTimer(this);
    SecondLockingTimer = new QTimer(this);

    connect(LockingTimer, SIGNAL(timeout()), this, SLOT(CheckToLockScreen()));
    connect(SecondLockingTimer, SIGNAL(timeout()), this, SLOT(CheckIfRubikIsVisible()));

    LockingTimer->start(1000);
}




void MainWindow::on_action_5_triggered() //  open the electronical diary writer
{

   newWriteDiaryDialog->show();

}


void MainWindow::on_action_PGEE_Control_triggered()  // show For_PGEE dialog
{
    ForPgeeDialog->show();
}


void MainWindow::on_action_6_triggered() // show dialog, that will allow you to change information
{

    NewChangeDialog->show();

}


void MainWindow::CheckToLockScreen()   // Check every 10 seconds, if cursor position at 1 second is equal to cursor position at the 10 second.
{

    LockingCounter++;


    if(LockingCounter == 1)
    {
        CursorPositionAtX = this->cursor().pos().x();
        CursorPositionAtY = this->cursor().pos().y();
    }

    else if(LockingCounter == 60)
    {
        if(CursorPositionAtX == this->cursor().pos().x() && CursorPositionAtY == this->cursor().pos().y())
        {

            this->setEnabled(false);
            NewEncryptionDialog.exec();


            LockingCounter = 0;
            LockingTimer->stop();

            SecondLockingTimer->start(1000);

        }
        else
        {
            LockingCounter = 0;
        }
    }


}

void MainWindow::CheckIfRubikIsVisible() // Check if rubik is visible or it is not visible, so you can know should you start the timer again
{
    SecondLockingCounter++;


    if(SecondLockingCounter == 1)
    {
        if(NewEncryptionDialog.isVisibleTo(this))
        {
            qDebug() << "Visible";
        }
        else
        {
            this->setEnabled(true);
            SecondLockingCounter = 0;
            SecondLockingTimer->stop();
            LockingTimer->start(1000);
        }

        SecondLockingCounter = 0;

    }

}

