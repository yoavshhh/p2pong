#include "pong.h"
#include "./ui_pong.h"
#include "paddle.h"

#include <QClipboard>

Pong::Pong(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pong)
    , clipboard(QApplication::clipboard())
{
    ui->setupUi(this);
    ui->swWindowsStack->setCurrentIndex(0);
    setWindowFlags(Qt::FramelessWindowHint);
}

Pong::~Pong()
{
    delete ui;
}

void Pong::initPlayer()
{
    if (me.loadPlayer()) {
        ui->lUsername->setText(QString("username: %1").arg(me.username()));
    } else {
        // assuming never played. creating a new player!
        newPlayer();
    }
}

void Pong::newPlayer()
{
    me.setGamesPlayed(0);
    connect(&usernameDialog, &UsernameDialog::usernameResult, this, &Pong::handleUsernameResult);
    usernameDialog.exec();
}

void Pong::handleUsernameResult(const QString &result)
{
    me.setUsername(result);
    ui->lUsername->setText(QString("username: %1").arg(me.username()));
}

void Pong::connectToPeer()
{
    // networking shit
}

void Pong::setUpGame()
{
    ui->swWindowsStack->setCurrentIndex(1);
    ui->pongView->setScene(&scene);
    Paddle *pad = new Paddle(scene.sceneRect().bottom() - 80 - 40,
                             (scene.sceneRect().left() - 20) / 2,
                             80,
                             20);
    scene.addItem(pad);
}

void Pong::on_btnConnect_clicked()
{
    connectToPeer();
    setUpGame();
}

void Pong::on_btnGenCode_clicked()
{
    static int i = 0;
    ui->lCode->setText(QString("LIOR%1").arg(i++));
}

void Pong::on_btnOptions_clicked()
{
    destroy();
}

void Pong::on_btnCopyCode_clicked()
{
    clipboard->setText(ui->lCode->text());
}

void Pong::destroy()
{
    me.savePlayer();
    QMainWindow::destroy();
}
