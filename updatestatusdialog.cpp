#include "updatestatusdialog.h"
#include "ui_updatestatusdialog.h"

UpdateStatusDialog::UpdateStatusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateStatusDialog)
{
    ui->setupUi(this);

    connect(ui->submitButton, &QPushButton::clicked, this, &UpdateStatusDialog::on_submitButton_clicked);
}

UpdateStatusDialog::~UpdateStatusDialog()
{
    delete ui;
}

void UpdateStatusDialog::populateDefectList(const QStringList &defectList)
{
    ui->defectListComboBox->clear();
    ui->defectListComboBox->addItems(defectList);
}

void UpdateStatusDialog::setCurrentStatus(const QString &status)
{
    int index = ui->statusComboBox->findText(status);
    if (index != -1)
        ui->statusComboBox->setCurrentIndex(index);
}

void UpdateStatusDialog::on_submitButton_clicked()
{
    QString defect = ui->defectListComboBox->currentText();
    QString status = ui->statusComboBox->currentText();

    emit statusUpdated(defect, status);

    accept(); // Close the dialog
}
