#include "game.h"
#include <QDebug>

Game::Game(QStringList words) : m_words(words), m_currentWord(0) {
  connect(&m_timer, SIGNAL(timeout()), this, SLOT(tick()));
  m_timer.start(1000);
}

QString Game::currentWord() const { return m_words[m_currentWord]; }

void Game::nextWord() {
  m_currentWord++;
  if (finished()) {
    m_timer.stop();

    emit finishedChanged(true);
    disconnect(&m_timer);

    connect(&m_timer, &QTimer::timeout, [&]() { emit close(); });
    m_timer.start(2000);
  } else {
    emit currentWordChanged(m_words[m_currentWord]);
  }
}

bool Game::finished() const { return m_currentWord >= m_words.size(); }

void Game::tick() { nextWord(); }
