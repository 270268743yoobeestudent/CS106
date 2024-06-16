#include "EditDefectDialog.h"
#include "ui_EditDefectDialog.h"

EditDefectDialog::EditDefectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDefectDialog)
{
    ui->setupUi(this);
    connect(ui->submitButton, &QPushButton::clicked, this, &EditDefectDialog::onSubmit);
}

EditDefectDialog::~EditDefectDialog()
{
    delete ui;
}

void EditDefectDialog::onSubmit()
{
    QString selectedDefect = ui->defectListComboBox->currentText();
    QString defectName = ui->defectNameLineEdit->text();

    // Retrieve the selected defect and update its details in your data structure or database

    accept(); // Close the dialog
}
