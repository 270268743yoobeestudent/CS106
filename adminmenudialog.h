#ifndef ADMINMENUDIALOG_H
#define ADMINMENUDIALOG_H

#include <QDialog>
#include "addeditdefectmenu.h" // Include AddEditDefectMenu header

namespace Ui {
class AdminMenuDialog;
}

class AdminMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMenuDialog(QWidget *parent = nullptr);
    ~AdminMenuDialog();

private slots:
    void on_addEditDefectButton_clicked();
    void on_addEditPriorityButton_clicked();
    void on_addProjectButton_clicked();
    void on_updateDefectStatusButton_clicked();
    void on_createReportButton_clicked();
    void on_addEditEmployeeButton_clicked();
    void on_assignDefectButton_clicked();

private:
    Ui::AdminMenuDialog *ui;
    AddEditDefectMenu *addEditDefectMenu; // Instance of AddEditDefectMenu

};

#endif // ADMINMENUDIALOG_H
