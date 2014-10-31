import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    id: main
    visible: true
    width: 800
    height: 1280
    color: "lightgray"
    ToolBar {
        id: toolBar
        objectName: "toolBar"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height / 8
        Text {
            id: toolTime
            objectName: "toolTime"
            anchors.fill: parent
            font.pixelSize: height * 0.6
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: "black"
        }
    }
    ListView {
        id: listTimes
        objectName: "listTimes"
        anchors.top: toolBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: main.height - toolBar.height - tillTheEnd.height
        model: ListModel {
            objectName: "modelTime"
            id: modelTime            
        }
        function append(newTime) {
            listTimes.model.append(newTime);
        }
        clip: true
        delegate: Rectangle {
            width: listTimes.width
            height: listTimes.height / 6
            color: "#AFAFAF"
            Text {
                id: currentTime
                height: parent.height
                anchors.left: parent.left
                anchors.top: parent.top
                width: parent.width * 0.4
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height * 0.5
                text: time
            }
            Text {
                anchors.left: currentTime.right
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                height: parent.height
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height * 0.4
                text: name
            }
        }
    }
    Text {
        id: tillTheEnd_name
        anchors.left: parent.left
        color: "black"
        anchors.bottom: parent.bottom
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        width: parent.width * 0.6
        font.pixelSize: height / 2
        height: parent.height / 8
        text: "До выхода:"
    }
    Text {
        id: tillTheEnd
        objectName: "tillTheEnd"
        anchors.right: parent.right
        anchors.left: tillTheEnd_name.right
        anchors.bottom: parent.bottom
        height: tillTheEnd_name.height
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: height / 2
    }
}
