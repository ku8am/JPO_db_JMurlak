#ifndef STUDENT_H
#define STUDENT_H
#include <QString>

class student
{
    QString name;
    QString lastName;
    int indexNumber;
    QString faculty;
    QString field;
public:
    student(QString n, QString ln, QString fa, QString fi, int num);
    QString getName(void);
    QString getLastName(void);
    QString getField(void);
    QString getFaculty(void);
    int getIndexNumber(void);
};

#endif // STUDENT_H
