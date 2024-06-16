#include "CreateReportDialog.h"
#include "ui_CreateReportDialog.h"
#include <QMessageBox> // Include for QMessageBox if needed

CreateReportDialog::CreateReportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateReportDialog)
{
    ui->setupUi(this);

    // Connect the generate report button click to the onGenerateReport slot
    connect(ui->generateReportButton, &QPushButton::clicked, this, &CreateReportDialog::onGenerateReport);

    // Populate defect list combo box (simulate data)
    ui->defectListComboBox->addItem("Defect 1");
    ui->defectListComboBox->addItem("Defect 2");
    ui->defectListComboBox->addItem("Defect 3");
}

CreateReportDialog::~CreateReportDialog()
{
    delete ui;
}

void CreateReportDialog::onGenerateReport()
{
    QString selectedDefect = ui->defectListComboBox->currentText();

    // Here you would generate a report for 'selectedDefect'
    // Example: emit a signal to request report generation based on selected defect
    // You need to implement the actual logic to generate the report in your system

    // For demonstration, show a message box with a report (remove in actual implementation)
    QString reportMessage = QString("Report for %1:\n\nStatus: Open\nPriority: High\nDescription: Sample description.").arg(selectedDefect);
    QMessageBox::information(this, "Generated Report", reportMessage);

    // Close the dialog after generating report
    accept(); // This closes the dialog and returns QDialog::Accepted
}
