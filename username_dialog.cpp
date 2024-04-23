#include "username_dialog.h"
#include "ui_username_dialog.h"

UsernameDialog::UsernameDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UsernameDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

UsernameDialog::~UsernameDialog()
{
    delete ui;
}

void UsernameDialog::on_btnOK_clicked()
{
    reject();
}

void UsernameDialog::reject()
{
    QString username = ui->leUsername->text();
    if (username.length() < USERNAME_MIN_LENGTH) {
        ui->lErrMsg->setText(QString("Username length is less than %1!").arg(USERNAME_MIN_LENGTH));
        return;
    }
    for (const QChar& ch : username) {
        if (!ch.isPrint()) {
            ui->lErrMsg->setText("Username has to be printable!");
            return;
        }
        if (ch.isSpace()) {
            ui->lErrMsg->setText("Username cannot contain spaces!");
            return;
        }
    }
    // valid username
    emit usernameResult(username);
    QDialog::reject();
}

