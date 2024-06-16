#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginDialog; }
QT_END_NAMESPACE

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    QString getUsername() const;

private slots:
    void on_loginButton_clicked();

signals:
    void userLoggedIn(bool isAdmin);

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
