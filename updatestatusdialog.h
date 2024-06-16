#ifndef UPDATESTATUSDIALOG_H
#define UPDATESTATUSDIALOG_H

#include <QDialog>

namespace Ui {
class UpdateStatusDialog;
}

class UpdateStatusDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateStatusDialog(QWidget *parent = nullptr);
    ~UpdateStatusDialog();

private slots:
    void onSubmit();

private:
    Ui::UpdateStatusDialog *ui;
};

#endif // UPDATESTATUSDIALOG_H
