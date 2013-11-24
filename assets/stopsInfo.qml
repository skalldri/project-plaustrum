import bb.cascades 1.0

Page {
    Container {
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
                    Container{
                        layout: DockLayout {}
                        touchPropagationMode: TouchPropagationMode.Full;
                        Container{
                            layout: DockLayout {}
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
                                    text: ListItemData.routeId;
                                    verticalAlignment: VerticalAlignment.Center
                                    textStyle.fontWeight: FontWeight.Bold
                                    textStyle.textAlign: TextAlign.Center
                                    textStyle.fontSize: FontSize.XXLarge
                                }
                                Container {
                                    bottomPadding: 10
                                    verticalAlignment: VerticalAlignment.Center
                                    Label{
                                        text: ListItemData.routeShortName
                                    }
                                }
                            }
                        } 
                    }
                }
            ]
        }
    }
}
