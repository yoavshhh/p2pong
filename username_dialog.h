#ifndef USERNAME_DIALOG_H
#define USERNAME_DIALOG_H

#include <QDialog>

namespace Ui {
class UsernameDialog;
}

class UsernameDialog : public QDialog
{
    Q_OBJECT
public:
    static const int USERNAME_MIN_LENGTH = 3;

signals:
    void usernameResult(const QString& result);

public:
    explicit UsernameDialog(QWidget *parent = nullptr);
    ~UsernameDialog();

protected:
    void reject();

private slots:
    void on_btnOK_clicked();

private:
    Ui::UsernameDialog *ui;
};

#endif // USERNAME_DIALOG_H
