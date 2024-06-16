#include <QApplication>
#include "logindialog.h"
#include "adminmenudialog.h"
#include "employeemenudialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog loginDialog;
    if (loginDialog.exec() == QDialog::Accepted) {
        QString username = loginDialog.getUsername();
        // Example logic to determine if the user is admin or employee based on username
        bool isAdmin = (username == "admin");

        if (isAdmin) {
            AdminMenuDialog adminMenuDialog;
            adminMenuDialog.exec();
        } else {
            EmployeeMenuDialog employeeMenuDialog;
            QObject::connect(&employeeMenuDialog, &EmployeeMenuDialog::logoutRequested, [&loginDialog, &employeeMenuDialog]() {
                // Close current dialog and show login dialog
                employeeMenuDialog.close();
                loginDialog.show();
            });
            employeeMenuDialog.exec();
        }
    }

    return a.exec();
}
