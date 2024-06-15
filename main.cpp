#include <QApplication>
#include <QDebug>
#include "logindialog.h"
#include "adminmenudialog.h"
#include "employeemenudialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog loginDialog;
    bool isAdmin = false;

    // Connect the userLoggedIn signal to set isAdmin when user logs in
    QObject::connect(&loginDialog, &LoginDialog::userLoggedIn, [&](bool loggedInAsAdmin) {
        isAdmin = loggedInAsAdmin;
    });

    if (loginDialog.exec() == QDialog::Accepted) {
        if (isAdmin) {
            AdminMenuDialog adminMenu;
            int result = adminMenu.exec();
            if (result == QDialog::Rejected) {
                qDebug() << "Admin menu closed or rejected.";
            }
        } else {
            EmployeeMenuDialog employeeMenu;
            int result = employeeMenu.exec();
            if (result == QDialog::Rejected) {
                qDebug() << "Employee menu closed or rejected.";
            }
        }
    } else {
        qDebug() << "Login dialog closed or rejected.";
    }

    return a.exec();
}
