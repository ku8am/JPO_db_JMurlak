#include "student.h"


student::student(QString n, QString ln, QString fa, QString fi, int num)
{
    name=n;
    lastName=ln;
    indexNumber=num;
    faculty=fa;
    field=fi;

}

QString student::getName(){return name;}

QString student::getLastName(){return lastName;}

QString student::getField(){return field;}

QString student::getFaculty(){return faculty;}

int student::getIndexNumber(){return indexNumber;}
