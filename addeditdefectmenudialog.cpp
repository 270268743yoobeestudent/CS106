#include "addeditdefectmenudialog.h"
#include "ui_addeditdefectmenudialog.h"

AddEditDefectMenuDialog::AddEditDefectMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDefectMenuDialog),
    addDefectSelected(false)
{
    ui->setupUi(this);

    connect(ui->addDefectButton, &QPushButton::clicked, this, &AddEditDefectMenuDialog::on_addDefectButton_clicked);
    connect(ui->editDefectButton, &QPushButton::clicked, this, &AddEditDefectMenuDialog::on_editDefectButton_clicked);
}

AddEditDefectMenuDialog::~AddEditDefectMenuDialog()
{
    delete ui;
}

bool AddEditDefectMenuDialog::isAddDefectSelected() const
{
    return addDefectSelected;
}

bool AddEditDefectMenuDialog::isEditDefectSelected() const
{
    return !addDefectSelected;
}

void AddEditDefectMenuDialog::on_addDefectButton_clicked()
{
    addDefectSelected = true;
    accept(); // Accept the dialog to return QDialog::Accepted
}

void AddEditDefectMenuDialog::on_editDefectButton_clicked()
{
    addDefectSelected = false;
    accept(); // Accept the dialog to return QDialog::Accepted
}
