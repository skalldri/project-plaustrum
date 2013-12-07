import bb.cascades 1.0

Page {
    Container {
        Container {
            layout: DockLayout { }
            preferredWidth: maxWidth
            Container {
                horizontalAlignment: HorizontalAlignment.Left
                layout:StackLayout {
                    orientation: LayoutOrientation.LeftToRight;                
                }
                Label{
                    objectName: "stopId"
                    text: "000"
                    verticalAlignment: VerticalAlignment.Center
                    textStyle.fontWeight: FontWeight.Bold
                    textStyle.textAlign: TextAlign.Center
                }
                Label{
                    objectName: "stopName"
                    text: "Name"
                    verticalAlignment: VerticalAlignment.Center
                }
            }
            Container {
                horizontalAlignment: HorizontalAlignment.Right
                ImageButton {
                    objectName: "refresh"
                    defaultImageSource: "asset:///icons/ic_reload.png"
                }
            }
        }
        Header {
            title: "Departure Times"
        }
        ListView {
            objectName: "departuresListView"
            dataModel: ArrayDataModel {
                objectName: "departuresListModel"
            }
            onTriggered: {
                //StopsView.showStop(indexPath);
            }
            listItemComponents: [
                ListItemComponent {
                    Container {
                        layout: DockLayout {
                        }
                        touchPropagationMode: TouchPropagationMode.Full
                        Container {
                            layout: DockLayout {
                            }
                            preferredWidth: 768; preferredHeight: 120    
                            Divider {
                                verticalAlignment: VerticalAlignment.Bottom
                                horizontalAlignment: HorizontalAlignment.Center  
                            }
                            Container {
                                verticalAlignment: VerticalAlignment.Center
                                layout:StackLayout {
                                    orientation: LayoutOrientation.LeftToRight;                
                                }
                                Label{
                                    text: ListItemData.routeShortName;
                                    verticalAlignment: VerticalAlignment.Center
                                    textStyle.fontWeight: FontWeight.Bold
                                    textStyle.textAlign: TextAlign.Center
                                }
                                Label{
                                    text: ListItemData.routeLongName
                                }
                            
                            }
                        } 
                    }
                }
            ]
        }
    }
}
