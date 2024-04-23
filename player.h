 #ifndef PLAYER_H
#define PLAYER_H

#include "qobjectdefs.h"
#include "qtmetamacros.h"
#include <QJsonObject>
#include <QString>

class Player
{
    Q_GADGET
public:
    Player();
    Player(const QString& username, int gamesPlayed=0);

    QString username() const                    { return mUsername; }
    void setUsername(const QString &username)   { mUsername = username; }

    int gamesPlayed() const                     { return mGamesPlayed; }
    void setGamesPlayed(int gamesPlayed)        { mGamesPlayed = gamesPlayed; }

    bool fromJson(const QJsonObject &json);
    QJsonObject toJson() const;

    bool loadPlayer();
    bool savePlayer() const;
private:
    QString mUsername;
    int mGamesPlayed;
};

#endif // PLAYER_H
