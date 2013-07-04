import bb.cascades 1.0

Page {
    Container {
        Header {
            title: "Search Results"
        }
        ListView {
            objectName: "stopsListView"
            dataModel: ArrayDataModel {
                objectName: "stopsListModel"
            }
        }
    }
    
    paneProperties: NavigationPaneProperties {
        backButton: ActionItem {
            title: "Back"
            onTriggered: {
                navStops.pop();
            }
        }
    }
}

