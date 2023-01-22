#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "student.h"
#include "students.h"
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <table.h>
#include <QFileDialog>
#include <QFile>
#include <QDomDocument>
#include <QDebug>

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

void MainWindow::saveXML(QDomDocument qdoc, QString xml_filter)
{
    studenci.writee(dataBase,qdoc);
    QString filename = QFileDialog::getOpenFileName(this,tr("Open file"),"C:/",xml_filter,&xml_filter,QFileDialog::DontUseNativeDialog);
    if(filename.isEmpty())
    {
        QMessageBox::information(this,tr("Error"),tr("You dont select the file"));
    }

    QFile xml_file(filename);


    if(xml_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&xml_file);
        stream << qdoc.toString();
        xml_file.close();
        QMessageBox::information(this,tr("Success"),tr("You saved the file "));

    }

    else
    {
    QMessageBox::information(this,tr("Error"),tr("Failed to open file"));
    }
}

void MainWindow::importXML(QDomDocument studentsFromXML, QString xml_filter)
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open file"),"C:/",xml_filter,&xml_filter,QFileDialog::DontUseNativeDialog);
    QFile xml_file(filename);

    if(filename.isEmpty())
    {
        QMessageBox::information(this,tr("Error"),tr("You dont selected the file"));
    }
    else
    {
        if (xml_file.open(QIODevice::ReadOnly))
        {
            studentsFromXML.setContent(&xml_file);
            xml_file.close();
            studenci.readd(dataBase,studentsFromXML);
            QMessageBox::information(this,tr("Success"),tr("You imported the file correctly"));
           }
        else
        {
            QMessageBox::information(this,tr("Error"),tr("Failed to open file"));
        }
    }
}

void MainWindow::on_pushButton_dodaj_clicked()
{
    bool x = studenci.addStudent(dataBase,ui->lineEdit_Name->text(),ui->lineEdit_lName->text(),ui->lineEdit_field->text(), ui->lineEdit_faculty->text(),ui->spinBox_Index->value());
    if(x)
    QMessageBox::information(this,tr("Success"),tr("You added a student"));
    else
    QMessageBox::information(this,tr("Success"),tr("You dont added a student, try again"));
}

void MainWindow::on_pushButton_usun_clicked()
{
    studenci.removeStudent(dataBase,ui->spinBox_Index->value());
    QMessageBox::information(this,tr("Success"),tr("you removed a student"));
}

void MainWindow::on_pushButton_wyswietl_clicked()
{
    Table tb(this);
    tb.setWindowTitle("Database");
    tb.TableDisp(dataBase);
    tb.exec();
}

void MainWindow::on_pushButton_sortuj_clicked()
{
    Table tc(this);
    tc.setWindowTitle("Found");
    tc.TableDisp(studenci.findStudent(dataBase, ui->spinBox_Index->value()));
    tc.exec();
}

void MainWindow::on_pushButton_import_clicked()
{
    importXML(doc, xml_type);
}
void MainWindow::on_pushButton_save_clicked()
{
    saveXML(doc, xml_type);
}

