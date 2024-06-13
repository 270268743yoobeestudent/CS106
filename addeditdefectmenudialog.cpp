#include "addeditdefectmenudialog.h"
#include "ui_addeditdefectmenudialog.h"

AddEditDefectMenuDialog::AddEditDefectMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDefectMenuDialog)
{
    ui->setupUi(this);

    connect(ui->addDefectButton, &QPushButton::clicked, this, &AddEditDefectMenuDialog::on_addDefectButton_clicked);
    connect(ui->editDefectButton, &QPushButton::clicked, this, &AddEditDefectMenuDialog::on_editDefectButton_clicked);
}

AddEditDefectMenuDialog::~AddEditDefectMenuDialog()
{
    delete ui;
}

void AddEditDefectMenuDialog::on_addDefectButton_clicked()
{
    emit addDefectRequested();
}

void AddEditDefectMenuDialog::on_editDefectButton_clicked()
{
    emit editDefectRequested();
}
