#include "AddDefectDialog.h"
#include "ui_AddDefectDialog.h"

AddDefectDialog::AddDefectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDefectDialog)
{
    ui->setupUi(this);
    connect(ui->submitButton, &QPushButton::clicked, this, &AddDefectDialog::onSubmit);
}

AddDefectDialog::~AddDefectDialog()
{
    delete ui;
}

void AddDefectDialog::onSubmit()
{
    QString defectName = ui->defectNameLineEdit->text();
    QString defectDescription = ui->defectDescriptionTextEdit->toPlainText();

    // Handle submission of defect details here (e.g., store in database, update model, etc.)

    accept(); // Close the dialog
}
