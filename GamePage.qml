import QtQuick 2.10
import OrdBlink 1.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

StackLayout {
    property Game game

    currentIndex: {
        if (game === null) return 0;
        game.finished ? 1 : 0
    }

    Item {
        id: gamePage
        Text {
            text: game===null ? "" : game.currentWord
            fontSizeMode: Text.Fit
            font.pixelSize: 72
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    FinishPage {
        id: finishPage
    }
}
