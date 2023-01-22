#ifndef STUDENTS_H
#define STUDENTS_H
#include <vector>
#include "student.h"
#include <QFileDialog>
#include <QFile>
#include <QDomDocument>

class Students
{
public:
    Students();
    //funkcja przyjmująca
    bool addStudent(std::vector<student>& db, QString nname, QString lname, QString faculty, QString field, int inumber );
    void removeStudent(std::vector<student>& db, int inumber);
    std::vector<student> findStudent(std::vector<student> db, int index);
    void readXML (std::vector<student>& db, QDomDocument qdoc);
    void writeXML (std::vector<student>& db, QDomDocument &qdoc);
private:
};

#endif // STUDENTS_H
