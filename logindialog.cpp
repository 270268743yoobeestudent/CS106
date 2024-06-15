#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    // Connect login button click to slot
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginDialog::on_loginButton_clicked);
}

LoginDialog::~LoginDialog()
{
    delete ui;
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
        // Display error message using QMessageBox
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
        ui->passwordLineEdit->clear(); // Clear password field
        ui->usernameLineEdit->setFocus(); // Set focus back to username field
    }
}
