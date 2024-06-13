#include "adddefectdialog.h"
#include "ui_adddefectdialog.h"

AddDefectDialog::AddDefectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDefectDialog)
{
    ui->setupUi(this);

    connect(ui->submitButton, &QPushButton::clicked, this, &AddDefectDialog::on_submitButton_clicked);
}

AddDefectDialog::~AddDefectDialog()
{
    delete ui;
}

void AddDefectDialog::on_submitButton_clicked()
{
    QString defectName = ui->defectNameLineEdit->text().trimmed();
    QString defectDescription = ui->defectDescriptionTextEdit->toPlainText().trimmed();

    // Emit signal with defect details
    emit defectAdded(defectName, defectDescription);

    // Close the dialog
    accept(); // Accept the dialog (return QDialog::Accepted)
}
