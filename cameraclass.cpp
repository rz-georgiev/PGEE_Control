#include "cameraclass.h"
#include "ui_cameraclass.h"

CameraClass::CameraClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraClass)
{
    ui->setupUi(this);



    load_camera_main_settings();



}

CameraClass::~CameraClass()  //stop the camera and close the view finder then destroy CameraClass object
{
    delete ui;
    camera->stop();
    viewFinder->close();

}

void CameraClass::on_ChooseDirectoryButton_clicked() // set directory where to save the image
{
    setDirectory = QFileDialog::getExistingDirectory(this,"Изберете директория");
    ui->lineEdit->setText(setDirectory);
}

void CameraClass::on_StartCameraButton_clicked() //start camera and search for object to capture
{



    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()){

        QMessageBox::critical(this,"Грешка","Моля задайте директория и име на снимката!");

        return;

    }
    else{
        ui->StartCameraButton->setEnabled(false);
        camera->setViewfinder(viewFinder);
        viewFinder->show();
        camera->start();

        ui->TakeAPhotoButton->setVisible(true);
    }
}

void CameraClass::on_TakeAPhotoButton_clicked() // capture image and save it to the given directory
{

    Capture_Sound->play();

    imageCapture->capture(setDirectory + "/" + ui->lineEdit_2->text() + ".jpg");
    user_directory = setDirectory;
    QMessageBox::information(this,"Ок","Снимката бе запаметена успешно");

      viewFinder->close();

       camera->unlock();
        camera->stop();

         ui->TakeAPhotoButton->setVisible(false);
          ui->StartCameraButton->setEnabled(true);



}

void CameraClass::load_camera_main_settings() //load camera main settings
{
    camera = new QCamera(this);
    imageCapture = new QCameraImageCapture(camera,this);
    viewFinder = new QCameraViewfinder(this);
    Capture_Sound = new QSound(":/sounds/MainResources/camera-shutter-click-01.wav",this);
    this->setWindowIcon(QIcon(QPixmap(":/Icons/MainResources/PGEE_Control_Version.png")));

    camera->setCaptureMode(QCamera::CaptureStillImage);
    viewFinder->setGeometry(20,170,250,210);

    ui->lineEdit->setReadOnly(true);
    ui->TakeAPhotoButton->setVisible(false);


    ui->ChooseDirectoryButton->setToolTip("<b><i><font color = 'green'>Задаване на директория</font></i></b>");
    ui->StartCameraButton->setToolTip("<b><i><font color = 'blue'>Стартиране на камера</font></i></b>");
    ui->TakeAPhotoButton->setToolTip("<b><i><font color = 'red'>Снимане</font></i></b>");
    ui->lineEdit->setReadOnly(true);
    ui->TakeAPhotoButton->setVisible(false);

    this->setWindowTitle("Режим на снимане");
    this->setFixedSize(this->width(),this->height());

}
