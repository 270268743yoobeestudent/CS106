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

    bool isAddDefectSelected() const;
    bool isEditDefectSelected() const;

private:
    Ui::AddEditDefectMenuDialog *ui;
    bool addDefectSelected;
    bool editDefectSelected;

private slots:
    void on_addDefectButton_clicked();
    void on_editDefectButton_clicked();
    void saveToFile(const QString &fileName);
    void loadFromFile(const QString &fileName);
};

#endif // ADDEDITDEFECTMENUDIALOG_H
