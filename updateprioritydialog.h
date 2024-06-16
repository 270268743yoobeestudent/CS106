#ifndef UPDATEPRIORITYDIALOG_H
#define UPDATEPRIORITYDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class UpdatePriorityDialog;
}
QT_END_NAMESPACE

class UpdatePriorityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdatePriorityDialog(QWidget *parent = nullptr);
    ~UpdatePriorityDialog();

private slots:
    void on_submitButton_clicked();

private:
    Ui::UpdatePriorityDialog *ui;
};

#endif // UPDATEPRIORITYDIALOG_H
