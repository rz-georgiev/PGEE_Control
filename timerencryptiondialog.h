#ifndef TIMERENCRYPTIONDIALOG_H
#define TIMERENCRYPTIONDIALOG_H

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
#include <QTimer>
#include <windows.h>
namespace Ui {
class TimerEncryptionDialog;
}

class TimerEncryptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimerEncryptionDialog(QWidget *parent = 0);
    ~TimerEncryptionDialog();

private slots:
    void on_UnlockButton_clicked();
    void DoRubiksAnimationAndClose();
    void onRejectClose();



private:
    Ui::TimerEncryptionDialog *ui;

    void  mouseMoveEvent(QMouseEvent *event);
     void  mousePressEvent(QMouseEvent *event);
      void reject();
       void MaskLooperZero();
        void MaskLooperOne();
         void load_main_settings();

     int RubikCounter;
     int RejectionCounter;


     QPoint dragPosition;
      QPalette *newPalette;

      QTimer *RubikTimer;
      QTimer *onRejectTimer;


};

#endif // TIMERENCRYPTIONDIALOG_H
