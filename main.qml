import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal qmlSignal(string message)

    function emitSignal(message) {
        console.log("Emitting QML signal with message: ", message)
        qmlSignal(message)
    }

    Rectangle {
        width: 640
        height: 480

        MouseArea {
            anchors.fill: parent
            onClicked: {
                emitSignal("Mouse Clicked")
            }
        }
    }
}
