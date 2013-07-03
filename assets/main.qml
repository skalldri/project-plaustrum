// Tabbed Pane project template
import bb.cascades 1.0

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
        NavigationPane {
            id: navStops
            Page {
                Container {
                    Header {
                        title: "Search"
                    }
                    
                    Container {
                        TextField {
                            id: textStopId
                        }
                        Button {
                            text: "Image"
                            onClicked: {
                                var page = stopsListDefinition.createObject();
                                navStops.push(page);
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
                actions: [
                    ActionItem {
                        title: "Delete"
                        ActionBar.placement: ActionBarPlacement.OnBar
                        onTriggered: {
                            var page = stopsListDefinition.createObject();
                            navStops.push(page);
                        }
                        
                        attachedObjects: ComponentDefinition {
                            id: stopsListDefinition
                            source: "stopsList.qml"
                        }
                    }
                ]
            }
            onPopTransitionEnded: {
                page.destroy();
            }
        }
    }
    Tab {
        title: qsTr("Test Data Load")
        Page {
            id: tab1
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
                    objectName: "getTestData"
                    text: "Get Test Data"
                    verticalAlignment: VerticalAlignment.Bottom
                    horizontalAlignment: HorizontalAlignment.Center
                }
            }
        }
    }
    Tab {
        title: qsTr("Tab 3")
        Page {
            id: tab3
            Container {
                // define tab content here
                Label {
                    text: qsTr("Tab 3 title")
                    horizontalAlignment: HorizontalAlignment.Center
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
                Container {
                    layout: DockLayout {
                    
                    }
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1.0
                    }
                    verticalAlignment: VerticalAlignment.Fill
                    horizontalAlignment: HorizontalAlignment.Fill
                    Label {
                        text: qsTr("Tab 3 content")
                        verticalAlignment: VerticalAlignment.Center
                        horizontalAlignment: HorizontalAlignment.Center
                        textStyle {
                            base: SystemDefaults.TextStyles.BodyText
                        }
                    }
                }
            }
        }
    }
}
