#ifndef LOGONMENU_H
#define LOGONMENU_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QSound>
#include <QPoint>
#include <QBitmap>
#include "nstudentdialog.h"
#include "mainwindow.h"
namespace Ui {
class LogonMenu;
}

class LogonMenu : public QDialog
{
    Q_OBJECT
    
public:
    explicit LogonMenu(QWidget *parent = 0);
    ~LogonMenu();

private slots:


    void on_UsernameLine_textChanged(const QString &arg1);

    void on_PasswordLine_textChanged(const QString &arg1);

    void on_LoginButton_clicked();


private:
    Ui::LogonMenu *ui;
     void load_main_settings();
      void check_login();
       void start_rubik();
        void  mouseMoveEvent(QMouseEvent *event);
         void  mousePressEvent(QMouseEvent *event);

          QString username, password;
           QPoint dragPosition;
            QPalette *newPalette;
             QSound *padlockSound;
              QSize imagesize;


};

#endif // LOGONMENU_H


