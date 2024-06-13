#include "editemployeedialog.h"
#include "ui_editemployeedialog.h"

EditEmployeeDialog::EditEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEmployeeDialog)
{
    ui->setupUi(this);

    connect(ui->submitButton, &QPushButton::clicked, this, &EditEmployeeDialog::on_submitButton_clicked);
}

EditEmployeeDialog::~EditEmployeeDialog()
{
    delete ui;
}

void EditEmployeeDialog::populateEmployeeList(const QStringList &employeeList)
{
    ui->employeeListComboBox->clear();
    ui->employeeListComboBox->addItems(employeeList);
}

void EditEmployeeDialog::on_submitButton_clicked()
{
    QString currentName = ui->employeeListComboBox->currentText();
    QString newName = ui->newNameLineEdit->text().trimmed();

    emit employeeEdited(currentName, newName);

    accept(); // Close the dialog
}
