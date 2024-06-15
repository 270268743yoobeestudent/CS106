#ifndef EMPLOYEEMENUDIALOG_H
#define EMPLOYEEMENUDIALOG_H

#include <QDialog>
#include "logindialog.h" // Include LoginDialog if needed

namespace Ui {
class EmployeeMenuDialog;
}

class EmployeeMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeMenuDialog(QWidget *parent = nullptr);
    ~EmployeeMenuDialog();

private slots:
    void on_addEditDefectButton_clicked();
    void on_addEditPriorityButton_clicked();
    void on_logoutButton_clicked();

private:
    Ui::EmployeeMenuDialog *ui;
    LoginDialog *loginDialog; // Instance of LoginDialog
};

#endif // EMPLOYEEMENUDIALOG_H
