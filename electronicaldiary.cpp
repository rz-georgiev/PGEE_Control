#include "electronicaldiary.h"
#include "ui_electronicaldiary.h"
#include <QColor>
ElectronicalDiary::ElectronicalDiary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ElectronicalDiary)
{
    ui->setupUi(this);


    load_main_settings();

}


ElectronicalDiary::~ElectronicalDiary()
{
    delete ui;
}



void ElectronicalDiary::load_main_settings() // load all main settings
{
    this->setWindowTitle("Електронен дневник / Четене");
    this->setWindowIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));

    ListModel = new QSqlTableModel(ui->tableView);
    ProxyModel = new QSortFilterProxyModel(this);

    ListModel->setTable("UserInformation");
    ListModel->select();
    ui->tableView->setModel(ListModel);
    ListModel->setEditStrategy(QSqlTableModel::OnManualSubmit);


    ProxyModel->setSourceModel(ListModel);
    ProxyModel->setFilterFixedString(0);
    ProxyModel->setFilterKeyColumn(1);


    ui->tableView->setSortingEnabled(true);
    ui->RefreshButton->setToolTip("<b><i><font color = 'green'>Обнови списък</font></i></b>");


    ui->NameLine->setEnabled(false);
     ui->ClassBox->setEnabled(false);
      ui->ClassLBox->setEnabled(false);
       ui->NameLine->setEnabled(false);
        ui->SubjectBox->setEnabled(false);
         ui->FiltrationToggle->setChecked(true);
          ui->StudentNameBox->setEnabled(false);
           ui->NameFiltrationToggle->setEnabled(false);



          SubjectsList << "БЕЛ" << "Математика" << "Английски_език";
           SubjectsList << "Физика" << "Химия" << "ФВС";
            SubjectsList << "Немски_език" << "История" << "Психология";
             SubjectsList << "География" << "Електротехника" << "Градивни_елементи";
              SubjectsList << "Информатика" << "Инф_Технологии" << "Биология";
               SubjectsList << "Цифрова_схемотехника" << "Аналогова_Схемотехника" << "Електротехническо_чертане";
                SubjectsList << "Етика_и_право" << "ЗБУТ" << "ТХД";
                 SubjectsList << "Икономика" << "Лабораторна_ел_измервания" << "Програмиране";
                  SubjectsList << "ТС_и_Ремонта" << "Техн_механика_и_машинни_елементи" << "Схемотехника";
                   SubjectsList << "Електроенергетика" << "Процесори_и_памети" << "Управление_на_АиП";
                    SubjectsList << "Предприемачество" << "Философия" << "Уплътнителни_телефонни_системи";
                     SubjectsList << "Хидрокинетични_съоражения_и_инсталации" << "Геотермални_съоражения_и_инсталации" << "Соларни_отоплителни_инсталации";
                      SubjectsList << "Електроника_и_преобразувателна_техника" << "Преносни_линии" << "Процесори_памети_и_ДП";
                       SubjectsList << "Потребителски_устройства" << "Електромонтажна_по_специалността" << "Монтаж_и_експлоатация";
                        SubjectsList << "ЕМА" << "Осветителна_техника" << "Диагностика_и_ремонт";
                         SubjectsList << "Мобилни_комуникации" << "Проектиране_на_асансьори" << "Проектиране";
                          SubjectsList << "Производствена_практика" << "Практика_по_специалността" << "Експлоатация_и_поддръжка";
                           SubjectsList << "Отраслови_стандарти" << "Комплексна_практика_по_специалността" << "Свят_и_личност";
                            SubjectsList << "Цифрови_мрежи_и_системи" << "Електрозадвижване" << "Автоматизация";
                             SubjectsList << "Технология" << "Електрически_машини" << "Бизнес_комуникации";
                              SubjectsList << "Лабораторна_диагностика_и_контрол" << "Периферни_устройства" << "Запомнящи_устройства";
                               SubjectsList << "Асемблиране_на_PC" << "Електроника_и_автоматизация" << "Руски_език";
                                SubjectsList.sort(Qt::CaseSensitive);



          ui->SubjectBox->addItems(SubjectsList);

          ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


}



void ElectronicalDiary::FilterInformation(QString class_x, QString class_word) // filter information for the table view with student parameters
{
     class_x = ui->ClassBox->currentText();
     class_word = ui->ClassLBox->currentText();

     qDebug() << "number" << class_x;
     qDebug() << "word: " << class_word;


     QString FilterOperation = "Клас = 8  AND Клас_със_букви = ''";
     QString FilterFOperation = FilterOperation.replace(7,2,class_x);
     if(class_x.length() == 1)
     {
         FilterFOperation.insert(31,class_word);
     }
     else
     {
         FilterFOperation.insert(32,class_word);
     }


     ListModel->setFilter(FilterFOperation);

     qDebug() << FilterFOperation;


}

void ElectronicalDiary::FilterStudentsForAppendingList(QString class_a, QString class_word_a) // filter information for the combobox students list
{

    class_a = ui->ClassBox->currentText();
    class_word_a = ui->ClassLBox->currentText();

    StudentsList.clear();
    ui->StudentNameBox->clear();

    QString StudentFilteringInformation = "SELECT Име FROM UserInformation WHERE Клас = 8  AND Клас_със_букви = ''";

    StudentFilteringInformation.replace(45,1,class_a);

    if(class_a.length() == 1)
    {
        StudentFilteringInformation.insert(70,class_word_a);
    }
    else
    {
        StudentFilteringInformation.insert(71,class_word_a);
    }

    if(newQuery.exec(StudentFilteringInformation))
    {
        while(newQuery.next())
        {
            StudentsList.append(newQuery.value(0).toStringList());
        }
    }
    else
    {
        QMessageBox::critical(this,"Грешка при изпълняване на заявка за запълване на списък с ученици","Моля проверете връзката с базата данни");
    }


    ui->StudentNameBox->addItems(StudentsList);
}




void ElectronicalDiary::on_ClassBox_currentTextChanged(const QString &arg1) // class
{


    FilterInformation(ui->ClassBox->currentText(), ui->ClassLBox->currentText());
    FilterStudentsForAppendingList(ui->ClassBox->currentText(), ui->ClassLBox->currentText());

}

void ElectronicalDiary::on_ClassLBox_currentTextChanged(const QString &arg1) // class with letters
{


    FilterInformation(ui->ClassBox->currentText(),ui->ClassLBox->currentText());
    FilterStudentsForAppendingList(ui->ClassBox->currentText(), ui->ClassLBox->currentText());

}

void ElectronicalDiary::on_StudentNameBox_currentTextChanged(const QString &arg1) // name of student
{

    ProxyModel->setFilterFixedString(ui->StudentNameBox->currentText());

}

void ElectronicalDiary::on_NameLine_textChanged(const QString &arg1) // check directly for student
{

   ProxyModel->setFilterFixedString(ui->NameLine->text());

}

void ElectronicalDiary::on_SubjectBox_currentTextChanged(const QString &arg1) // choose subject
{

    QString currentSubject = ui->SubjectBox->currentText();
    ListModel->setTable(currentSubject);
    ListModel->select();
    ui->tableView->setModel(ListModel);

    qDebug() << currentSubject;

}



void ElectronicalDiary::on_FiltrationToggle_clicked() // toggle the filtration mode -> on and off
{

    ListModel->submitAll();

    if (ui->FiltrationToggle->isChecked())
    {
        ui->tableView->setModel(ListModel);

        ListModel->setFilter(0);

         ui->ClassBox->setEnabled(false);
          ui->ClassLBox->setEnabled(false);
           ui->StudentNameBox->setEnabled(false);
            ui->SubjectBox->setEnabled(false);

             ui->NameFiltrationToggle->setEnabled(false);
             ui->NameLine->setEnabled(false);

             ui->NameFiltrationToggle->setChecked(false);
    }
    else
    {


         ui->ClassBox->setEnabled(true);
          ui->ClassLBox->setEnabled(true);
           ui->SubjectBox->setEnabled(true);

             ui->NameFiltrationToggle->setEnabled(true);


        FilterInformation(ui->ClassBox->currentText(), ui->ClassLBox->currentText());
        FilterStudentsForAppendingList(ui->ClassBox->currentText(), ui->ClassLBox->currentText());
    }
}

void ElectronicalDiary::on_NameFiltrationToggle_clicked() // use name filter via StudentNameBox
{

    ListModel->submitAll();

    if (ui->NameFiltrationToggle->isChecked())
    {
        ui->StudentNameBox->setEnabled(true);
        ui->NameLine->setEnabled(true);
        ui->tableView->setModel(ProxyModel);
        ProxyModel->setFilterFixedString(ui->StudentNameBox->currentText());
    }
    else
    {
        ui->StudentNameBox->setEnabled(false);
        ui->NameLine->setEnabled(false);
        ProxyModel->setFilterFixedString(0);
        ui->tableView->setModel(ListModel);

    }
}

void ElectronicalDiary::on_RefreshButton_clicked() // submit and refresh all the information in the table
{
    ListModel->submitAll();
}

