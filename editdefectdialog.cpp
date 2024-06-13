#include "editdefectdialog.h"
#include "ui_editdefectdialog.h"

EditDefectDialog::EditDefectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDefectDialog)
{
    ui->setupUi(this);

    connect(ui->submitButton, &QPushButton::clicked, this, &EditDefectDialog::on_submitButton_clicked);
}

EditDefectDialog::~EditDefectDialog()
{
    delete ui;
}

void EditDefectDialog::populateDefectList(const QStringList &defectList)
{
    ui->defectListComboBox->clear();
    ui->defectListComboBox->addItems(defectList);
}

void EditDefectDialog::setDefectDetails(const QString &defectName, const QString &defectDescription)
{
    ui->defectNameLineEdit->setText(defectName);
    ui->defectDescriptionTextEdit->setText(defectDescription);
}

void EditDefectDialog::on_submitButton_clicked()
{
    int defectIndex = ui->defectListComboBox->currentIndex();
    QString defectName = ui->defectNameLineEdit->text().trimmed();
    QString defectDescription = ui->defectDescriptionTextEdit->toPlainText().trimmed();

    // Emit signal with edited defect details
    emit defectEdited(defectIndex, defectName, defectDescription);

    // Close the dialog
    accept(); // Accept the dialog (return QDialog::Accepted)
}
