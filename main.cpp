#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "game.h"
#include "gamemanager.h"
#include "wordrepository.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);
  qmlRegisterType<GameManager>("OrdBlink", 1, 0, "GameManager");
  qmlRegisterType<WordRepository>("OrdBlink", 1, 0, "WordRepository");
  qmlRegisterType<Game>("OrdBlink", 1, 0, "Game");

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty()) return -1;

  return app.exec();
}
