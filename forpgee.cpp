#include "forpgee.h"
#include "ui_forpgee.h"

ForPGEE::ForPGEE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForPGEE)
{
    ui->setupUi(this);


    load_main_settings();

}

ForPGEE::~ForPGEE()
{
    delete ui;
}

void ForPGEE::load_main_settings()
{
    this->setWindowTitle("За PGEE_Control");
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));

    ui->label->setPixmap(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png"));
     ui->label_2->setText("Име на проекта: PGEE_CONTROL 2.0.0");
      ui->label_3->setText("Release: 02.02.2014");
       ui->label_4->setText("Автор: Радослав Георгиев");
}


