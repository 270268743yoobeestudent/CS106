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

signals:
    void defectEdited(int defectIndex, const QString &defectName, const QString &defectDescription);

public slots:
    void populateDefectList(const QStringList &defectList);
    void setDefectDetails(const QString &defectName, const QString &defectDescription);

private slots:
    void on_submitButton_clicked();

private:
    Ui::EditDefectDialog *ui;
};

#endif // EDITDEFECTDIALOG_H
