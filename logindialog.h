#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

signals:
    void userLoggedIn(bool isAdmin); // Signal for login success

private slots:
    void on_loginButton_clicked(); // Slot for login button click event

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
