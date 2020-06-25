#ifndef FORPGEE_H
#define FORPGEE_H

#include <QDialog>

namespace Ui {
class ForPGEE;
}

class ForPGEE : public QDialog
{
    Q_OBJECT
    
public:
    explicit ForPGEE(QWidget *parent = 0);
    ~ForPGEE();
    
private slots:


private:
    Ui::ForPGEE *ui;

    void load_main_settings();
};

#endif // FORPGEE_H
