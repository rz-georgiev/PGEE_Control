#include "notesforstudents.h"
#include "ui_notesforstudents.h"

NotesForStudents::NotesForStudents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotesForStudents)
{
    ui->setupUi(this);


    load_main_settings();

}

NotesForStudents::~NotesForStudents()
{
    delete ui;
}

void NotesForStudents::load_main_settings() // load main settings for this dialog
{
    this->setWindowTitle("Допълнителни бележки за ученици");
    this->setWindowIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));

    ui->CitizenshipLine->setEnabled(false);
     ui->FormOfEducation->setEnabled(false);
      ui->NumberOfYearsPast->setEnabled(false);
       ui->FinishedSchoolYear->setEnabled(false);
        ui->dateEdit_2->setEnabled(false);
         ui->MadeByLine->setEnabled(false);
          ui->BirthPlace->setEnabled(false);
           ui->HomeAddressLine->setEnabled(false);

            ui->CityLine->setText("Бургас");
             ui->CommunityLine->setText("Бургас");
              ui->AreaLine->setText("Бургас");
               ui->PhoneLine->setText("817691");
                ui->AddressLine->setText("ул. Христо Ботев 42");



         ui->dateEdit->setDate(QDate::currentDate());
         ui->dateEdit_2->setDate(QDate::currentDate());
         ui->YearLine->setText(QString::number(QDate::currentDate().year()) + "/" + QString::number(QDate::currentDate().year() + 1));

         this->setFixedSize(this->width(),this->height());

         ui->PrintButton->setToolTip("<b><font color = 'blue'>Генерирай документ</font></b>");
}

void NotesForStudents::print(QPrinter *p) // prepare printer for A4 format blank list and bind values
{
    QPainter painter(p);


     QFont painterFont;
     painterFont.setPointSize(10);

     painter.setFont(painterFont);


        painter.setRenderHints(QPainter::Antialiasing |
                               QPainter::TextAntialiasing |
                               QPainter::SmoothPixmapTransform, true);

        if(ui->TypeOfListBox->currentIndex() == 0)
        {
            painter.drawPixmap(1,1,4700,6338,QPixmap(":/Icons/MainResources/BelejkaZaDetski.jpg"));
            painter.drawText(1200,1000,"Гр./с. " + ui->CityLine->text() + "\t          общ. " + ui->CommunityLine->text() + "\tобл. " + ui->AreaLine->text());
            painter.drawText(1200,1100,"Адрес: " + ui->AddressLine->text() + "\tтел: " + ui->PhoneLine->text());
            painter.drawText(1800,1570, ui->NumberLine->text() + "     от     " + ui->dateEdit->text());
            painter.drawText(1500,2000,ui->NameLine->text() + " " + ui->SecondNameLine->text() + " " + ui->ThirdNameLine->text());
            painter.drawText(1200,2200,"ЕГН: " + ui->EGNLine->text() + ",");
            painter.drawText(2520,2320,ui->YearLine->text());
            painter.drawText(2050,2440,ui->CurrentClassLine->text() + " клас ");
            painter.drawText(2300,3500,"Коста Папазов");
            painter.drawText(2325,3560,"(подпис и печат)");
        }
        else
        {
            painter.drawPixmap(1,1,4700,6338,QPixmap(":/Icons/MainResources/DescriptionOfStudent.jpg"));
            painter.drawText(1100,1150,ui->NameLine->text() + " " + ui->SecondNameLine->text() + " " + ui->ThirdNameLine->text());
            painter.drawText(3000,1150,ui->EGNLine->text());
            painter.drawText(1100,1320,ui->BirthPlace->text());
            painter.drawText(3000,1300,ui->CitizenshipLine->text());
            painter.drawText(1100,1425,ui->HomeAddressLine->text());
            painter.drawText(1000,1525,ui->FormOfEducation->text());
            painter.drawText(3480,1525,ui->FinishedSchoolYear->text());
            painter.drawText(3480,1625,ui->NumberOfYearsPast->text());
            painter.drawText(1050,1620,ui->YearLine->text());
            painter.drawText(3400,5545,ui->MadeByLine->text());
            painter.drawText(1050,5750,ui->dateEdit_2->text());


            if(ui->checkBox->isChecked())
            {
                painter.drawText(3010,2640,"X");
            }
            else if(ui->checkBox_2->isChecked())
            {
                painter.drawText(3460,2640,"X");
            }
            else if(ui->checkBox_3->isChecked())
            {
                painter.drawText(3910,2640,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_4->isChecked())
            {
                painter.drawText(3010,2740,"X");
            }
            else if(ui->checkBox_5->isChecked())
            {
                painter.drawText(3460,2740,"X");
            }
            else if(ui->checkBox_6->isChecked())
            {
                painter.drawText(3910,2740,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_7->isChecked())
            {
                painter.drawText(3010,2840,"X");
            }
            else if(ui->checkBox_8->isChecked())
            {
                painter.drawText(3460,2840,"X");
            }
            else if(ui->checkBox_9->isChecked())
            {
                painter.drawText(3910,2840,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_10->isChecked())
            {
                painter.drawText(3010,2940,"X");
            }
            else if(ui->checkBox_11->isChecked())
            {
                painter.drawText(3460,2940,"X");
            }
            else if(ui->checkBox_12->isChecked())
            {
                painter.drawText(3910,2940,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_13->isChecked())
            {
                painter.drawText(3010,3040,"X");
            }
            else if(ui->checkBox_14->isChecked())
            {
                painter.drawText(3460,3040,"X");
            }
            else if(ui->checkBox_15->isChecked())
            {
                painter.drawText(3910,3040,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_16->isChecked())
            {
                painter.drawText(3010,3140,"X");
            }
            else if(ui->checkBox_17->isChecked())
            {
                painter.drawText(3460,3140,"X");
            }
            else if(ui->checkBox_18->isChecked())
            {
                painter.drawText(3910,3140,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_19->isChecked())
            {
                painter.drawText(3010,3340,"X");
            }
            else if(ui->checkBox_20->isChecked())
            {
                painter.drawText(3460,3340,"X");
            }
            else if(ui->checkBox_21->isChecked())
            {
                painter.drawText(3910,3340,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_22->isChecked())
            {
                painter.drawText(3010,3440,"X");
            }
            else if(ui->checkBox_23->isChecked())
            {
                painter.drawText(3460,3440,"X");
            }
            else if(ui->checkBox_24->isChecked())
            {
                painter.drawText(3910,3440,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_25->isChecked())
            {
                painter.drawText(3010,3540,"X");
            }
            else if(ui->checkBox_26->isChecked())
            {
                painter.drawText(3460,3540,"X");
            }
            else if(ui->checkBox_27->isChecked())
            {
                painter.drawText(3910,3540,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_28->isChecked())
            {
                painter.drawText(3010,3640,"X");
            }
            else if(ui->checkBox_29->isChecked())
            {
                painter.drawText(3460,3640,"X");
            }
            else if(ui->checkBox_30->isChecked())
            {
                painter.drawText(3910,3640,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_31->isChecked())
            {
                painter.drawText(3010,3740,"X");
            }
            else if(ui->checkBox_32->isChecked())
            {
                painter.drawText(3460,3740,"X");
            }
            else if(ui->checkBox_33->isChecked())
            {
                painter.drawText(3910,3740,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_34->isChecked())
            {
                painter.drawText(3010,3840,"X");
            }
            else if(ui->checkBox_35->isChecked())
            {
                painter.drawText(3460,3840,"X");
            }
            else if(ui->checkBox_36->isChecked())
            {
                painter.drawText(3910,3840,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_37->isChecked())
            {
                painter.drawText(3010,4155,"X");
            }
            else if(ui->checkBox_38->isChecked())
            {
                painter.drawText(3460,4155,"X");
            }
            else if(ui->checkBox_39->isChecked())
            {
                painter.drawText(3910,4155,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_40->isChecked())
            {
                painter.drawText(3010,4245,"X");
            }
            else if(ui->checkBox_41->isChecked())
            {
                painter.drawText(3460,4245,"X");
            }
            else if(ui->checkBox_42->isChecked())
            {
                painter.drawText(3910,4245,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_43->isChecked())
            {
                painter.drawText(3010,4345,"X");
            }
            else if(ui->checkBox_44->isChecked())
            {
                painter.drawText(3460,4345,"X");
            }
            else if(ui->checkBox_45->isChecked())
            {
                painter.drawText(3910,4345,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_46->isChecked())
            {
                painter.drawText(3010,4440,"X");
            }
            else if(ui->checkBox_47->isChecked())
            {
                painter.drawText(3460,4440,"X");
            }
            else if(ui->checkBox_48->isChecked())
            {
                painter.drawText(3910,4440,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_49->isChecked())
            {
                painter.drawText(3010,4540,"X");
            }
            else if(ui->checkBox_50->isChecked())
            {
                painter.drawText(3460,4540,"X");
            }
            else if(ui->checkBox_51->isChecked())
            {
                painter.drawText(3910,4540,"X");
            }
            /////////////////////////////////////
            if(ui->checkBox_52->isChecked())
            {
                painter.drawText(3010,4640,"X");
            }
            else if(ui->checkBox_53->isChecked())
            {
                painter.drawText(3460,4640,"X");
            }
            else if(ui->checkBox_54->isChecked())
            {
                painter.drawText(3910,4640,"X");
            }
            /////////////////////////////////////
            painter.drawText(1500,3940,ui->lineEdit_2->text());
            /////////////////////////////////////
            painter.drawText(1500,4740,ui->lineEdit_3->text());
            /////////////////////////////////////
            painter.drawText(1500,4945,ui->lineEdit->text());
            /////////////////////////////////////
            painter.drawText(1500,5140,ui->lineEdit_4->text());


        }


//otlichno = 3010, 2645
//dobro = 3460, 2645
//nnop =  3910, 2645


}

void NotesForStudents::on_PrintButton_clicked() // open print preview dialog
{

    QPrinter printer(QPrinter::HighResolution);
    printer.setCreator("Аз");

    if(ui->TypeOfListBox->currentIndex() == 0)
    {
            printer.setDocName("УДОСТОВЕРЕНИЕ");
    }
    else
    {
            printer.setDocName("ХАРАКТЕРИСТИКА НА УЧЕНИКА");
    }

    printer.setPaperSize(QPrinter::A4);


    QPrintPreviewDialog *pDialog = new QPrintPreviewDialog(&printer,this);
    connect(pDialog,SIGNAL(paintRequested(QPrinter*)),this,SLOT(print(QPrinter*)));

    pDialog->exec();
}

void NotesForStudents::on_TypeOfListBox_currentIndexChanged(int index) // set enabled and disabled depending on the list choice
{
    index = ui->TypeOfListBox->currentIndex();

    if(index == 0)
    {
        ui->CitizenshipLine->setEnabled(false);
         ui->FormOfEducation->setEnabled(false);
          ui->NumberOfYearsPast->setEnabled(false);
           ui->FinishedSchoolYear->setEnabled(false);
            ui->dateEdit_2->setEnabled(false);
             ui->MadeByLine->setEnabled(false);
              ui->BirthPlace->setEnabled(false);
               ui->HomeAddressLine->setEnabled(false);

           ui->CommunityLine->setEnabled(true);
            ui->AreaLine->setEnabled(true);
             ui->PhoneLine->setEnabled(true);
              ui->CurrentClassLine->setEnabled(true);
               ui->dateEdit->setEnabled(true);
                ui->NumberLine->setEnabled(true);
                 ui->CityLine->setEnabled(true);
                  ui->AddressLine->setEnabled(true);
    }
    else
    {
        ui->CitizenshipLine->setEnabled(true);
         ui->FormOfEducation->setEnabled(true);
          ui->NumberOfYearsPast->setEnabled(true);
           ui->FinishedSchoolYear->setEnabled(true);
            ui->dateEdit_2->setEnabled(true);
             ui->MadeByLine->setEnabled(true);
              ui->BirthPlace->setEnabled(true);
               ui->HomeAddressLine->setEnabled(true);

            ui->CommunityLine->setEnabled(false);
             ui->AreaLine->setEnabled(false);
              ui->PhoneLine->setEnabled(false);
               ui->CurrentClassLine->setEnabled(false);
                ui->dateEdit->setEnabled(false);
                 ui->NumberLine->setEnabled(false);
                  ui->CityLine->setEnabled(false);
                   ui->AddressLine->setEnabled(false);
    }
}







void NotesForStudents::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
        ui->checkBox_2->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
    }
    else
    {
        ui->checkBox_2->setEnabled(true);
        ui->checkBox_3->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked())
    {
        ui->checkBox->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
    }
    else
    {
        ui->checkBox->setEnabled(true);
        ui->checkBox_3->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_3_clicked()
{
    if(ui->checkBox_3->isChecked())
    {
        ui->checkBox->setEnabled(false);
        ui->checkBox_2->setEnabled(false);
    }
    else
    {
        ui->checkBox->setEnabled(true);
        ui->checkBox_2->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_4_clicked()
{
    if(ui->checkBox_4->isChecked())
    {
        ui->checkBox_5->setEnabled(false);
        ui->checkBox_6->setEnabled(false);
    }
    else
    {
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_6->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_5_clicked()
{
    if(ui->checkBox_5->isChecked())
    {
        ui->checkBox_4->setEnabled(false);
        ui->checkBox_6->setEnabled(false);
    }
    else
    {
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_6->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_6_clicked()
{
    if(ui->checkBox_6->isChecked())
    {
        ui->checkBox_4->setEnabled(false);
        ui->checkBox_5->setEnabled(false);
    }
    else
    {
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_5->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_7_clicked()
{
    if(ui->checkBox_7->isChecked())
    {
        ui->checkBox_8->setEnabled(false);
        ui->checkBox_9->setEnabled(false);
    }
    else
    {
        ui->checkBox_8->setEnabled(true);
        ui->checkBox_9->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_8_clicked()
{
    if(ui->checkBox_8->isChecked())
    {
        ui->checkBox_7->setEnabled(false);
        ui->checkBox_9->setEnabled(false);
    }
    else
    {
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_9->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_9_clicked()
{
    if(ui->checkBox_9->isChecked())
    {
        ui->checkBox_7->setEnabled(false);
        ui->checkBox_8->setEnabled(false);
    }
    else
    {
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_8->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_10_clicked()
{
    if(ui->checkBox_10->isChecked())
    {
        ui->checkBox_11->setEnabled(false);
        ui->checkBox_12->setEnabled(false);
    }
    else
    {
        ui->checkBox_11->setEnabled(true);
        ui->checkBox_12->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_11_clicked()
{
    if(ui->checkBox_11->isChecked())
    {
        ui->checkBox_10->setEnabled(false);
        ui->checkBox_12->setEnabled(false);
    }
    else
    {
        ui->checkBox_10->setEnabled(true);
        ui->checkBox_12->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_12_clicked()
{
    if(ui->checkBox_12->isChecked())
    {
        ui->checkBox_10->setEnabled(false);
        ui->checkBox_11->setEnabled(false);
    }
    else
    {
        ui->checkBox_10->setEnabled(true);
        ui->checkBox_11->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_13_clicked()
{
    if(ui->checkBox_13->isChecked())
    {
        ui->checkBox_14->setEnabled(false);
        ui->checkBox_15->setEnabled(false);
    }
    else
    {
        ui->checkBox_14->setEnabled(true);
        ui->checkBox_15->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_14_clicked()
{
    if(ui->checkBox_14->isChecked())
    {
        ui->checkBox_13->setEnabled(false);
        ui->checkBox_15->setEnabled(false);
    }
    else
    {
        ui->checkBox_13->setEnabled(true);
        ui->checkBox_15->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_15_clicked()
{
    if(ui->checkBox_15->isChecked())
    {
        ui->checkBox_13->setEnabled(false);
        ui->checkBox_14->setEnabled(false);
    }
    else
    {
        ui->checkBox_13->setEnabled(true);
        ui->checkBox_14->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_16_clicked()
{
    if(ui->checkBox_16->isChecked())
    {
        ui->checkBox_17->setEnabled(false);
        ui->checkBox_18->setEnabled(false);
    }
    else
    {
        ui->checkBox_17->setEnabled(true);
        ui->checkBox_18->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_17_clicked()
{
    if(ui->checkBox_17->isChecked())
    {
        ui->checkBox_16->setEnabled(false);
        ui->checkBox_18->setEnabled(false);
    }
    else
    {
        ui->checkBox_16->setEnabled(true);
        ui->checkBox_18->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_18_clicked()
{
    if(ui->checkBox_18->isChecked())
    {
        ui->checkBox_16->setEnabled(false);
        ui->checkBox_17->setEnabled(false);
    }
    else
    {
        ui->checkBox_16->setEnabled(true);
        ui->checkBox_17->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_19_clicked()
{
    if(ui->checkBox_19->isChecked())
    {
        ui->checkBox_20->setEnabled(false);
        ui->checkBox_21->setEnabled(false);
    }
    else
    {
        ui->checkBox_20->setEnabled(true);
        ui->checkBox_21->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_20_clicked()
{
    if(ui->checkBox_20->isChecked())
    {
        ui->checkBox_19->setEnabled(false);
        ui->checkBox_21->setEnabled(false);
    }
    else
    {
        ui->checkBox_19->setEnabled(true);
        ui->checkBox_21->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_21_clicked()
{
    if(ui->checkBox_21->isChecked())
    {
        ui->checkBox_19->setEnabled(false);
        ui->checkBox_20->setEnabled(false);
    }
    else
    {
        ui->checkBox_19->setEnabled(true);
        ui->checkBox_20->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_22_clicked()
{
    if(ui->checkBox_22->isChecked())
    {
        ui->checkBox_23->setEnabled(false);
        ui->checkBox_24->setEnabled(false);
    }
    else
    {
        ui->checkBox_23->setEnabled(true);
        ui->checkBox_24->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_23_clicked()
{
    if(ui->checkBox_23->isChecked())
    {
        ui->checkBox_22->setEnabled(false);
        ui->checkBox_24->setEnabled(false);
    }
    else
    {
        ui->checkBox_22->setEnabled(true);
        ui->checkBox_24->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_24_clicked()
{
    if(ui->checkBox_24->isChecked())
    {
        ui->checkBox_22->setEnabled(false);
        ui->checkBox_23->setEnabled(false);
    }
    else
    {
        ui->checkBox_22->setEnabled(true);
        ui->checkBox_23->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_25_clicked()
{
    if(ui->checkBox_25->isChecked())
    {
        ui->checkBox_26->setEnabled(false);
        ui->checkBox_27->setEnabled(false);
    }
    else
    {
        ui->checkBox_26->setEnabled(true);
        ui->checkBox_27->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_26_clicked()
{
    if(ui->checkBox_26->isChecked())
    {
        ui->checkBox_25->setEnabled(false);
        ui->checkBox_27->setEnabled(false);
    }
    else
    {
        ui->checkBox_25->setEnabled(true);
        ui->checkBox_27->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_27_clicked()
{
    if(ui->checkBox_27->isChecked())
    {
        ui->checkBox_25->setEnabled(false);
        ui->checkBox_26->setEnabled(false);
    }
    else
    {
        ui->checkBox_25->setEnabled(true);
        ui->checkBox_26->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_28_clicked()
{
    if(ui->checkBox_28->isChecked())
    {
        ui->checkBox_29->setEnabled(false);
        ui->checkBox_30->setEnabled(false);
    }
    else
    {
        ui->checkBox_29->setEnabled(true);
        ui->checkBox_30->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_29_clicked()
{
    if(ui->checkBox_29->isChecked())
    {
        ui->checkBox_28->setEnabled(false);
        ui->checkBox_30->setEnabled(false);
    }
    else
    {
        ui->checkBox_28->setEnabled(true);
        ui->checkBox_30->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_30_clicked()
{
    if(ui->checkBox_30->isChecked())
    {
        ui->checkBox_28->setEnabled(false);
        ui->checkBox_29->setEnabled(false);
    }
    else
    {
        ui->checkBox_28->setEnabled(true);
        ui->checkBox_29->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_31_clicked()
{
    if(ui->checkBox_31->isChecked())
    {
        ui->checkBox_32->setEnabled(false);
        ui->checkBox_33->setEnabled(false);
    }
    else
    {
        ui->checkBox_32->setEnabled(true);
        ui->checkBox_33->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_32_clicked()
{
    if(ui->checkBox_32->isChecked())
    {
        ui->checkBox_31->setEnabled(false);
        ui->checkBox_33->setEnabled(false);
    }
    else
    {
        ui->checkBox_31->setEnabled(true);
        ui->checkBox_33->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_33_clicked()
{
    if(ui->checkBox_33->isChecked())
    {
        ui->checkBox_31->setEnabled(false);
        ui->checkBox_32->setEnabled(false);
    }
    else
    {
        ui->checkBox_31->setEnabled(true);
        ui->checkBox_32->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_34_clicked()
{
    if(ui->checkBox_34->isChecked())
    {
        ui->checkBox_35->setEnabled(false);
        ui->checkBox_36->setEnabled(false);
    }
    else
    {
        ui->checkBox_35->setEnabled(true);
        ui->checkBox_36->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_35_clicked()
{
    if(ui->checkBox_35->isChecked())
    {
        ui->checkBox_34->setEnabled(false);
        ui->checkBox_36->setEnabled(false);
    }
    else
    {
        ui->checkBox_34->setEnabled(true);
        ui->checkBox_36->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_36_clicked()
{
    if(ui->checkBox_36->isChecked())
    {
        ui->checkBox_34->setEnabled(false);
        ui->checkBox_35->setEnabled(false);
    }
    else
    {
        ui->checkBox_34->setEnabled(true);
        ui->checkBox_35->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_37_clicked()
{
    if(ui->checkBox_37->isChecked())
    {
        ui->checkBox_38->setEnabled(false);
        ui->checkBox_39->setEnabled(false);
    }
    else
    {
        ui->checkBox_38->setEnabled(true);
        ui->checkBox_39->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_38_clicked()
{
    if(ui->checkBox_38->isChecked())
    {
        ui->checkBox_37->setEnabled(false);
        ui->checkBox_39->setEnabled(false);
    }
    else
    {
        ui->checkBox_37->setEnabled(true);
        ui->checkBox_39->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_39_clicked()
{
    if(ui->checkBox_39->isChecked())
    {
        ui->checkBox_37->setEnabled(false);
        ui->checkBox_38->setEnabled(false);
    }
    else
    {
        ui->checkBox_37->setEnabled(true);
        ui->checkBox_38->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_40_clicked()
{
    if(ui->checkBox_40->isChecked())
    {
        ui->checkBox_41->setEnabled(false);
        ui->checkBox_42->setEnabled(false);
    }
    else
    {
        ui->checkBox_41->setEnabled(true);
        ui->checkBox_42->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_41_clicked()
{
    if(ui->checkBox_41->isChecked())
    {
        ui->checkBox_40->setEnabled(false);
        ui->checkBox_42->setEnabled(false);
    }
    else
    {
        ui->checkBox_40->setEnabled(true);
        ui->checkBox_42->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_42_clicked()
{
    if(ui->checkBox_42->isChecked())
    {
        ui->checkBox_40->setEnabled(false);
        ui->checkBox_41->setEnabled(false);
    }
    else
    {
        ui->checkBox_40->setEnabled(true);
        ui->checkBox_41->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_43_clicked()
{
    if(ui->checkBox_43->isChecked())
    {
        ui->checkBox_44->setEnabled(false);
        ui->checkBox_45->setEnabled(false);
    }
    else
    {
        ui->checkBox_44->setEnabled(true);
        ui->checkBox_45->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_44_clicked()
{
    if(ui->checkBox_44->isChecked())
    {
        ui->checkBox_43->setEnabled(false);
        ui->checkBox_45->setEnabled(false);
    }
    else
    {
        ui->checkBox_43->setEnabled(true);
        ui->checkBox_45->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_45_clicked()
{
    if(ui->checkBox_45->isChecked())
    {
        ui->checkBox_43->setEnabled(false);
        ui->checkBox_44->setEnabled(false);
    }
    else
    {
        ui->checkBox_43->setEnabled(true);
        ui->checkBox_44->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_46_clicked()
{
    if(ui->checkBox_46->isChecked())
    {
        ui->checkBox_47->setEnabled(false);
        ui->checkBox_48->setEnabled(false);
    }
    else
    {
        ui->checkBox_47->setEnabled(true);
        ui->checkBox_48->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_47_clicked()
{
    if(ui->checkBox_47->isChecked())
    {
        ui->checkBox_46->setEnabled(false);
        ui->checkBox_48->setEnabled(false);
    }
    else
    {
        ui->checkBox_46->setEnabled(true);
        ui->checkBox_48->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_48_clicked()
{
    if(ui->checkBox_48->isChecked())
    {
        ui->checkBox_46->setEnabled(false);
        ui->checkBox_47->setEnabled(false);
    }
    else
    {
        ui->checkBox_46->setEnabled(true);
        ui->checkBox_47->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_49_clicked()
{
    if(ui->checkBox_49->isChecked())
    {
        ui->checkBox_50->setEnabled(false);
        ui->checkBox_51->setEnabled(false);
    }
    else
    {
        ui->checkBox_50->setEnabled(true);
        ui->checkBox_51->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_50_clicked()
{
    if(ui->checkBox_50->isChecked())
    {
        ui->checkBox_49->setEnabled(false);
        ui->checkBox_51->setEnabled(false);
    }
    else
    {
        ui->checkBox_49->setEnabled(true);
        ui->checkBox_51->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_51_clicked()
{
    if(ui->checkBox_51->isChecked())
    {
        ui->checkBox_49->setEnabled(false);
        ui->checkBox_50->setEnabled(false);
    }
    else
    {
        ui->checkBox_49->setEnabled(true);
        ui->checkBox_50->setEnabled(true);

    }
}
//////////////////////////////////////////////////////
void NotesForStudents::on_checkBox_52_clicked()
{
    if(ui->checkBox_52->isChecked())
    {
        ui->checkBox_53->setEnabled(false);
        ui->checkBox_54->setEnabled(false);
    }
    else
    {
        ui->checkBox_53->setEnabled(true);
        ui->checkBox_54->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_53_clicked()
{
    if(ui->checkBox_53->isChecked())
    {
        ui->checkBox_52->setEnabled(false);
        ui->checkBox_54->setEnabled(false);
    }
    else
    {
        ui->checkBox_52->setEnabled(true);
        ui->checkBox_54->setEnabled(true);

    }
}

void NotesForStudents::on_checkBox_54_clicked()
{
    if(ui->checkBox_54->isChecked())
    {
        ui->checkBox_52->setEnabled(false);
        ui->checkBox_53->setEnabled(false);
    }
    else
    {
        ui->checkBox_52->setEnabled(true);
        ui->checkBox_53->setEnabled(true);

    }
}



