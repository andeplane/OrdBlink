#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QTimer>

class Game : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString currentWord READ currentWord NOTIFY currentWordChanged)
  Q_PROPERTY(bool finished READ finished NOTIFY finishedChanged)

 public:
  explicit Game(QObject *parent = nullptr) : QObject(parent) {}
  Game(QStringList words);
  QString currentWord() const;
  void nextWord();
  bool finished() const;

 signals:
  void currentWordChanged(QString currentWord);
  void finishedChanged(bool finished);
  void close();

 public slots:
  void tick();
  void emitClose() { emit close(); }

 private:
  const QStringList m_words;
  QTimer m_timer;
  int m_currentWord;
  bool m_finished;
};

#endif  // GAME_H
