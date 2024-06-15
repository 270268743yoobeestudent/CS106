#ifndef ADDEDITPRIORITYDIALOG_H
#define ADDEDITPRIORITYDIALOG_H

#include <QDialog>
#include <QCloseEvent> // Include QCloseEvent header

namespace Ui {
class AddEditPriorityDialog;
}

class AddEditPriorityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditPriorityDialog(QWidget *parent = nullptr);
    ~AddEditPriorityDialog();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void closeEvent(QCloseEvent *event); // Override closeEvent to handle dialog closing

private:
    Ui::AddEditPriorityDialog *ui;
    bool changesSaved; // Flag to track if changes were saved
};

#endif // ADDEDITPRIORITYDIALOG_H

