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

private slots:
    void onSubmit();

private:
    Ui::AssignDefectDialog *ui;
};

#endif // ASSIGNDEFECTDIALOG_H
