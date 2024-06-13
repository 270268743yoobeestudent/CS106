#include "employeemenudialog.h"
#include "ui_employeemenudialog.h"
#include "editdefectdialog.h"
#include "updatestatusdialog.h"
#include "adddefectdialog.h"

EmployeeMenuDialog::EmployeeMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeMenuDialog)
{
    ui->setupUi(this);

    // Initialize AddEditDefectMenu
    addEditDefectMenu = new AddEditDefectMenu(this);

    // Connect buttons to their respective slots
    connect(ui->addEditDefectButton, &QPushButton::clicked, this, &EmployeeMenuDialog::on_addEditDefectButton_clicked);
    connect(ui->addEditPriorityButton, &QPushButton::clicked, this, &EmployeeMenuDialog::on_addEditPriorityButton_clicked);
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
    AddEditPriorityDialog priorityDialog;
    priorityDialog.exec();
}
