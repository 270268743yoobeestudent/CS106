#include "addeditprioritydialog.h"
#include "ui_addeditprioritydialog.h"
#include <QMessageBox>

AddEditPriorityDialog::AddEditPriorityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditPriorityDialog),
    changesSaved(false)
{
    ui->setupUi(this);
}

AddEditPriorityDialog::~AddEditPriorityDialog()
{
    delete ui;
}

void AddEditPriorityDialog::on_addButton_clicked()
{
    // Implement logic for adding priority
    changesSaved = true;
    accept(); // Close the dialog
}

void AddEditPriorityDialog::on_editButton_clicked()
{
    // Implement logic for editing priority
    changesSaved = true;
    accept(); // Close the dialog
}

void AddEditPriorityDialog::closeEvent(QCloseEvent *event)
{
    if (changesSaved) {
        event->accept(); // Accept the close event if changes were saved
    } else {
        event->accept(); // Accept the close event if no changes were made
    }
}
