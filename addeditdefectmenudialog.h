#ifndef ADDEDITDEFECTMENUDIALOG_H
#define ADDEDITDEFECTMENUDIALOG_H

#include <QDialog>

namespace Ui {
class AddEditDefectMenuDialog;
}

class AddEditDefectMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditDefectMenuDialog(QWidget *parent = nullptr);
    ~AddEditDefectMenuDialog();

signals:
    void addDefectRequested();
    void editDefectRequested();

private slots:
    void on_addDefectButton_clicked();
    void on_editDefectButton_clicked();

private:
    Ui::AddEditDefectMenuDialog *ui;
};

#endif // ADDEDITDEFECTMENUDIALOG_H
