#ifndef PONG_H
#define PONG_H

#include "player.h"
#include "username_dialog.h"

#include <QClipboard>
#include <QGraphicsScene>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Pong;
}
QT_END_NAMESPACE

class Pong : public QMainWindow
{
    Q_OBJECT

public:
    Pong(QWidget *parent = nullptr);
    ~Pong();

    void initPlayer();
    void newPlayer();
    void handleUsernameResult(const QString &result);
    void connectToPeer();
    void setUpGame();

private slots:
    void on_btnConnect_clicked();
    void on_btnGenCode_clicked();
    void on_btnOptions_clicked();
    void on_btnCopyCode_clicked();

protected:
    void destroy();

private:
    Ui::Pong *ui;
    QClipboard *clipboard;
    Player me;
    UsernameDialog usernameDialog;
    QGraphicsScene scene;
};
#endif // PONG_H
