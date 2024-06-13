#ifndef ADDEDITDEFECTMENU_H
#define ADDEDITDEFECTMENU_H

#include <QDialog>

namespace Ui {
class AddEditDefectMenu;
}

class AddEditDefectMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditDefectMenu(QWidget *parent = nullptr);
    ~AddEditDefectMenu();

    bool isAddDefectSelected() const;
    bool isEditDefectSelected() const;

private:
    Ui::AddEditDefectMenu *ui;
    bool addDefectSelected;
    bool editDefectSelected;

private slots:
    void on_addDefectButton_clicked();
    void on_editDefectButton_clicked();
};

#endif // ADDEDITDEFECTMENU_H
