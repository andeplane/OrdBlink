#ifndef WORDREPOSITORY_H
#define WORDREPOSITORY_H

#include <QList>
#include <QMap>
#include <QObject>

#include <array>

class WordRepository : public QObject {
  Q_OBJECT

 public:
  enum class Difficulty { Easiest = 0, Easy, Medium, Hard, Hardest };

  const QList<Difficulty> difficulties = {Difficulty::Easiest, Difficulty::Easy,
                                          Difficulty::Medium, Difficulty::Hard,
                                          Difficulty::Hardest};

  explicit WordRepository(QObject *parent = nullptr);
  QStringList get(int n, Difficulty difficulty);

 signals:

 public slots:

 private:
  int getRandomIndex(Difficulty difficulty);
  QMap<Difficulty, QStringList> m_words;
  //  QStringList m_words;
};

#endif  // WORDREPOSITORY_H
