#include "students.h"

Students::Students(){}

bool Students::addStudent(std::vector<student> &db, QString nname, QString lname, QString faculty, QString field, int inumber)
{   if(inumber>0)
    {
        db.push_back(student(nname,lname,faculty, field,inumber ));
        return true;
    }
    else
        return false;
}


void Students::removeStudent(std::vector<student >& db, int inumber)
{
    for(int i=0; i<(int)db.size(); ++i){
        if(db[i].getIndexNumber()==inumber)
            db.erase(db.begin()+i);
    }

}

std::vector<student> Students::findStudent(std::vector<student> db, int index)
{
    std::vector<student> tempVect;
        for(int i=0; i<(int)db.size();i++ )
        {
            if(db[i].getIndexNumber() == index)
            {
                tempVect.push_back(db[i]);
                return tempVect;
            }
        }
}

void Students::readd(std::vector<student> &db,QDomDocument qdoc)
{
    QDomElement root = qdoc.documentElement();
    QDomElement node = root.firstChild().toElement();

    while(node.isNull() == false)
       {
               while(!node.isNull()){
                   addStudent(db,node.attribute("Name","Name")
                                ,node.attribute("LastName","LastName")
                                ,node.attribute("Faculty","Faculty")
                                ,node.attribute("Field","Field")
                                ,node.attribute("Index","0000").toInt());
                   node = node.nextSibling().toElement();
               }
           }
    node = node.nextSibling().toElement();
}

void Students::writee(std::vector<student> &db, QDomDocument &qdoc)
{
    QDomElement root = qdoc.createElement("Students");
    qdoc.appendChild(root);

    for(int i = 0; i < (int)db.size(); i++)
    {
        QDomElement student = qdoc.createElement("Student");
        student.setAttribute("Name", db[i].getName());
        student.setAttribute("LastName", db[i].getLastName());
        student.setAttribute("Field", db[i].getField());
        student.setAttribute("Faculty", db[i].getFaculty());
        student.setAttribute("Index", db[i].getIndexNumber());
        root.appendChild(student);
    }
}








