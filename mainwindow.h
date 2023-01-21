#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "student.h"
#include "students.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Students studenci;
    std::vector<student> dataBase;
    void showStudents(std::vector<student> db);
    void saveXML(void);
    void importXML(void);

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
