#include "employeemenudialog.h"
#include "ui_employeemenudialog.h"
#include "editdefectdialog.h"
#include "updatestatusdialog.h"
#include "adddefectdialog.h"
#include "updateprioritydialog.h" // Include the header file for AddEditPriorityDialog

EmployeeMenuDialog::EmployeeMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeMenuDialog),
    addEditDefectMenu(new AddEditDefectMenuDialog(this))
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->addEditDefectButton, &QPushButton::clicked, this, &EmployeeMenuDialog::on_addEditDefectButton_clicked);
    connect(ui->addEditPriorityButton, &QPushButton::clicked, this, &EmployeeMenuDialog::on_addEditPriorityButton_clicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &EmployeeMenuDialog::on_logoutButton_clicked);
}

EmployeeMenuDialog::~EmployeeMenuDialog()
{
    delete ui;
    delete addEditDefectMenu;
}

void EmployeeMenuDialog::on_addEditDefectButton_clicked()
{
    // Show AddEditDefectMenu and handle its result
    if (addEditDefectMenu->exec() == QDialog::Accepted) {
        if (addEditDefectMenu->isAddDefectSelected()) {
            AddDefectDialog addDialog;
            addDialog.exec();
        } else if (addEditDefectMenu->isEditDefectSelected()) {
            EditDefectDialog editDialog;
            editDialog.exec();
        }
    }
}

void EmployeeMenuDialog::on_addEditPriorityButton_clicked()
{
    // Show Add/Edit Priority dialog
    UpdatePriorityDialog priorityDialog;
    priorityDialog.exec();
}

void EmployeeMenuDialog::on_logoutButton_clicked()
{
    // Emit the signal to request logout
    emit logoutRequested();
}
