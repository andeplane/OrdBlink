#include "gamemanager.h"
#include <QDebug>
#include "game.h"
#include "wordrepository.h"

GameManager::GameManager(QObject *parent) : QObject(parent) {}

WordRepository *GameManager::wordRepository() const { return m_wordRepository; }

void GameManager::next() { m_game->nextWord(); }

Game *GameManager::game() const { return m_game.get(); }

void GameManager::start(int difficulty) {
  if (m_game) {
    disconnect(m_game.get());
  }

  auto words = m_wordRepository->get(
      10, static_cast<WordRepository::Difficulty>(difficulty));
  m_game = std::make_unique<Game>(std::move(words));

  connect(m_game.get(), SIGNAL(close()), this, SLOT(onGameFinished()));

  emit gameChanged(m_game.get());
}

void GameManager::setWordRepository(WordRepository *wordRepository) {
  if (m_wordRepository == wordRepository) return;

  m_wordRepository = wordRepository;
  emit wordRepositoryChanged(m_wordRepository);
}

void GameManager::onGameFinished() {
  m_game = nullptr;
  emit gameChanged(nullptr);
}
