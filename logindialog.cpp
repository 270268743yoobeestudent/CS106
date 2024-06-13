#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    // Connect login button click to slot
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginDialog::on_loginButton_clicked);
}

void LoginDialog::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text().trimmed();
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

LoginDialog::~LoginDialog()
{
    delete ui;
}
