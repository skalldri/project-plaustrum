import bb.cascades 1.0
import bb.cascades.maps 1.0

Page {
    Container {
        // The map view
        MapView {
            objectName: "mapView"

            horizontalAlignment: HorizontalAlignment.Fill

            // Enforce the usage of the 3D rendering engine
            //onCreationCompleted: setRenderEngine("RenderEngine3D")
        }
    }
}
