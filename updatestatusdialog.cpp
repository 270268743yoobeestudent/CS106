#include "UpdateStatusDialog.h"
#include "ui_UpdateStatusDialog.h"
#include <QMessageBox> // Include for QMessageBox if needed

UpdateStatusDialog::UpdateStatusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateStatusDialog)
{
    ui->setupUi(this);

    // Connect the submit button click to the onSubmit slot
    connect(ui->submitButton, &QPushButton::clicked, this, &UpdateStatusDialog::onSubmit);

    // Populate defect list and status combo box (simulate data)
    ui->defectListComboBox->addItem("Defect 1");
    ui->defectListComboBox->addItem("Defect 2");
    ui->defectListComboBox->addItem("Defect 3");
}

UpdateStatusDialog::~UpdateStatusDialog()
{
    delete ui;
}

void UpdateStatusDialog::onSubmit()
{
    QString selectedDefect = ui->defectListComboBox->currentText();
    QString selectedStatus = ui->statusComboBox->currentText();

    // Here you would update the status of 'selectedDefect' to 'selectedStatus'
    // Example: emit a signal to notify the main application of the status update
    // You need to implement the actual logic to update the status in your system

    // For demonstration, show a message box indicating success (remove in actual implementation)
    QMessageBox::information(this, "Status Updated", "Status of defect updated successfully.");

    // Close the dialog after updating
    accept(); // This closes the dialog and returns QDialog::Accepted
}
