// Tabbed Pane project template
import bb.cascades 1.0
import QtMobility.sensors 1.2
import bb.cascades.maps 1.0
import QtMobilitySubset.location 1.1

TabbedPane {
    showTabsOnActionBar: false
    
    onCreationCompleted: {
        // this slot is called when declarative scene is created
        // write post creation initialization here
        console.log("TabbedPane - onCreationCompleted()")
        
        // enable layout to adapt to the device rotation
        // don't forget to enable screen rotation in bar-bescriptor.xml (Application->Orientation->Auto-orient)
        OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
    }
    Tab {
        title: qsTr("Stops")
        id: tab1
        NavigationPane {
            objectName: "navStops"
            Page {
                Container {  
                    Header {
                        title: "Search"
                    }
                    Container {
                        layout: StackLayout {
                            orientation: LayoutOrientation.LeftToRight
                        }
                        TextField {
                            id: textStopCode
                            textStyle.textAlign: TextAlign.Default
                        }
                        Button {
                            text: "Image"
                            onClicked: {
                            	ApplicationUI.showStopsList(textStopCode.text);
                            }
                        }
                    }
                    Header {
                        title: "Favorites"
                    }
                    ListView {
                        objectName: "favoriteStopsListView"
                        dataModel: ArrayDataModel {
                        	objectName: "favoriteStopsListModel"
                        }
                    }
                }       
            }
        }
    }
    Tab {
        title: qsTr("Test Data Load")
        Page {
            id: tab2
            actions: [
                // define the actions for first tab here
                ActionItem {
                    title: qsTr("Rotate")
                    onTriggered: {
                        //imgTab1.rotationZ = imgTab1.rotationZ + 90;
                    }
                },
                ActionItem {
                    title: qsTr("Break")
                    onTriggered: {
                        //imgTab1.imageSource = "asset:///images/picture1br.png";
                    }
                }
            ]
            Container {
                // define tab content here
                Label {
                    text: qsTr("Test Data")
                    horizontalAlignment: HorizontalAlignment.Center
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
                Button {
                    text: "Get Test Data"
                    verticalAlignment: VerticalAlignment.Bottom
                    horizontalAlignment: HorizontalAlignment.Center
                    onClicked: {
                        ApplicationUI.getStops();
                    }
                }
            }
        }
    }
    Tab {
        title: qsTr("Map")
        id: mapTab
        Page {
            Container {
                // The map view
                MapView {
                    objectName: "mapView"
                    horizontalAlignment: HorizontalAlignment.Fill
                    followedId: "device-location-id"
                    // Enforce the usage of the 3D rendering engine
                    //onCreationCompleted: setRenderEngine("RenderEngine3D")
                }
            }
        }
        attachedObjects: [
            PositionSource {
                id: positionSource
                updateInterval: 2000
                active: true
                onPositionChanged: {
                    ApplicationUI.updateDeviceLocation(
                    positionSource.position.coordinate.latitude, 
                    positionSource.position.coordinate.longitude);
                }
            }
        ]
    }
}





