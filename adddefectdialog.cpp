#include "adddefectdialog.h"
#include "ui_adddefectdialog.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

const QString DEFECTS_FILE_PATH = "defects.txt";

AddDefectDialog::AddDefectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDefectDialog)
{
    ui->setupUi(this);

    // Connect submitButton clicked signal to on_submitButton_clicked slot
    connect(ui->submitButton, &QPushButton::clicked, this, &AddDefectDialog::on_submitButton_clicked);

    qDebug() << "AddDefectDialog constructor called.";
}

AddDefectDialog::~AddDefectDialog()
{
    delete ui;
}

void AddDefectDialog::on_submitButton_clicked()
{
    qDebug() << "Submit button clicked.";

    QString defectName = ui->defectNameLineEdit->text().trimmed();

    // Emit signal with defect name
    emit defectAdded(defectName);

    // Save defect name to a file using QFile
    QFile file(DEFECTS_FILE_PATH);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open defects file for writing:" << file.errorString();
        return;
    }

    QTextStream out(&file);
    out << "Defect Name: " << defectName << "\n\n";  // Separate defects with double newline

    file.close();
    qDebug() << "Defect name saved to file:" << DEFECTS_FILE_PATH;

    // Close the dialog
    accept(); // Accept the dialog (return QDialog::Accepted)
}
