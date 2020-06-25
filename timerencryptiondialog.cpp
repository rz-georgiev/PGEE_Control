#include "timerencryptiondialog.h"
#include "ui_timerencryptiondialog.h"

TimerEncryptionDialog::TimerEncryptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerEncryptionDialog)
{
    ui->setupUi(this);


    load_main_settings();


}

TimerEncryptionDialog::~TimerEncryptionDialog()
{
    delete ui;
}

void TimerEncryptionDialog::mouseMoveEvent(QMouseEvent *event) // default mouse move event. It is used for the right moving of the dialog, after cutting the main dialog
{
    move( event->globalPos() - dragPosition );

    event->accept();
}

void TimerEncryptionDialog::mousePressEvent(QMouseEvent *event) // check when mouse left button is pressed and synchronize with mouseMoveEvent
{
    if ( event->button() == Qt::LeftButton )
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void TimerEncryptionDialog::reject() // Qt default OnReject()/OnCloseDialog method
{
    if( ui->PasswordLine->text() == "1" )
    {
        onRejectTimer->start(1000);
    }
    else
    {
        QMessageBox::critical(this,"Грешка", "Не може да затворите този диалог, без правилно въведена парола.");
    }
}



void TimerEncryptionDialog::MaskLooperZero() // Set unsolved rubik dialog palette and mask
{
    setMask((new QPixmap(":/LockingTimerRubiks/MainResources/LockingTimerRubiks/0.png"))->mask());

    newPalette = new QPalette();
    newPalette->setBrush(QPalette::Background,QBrush(QPixmap(":/LockingTimerRubiks/MainResources/LockingTimerRubiks/0.png")));

    setPalette(*newPalette);
}

void TimerEncryptionDialog::MaskLooperOne() // Set solved rubik dialog palette and mask
{
    setMask((new QPixmap(":/LockingTimerRubiks/MainResources/LockingTimerRubiks/9.png"))->mask());

    newPalette = new QPalette();
    newPalette->setBrush(QPalette::Background,QBrush(QPixmap(":/LockingTimerRubiks/MainResources/LockingTimerRubiks/9.png")));

    setPalette(*newPalette);
}

void TimerEncryptionDialog::load_main_settings()
{
    this->setFixedSize(this->width(), this->height());
    this->setWindowTitle("Автоматично заключване");
    this->setWindowIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));

    ui->PasswordLine->setMaxLength(8);

    MaskLooperZero();


    RubikTimer = new QTimer(this);
    onRejectTimer = new QTimer(this);

    RubikCounter = 0;
    RejectionCounter = 0;

    connect(RubikTimer, SIGNAL(timeout()), this, SLOT(DoRubiksAnimationAndClose()));
    connect(onRejectTimer, SIGNAL(timeout()), this, SLOT(onRejectClose()));
}




void TimerEncryptionDialog::on_UnlockButton_clicked() // check if password is true and then prepare to solve rubiks cube and close it
{
    if(ui->PasswordLine->text() == "1")
    {
        RubikTimer->start(1000);

    }
    else
    {
        QMessageBox::critical(this,"Грешка", "Вие въведохте грешна парола, моля опитайте отново.");
    }
}

void TimerEncryptionDialog::DoRubiksAnimationAndClose() // close rubik when entered password is true and if RubikCounter == 2, then close and destroy this dialog
{

    MaskLooperOne();


    RubikCounter += 1;

    if ( RubikCounter == 2 )
    {
       MaskLooperZero();

       ui->PasswordLine->clear();

       RubikCounter = 0;
       RubikTimer->stop();
       this->setVisible(false);
       this->destroy(true,false);
    }


}

void TimerEncryptionDialog::onRejectClose() // this magical algorithm, lies Qt framework, not to close the dialog, until the entered password is true.
                                            // if i don't use that fragment of code, then everyone who has some programming abilities, will see that there is big hole in the security.
                                            // if this piece of code is not used, then you can close this dialog, without the true password. This is big hole in the security, really.
{
      RejectionCounter += 1;

      if(RejectionCounter == 1)
      {
          MaskLooperOne();
      }
      else
      {
          onRejectTimer->stop();
          MaskLooperZero();

          RejectionCounter = 0;
          ui->PasswordLine->clear();
          done(0);

      }
}


