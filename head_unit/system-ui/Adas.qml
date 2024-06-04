import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2

Item{
    Column{
        spacing: 50
        Button {
            id: lkas
            background: Image {
                source: husystem.hu_lkas === 1 ? "images/lkas_red.png" : "images/lkas.png"
                anchors.fill: parent
            }
            onClicked: {
                husystem.changelkas();
            }
        }

        Button {
            id: aeb
            background: Image {
                source: husystem.hu_aeb === 1 ? "images/aeb_red.png" : "images/aeb.png"
                anchors.fill: parent
            }
            onClicked: {
                husystem.changeaeb();
            }
        }

    }
}