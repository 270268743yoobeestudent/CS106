#ifndef EMPLOYEEMENUDIALOG_H
#define EMPLOYEEMENUDIALOG_H

#include <QDialog>
#include "addeditdefectmenudialog.h" // Include the header file for AddEditDefectMenuDialog

QT_BEGIN_NAMESPACE
namespace Ui {
class EmployeeMenuDialog;
}
QT_END_NAMESPACE

class EmployeeMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeMenuDialog(QWidget *parent = nullptr);
    ~EmployeeMenuDialog();

signals:
    void logoutRequested(); // Signal for logout request

private slots:
    void on_addEditDefectButton_clicked();
    void on_addEditPriorityButton_clicked();
    void on_logoutButton_clicked(); // Slot for logout button click

private:
    Ui::EmployeeMenuDialog *ui;
    AddEditDefectMenuDialog *addEditDefectMenu;
};

#endif // EMPLOYEEMENUDIALOG_H
