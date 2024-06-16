#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

QString LoginDialog::getUsername() const
{
    return ui->usernameLineEdit->text().trimmed();
}

void LoginDialog::on_loginButton_clicked()
{
    QString username = getUsername();
    QString password = ui->passwordLineEdit->text().trimmed();

    if (username == "admin" && password == "admin") {
        emit userLoggedIn(true); // Signal admin login
        accept(); // Close the dialog
    } else if (username == "employee" && password == "employee") {
        emit userLoggedIn(false); // Signal employee login
        accept(); // Close the dialog
    } else {
        qDebug() << "Invalid username or password!";
    }
}
