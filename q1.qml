import QtQuick 2.0
import QtQuick.Controls 1.1

Rectangle {
    width: 100
    height: 62

    Text {
        id: text1
        x: 192
        y: 54
        width: 128
        height: 88
        text: qsTr("Text")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
        font.pixelSize: 59
    }

    Slider {
        id: sliderVertical1
        x: 448
        y: 0
        width: 32
        height: 792
        opacity: 1
        orientation: 0
    }
    states: [
        State {
            name: "State1"

            PropertyChanges {
                target: text1
                x: 26
                y: 19
            }
        }
    ]
}
