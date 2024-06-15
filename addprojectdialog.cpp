#include "addprojectdialog.h"
#include "ui_addprojectdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

AddProjectDialog::AddProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProjectDialog)
{
    ui->setupUi(this);

    // Connect submitButton click signal to on_submitButton_clicked slot
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

    if (projectName.isEmpty() || projectDescription.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter both project name and description.");
        return;
    }

    // Save to a text file
    QFile file("projects.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Project Name: " << projectName << "\n";
        out << "Description: " << projectDescription << "\n\n";
        file.close();
        QMessageBox::information(this, "Success", "Project information saved successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to open projects.txt for writing.");
    }
}
