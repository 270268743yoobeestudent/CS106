#include "EmployeeMenuDialog.h"
#include "ui_EmployeeMenuDialog.h"
#include "addeditdefectmenudialog.h"
#include "addeditprioritydialog.h"
#include "loginDialog.h" // Assuming this is your LoginDialog header

EmployeeMenuDialog::EmployeeMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeMenuDialog),
    loginDialog(new LoginDialog(this)) // Initialize LoginDialog with parent
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
}

void EmployeeMenuDialog::on_addEditDefectButton_clicked()
{
    // Show Add/Edit Defect dialog
    AddEditDefectMenuDialog addEditDefectMenuDialog;
    addEditDefectMenuDialog.exec();
}

void EmployeeMenuDialog::on_addEditPriorityButton_clicked()
{
    // Show Add/Edit Priority dialog
    AddEditPriorityDialog addEditPriorityDialog;
    addEditPriorityDialog.exec();
}

void EmployeeMenuDialog::on_logoutButton_clicked()
{
    // Handle logout functionality here
    close();  // Close the employee menu dialog

    // Show the login dialog
    loginDialog->exec();
}
