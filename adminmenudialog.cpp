#include "adminmenudialog.h"
#include "ui_adminmenudialog.h"
#include "addeditdefectmenudialog.h"
#include "updateprioritydialog.h"
#include "addprojectdialog.h"
#include "updatestatusdialog.h"
#include "createreportdialog.h"
#include "addemployeedialog.h"
#include "assigndefectdialog.h"
#include "editdefectdialog.h"
#include "adddefectdialog.h"
#include "logindialog.h" // Assuming you have a LoginDialog

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

    // Connect logout button
    connect(ui->logoutButton, &QPushButton::clicked, this, &AdminMenuDialog::on_logoutButton_clicked);
}

AdminMenuDialog::~AdminMenuDialog()
{
    delete ui;
}

void AdminMenuDialog::on_addEditDefectButton_clicked()
{
    // Show Add/Edit Defect menu dialog
    AddEditDefectMenuDialog menuDialog;
    if (menuDialog.exec() == QDialog::Accepted) {
        if (menuDialog.isAddDefectSelected()) {
            // Show Add Defect dialog
            AddDefectDialog addDialog;
            addDialog.exec();
        } else {
            // Show Edit Defect dialog
            EditDefectDialog editDialog;
            editDialog.exec();
        }
    }
}

void AdminMenuDialog::on_addEditPriorityButton_clicked()
{
    // Show Add/Edit Priority of Defect dialog
    UpdatePriorityDialog priorityDialog;
    priorityDialog.exec();
}

void AdminMenuDialog::on_addProjectButton_clicked()
{
    // Show Add Project dialog
    AddProjectDialog projectDialog;
    projectDialog.exec();
}

void AdminMenuDialog::on_updateDefectStatusButton_clicked()
{
    // Show Update Status of Defect dialog
    UpdateStatusDialog statusDialog;
    statusDialog.exec();
}

void AdminMenuDialog::on_createReportButton_clicked()
{
    // Show Create Report for Defect Status dialog
    CreateReportDialog reportDialog;
    reportDialog.exec();
}

void AdminMenuDialog::on_addEditEmployeeButton_clicked()
{
    // Show Add/Edit Employee dialog
    AddEmployeeDialog employeeDialog;
    employeeDialog.exec();
}

void AdminMenuDialog::on_assignDefectButton_clicked()
{
    // Show Assign Defect dialog
    AssignDefectDialog assignDialog;
    assignDialog.exec();
}

void AdminMenuDialog::on_logoutButton_clicked()
{
    // Close the admin menu dialog
    close();

    // Show the login dialog
    LoginDialog loginDialog;
    loginDialog.exec();
}
