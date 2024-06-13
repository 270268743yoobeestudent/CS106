#include "assigndefectdialog.h"
#include "ui_assigndefectdialog.h"

AssignDefectDialog::AssignDefectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AssignDefectDialog)
{
    ui->setupUi(this);

    connect(ui->submitButton, &QPushButton::clicked, this, &AssignDefectDialog::on_submitButton_clicked);
}

AssignDefectDialog::~AssignDefectDialog()
{
    delete ui;
}

void AssignDefectDialog::populateDefectList(const QStringList &defectList)
{
    ui->defectListComboBox->clear();
    ui->defectListComboBox->addItems(defectList);
}

void AssignDefectDialog::populateEmployeeList(const QStringList &employeeList)
{
    ui->employeeListComboBox->clear();
    ui->employeeListComboBox->addItems(employeeList);
}

void AssignDefectDialog::on_submitButton_clicked()
{
    QString defect = ui->defectListComboBox->currentText();
    QString employee = ui->employeeListComboBox->currentText();

    emit defectAssigned(defect, employee);

    accept(); // Close the dialog
}
