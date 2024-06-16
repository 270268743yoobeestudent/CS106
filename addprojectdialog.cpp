#include "AddProjectDialog.h"
#include "ui_AddProjectDialog.h"

AddProjectDialog::AddProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProjectDialog)
{
    ui->setupUi(this);
}

AddProjectDialog::~AddProjectDialog()
{
    delete ui;
}
