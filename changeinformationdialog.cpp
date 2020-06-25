#include "changeinformationdialog.h"
#include "ui_changeinformationdialog.h"

ChangeInformationDialog::ChangeInformationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeInformationDialog)
{
    ui->setupUi(this);


    load_main_settings();

}

ChangeInformationDialog::~ChangeInformationDialog()
{
    delete ui;
}

void ChangeInformationDialog::on_Add1_clicked() // add, edit or delete information for the teachers
{
    QSqlQuery newQuery;
    newQuery.prepare("INSERT INTO Учители VALUES (:ClassTeacher);");

    QString newClassTeacher = QInputDialog::getText(this,"Име на класен ръководител", "Име на новия класен ръководител:");

    newQuery.bindValue(":ClassTeacher",newClassTeacher);

    if(newQuery.exec())
    {
        QMessageBox::information(this, "Успех", "Новият учител, бе записан успешно");
    }

    ClassTeacherModel->select();
}

void ChangeInformationDialog::on_Add2_clicked() // add, edit or delete information for the subjects
{
    QSqlQuery newQuery;
    newQuery.prepare("INSERT INTO Учебни_предмети VALUES (:Subject);");

    QString newSubject = QInputDialog::getText(this,"Име на предмет", "Име на новия предмет:");

    newQuery.bindValue(":Subject",newSubject);

    if(newQuery.exec())
    {
        QMessageBox::information(this, "Успех", "Новият учебен предмет, бе записан успешно");
    }

    SubjectModel->select();
}

void ChangeInformationDialog::on_Add3_clicked() // add, edit or delete information for the specialities
{

    QSqlQuery newQuery;
    newQuery.prepare("INSERT INTO Специалности VALUES (:Speciality);");

    QString newSpecialty = QInputDialog::getText(this,"Име на специалност", "Име на новата специалност:");

    newQuery.bindValue(":Speciality",newSpecialty);

    if(newQuery.exec())
    {
        QMessageBox::information(this, "Успех", "Новата специалност, бе записана успешно");
    }

    SpecialityModel->select();
}

void ChangeInformationDialog::on_Delete1_clicked() // delete current row for teacher
{
    ClassTeacherModel->removeRows(ui->tableView->currentIndex().row(),1);
    ClassTeacherModel->submitAll();
    ClassTeacherModel->select();
}

void ChangeInformationDialog::on_Delete2_clicked() // delete current row for subject
{
    SubjectModel->removeRows(ui->tableView_2->currentIndex().row(),1);
    SubjectModel->submitAll();
    SubjectModel->select();
}

void ChangeInformationDialog::on_Delete3_clicked() // delete current row for speciality
{
        SpecialityModel->removeRows(ui->tableView_3->currentIndex().row(),1);
        SpecialityModel->submitAll();
        SpecialityModel->select();
}

void ChangeInformationDialog::load_main_settings()
{
    this->setFixedSize(this->width(),this->height());
    this->setWindowTitle("Промени информация за регистрационната форма");
    this->setWindowIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));

    ui->tabWidget->setTabText(0,"Учители");
        ui->tabWidget->setTabText(1,"Учебни_предмети");
            ui->tabWidget->setTabText(2,"Специалности");

    ClassTeacherModel = new QSqlTableModel(this);
     SubjectModel = new QSqlTableModel(this);
      SpecialityModel = new QSqlTableModel(this);

        ClassTeacherModel->setEditStrategy(QSqlTableModel::OnRowChange);
         SubjectModel->setEditStrategy(QSqlTableModel::OnRowChange);
          SpecialityModel->setEditStrategy(QSqlTableModel::OnRowChange);


      ClassTeacherModel->setTable("Учители");
       SubjectModel->setTable("Учебни_предмети");
        SpecialityModel->setTable("Специалности");



       ClassTeacherModel->select();
        SubjectModel->select();
         SpecialityModel->select();

         ui->tableView->setSortingEnabled(true);
          ui->tableView_2->setSortingEnabled(true);
           ui->tableView_3->setSortingEnabled(true);


      ui->tableView->setModel(ClassTeacherModel);
       ui->tableView_2->setModel(SubjectModel);
        ui->tableView_3->setModel(SpecialityModel);

        ui->tableView->setColumnWidth(0,370);

         ui->tableView_2->setColumnWidth(0,370);

          ui->tableView_3->setColumnWidth(0,370);
}

