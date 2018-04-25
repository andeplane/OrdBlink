import QtQuick 2.10
import QtQuick.Controls 2.2

Rectangle {
    signal start
    property int counter
    color: "#714c8f"
    // source: "qrc:///background.png"

//    Text {
//        text: "OrdBlink"
//        fontSizeMode: Text.Fit
//        font.pixelSize: 100
//        anchors.top: parent.top
//        anchors.topMargin: 10
//        anchors.horizontalCenter: parent.horizontalCenter
//    }

    Text {
        id: play
        anchors.centerIn: parent
        // text: "▶️"
        text: "Start"
        color: "white"
        fontSizeMode: Text.Fit
        font.pixelSize: 110
        MouseArea {
            anchors.fill: parent
            onClicked: start()
        }
    }

    Text {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: "😀  x "+counter
        color: "white"
        fontSizeMode: Text.Fit
        font.pixelSize: 35
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
