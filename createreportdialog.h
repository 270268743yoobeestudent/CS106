#ifndef CREATEREPORTDIALOG_H
#define CREATEREPORTDIALOG_H

#include <QDialog>

namespace Ui {
class CreateReportDialog;
}

class CreateReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateReportDialog(QWidget *parent = nullptr);
    ~CreateReportDialog();

private slots:
    void onGenerateReport();

private:
    Ui::CreateReportDialog *ui;
};

#endif // CREATEREPORTDIALOG_H
