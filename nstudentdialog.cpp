#include "nstudentdialog.h"
#include "ui_nstudentdialog.h"


NStudentDialog::NStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NStudentDialog)
{
    ui->setupUi(this);


    load_main_settings();
    load_first_region();



}


NStudentDialog::~NStudentDialog() //destructor for the dialog
{
    db.close();
    delete ui;
}



void NStudentDialog::on_pushButton_clicked()  //calendar
{
    ui->label_20->setVisible(false);
    ui->calendarWidget->setVisible(true);
    ui->pushButton_4->setVisible(true);

}

void NStudentDialog::on_pushButton_2_clicked()  // save personal information in database
{
    //line edits 12,13,14,15 are not needed


    checkIfEverythingIsSuccessful();

}

void NStudentDialog::on_pushButton_3_clicked() //close NStudentDialog and clean all line edits
{
    clean_all_line_edits();
}

void NStudentDialog::on_pushButton_4_clicked()  //calendar current date and set date
{

 ui->label_20->setVisible(true);

    if(ui->PictureLine->text().isEmpty()){

        qDebug() << "directory does not exists or line edit is empty!";

        ui->label_20->setPixmap(QPixmap(":/Images/MainResources/Who_is_it.png"));
    }
    else{

        ui->label_20->setPixmap(QPixmap(ImagePath));
    }

    QString date = ui->calendarWidget->selectedDate().toString("dd-MM-yyyy");
    ui->SaveDateLine->setText(date);
    ui->calendarWidget->setVisible(false);
    ui->pushButton_4->setVisible(false);

}

void NStudentDialog::on_pushButton_5_clicked()    //search for photo
{

    ui->calendarWidget->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ImagePath = QFileDialog::getOpenFileName(this,"Избери снимка на ученика","E:/ALL STUFF WITHOUT GAMES/ВсичкиСнимки/Снимки",tr("Image Formats (*.TIFF *.PNG *.GIF *.JPG *.JPEG *.RAW *.BMP)"));
    if(ImagePath.isEmpty()){

        ui->pushButton_4->setVisible(false);
        ui->label_20->setVisible(true);
        ui->PictureLine->clear();
        QMessageBox::warning(this,"Грешка","Не сте избрали снимка");
        ui->label_20->setPixmap(QPixmap(":/Images/MainResources/Who_is_it.png"));
        return;

    }
    else{
        ui->PictureLine->clear();
        ui->PictureLine->setText(ImagePath);
        ui->label_20->setVisible(true);
        ui->label_20->setPixmap(QPixmap(ImagePath));
    }


}




void NStudentDialog::on_EGNLine_textChanged(const QString &arg1) // This is the whole magic EGN algorithm
{

    EGN = ui->EGNLine->text();

     month[0] = EGN.at(2);
      month[1] = EGN.at(3);
       month[2] = month[0] + month[1];
        final_month = month[2].toInt();

        a = EGN.at(2);
        b = EGN.at(3);
        c = a + b;
        second_month = c.toInt();

        day[0] = EGN.at(4);
         day[1] = EGN.at(5);
          day[2] = day[0] + day[1];
           final_day = day[2].toInt();


         current_year = QDate::currentDate().year();
          current_month = QDate::currentDate().month();
           current_day = QDate::currentDate().day();


         //first set gender
           gender_choose = EGN.at(8);
           final_gender = gender_choose.toInt();

           if(final_gender % 2 == 0){
               ui->GenderLine->setText("Мъжки");
           }
           else{
               ui->GenderLine->setText("Женски");
           }

    if(ui->EGNLine->text().isEmpty()){
        ui->AgeLine->clear();
        ui->GenderLine->clear();
    }

    else{


        if(final_month < 41){

            year[0] = EGN.at(0);
             year[1] = EGN.at(1);
              year[2] = "19" + year[0] + year[1];
               final_year = year[2].toInt();




                   if(final_month < current_month){

                       ui->AgeLine->setText(QString::number(current_year - final_year));
                   }

                   else{

                      ui->AgeLine->setText(QString::number(current_year - final_year - 1));
                   }

                   if((final_month == current_month) && (final_day == current_day)){

                       ui->AgeLine->setText(QString::number(current_year - final_year));
                   }

                   if((final_month == current_month) && (final_day < current_day)){

                       ui->AgeLine->setText(QString::number(current_year - final_year));
                   }

                   if((final_month == current_month) && (final_day > current_day)){

                       ui->AgeLine->setText(QString::number(current_year - final_year - 1));
                   }


        }

        else{
            year[2] = "20" + year[0] + year[1];
            final_year = year[2].toInt();

            switch(second_month)
            {
                case 41: second_month = 1; break;
                case 42: second_month = 2; break;
                case 43: second_month = 3; break;
                case 44: second_month = 4; break;
                case 45: second_month = 5; break;
                case 46: second_month = 6; break;
                case 47: second_month = 7; break;
                case 48: second_month = 8; break;
                case 49: second_month = 9; break;
                case 50: second_month = 10; break;
                case 51: second_month = 11; break;
                case 52: second_month = 12; break;
            }




                if(second_month < current_month)
                {
                   ui->AgeLine->setText(QString::number(current_year - final_year));
                }
                else
                {
                   ui->AgeLine->setText(QString::number(current_year - final_year - 1));
                }

                if((second_month == current_month) && (final_day == current_day))
                {
                    ui->AgeLine->setText(QString::number(current_year - final_year));
                }

                if((second_month == current_month) && (final_day < current_day))
                {
                    ui->AgeLine->setText(QString::number(current_year - final_year));
                }

                if((second_month == current_month) && (final_day > current_day))
                {
                    ui->AgeLine->setText(QString::number(current_year - final_year - 1));
                }

        }
    }
}

void NStudentDialog::on_CommunityLine_currentTextChanged(const QString &arg1) // Load some cities, depending of the selected area and region
{
    loadCurrentRegion(ui->CommunityLine->currentText());
}



void NStudentDialog::load_main_settings() //load title,calendar conditions, and make dialog unresizeable
{
    this->setWindowIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));
    this->setWindowTitle("Регистрация на ученик");
    this->setFixedSize(this->width(),this->height());



    db = QSqlDatabase::addDatabase("QSQLITE");

    QString SqlitePath = QFileInfo( QCoreApplication::applicationFilePath() ).absolutePath() + "/SqliteDatabase/PGEE.sqlite";
      db.setDatabaseName(SqlitePath);

      qDebug() << "path: " << SqlitePath;
         db.open();



    ui->calendarWidget->setVisible(false);
    ui->pushButton_4->setVisible(false);

    ui->AgeLine->setReadOnly(true);
    ui->GenderLine->setReadOnly(true);
    ui->SaveDateLine->setReadOnly(true);


    ui->label_20->setVisible(false);
    ui->PictureLine->setReadOnly(true);

    fill_boxes();
    auto_refill_button_counter = 0;

        ui->FormMasterLine->addItems(TeachersList);
         ui->SubjectLine->addItems(SubjectsList);
          ui->SpecialtyLine->addItems(SpecialtyList);

           ui->ClassLine->addItems(ClassesList);
            ui->ClassByWordsLine->addItems(ClassesListByString);
             ui->ConnectionWithTheStudentLine->addItems(TypeGuardianList);

               QRegExp rx("[a-zA-Zа-яА-Я\-\ ]*");
                QRegExp nx("[0-9\ ]*");
                 QRegExp px("[a-zA-Zа-яА-Я0-9\-\ ]*");
                //  QRegExp tx("[a-zA-Zа-яА-Я\-\.\ ]*");

               ui->NameLine->setValidator(new QRegExpValidator(rx,ui->NameLine));
                ui->SecondNameLine->setValidator(new QRegExpValidator(rx,ui->SecondNameLine));
                 ui->ThirdNameLine->setValidator(new QRegExpValidator(rx,ui->ThirdNameLine));
                  ui->ParentLine->setValidator(new QRegExpValidator(rx,ui->ParentLine));



                     ui->EGNLine->setValidator(new QRegExpValidator(nx,ui->EGNLine));
                      ui->PhoneLine->setValidator(new QRegExpValidator(nx,ui->PhoneLine));
                       ui->BlockLine->setValidator(new QRegExpValidator(nx,ui->BlockLine));
                        ui->FloorLine->setValidator(new QRegExpValidator(nx,ui->FloorLine));
                         ui->ApartmentLine->setValidator(new QRegExpValidator(nx,ui->ApartmentLine));

                          ui->StreetLine->setValidator(new QRegExpValidator(px,ui->StreetLine));
                           ui->EntranceLine->setValidator(new QRegExpValidator(px,ui->EntranceLine));
                            ui->JobLine->setValidator(new QRegExpValidator(px,ui->JobLine));
                             ui->JobPlaceLine->setValidator(new QRegExpValidator(px,ui->JobPlaceLine));



                             ui->NameLine->setMaxLength(20);
                               ui->SecondNameLine->setMaxLength(20);
                                 ui->ThirdNameLine->setMaxLength(20);
                                   ui->EGNLine->setMaxLength(10);
                                     ui->ParentLine->setMaxLength(40);
                                       ui->JobPlaceLine->setMaxLength(30);
                                         ui->JobLine->setMaxLength(30);
                                           ui->PhoneLine->setMaxLength(15);
                                             ui->StreetLine->setMaxLength(30);
                                               ui->BlockLine->setMaxLength(3);
                                                 ui->EntranceLine->setMaxLength(3);
                                                   ui->FloorLine->setMaxLength(3);
                                                     ui->ApartmentLine->setMaxLength(3);


                                                     ui->label_20->setVisible(true);
                                                     ui->label_20->setPixmap(QPixmap(":/Images/MainResources/Who_is_it.png"));

                                                     ui->pushButton_2->setToolTip("<b><i><font color = 'blue'> Запиши </color></i></b>");
                                                     ui->pushButton_3->setToolTip("<b><i><font color = 'red'> Отказ </color></i></b>");
                                                     ui->pushButton_6->setToolTip("<b><i><font color = 'green'> Обнови записващата информация </color></i></b>");
                                                     ui->AutoRefillButton->setToolTip("<b><i><font color = 'green'> Запълни формата с примерна информация </color></i></b>");

                                                     QSqlQuery LoadClassTeacherInformation;
                                                      QSqlQuery LoadSubjectsInformation;
                                                       QSqlQuery LoadSpecialityInformation;


                                                     LoadClassTeacherInformation.prepare("SELECT * FROM Учители");
                                                      LoadSubjectsInformation.prepare("SELECT * FROM Учебни_предмети");
                                                       LoadSpecialityInformation.prepare("SELECT * FROM Специалности");

                                                     if(LoadClassTeacherInformation.exec())
                                                     {
                                                         while(LoadClassTeacherInformation.next())
                                                         {
                                                             ClassTeachersList.append(LoadClassTeacherInformation.value(0).toStringList());
                                                         }
                                                         ui->FormMasterLine->addItems(ClassTeachersList);
                                                     }

                                                     if(LoadSubjectsInformation.exec())
                                                     {
                                                         while(LoadSubjectsInformation.next())
                                                         {
                                                             NewSubjectsList.append(LoadSubjectsInformation.value(0).toStringList());
                                                         }
                                                         ui->SubjectLine->addItems(NewSubjectsList);
                                                     }

                                                     if(LoadSpecialityInformation.exec())
                                                     {
                                                         while(LoadSpecialityInformation.next())
                                                         {
                                                             SpecialityListNew.append(LoadSpecialityInformation.value(0).toStringList());
                                                         }
                                                         ui->SpecialtyLine->addItems(SpecialityListNew);
                                                     }


}

void NStudentDialog::loadCurrentRegion(QString current_region) // Select region from the database, depending on the made query
{

    QSqlQuery MainQuery;
       QStringList MainList;
         QString queryBinder = "SELECT * FROM ";



    current_region = ui->CommunityLine->currentText();


    queryBinder.insert(14 , current_region);


    qDebug() << "finalQuery: " << queryBinder ;


             ui->CityLine->clear();

             if(MainQuery.exec(queryBinder))
             {
                 qDebug() <<"Query is ok!";


                 while(MainQuery.next())
                 {
                     MainList.append(MainQuery.value(0).toStringList());
                 }
                 ui->CityLine->addItems(MainList);
             }
             else
             {
                  QMessageBox::critical(this,"Грешка при зареждане на регионите от базата с данни","Моля проверете връзката с базата данни на Sqlite");
             }
}

void NStudentDialog::load_first_region() //load first region and database + database query
{

     ui->CityLine->clear();

     if(db.open())
     {
         qDebug() <<"Opened!";
         QSqlQuery LoadQuery;
         QStringList LoadList;

         if(LoadQuery.exec("SELECT * FROM Айтос"))
         {
             qDebug() <<"Query Opened";
             while(LoadQuery.next())
             {
                 LoadList.append(LoadQuery.value(0).toStringList());
             }
             ui->CityLine->addItems(LoadList);
         }
         else
         {
             QMessageBox::critical(this,"Грешка при зареждане на регионите от базата с данни","Моля проверете връзката с базата данни на SQL");
         }

     }

     else
     {
         QMessageBox::critical(this,"Грешка при зареждане на базата с данни","Моля проверете връзката с базата данни на SQL");
         qDebug() << "Error from db open = " << db.lastError().text();
     }

}

void NStudentDialog::clean_all_line_edits() //clean all line edits on successful save and then close NStudentDialog
{
     ui->NameLine->clear();
      ui->SecondNameLine->clear();
       ui->ThirdNameLine->clear();
        ui->EGNLine->clear();
         ui->AgeLine->clear();
          ui->GenderLine->clear();
           ui->PhoneLine->clear();
            ui->ParentLine->clear();
             ui->JobLine->clear();
              ui->JobPlaceLine->clear();
               ui->SaveDateLine->clear();
                ui->StreetLine->clear();
                 ui->BlockLine->clear();
                  ui->EntranceLine->clear();
                   ui->FloorLine->clear();
                    ui->ApartmentLine->clear();
                     ui->PictureLine->clear();
                      ui->Notes->clear();
                       ui->label_20->setPixmap(QPixmap(":/Images/MainResources/Who_is_it.png"));

                         this->close();
}

void NStudentDialog::fill_boxes() // Fill some registration boxes with some default information
{


   ClassesList << "8" << "9" << "10" << "11" << "12";
    ClassesListByString << "А" << "Б" << "В" << "Г" << "Д";

     TypeGuardianList << "Майка" << "Баща" << "Баба";
      TypeGuardianList << "Дядо" << "Леля" << "Чичо";
       TypeGuardianList << "Свако" << "Стринка" << "Брат";
        TypeGuardianList << "Сестра" << "Вуйчо" << "Вуйна";
         TypeGuardianList << "Братовчед" << "Братовчедка";
          TypeGuardianList << "Соц.работник" << "Друг";
           TypeGuardianList.sort(Qt::CaseSensitive);

}

void NStudentDialog::checkIfEverythingIsSuccessful() // check if there is no problem with the registration lines
{
    if(ui->NameLine->text().isEmpty() || ui->SecondNameLine->text().isEmpty()
            || ui->ThirdNameLine->text().isEmpty() || ui->EGNLine->text().isEmpty()
            || ui->AgeLine->text().isEmpty() || ui->GenderLine->text().isEmpty()
            || ui->PhoneLine->text().isEmpty() || ui->ParentLine->text().isEmpty()
            || ui->JobPlaceLine->text().isEmpty() || ui->SaveDateLine->text().isEmpty()
            || ui->StreetLine->text().isEmpty()|| ui->PictureLine->text().isEmpty())


    {


        QMessageBox::critical(this,"Грешка при записване на нов ученик","Моля попълнете всички задължителни полета");
        return;
    }



    else if(ui->AgeLine->text().toInt() < 1)
    {
        QMessageBox::critical(this,"Грешно ЕГН","Моля проверете въведеното от вас ЕГН");
        return;
    }


    else{


       QSqlQuery SaveInformationQuery;
       QString PreparePersonalInformation = "INSERT INTO UserInformation ([Име],[Презиме],[Фамилия],[ЕГН],[Навършени години],[Пол],[Дата на вписване],[Път на изображение],[Настойник],[Връзка с ученик],[Месторабота],[Професия],[Телефонен номер],[Регион],[Град/Село],[Комплекс/Улица],[Блок],[Вход],[Етаж],[Апартамент],[Забележка],[Класен ръководител],[Преподава по],[Специалност],[Клас],[Клас_със_букви]) VALUES (:name,:second_name,:third_name,:egn,:age,:gender,:date_of_entry,:image_pos,:guardian,:type_guardian,:job,:current_job,:phone_number,:community,:city_or_village,:complex_or_street,:block,:entrance,:floor,:apartment,:comment,:form_master,:taught,:speciality,:class,:class_by_word)";

       SaveInformationQuery.prepare(PreparePersonalInformation);

       SaveInformationQuery.bindValue(":name",ui->NameLine->text());
        SaveInformationQuery.bindValue(":second_name",ui->SecondNameLine->text());
         SaveInformationQuery.bindValue(":third_name",ui->ThirdNameLine->text());
          SaveInformationQuery.bindValue(":egn",ui->EGNLine->text());
           SaveInformationQuery.bindValue(":age",ui->AgeLine->text());
            SaveInformationQuery.bindValue(":gender",ui->GenderLine->text());
             SaveInformationQuery.bindValue(":date_of_entry",ui->SaveDateLine->text());
              SaveInformationQuery.bindValue(":image_pos",ui->PictureLine->text());
               SaveInformationQuery.bindValue(":guardian",ui->ParentLine->text());
                SaveInformationQuery.bindValue(":type_guardian",ui->ConnectionWithTheStudentLine->currentText());
                 SaveInformationQuery.bindValue(":job",ui->JobPlaceLine->text());
                  SaveInformationQuery.bindValue(":current_job",ui->JobLine->text());
                   SaveInformationQuery.bindValue(":phone_number",ui->PhoneLine->text());
                    SaveInformationQuery.bindValue(":community",ui->CommunityLine->currentText());
                     SaveInformationQuery.bindValue(":city_or_village",ui->CityLine->currentText());
                      SaveInformationQuery.bindValue(":complex_or_street",ui->StreetLine->text());
                       SaveInformationQuery.bindValue(":block",ui->BlockLine->text());
                        SaveInformationQuery.bindValue(":entrance",ui->EntranceLine->text());
                         SaveInformationQuery.bindValue(":floor",ui->FloorLine->text());
                          SaveInformationQuery.bindValue(":apartment",ui->ApartmentLine->text());
                           SaveInformationQuery.bindValue(":comment",ui->Notes->toPlainText());

                            SaveInformationQuery.bindValue(":form_master",ui->FormMasterLine->currentText());
                             SaveInformationQuery.bindValue(":taught",ui->SubjectLine->currentText());
                              SaveInformationQuery.bindValue(":speciality",ui->SpecialtyLine->currentText());
                               SaveInformationQuery.bindValue(":class",ui->ClassLine->currentText());
                                SaveInformationQuery.bindValue(":class_by_word",ui->ClassByWordsLine->currentText());



       if(SaveInformationQuery.exec()){
           QMessageBox::information(this,"Успешен Запис","Ученикът бе записан успешно в базата данни");
           clean_all_line_edits();
         //  db.exec();

       }
       else{
           QMessageBox::critical(this,"Грешка при записване на нов ученик","Моля проверете базата данни");
           qDebug() << "query problem: " << SaveInformationQuery.lastError().text();
           return;
       }

    }
}

void NStudentDialog::reject()
{
    clean_all_line_edits();

    done(0);
}


void NStudentDialog::on_pushButton_6_clicked() //update information for this dialog
{
    QSqlQuery LoadClassTeacherInformation;
     QSqlQuery LoadSubjectsInformation;
      QSqlQuery LoadSpecialityInformation;


    LoadClassTeacherInformation.prepare("SELECT * FROM Учители");
     LoadSubjectsInformation.prepare("SELECT * FROM Учебни_предмети");
      LoadSpecialityInformation.prepare("SELECT * FROM Специалности");

    ClassTeachersList.clear();
    ui->FormMasterLine->clear();
    if(LoadClassTeacherInformation.exec())
    {
        while(LoadClassTeacherInformation.next())
        {
            ClassTeachersList.append(LoadClassTeacherInformation.value(0).toStringList());
        }
        ui->FormMasterLine->addItems(ClassTeachersList);
    }

    NewSubjectsList.clear();
    ui->SubjectLine->clear();
    if(LoadSubjectsInformation.exec())
    {
        while(LoadSubjectsInformation.next())
        {
            NewSubjectsList.append(LoadSubjectsInformation.value(0).toStringList());
        }
        ui->SubjectLine->addItems(NewSubjectsList);
    }

    SpecialityListNew.clear();
    ui->SpecialtyLine->clear();
    if(LoadSpecialityInformation.exec())
    {
        while(LoadSpecialityInformation.next())
        {
            SpecialityListNew.append(LoadSpecialityInformation.value(0).toStringList());
        }
        ui->SpecialtyLine->addItems(SpecialityListNew);
    }
}

void NStudentDialog::on_AutoRefillButton_clicked() // fill some example information in the line edits
{


        if(auto_refill_button_counter == 0)
        {
            ui->NameLine->setText("Радослав");
             ui->SecondNameLine->setText("Златомиров");
              ui->ThirdNameLine->setText("Георгиев");
               ui->EGNLine->setText("9608180586");
                ui->SaveDateLine->setText("22.12.2012");
                 ui->PictureLine->setText(":/Icons/MainResources/MeLocker.jpg");
                  ui->ParentLine->setText("Димитър Георгиев");
                   ui->JobPlaceLine->setText("ТестАрена ООД");
                    ui->JobLine->setText("Архитект");
                     ui->PhoneLine->setText("0855506479");
                      ui->StreetLine->setText("Хърватска");
                       ui->BlockLine->setText("5");
                        ui->EntranceLine->setText("2");
                         ui->FloorLine->setText("4");
                          ui->ApartmentLine->setText("3");
                           ui->Notes->setPlainText("Тази форма бе попълнена автоматично [пример] ");
                            ui->label_20->setPixmap(QPixmap(":/Icons/MainResources/MeLocker.jpg"));
                             ui->ConnectionWithTheStudentLine->setCurrentIndex(1);

                          auto_refill_button_counter = 1;
        }
        else
        {
           ui->label_20->setPixmap(QPixmap(":/Images/MainResources/Who_is_it.png"));
            ui->NameLine->clear();
             ui->SecondNameLine->clear();
              ui->ThirdNameLine->clear();
               ui->EGNLine->clear();
                ui->SaveDateLine->clear();
                 ui->PictureLine->clear();
                  ui->ParentLine->clear();
                   ui->JobPlaceLine->clear();
                    ui->JobLine->clear();
                     ui->PhoneLine->clear();
                      ui->StreetLine->clear();
                       ui->BlockLine->clear();
                        ui->EntranceLine->clear();
                         ui->FloorLine->clear();
                          ui->ApartmentLine->clear();
                           ui->Notes->clear();

                           auto_refill_button_counter = 0;
        }

}

