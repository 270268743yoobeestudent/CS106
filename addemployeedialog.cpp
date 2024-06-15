#include "addemployeedialog.h"
#include "ui_addemployeedialog.h"
#include "filemanager.h"

AddEmployeeDialog::AddEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmployeeDialog)
{
    ui->setupUi(this);

    connect(ui->submitButton, &QPushButton::clicked, this, &AddEmployeeDialog::on_submitButton_clicked);
}

AddEmployeeDialog::~AddEmployeeDialog()
{
    delete ui;
}

void AddEmployeeDialog::on_submitButton_clicked()
{
    QString employeeName = ui->employeeNameLineEdit->text().trimmed();

    FileManager fileManager("employees.txt");
    if (fileManager.writeToFile("Employee Name: " + employeeName)) {
        qDebug() << "Employee name saved successfully:" << employeeName;
        emit employeeAdded(employeeName);
        accept(); // Close the dialog
    } else {
        qDebug() << "Failed to save employee name:" << employeeName;
    }
}
