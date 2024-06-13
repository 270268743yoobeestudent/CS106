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

signals:
    void defectAdded(const QString &defectName, const QString &defectDescription);

private slots:
    void on_submitButton_clicked();

private:
    Ui::AddDefectDialog *ui;
};

#endif // ADDDEFECTDIALOG_H
