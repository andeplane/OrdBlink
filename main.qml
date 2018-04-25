import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import OrdBlink 1.0
import Qt.labs.settings 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    flags: Qt.MaximizeUsingFullscreenGeometryHint

    GameManager {
        id: gameManager
        wordRepository: WordRepository {
            id: wordRepository
        }
        onGameChanged: {
            if (game) {
                stack.push(gamePage)
            } else {
                stack.pop()
                frontPage.counter++
            }
        }
    }

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: frontPage

        FrontPage {
            id: frontPage
            counter: 0
            onStart: {
                gameManager.start(0)
            }
        }

        GamePage {
            id: gamePage
            game: gameManager.game
        }
    }

    Settings {
        property alias count: frontPage.counter
    }
}
