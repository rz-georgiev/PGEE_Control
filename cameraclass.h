#ifndef CAMERACLASS_H
#define CAMERACLASS_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimedia/QCamera>
#include <QGraphicsView>
#include <QtMultimediaWidgets/QCameraViewfinder>
#include <QtMultimediaWidgets/QGraphicsVideoItem>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimedia/QCameraImageCapture>
#include <QDebug>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QtMultimedia>

#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QCameraViewfinder>
#include <QtMultimediaWidgets/QCameraViewfinder>
#include <QTranslator>
#include <windows.h>
namespace Ui {
class CameraClass;
}

class CameraClass : public QDialog
{
    Q_OBJECT

public:
    explicit CameraClass(QWidget *parent = 0);
    ~CameraClass();


private slots:


    void on_ChooseDirectoryButton_clicked();

    void on_StartCameraButton_clicked();

    void on_TakeAPhotoButton_clicked();

private:
    Ui::CameraClass *ui;

    QCamera *camera;
     QCameraImageCapture *imageCapture;
      QCameraViewfinder *viewFinder;
       QString setDirectory;
        QString user_directory;
         QSound *Capture_Sound;

         void load_camera_main_settings();


};

#endif // CAMERACLASS_H
