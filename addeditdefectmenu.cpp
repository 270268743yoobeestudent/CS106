#include "addeditdefectmenu.h"
#include "ui_addeditdefectmenu.h"

AddEditDefectMenu::AddEditDefectMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDefectMenu),
    addDefectSelected(false),
    editDefectSelected(false)
{
    ui->setupUi(this);

    connect(ui->addDefectButton, &QPushButton::clicked, this, &AddEditDefectMenu::on_addDefectButton_clicked);
    connect(ui->editDefectButton, &QPushButton::clicked, this, &AddEditDefectMenu::on_editDefectButton_clicked);
}

AddEditDefectMenu::~AddEditDefectMenu()
{
    delete ui;
}

bool AddEditDefectMenu::isAddDefectSelected() const
{
    return addDefectSelected;
}

bool AddEditDefectMenu::isEditDefectSelected() const
{
    return editDefectSelected;
}

void AddEditDefectMenu::on_addDefectButton_clicked()
{
    addDefectSelected = true;
    editDefectSelected = false;
    accept(); // Close the dialog and return QDialog::Accepted
}

void AddEditDefectMenu::on_editDefectButton_clicked()
{
    editDefectSelected = true;
    addDefectSelected = false;
    accept(); // Close the dialog and return QDialog::Accepted
}
