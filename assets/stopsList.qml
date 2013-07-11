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
}

