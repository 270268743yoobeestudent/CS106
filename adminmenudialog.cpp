#include "adminmenudialog.h"
#include "adddefectdialog.h"
#include "ui_adminmenudialog.h"
#include "addeditdefectmenu.h"
#include "addeditprioritydialog.h"
#include "addprojectdialog.h"
#include "updatestatusdialog.h"
#include "createreportdialog.h"
#include "addemployeedialog.h"
#include "assigndefectdialog.h"
#include "editdefectdialog.h" // Include EditDefectDialog header
#include <QMessageBox>

AdminMenuDialog::AdminMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminMenuDialog)
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->addEditDefectButton, &QPushButton::clicked, this, &AdminMenuDialog::on_addEditDefectButton_clicked);
    connect(ui->addEditPriorityButton, &QPushButton::clicked, this, &AdminMenuDialog::on_addEditPriorityButton_clicked);
    connect(ui->addProjectButton, &QPushButton::clicked, this, &AdminMenuDialog::on_addProjectButton_clicked);
    connect(ui->updateDefectStatusButton, &QPushButton::clicked, this, &AdminMenuDialog::on_updateDefectStatusButton_clicked);
    connect(ui->createReportButton, &QPushButton::clicked, this, &AdminMenuDialog::on_createReportButton_clicked);
    connect(ui->addEditEmployeeButton, &QPushButton::clicked, this, &AdminMenuDialog::on_addEditEmployeeButton_clicked);
    connect(ui->assignDefectButton, &QPushButton::clicked, this, &AdminMenuDialog::on_assignDefectButton_clicked);
}

AdminMenuDialog::~AdminMenuDialog()
{
    delete ui;
}

void AdminMenuDialog::on_addEditDefectButton_clicked()
{
    // Example: Show Add/Edit Defect menu dialog
    AddEditDefectMenu menuDialog;
    if (menuDialog.exec() == QDialog::Accepted) {
        if (menuDialog.isAddDefectSelected()) {
            // Show Add Defect dialog
            AddDefectDialog addDialog;
            addDialog.exec();
        } else if (menuDialog.isEditDefectSelected()) {
            // Show Edit Defect dialog
            EditDefectDialog editDialog;
            editDialog.exec();
        }
    }
}

void AdminMenuDialog::on_addEditPriorityButton_clicked()
{
    // Example: Show Add/Edit Priority of Defect dialog
    AddEditPriorityDialog priorityDialog;
    priorityDialog.exec();
}

void AdminMenuDialog::on_addProjectButton_clicked()
{
    // Example: Show Add Project dialog
    AddProjectDialog projectDialog;
    projectDialog.exec();
}

void AdminMenuDialog::on_updateDefectStatusButton_clicked()
{
    // Example: Show Update Status of Defect dialog
    UpdateStatusDialog statusDialog;
    statusDialog.exec();
}

void AdminMenuDialog::on_createReportButton_clicked()
{
    // Example: Show Create Report for Defect Status dialog
    CreateReportDialog reportDialog;
    reportDialog.exec();
}

void AdminMenuDialog::on_addEditEmployeeButton_clicked()
{
    // Example: Show Add/Edit Employee dialog
    AddEmployeeDialog employeeDialog;
    employeeDialog.exec();
}

void AdminMenuDialog::on_assignDefectButton_clicked()
{
    // Example: Show Assign Defect dialog
    AssignDefectDialog assignDialog;
    assignDialog.exec();
}
