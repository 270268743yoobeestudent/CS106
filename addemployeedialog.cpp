#include "AddEmployeeDialog.h"
#include "ui_AddEmployeeDialog.h"
#include <QMessageBox> // Include for QMessageBox if needed

AddEmployeeDialog::AddEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmployeeDialog)
{
    ui->setupUi(this);

    // Connect submit button click to onSubmit slot
    connect(ui->submitButton, &QPushButton::clicked, this, &AddEmployeeDialog::onSubmit);
}

AddEmployeeDialog::~AddEmployeeDialog()
{
    delete ui;
}

void AddEmployeeDialog::onSubmit()
{
    QString employeeName = ui->employeeNameLineEdit->text();

    // Here you would add the employee to your system
    // Example: emit a signal to add 'employeeName' to your employee list
    // You need to implement the actual logic to add an employee in your system

    // For demonstration, show a message box (remove in actual implementation)
    QMessageBox::information(this, "Employee Added", QString("Employee %1 added.").arg(employeeName));

    // Close the dialog after adding employee
    accept(); // This closes the dialog and returns QDialog::Accepted
}
