#include "table.h"
#include "ui_table.h"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "mainwindow.h"
#include"QHeaderView"

Table::Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
}

Table::~Table()
{
    delete ui;
}

void Table::TableDisp(std::vector<student> db)
{
    QTableWidget *table= new QTableWidget(this);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setFixedSize(QSize(680,300));

    //table properties
    table->setShowGrid(true);
    table->setGridStyle(Qt::DotLine);
    table->setSortingEnabled(true);
    table->setCornerButtonEnabled(true);
    table->setRowCount((int)db.size());
    table->setColumnCount(5);

    QStringList hLabels;
    hLabels <<"Index" <<"Surename"<<"Name"<<"Field"<<"Faculty";
    table->setHorizontalHeaderLabels(hLabels);
    QTableWidgetItem *item;

    for(int i=0; i<(int)db.size(); ++i)
    {
        for(int j =0; j<5; j++)
        {
            item = new QTableWidgetItem;
            if(j==0)
                item->setText(QString::number(db[i].getIndexNumber()));
            if(j==1)
                item->setText(db[i].getLastName());
            if(j==2)
                item->setText(db[i].getName());
            if(j==3)
                item->setText(db[i].getField());
            if(j==4)
                item->setText(db[i].getFaculty());
            table->setItem(i,j,item);
        }
    }
}

//todo:
//sciezka
//na gita
