#ifndef ASSIGNDEFECTDIALOG_H
#define ASSIGNDEFECTDIALOG_H

#include <QDialog>

namespace Ui {
class AssignDefectDialog;
}

class AssignDefectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AssignDefectDialog(QWidget *parent = nullptr);
    ~AssignDefectDialog();

public slots:
    void populateDefectList(const QStringList &defectList);
    void populateEmployeeList(const QStringList &employeeList);

signals:
    void defectAssigned(const QString &defect, const QString &employee);

private slots:
    void on_submitButton_clicked();

private:
    Ui::AssignDefectDialog *ui;
};

#endif // ASSIGNDEFECTDIALOG_H
