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
    enum Action {
        AddDefect,
        EditDefect
    };

    explicit AddEditDefectMenuDialog(QWidget *parent = nullptr);
    ~AddEditDefectMenuDialog();

    bool isAddDefectSelected() const;
    bool isEditDefectSelected() const;

private slots:
    void on_addDefectButton_clicked();
    void on_editDefectButton_clicked();

private:
    Ui::AddEditDefectMenuDialog *ui;
    bool addDefectSelected;
};

#endif // ADDEDITDEFECTMENUDIALOG_H
