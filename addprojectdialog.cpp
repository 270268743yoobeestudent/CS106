#include "addprojectdialog.h"
#include "ui_addprojectdialog.h"

AddProjectDialog::AddProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProjectDialog)
{
    ui->setupUi(this);

    connect(ui->submitButton, &QPushButton::clicked, this, &AddProjectDialog::on_submitButton_clicked);
}

AddProjectDialog::~AddProjectDialog()
{
    delete ui;
}

void AddProjectDialog::on_submitButton_clicked()
{
    QString projectName = ui->projectNameLineEdit->text().trimmed();
    QString projectDescription = ui->projectDescriptionTextEdit->toPlainText().trimmed();

    emit projectAdded(projectName, projectDescription);

    accept(); // Close the dialog
}
