#include "addeditdefectmenudialog.h"
#include "ui_addeditdefectmenudialog.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>

AddEditDefectMenuDialog::AddEditDefectMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDefectMenuDialog),
    addDefectSelected(false),
    editDefectSelected(false)
{
    ui->setupUi(this);

    connect(ui->addDefectButton, &QPushButton::clicked, this, &AddEditDefectMenuDialog::on_addDefectButton_clicked);
    connect(ui->editDefectButton, &QPushButton::clicked, this, &AddEditDefectMenuDialog::on_editDefectButton_clicked);
}

AddEditDefectMenuDialog::~AddEditDefectMenuDialog()
{
    delete ui;
}

bool AddEditDefectMenuDialog::isAddDefectSelected() const
{
    return addDefectSelected;
}

bool AddEditDefectMenuDialog::isEditDefectSelected() const
{
    return editDefectSelected;
}

void AddEditDefectMenuDialog::on_addDefectButton_clicked()
{
    addDefectSelected = true;
    editDefectSelected = false;
    accept(); // Close the dialog and return QDialog::Accepted
}

void AddEditDefectMenuDialog::on_editDefectButton_clicked()
{
    editDefectSelected = true;
    addDefectSelected = false;
    accept(); // Close the dialog and return QDialog::Accepted
}

void AddEditDefectMenuDialog::saveToFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for writing:" << file.errorString();
        return;
    }

    QTextStream out(&file);
    out << "Add Defect Selected: " << (addDefectSelected ? "true" : "false") << "\n";
    out << "Edit Defect Selected: " << (editDefectSelected ? "true" : "false") << "\n";

    file.close();
    qDebug() << "Data saved to file:" << fileName;
}

void AddEditDefectMenuDialog::loadFromFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for reading:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        qDebug() << "Read line from file:" << line;
        // Here you could parse the line and update addDefectSelected and editDefectSelected
    }

    file.close();
    qDebug() << "Data loaded from file:" << fileName;
}
