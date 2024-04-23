#include "player.h"
#include "username_dialog.h"

#include <QFile>
#include <QJsonDocument>

Player::Player() {}

Player::Player(const QString &username, int gamesPlayed)
    : mUsername(username)
    , mGamesPlayed(gamesPlayed)
{}

bool Player::fromJson(const QJsonObject &json)
{
    if (const QJsonValue v = json["username"]; v.isString())
        mUsername = v.toString();
    else
        return false;

    if (const QJsonValue v = json["gamesPlayed"]; v.isDouble())
        mGamesPlayed = v.toInt();
    else
        return false;

    return true;
}

QJsonObject Player::toJson() const
{
    QJsonObject json;
    json["username"] = mUsername;
    json["gamesPlayed"] = mGamesPlayed;
    return json;
}

bool Player::loadPlayer()
{
    QFile loadFile("player.json");

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qInfo("Couldn't open save file. Maybe first time?");
        return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    if (!fromJson(loadDoc.object())) {
        qWarning("Invalid JSON save file. Cannot load saved data!");
        return false;
    }

    QTextStream(stdout) << "Loaded save for " << mUsername << "...\n";
    return true;
}

bool Player::savePlayer() const
{
    QFile saveFile("player.json");

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open player state save file.");
        return false;
    }

    QJsonObject gameObject = toJson();
    saveFile.write(QJsonDocument(gameObject).toJson());

    return true;
}
