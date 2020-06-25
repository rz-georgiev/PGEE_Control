#include "electronicaldiary_write.h"
#include "ui_electronicaldiary_write.h"

Electronicaldiary_write::Electronicaldiary_write(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Electronicaldiary_write)
{
    ui->setupUi(this);

    load_main_settings();


}

Electronicaldiary_write::~Electronicaldiary_write()
{
    delete ui;
}


void Electronicaldiary_write::load_main_settings()
{
    this->setWindowTitle("Електронен дневник / Запис");
    this->setWindowIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));

    ListModel = new QSqlTableModel(this);
    ProxyModel = new QSortFilterProxyModel(this);

    ProxyModel->setSourceModel(ListModel);
    ProxyModel->setFilterFixedString(0);

    ui->tableView->setSortingEnabled(true);


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

    ListModel->setEditStrategy(QSqlTableModel::OnRowChange);

}

void Electronicaldiary_write::on_SubjectBox_currentTextChanged(const QString &arg1) // display all information from the database for selected subject
{
    QString currentSubject = ui->SubjectBox->currentText();
    ListModel->setTable(currentSubject + "1");
    ListModel->select();
    ui->tableView->setModel(ListModel);

    qDebug() << currentSubject + "1";
}

void Electronicaldiary_write::on_IDEdit_textChanged(const QString &arg1) // filter via number, to find some student, through ID
{
    if(ui->IDEdit->text().isEmpty())
    {
        qDebug() << "Empty";
        ProxyModel->setFilterFixedString(0);
        ui->tableView->setModel(ListModel);
    }
    else
    {
        ui->tableView->setModel(ProxyModel);
        ProxyModel->setFilterKeyColumn(0);
        ProxyModel->setFilterFixedString(ui->IDEdit->text());
        qDebug() << "Full";
    }
}

