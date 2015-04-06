#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

extern void heartProgram(std::string);
extern std::string value;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::string str = ui->lineEdit->text().toStdString();
    ui->lineEdit->clear();
    heartProgram(str);                        /* Heart of the Program */
    ui->plainTextEdit->clear();               /* Plain text */
    ui->plainTextEdit->appendPlainText(tr(value.c_str()));
}
