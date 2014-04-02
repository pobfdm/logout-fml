#include "manageclients.h"
#include "ui_manageclients.h"

ManageClients::ManageClients(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageClients)
{
    ui->setupUi(this);
}

ManageClients::~ManageClients()
{
    delete ui;
}
