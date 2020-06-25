#include "logonmenu.h"
#include "ui_logonmenu.h"

LogonMenu::LogonMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogonMenu)
{
    ui->setupUi(this);

    load_main_settings();

}

LogonMenu::~LogonMenu()
{
    delete ui;
}





//All functions are implemented below...

void LogonMenu::on_LoginButton_clicked() // enter in the main menu if the filled information is correct
{
    start_rubik();

    check_login();
}


void LogonMenu::load_main_settings() // load main settings for this dialog
{



    this->setWindowTitle("Вписване в ПГЕЕ Бургас");
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));

    ui->UsernameLine->setMaxLength(16);
    ui->PasswordLine->setMaxLength(16);



    connect(ui->CloseButton,SIGNAL(clicked()),this,SLOT(close()));


    setMask((new QPixmap(":/Images/MainResources/FinalPadlock.png"))->mask());

    newPalette = new QPalette();
    newPalette->setBrush(QPalette::Background,QBrush(QPixmap(":/Images/MainResources/FinalPadlock.png")));

    setPalette(*newPalette);

}


void LogonMenu::check_login() // chech login if it is successful or not
{
    username = ui->UsernameLine->text();
    password = ui->PasswordLine->text();


        if(username == "1" && password == "2"){

            MainWindow *window1 = new MainWindow(this);

            ui->UsernameLine->setEnabled(false);
            ui->PasswordLine->setEnabled(false);
            ui->LoginButton->setEnabled(false);
            
            window1->show();

        }
        else{

            QMessageBox::critical(this, "Грешно въведена информация", "Грещно въведено потребителско име или парола!");
            ui->UsernameLine->clear();
            ui->PasswordLine->clear();
        }

}


void LogonMenu::start_rubik() // start rubiks cube animation
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
}


void LogonMenu::mouseMoveEvent(QMouseEvent *event) // this makes available the movement of the padlock
{
    if ( event->buttons() & Qt::LeftButton )
    {
        move( event->globalPos() - dragPosition );

        event->accept();
    }
}


void LogonMenu::mousePressEvent(QMouseEvent *event) // this makes available the movement of the padlock with left button
{
    if ( event->button() == Qt::LeftButton )
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}


void LogonMenu::on_UsernameLine_textChanged(const QString &arg1) // real time check of the login information and play sounds and animation
{

    if(ui->UsernameLine->text() == "1" && ui->PasswordLine->text() == "2")
    {


        setMask((new QPixmap(":/Images/MainResources/FinalPadlock2.png"))->mask());

        newPalette->setBrush(QPalette::Background,QBrush(QPixmap(":/Images/MainResources/FinalPadlock2.png")));

        setPalette(*newPalette);

        padlockSound->play(":/sounds/MainResources/door-lock-1.wav");
    }
    else
    {
        setMask((new QPixmap(":/Images/MainResources/FinalPadlock.png"))->mask());

        newPalette->setBrush(QPalette::Background,QBrush(QPixmap(":/Images/MainResources/FinalPadlock.png")));

        setPalette(*newPalette);


    }
}


void LogonMenu::on_PasswordLine_textChanged(const QString &arg1) // real time check of the login information and play sounds and animation
{
    if(ui->UsernameLine->text() == "1" && ui->PasswordLine->text() == "2")
    {


        setMask((new QPixmap(":/Images/MainResources/FinalPadlock2.png"))->mask());

        newPalette->setBrush(QPalette::Background,QBrush(QPixmap(":/Images/MainResources/FinalPadlock2.png")));

        setPalette(*newPalette);

        padlockSound->play(":/sounds/MainResources/door-lock-1.wav");
    }
    else
    {
        setMask((new QPixmap(":/Images/MainResources/FinalPadlock.png"))->mask());

        newPalette->setBrush(QPalette::Background,QBrush(QPixmap(":/Images/MainResources/FinalPadlock.png")));

        setPalette(*newPalette);

        padlockSound->play(":/sounds/MainResources/door-lock-2.wav");
    }
}

