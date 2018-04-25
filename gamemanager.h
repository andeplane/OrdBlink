#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "game.h"
#include <QObject>
#include <memory>
class WordRepository;

class GameManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(WordRepository* wordRepository READ wordRepository WRITE
            setWordRepository NOTIFY wordRepositoryChanged)
    Q_PROPERTY(Game* game READ game NOTIFY gameChanged)
public:
    explicit GameManager(QObject* parent = nullptr);

    WordRepository* wordRepository() const;
    Game* game() const;
    Q_INVOKABLE void start(int difficulty);
    Q_INVOKABLE void next();

signals:
    void wordRepositoryChanged(WordRepository* wordRepository);
    void gameChanged(Game* game);

public slots:
    void setWordRepository(WordRepository* wordRepository);
    void onGameFinished();

private:
    WordRepository* m_wordRepository = nullptr;
    std::unique_ptr<Game> m_game;
};

#endif // GAMEMANAGER_H
