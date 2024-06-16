#include "ui_updateprioritydialog.h"
#include "updateprioritydialog.h"
#include <QDebug>

UpdatePriorityDialog::UpdatePriorityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdatePriorityDialog)
{
    ui->setupUi(this);

    // Connect submit button click signal to slot
    connect(ui->submitButton, &QPushButton::clicked, this, &UpdatePriorityDialog::on_submitButton_clicked);
}

UpdatePriorityDialog::~UpdatePriorityDialog()
{
    delete ui;
}

void UpdatePriorityDialog::on_submitButton_clicked()
{
    // Example implementation: Handle submit button click
    QString selectedPriority = ui->priorityComboBox->currentText();
    QString selectedDefect = ui->defectListComboBox->currentText();

    // Debugging output - you can remove this in production
    qDebug() << "Selected Defect: " << selectedDefect;
    qDebug() << "Selected Priority: " << selectedPriority;

    // Implement logic to update priority for selected defect
    // For now, just close the dialog
    accept();
}
