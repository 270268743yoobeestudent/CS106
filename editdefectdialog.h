#ifndef EDITDEFECTDIALOG_H
#define EDITDEFECTDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

class EditDefectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDefectDialog(QWidget *parent = nullptr);
    ~EditDefectDialog();

signals:
    void defectEdited(const QString &newDefectName);

private slots:
    void onDefectSelected(int index);
    void submitForm();

private:
    void loadDefectNamesFromFile();
    void populateDefectComboBox(const QStringList &defectNames);

    QComboBox *defectListComboBox;
    QLineEdit *defectNameLineEdit;
    QPushButton *submitButton;
};

#endif // EDITDEFECTDIALOG_H
