import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

Rectangle {
    width: 800
    height: 600

    // Charger la police FontAwesome

    Plugin {
        id: mapPlugin
        name: "osm"
        PluginParameter {
            name: "osm.mapping.providersrepository.address"
            value: "http://a.tile.openstreetmap.org/%1/%2/%3.png"
        }
    }

    // Définition de la carte
    Map {
        id: myMap
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(34.0, 9.0) // Tunisie centrale
        zoomLevel: 7  // Niveau de zoom optimal pour voir la Tunisie en contexte régional
        minimumZoomLevel: 5   // Empêche un zoom trop large
        maximumZoomLevel: 10  // Empêche un zoom trop rapproché

        // Champ de texte pour saisir une localisation
        TextField {
            id: locationInput
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 10
            placeholderText: "Entrez une localisation"
            width: parent.width * 0.8
            onEditingFinished: mainWindow.searchLocation(locationInput.text)
        }

        // Affichage des marqueurs
        MapItemView {
            model: markerModel // Modèle de marqueur défini dans C++
            delegate: MapQuickItem {
                id: markerItem
                coordinate: model.coordinate
                anchorPoint: Qt.point(width / 2, height)
                width: 32
                height: 32

                Text {
                    text: "\uf041" // Code Unicode pour l'icône de l'épingle (📍)
                    font.family: fontAwesomeLoader.name // Utiliser la police FontAwesome
                    font.pixelSize: 24
                    color: "red"
                    anchors.centerIn: parent
                }
            }
        }

        // Gestion du mouvement de la carte avec la souris
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            property var lastMousePos

            onPressed: (mouse) => {
                lastMousePos = Qt.point(mouse.x, mouse.y)
            }

            onPositionChanged: (mouse) => {
                var dx = mouse.x - lastMousePos.x
                var dy = mouse.y - lastMousePos.y
                myMap.pan(-dx, -dy)
                lastMousePos = Qt.point(mouse.x, mouse.y)
            }
        }

        // Gestion du zoom avec la molette
        WheelHandler {
            id: zoomHandler
            target: myMap
            property real step: 0.5

            onWheel: (event) => {
                myMap.zoomLevel += event.angleDelta.y > 0 ? step : -step
                event.accepted = true
            }
        }

        // Rechargement des marqueurs au démarrage
        Component.onCompleted: {
            markerModel.loadFromJson()
            console.log("🔁 loadFromJson() forcé côté QML.")
        }

        // Connexion avec mainWindow pour l'ajout de marqueurs via signal
        Connections {
            target: mainWindow

            function onMarqueurAjoute(lat, lon) {
                if (!isNaN(lat) && !isNaN(lon)) {
                    markerModel.addMarker(QtPositioning.coordinate(lat, lon))
                    console.log("✅ Marqueur ajouté via signal :", lat, lon)
                } else {
                    console.warn("❌ Coordonnées invalides reçues :", lat, lon)
                }
            }

            function onCenterMap(lat, lon) {
                setCenter(lat, lon)
            }
        }

    }

    // Fonction pour centrer la carte sur une localisation spécifique
    function setCenter(lat, lng) {
        myMap.center = QtPositioning.coordinate(lat, lng)
        myMap.zoomLevel = 10  // Force le niveau de zoom souhaité
    }
}
