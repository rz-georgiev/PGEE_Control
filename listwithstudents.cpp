#include "listwithstudents.h"
#include "ui_listwithstudents.h"

ListWithStudents::ListWithStudents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListWithStudents)
{
    ui->setupUi(this);


    load_main_settings();




}


ListWithStudents::~ListWithStudents()
{

    delete ui;

}


void ListWithStudents::load_main_settings()
{
    ui->tableView->setMouseTracking(true);
    ui->tableView->viewport()->setAttribute(Qt::WA_Hover,true);

    this->setWindowTitle("Списък с ученици");
    this->setWindowIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));

    ui->PrintButton->setToolTip("<b><i><font color = 'blue'> Принтирай информация за избрания ученик </color></i></b>");
     ui->DeleteButton->setToolTip("<b><i><font color = 'blue'> Изтрий избрания ученик </color></i></b>");
      ui->RefreshAndSaveButton->setToolTip("<b><i><font color = 'blue'> Обнови списък с ученици </color></i></b>");

    ListModel = new QSqlTableModel(ui->tableView);
    ListModel->setTable("UserInformation");
    ListModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ListModel->select();




    ui->tableView->setSortingEnabled(true);
    ui->FiltrationToggle->setChecked(true);



    ProxyModel = new QSortFilterProxyModel(this);
    ProxyModel->setSourceModel(ListModel);


    ui->tableView->setModel(ProxyModel);
    ProxyModel->setFilterFixedString(0);





    if(NameQuery.exec("SELECT Име FROM UserInformation"))
    {
        while(NameQuery.next())
        {
            NameList.append(NameQuery.value(0).toStringList());
        }
        ui->NamesBox->addItems(NameList);
    }



    ui->FiltrationLine->setReadOnly(true);
    ui->NamesBox->setDisabled(true);


    if(ui->FiltrationToggle->isChecked())
    {

        ProxyModel->setFilterKeyColumn(1);

        ProxyModel->setFilterFixedString(0);
        ui->FiltrationLine->setReadOnly(true);
        ui->NamesBox->setDisabled(true);
    }
    else
    {
        ProxyModel->setFilterKeyColumn(1);

        ProxyModel->setFilterFixedString(ui->NamesBox->currentText());
        ui->FiltrationLine->setReadOnly(false);
        ui->NamesBox->setDisabled(false);

    }

    ui->tableView->hideColumn(0);

}




void ListWithStudents::on_RefreshAndSaveButton_clicked() //refresh list with students
{



    if(NameQuery.exec("SELECT Име FROM UserInformation"))
    {
        NameList.clear();
        ui->NamesBox->clear();
        while(NameQuery.next())
        {
            NameList.append(NameQuery.value(0).toStringList());
        }
        ui->NamesBox->addItems(NameList);
    }


    ProxyModel->setFilterFixedString(0);
    ListModel->submitAll();


}


void ListWithStudents::on_DeleteButton_clicked() // delete current student
{

    QMessageBox *deleteQuestion = new QMessageBox(this);

    deleteQuestion->setText("Сигурни ли сте че искате да изтриете този ученик?");

    deleteQuestion->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);

    deleteQuestion->show();

    int FinalAnswer = deleteQuestion->exec();
    qDebug() << FinalAnswer;
    switch (FinalAnswer)
    {
    case QMessageBox::Yes:
        ProxyModel->removeRows(ui->tableView->currentIndex().row(),1);
        ListModel->submitAll();
          break;

      case QMessageBox::Cancel:

          return;

          break;

    }

    if(NameQuery.exec("SELECT Име FROM UserInformation"))
    {
        NameList.clear();
        ui->NamesBox->clear();
        while(NameQuery.next())
        {
            NameList.append(NameQuery.value(0).toStringList());
        }
        ui->NamesBox->addItems(NameList);
    }


    ProxyModel->setFilterFixedString(0);
    ListModel->submitAll();


}


void ListWithStudents::on_NamesBox_currentTextChanged(const QString &arg1) // combobox that is containing names of the filtered students
{
       ProxyModel->setFilterKeyColumn(1);
       ProxyModel->setFilterFixedString(ui->NamesBox->currentText());

}


void ListWithStudents::on_FiltrationLine_textChanged(const QString &arg1) // line edit for filtration of students
{
    ProxyModel->setFilterKeyColumn(1);
    ProxyModel->setFilterFixedString(ui->FiltrationLine->text());
}


void ListWithStudents::on_FiltrationToggle_clicked() // check box for filtration toggle
{

    ListModel->submitAll();
    ProxyModel->setFilterKeyColumn(1);

    if(ui->FiltrationToggle->isChecked())
    {

        ProxyModel->setFilterFixedString(0);
        ui->FiltrationLine->setReadOnly(true);
        ui->NamesBox->setDisabled(true);
    }
    else
    {
        ProxyModel->setFilterFixedString(ui->NamesBox->currentText());
        ui->FiltrationLine->setReadOnly(false);
        ui->NamesBox->setDisabled(false);

    }
}


void ListWithStudents::on_tableView_clicked(const QModelIndex &index) // table view for this dialog
{


    for(int i = 1; i <= 26; i++)
    {

        PersonalInformationForThePrinter[i] = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),i)).toString();

    }


}


void ListWithStudents::print(QPrinter *p) // print information for the selected student // you need printer ;D
{
    QPainter painter(p);
     painter.setPen(Qt::black);

     QFont painterFont;
     painterFont.setPointSize(12);

     QFont LogoFont;
     LogoFont.setPointSize(15);

     QFont MainLogoFont;
     MainLogoFont.setPointSize(18);

     painter.setFont(painterFont);


        painter.setRenderHints(QPainter::Antialiasing |
                               QPainter::TextAntialiasing |
                               QPainter::SmoothPixmapTransform, true);

    painter.drawPixmap(3800,100,600,600,QPixmap(":/Icons/MainResources/PGEE_Control_Version.png"));
     painter.drawPixmap(3800,1400,800,800,PersonalInformationForThePrinter[8]);
      painter.drawRect(3750,1350,900,900);
      painter.setFont(LogoFont);
       painter.drawText(3700,1000,"PGEE_CONTROL");

        painter.setFont(painterFont);
         painter.drawText(300, 1000, "Име: "); painter.drawText(1600,1000,PersonalInformationForThePrinter[1]);
          painter.drawText(300, 1200, "Презиме: "); painter.drawText(1600,1200,PersonalInformationForThePrinter[2]);
           painter.drawText(300, 1400, "Фамилия: "); painter.drawText(1600,1400,PersonalInformationForThePrinter[3]);

          painter.drawText(300, 1600, "ЕГН: "); painter.drawText(1600,1600,PersonalInformationForThePrinter[4]);
           painter.drawText(300, 1800, "Навършени години: "); painter.drawText(1600,1800,PersonalInformationForThePrinter[5]);
            painter.drawText(300, 2000, "Пол: "); painter.drawText(1600,2000,PersonalInformationForThePrinter[6]);

            painter.drawText(300, 2200, "Дата на вписване: "); painter.drawText(1600,2200,PersonalInformationForThePrinter[7]);
             painter.drawText(300, 2400, "Настойник: "); painter.drawText(1600,2400,PersonalInformationForThePrinter[9]);
              painter.drawText(300, 2600, "Връзка с ученик: "); painter.drawText(1600,2600,PersonalInformationForThePrinter[10]);

              painter.drawText(300, 2800, "Месторабота: "); painter.drawText(1600,2800,PersonalInformationForThePrinter[11]);
               painter.drawText(300, 3000, "Професия: "); painter.drawText(1600,3000,PersonalInformationForThePrinter[12]);
                painter.drawText(300, 3200, "Телефонен номер: "); painter.drawText(1600,3200,PersonalInformationForThePrinter[13]);

                painter.drawText(300, 3400, "Регион: "); painter.drawText(1600,3400,PersonalInformationForThePrinter[14]);
                 painter.drawText(300, 3600, "Град/Село: "); painter.drawText(1600,3600,PersonalInformationForThePrinter[15]);
                  painter.drawText(300, 3800, "Комплекс/Улица: "); painter.drawText(1600,3800,PersonalInformationForThePrinter[16]);

                  painter.drawText(300, 4000, "Блок: "); painter.drawText(1600,4000,PersonalInformationForThePrinter[17]);
                   painter.drawText(300, 4200, "Вход: "); painter.drawText(1600,4200,PersonalInformationForThePrinter[18]);
                    painter.drawText(300, 4400, "Етаж: "); painter.drawText(1600,4400,PersonalInformationForThePrinter[19]);

                    painter.drawText(300, 4600, "Апартамент: "); painter.drawText(1600,4600,PersonalInformationForThePrinter[20]);
                     painter.drawText(300, 4800, "Класен ръководител: "); painter.drawText(1600,4800,PersonalInformationForThePrinter[22]);
                      painter.drawText(300, 5000, "Преподава по: "); painter.drawText(1600,5000,PersonalInformationForThePrinter[23]);

                      painter.drawText(300, 5200, "Специалност: "); painter.drawText(1600,5200,PersonalInformationForThePrinter[24]);
                       painter.drawText(300, 5400, "Клас: "); painter.drawText(1600,5400,PersonalInformationForThePrinter[25]);
                        painter.drawText(300, 5600, "Клас със букви: "); painter.drawText(1600,5600,PersonalInformationForThePrinter[26]);

                         painter.drawText(300, 5800, "Забележки: "); painter.drawText(1600,5800,PersonalInformationForThePrinter[21]);

                          painter.drawText(2300,6500,"Класен ръководител: .................................  ...........");
                           painter.drawText(2300,6700,"Директор:  .................................  ...........");

                           painter.setFont(MainLogoFont);
                            painter.drawText(1500,500,"Информация за ученика");
                             painter.setFont(painterFont);
                              painter.drawText(200,6500,"Дата на отпечатване: "); painter.drawText(1300,6500,QDate::currentDate().toString("dd.MM.yyyy"));
                               painter.drawText(200,6700,"Час на отпечатване: "); painter.drawText(1300,6700,QTime::currentTime().toString("hh:mm:ss:zzz"));



}


void ListWithStudents::on_PrintButton_clicked() // Click to start preview dialog and print
{
    QPrinter printer(QPrinter::HighResolution);

    printer.setCreator("Аз");
    printer.setDocName("ИНФОРМАЦИЯ ЗА ИЗБРАНИЯ УЧЕНИК");
    printer.setPaperSize(QPrinter::A4);



    QPrintPreviewDialog *pd = new QPrintPreviewDialog(&printer,this);

    connect(pd,SIGNAL(paintRequested(QPrinter*)),this,SLOT(print(QPrinter*)));

    pd->exec();
}


void ListWithStudents::on_tableView_entered(const QModelIndex &index) // This fragment of code shows image of some student when you move your mouse in the image path column, by default it is white empty blank
{

    QString ImagePath =  ui->tableView->model()->data(ui->tableView->model()->index(index.row(),index.column())).toString();
    QString FinalImagePath = "<img src = " + QString("'") + QString(ImagePath) + QString("' width = 350 height = 250>");


    if ( index.column() == 8 )
    {


        if ( !QDir(ImagePath).exists() )
        {
            QToolTip::showText(QPoint(900,200),FinalImagePath);
        }
        else if( ImagePath.isEmpty() )
        {
            QToolTip::showText(QPoint(900,200),"<img src = ':/Images/MainResources/Who_is_it.png' width = 250 height = 250>");
        }
        else
        {
            QToolTip::showText(QPoint(900,200),"<img src = ':/Images/MainResources/Who_is_it.png' width = 250 height = 250>");
        }

    }
    else
    {
        FinalImagePath.clear();
        QToolTip::hideText();
    }


}


void ListWithStudents::on_tableView_doubleClicked(const QModelIndex &index) // this code allows you when you double click on some image path you can change it
{
    if ( index.column() == 8 )
    {

       QString current_Image = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),ui->tableView->currentIndex().column())).toString();;
       QString newImage = QFileDialog::getOpenFileName(this,"Избери нова снимка");

       if( newImage.isEmpty() )
       {
           ui->tableView->model()->setData(ui->tableView->currentIndex(),current_Image);
       }
       else
       {
           ui->tableView->model()->setData(ui->tableView->currentIndex(),newImage);
       }


    }
}
