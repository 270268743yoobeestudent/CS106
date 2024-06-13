#ifndef EDITEMPLOYEEDIALOG_H
#define EDITEMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class EditEmployeeDialog;
}

class EditEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditEmployeeDialog(QWidget *parent = nullptr);
    ~EditEmployeeDialog();

public slots:
    void populateEmployeeList(const QStringList &employeeList);

signals:
    void employeeEdited(const QString &currentName, const QString &newName);

private slots:
    void on_submitButton_clicked();

private:
    Ui::EditEmployeeDialog *ui;
};

#endif // EDITEMPLOYEEDIALOG_H
