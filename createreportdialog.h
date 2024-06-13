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

public slots:
    void populateDefectList(const QStringList &defectList);

signals:
    void reportRequested(const QString &defect);

private slots:
    void on_generateReportButton_clicked();

private:
    Ui::CreateReportDialog *ui;
};

#endif // CREATEREPORTDIALOG_H
