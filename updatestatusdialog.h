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

public slots:
    void populateDefectList(const QStringList &defectList);
    void setCurrentStatus(const QString &status);

signals:
    void statusUpdated(const QString &defect, const QString &status);

private slots:
    void on_submitButton_clicked();

private:
    Ui::UpdateStatusDialog *ui;
};

#endif // UPDATESTATUSDIALOG_H
