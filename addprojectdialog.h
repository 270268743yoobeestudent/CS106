#ifndef ADDPROJECTDIALOG_H
#define ADDPROJECTDIALOG_H

#include <QDialog>

namespace Ui {
class AddProjectDialog;
}

class AddProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProjectDialog(QWidget *parent = nullptr);
    ~AddProjectDialog();

signals:
    void projectAdded(const QString &projectName, const QString &projectDescription);

private slots:
    void on_submitButton_clicked();

private:
    Ui::AddProjectDialog *ui;
};

#endif // ADDPROJECTDIALOG_H
