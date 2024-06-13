#include "createreportdialog.h"
#include "ui_createreportdialog.h"

CreateReportDialog::CreateReportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateReportDialog)
{
    ui->setupUi(this);

    connect(ui->generateReportButton, &QPushButton::clicked, this, &CreateReportDialog::on_generateReportButton_clicked);
}

CreateReportDialog::~CreateReportDialog()
{
    delete ui;
}

void CreateReportDialog::populateDefectList(const QStringList &defectList)
{
    ui->defectListComboBox->clear();
    ui->defectListComboBox->addItems(defectList);
}

void CreateReportDialog::on_generateReportButton_clicked()
{
    QString selectedDefect = ui->defectListComboBox->currentText();
    emit reportRequested(selectedDefect);
    accept(); // Close the dialog
}
