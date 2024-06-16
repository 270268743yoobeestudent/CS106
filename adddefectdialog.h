#ifndef ADDDEFECTDIALOG_H
#define ADDDEFECTDIALOG_H

#include <QDialog>

namespace Ui {
class AddDefectDialog;
}

class AddDefectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDefectDialog(QWidget *parent = nullptr);
    ~AddDefectDialog();

private slots:
    void onSubmit();

private:
    Ui::AddDefectDialog *ui;
};

#endif // ADDDEFECTDIALOG_H
