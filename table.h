#ifndef TABLE_H
#define TABLE_H
#include <QDialog>
#include "student.h"
#include "students.h"
namespace Ui {
class Table;
}

class Table : public QDialog
{
    Q_OBJECT
public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();
    void TableDisp(std::vector<student> db);
private:
    Ui::Table *ui;
};

#endif // TABLE_H
