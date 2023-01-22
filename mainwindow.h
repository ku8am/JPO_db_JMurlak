#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "student.h"
#include "students.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <table.h>
#include <QFileDialog>
#include <QFile>
#include <QDomDocument>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Students manageStudents;
    std::vector<student> dataBase;
    void saveXML(QDomDocument qdoc, QString xml_filter);
    void importXML(QDomDocument qdoc, QString xml_filter);
    QDomDocument doc;
    QString xml_type = "XML files (*.xml)";





private slots:

    void on_pushButton_dodaj_clicked();

    void on_pushButton_usun_clicked();

    void on_pushButton_wyswietl_clicked();

    void on_pushButton_sortuj_clicked();

    void on_pushButton_import_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
