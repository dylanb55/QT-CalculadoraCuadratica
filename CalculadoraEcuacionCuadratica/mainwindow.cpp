#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    float a,b,c;
    float x1,x2;

    a = ui->leer_a->text().toFloat();
    b = ui->leer_b->text().toFloat();
    c = ui->leer_c->text().toFloat();

    x1 = ((-b)+(sqrt(pow(b,2)-4*a*c)))/(2*a);
    x2 = ((-b)-(sqrt(pow(b,2)-4*a*c)))/(2*a);

    if(std::isnan(x1) == 1 || std::isnan(x2)){
        QMessageBox::warning(this,"Informacion", "Soluciones imaginarias");
    }

    else{
        ui->resultado_x1->setText(QString::number(x1,'p',3));
        ui->resultado_x2->setText(QString::number(x2,'p',3));
    }

}

