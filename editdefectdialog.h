#ifndef EDITDEFECTDIALOG_H
#define EDITDEFECTDIALOG_H

#include <QDialog>

namespace Ui {
class EditDefectDialog;
}

class EditDefectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDefectDialog(QWidget *parent = nullptr);
    ~EditDefectDialog();

private slots:
    void onSubmit();

private:
    Ui::EditDefectDialog *ui;
};

#endif // EDITDEFECTDIALOG_H
