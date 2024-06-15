#include "editdefectdialog.h"
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>

const QString DEFECTS_FILE_PATH = "defects.txt";

EditDefectDialog::EditDefectDialog(QWidget *parent) :
    QDialog(parent),
    defectListComboBox(new QComboBox(this)),
    defectNameLineEdit(new QLineEdit(this)),
    submitButton(new QPushButton("Save", this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(defectListComboBox);
    layout->addWidget(defectNameLineEdit);
    layout->addWidget(submitButton);

    connect(defectListComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &EditDefectDialog::onDefectSelected);
    connect(submitButton, &QPushButton::clicked, this, &EditDefectDialog::submitForm);

    loadDefectNamesFromFile();

    setLayout(layout);
}

EditDefectDialog::~EditDefectDialog()
{
    // Clean up allocated resources if needed
}

void EditDefectDialog::loadDefectNamesFromFile()
{
    // Load defect names from a file and populate the combobox
    QStringList defectNames;
    QFile file(DEFECTS_FILE_PATH);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty()) {
                QStringList parts = line.split(": ");
                if (parts.length() >= 2 && parts[0] == "Defect Name") {
                    defectNames << parts[1];
                }
            }
        }
        file.close();
    } else {
        qDebug() << "Failed to open defects file for reading:" << file.errorString();
    }

    populateDefectComboBox(defectNames);
}

void EditDefectDialog::populateDefectComboBox(const QStringList &defectNames)
{
    defectListComboBox->clear();
    defectListComboBox->addItems(defectNames);
}

void EditDefectDialog::onDefectSelected(int index)
{
    // Load details of the selected defect for editing
    QString selectedDefectName = defectListComboBox->itemText(index);
    defectNameLineEdit->setText(selectedDefectName);
}

void EditDefectDialog::submitForm()
{
    // Save changes to the selected defect
    QString selectedDefectName = defectNameLineEdit->text().trimmed();

    QFile file(DEFECTS_FILE_PATH);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream stream(&file);
        QStringList lines;
        while (!stream.atEnd()) {
            QString line = stream.readLine().trimmed();
            if (!line.isEmpty()) {
                lines << line;
            }
        }

        // Find and update the defect details in the lines list
        bool defectFound = false;
        for (int i = 0; i < lines.size(); ++i) {
            if (lines[i].startsWith("Defect Name: ") && lines[i].endsWith(defectListComboBox->currentText())) {
                // Modify only the defect name line
                lines[i] = "Defect Name: " + selectedDefectName;
                defectFound = true;
                break;
            }
        }

        // Write back updated lines to the file
        file.resize(0); // Clear contents of the file
        QTextStream out(&file);
        for (const QString &line : lines) {
            out << line << "\n";
        }

        file.close();
        qDebug() << "Defect name updated in file:" << defectListComboBox->currentText() << "->" << selectedDefectName;

        // Emit signal indicating defect name was edited
        emit defectEdited(selectedDefectName);
    } else {
        qDebug() << "Failed to open defects file for writing:" << file.errorString();
    }

    // Close the dialog
    accept(); // Accept the dialog (return QDialog::Accepted)
}
