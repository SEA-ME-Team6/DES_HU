import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.12
import QtApplicationManager 2.0
import QtApplicationManager.Application 2.0

ApplicationManagerWindow {
    id: ambient
    color: "black"

    property string ambient_color: "#030000"

    Component.onCompleted: {
        sendInitialColortIntent();
    }

    function sendColortIntent() {
        var parameters = { abColorValue: ambient.ambient_color };
        var request = IntentClient.sendIntentRequest("get-color", parameters);
        request.onReplyReceived.connect(function() {
            if (request.succeeded) {
                console.log("Success intent: ", request.result);
            } 
            else {
                console.error("Fail intent: ", request.errorMessage);
            }
        });
    }

    function sendInitialColortIntent() {
        var request = IntentClient.sendIntentRequest("get-initialcolor", {});
        request.onReplyReceived.connect(function() {
            if (request.succeeded) {
                var inicolor = request.result.abIniColorValue;

                var red = parseInt(inicolor.substring(1, 3), 16);
                var green = parseInt(inicolor.substring(3, 5), 16);
                var blue = parseInt(inicolor.substring(5, 7), 16);

                redSlider.value = red;
                greenSlider.value = green;
                blueSlider.value = blue;

                ambient.ambient_color = inicolor;
            }
            else{
                console.error("Fail intent: ", request.errorMessage);
            }
        });
    }

    Column {
        anchors {
            verticalCenter: parent.verticalCenter
            horizontalCenter: parent.horizontalCenter
        } 
        spacing:1

        Slider {
            id: redSlider
            from: 0
            to: 255
            value: 0
            stepSize: 1
            onValueChanged: {
                ambient.ambient_color = "#" + (redSlider.value.toString(16).length === 1 ? "0" : "") + redSlider.value.toString(16) + ambient.ambient_color.substring(3, 7)
                sendColortIntent()
            }
        }

        Slider {
            id: greenSlider
            from: 0
            to: 255
            value: 0
            stepSize: 1
            onValueChanged: {
                ambient.ambient_color = "#" + ambient.ambient_color.substring(1, 3) + (greenSlider.value.toString(16).length === 1 ? "0" : "") + greenSlider.value.toString(16) + ambient.ambient_color.substring(5, 7)
                sendColortIntent()
            }

        }

        Slider {
            id: blueSlider
            from: 0
            to: 255
            value: 0
            stepSize: 1
            onValueChanged: {
                ambient.ambient_color = "#" + ambient.ambient_color.substring(1, 5) + (blueSlider.value.toString(16).length === 1 ? "0" : "") + blueSlider.value.toString(16)
                sendColortIntent()
            }
        }
    }
}