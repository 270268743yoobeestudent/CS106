#ifndef EMPLOYEEMENUDIALOG_H
#define EMPLOYEEMENUDIALOG_H

#include <QDialog>
#include "addeditdefectmenu.h"
#include "addeditprioritydialog.h" // Include AddEditPriorityDialog header

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
    void on_addEditPriorityButton_clicked(); // Slot for Add/Edit Priority button

private:
    Ui::EmployeeMenuDialog *ui;
    AddEditDefectMenu *addEditDefectMenu;

};

#endif // EMPLOYEEMENUDIALOG_H
