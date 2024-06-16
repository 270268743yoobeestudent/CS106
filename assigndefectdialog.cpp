#include "AssignDefectDialog.h"
#include "ui_AssignDefectDialog.h"
#include <QMessageBox> // Include for QMessageBox if needed

AssignDefectDialog::AssignDefectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AssignDefectDialog)
{
    ui->setupUi(this);

    // Populate defect list combo box (simulate data)
    ui->defectListComboBox->addItem("Defect 1");
    ui->defectListComboBox->addItem("Defect 2");
    ui->defectListComboBox->addItem("Defect 3");

    // Populate employee list combo box (simulate data)
    ui->employeeListComboBox->addItem("Employee 1");
    ui->employeeListComboBox->addItem("Employee 2");
    ui->employeeListComboBox->addItem("Employee 3");

    // Connect submit button click to onSubmit slot
    connect(ui->submitButton, &QPushButton::clicked, this, &AssignDefectDialog::onSubmit);
}

AssignDefectDialog::~AssignDefectDialog()
{
    delete ui;
}

void AssignDefectDialog::onSubmit()
{
    QString defect = ui->defectListComboBox->currentText();
    QString employee = ui->employeeListComboBox->currentText();

    // Here you would assign the selected defect to the selected employee in your system
    // Example: emit a signal to assign 'defect' to 'employee'
    // You need to implement the actual logic to assign a defect to an employee

    // For demonstration, show a message box (remove in actual implementation)
    QMessageBox::information(this, "Defect Assigned", QString("Assigned defect '%1' to employee '%2'.").arg(defect, employee));

    // Close the dialog after assigning defect
    accept(); // This closes the dialog and returns QDialog::Accepted
}
