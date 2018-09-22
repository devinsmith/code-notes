/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QML LOCATION
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// • MapRectangle, MapPolygon, MapCircle etc. cannot have children except MouseArea which resizes with map
// • MapItemGroup as a drag target can cause some move artefacts
// • All items need to be added to map before they are rendered, ensure mapReady is true before this happens

// COORDINATE
// import QtPositioning 5.11
// Auto converts to/from QGeoCoordinate
property var coord: QtPositioning.coordinate()
property var coord: QtPositioning.coordinate(latitude, longitue, altitude)
coord.altitude // double
coord.isValid // const bool
coord.latitude // double
coord.longitude // double
coord.distanceTo(coord2) // returns real distance in meters
coord.azimuth(coord2) // returns real angle [0, 360) of vector betweens coordinate to up vector
coord.atDistanceAndAzimuth(distance, angle) // returns coord distance (m) along vector at angle from up vector
    
------------------------------------------------------------------------------------------------------------

// MAP
// import QtLocation 5.11
// Values like center will not be valid until mapReady is true
Map {
    activeMapType: MapType {}
    bearing: 0.0 // Default, bearing for map between [0, 360], must be supported by plugin used
    center: QtPositioning.coordinate(0, 0) // Positions the map at coord, invalid coord is ignored
    color: "red" // Background color of map
    copyrightsVisible: true // Default, render copyright overlap
    fieldOfView: 45.0 // Default degrees, field of view of the camera used to look at the map
    mapParameters
    mapReady 
    maximumFieldOfView
    maximumTilt
    maximumZoomLevel
    minimumFieldOfView
    minimumTilt
    minimumZoomLevel
    supportedMapTypes
    tilt
    visibleRegion
    zoomLevel
        
    // MapGestureArea
    // Provides Map gesture interaction
    gesture {
        acceptedGestures
        enabled
        flickDeceleration
        maximumZoomLevelChange
        panActive
        pinchActive
        preventStealing 
        rotationActive
        tiltActive
        onFlickFinished()
        onFlickStarted()
        onPanFinished()
        onPanStarted()
        onPinchFinished: { event }
        onPinchStarted: { event }
        onPinchUpdated: { event }
        onRotationFinished: { event }
        onRotationStarted: { event }
        onRotationUpdated: { event }
        onTiltFinished: { event }
        onTiltStarted: { event }
        onTiltUpdated: { event }
    }
        
    plugin: Plugin {
        name: "osm" // "mapboxgl", "esri", "osm" or custom
    }
}

map.mapItems // list<MapItem> of all items that have been added to map
map.error // Last Mapping Provider Error Enum
map.errorString // Last mapping provider error
map.addMapItem(item) // Add MapItem
map.addMapItemGroup(itemGroup) // Add MapItemGroup
map.addMapItemView(itemView) // Add MapItemView
map.addMapParameter(parameter) // Add MapParameter
map.alignCoordinateToPoint(coordinate, point)
map.clearData()
map.clearMapItems()
map.clearMapParameters()
map.fitViewportToMapItems()
map.fitViewportToVisibleMapItems()
map.fromCoordinate(coordinate, clipToViewPort) // Returns point, out of bounds is NaN unless clip is false
map.pan(dx, dy)
map.prefetchData()
map.removeMapItem(item) // Remove MapItem
map.removeMapItemGroup(itemGroup) // Remove MapItemGroup
map.removeMapItemView(itemView) // Remove MapItemView
map.removeMapParameter(parameter) // Remove MapParameter
map.setBearing(bearing, coordinate)
map.toCoordinate(position, clipToViewPort) // Returns coordinate, out of bounds is NaN unless clip is false

// Mapping Provider Error Enum
Map.NoError                          // No error has occurred
Map.NotSupportedError                // Plugin property was not set or no mapping manager in plugin
Map.UnknownParameterError            // Plugin did not recognize one of the parameters it was given
Map.MissingRequiredParameterError    // The plugin did not find one of the parameters it was expecting
Map.ConnectionError                  // The plugin could not connect to its backend service or database
    
------------------------------------------------------------------------------------------------------------    
    
// MAPCIRCLE
// import QtLocation 5.11
// Auto transforms with Map if added to it
MapCircle {
    center: QtPositioning.coordinate()
    border.width
    border.color
    color
    opacity
    radius
}

------------------------------------------------------------------------------------------------------------

// MAPRECTANGLE
// import QtLocation 5.11
// Auto transforms with Map if added to it
MapRectangle {
    border.width 
    border.color
    bottomRight
    color
    opacity
    topLeft    
}

------------------------------------------------------------------------------------------------------------

// MAPPOLYGON
// import QtLocation 5.11
// Auto transforms with Map if added to it
MapPolygon {
    border.width
    border.color
    color
    path: [] // QVariantList with QGeoLocation/QML coord, Must reassign whole list when modifying any item
}

------------------------------------------------------------------------------------------------------------
    
// MAPPOLYLINE
// import QtLocation 5.11
// Auto transforms with Map if added to it
MapPolyLine {
    line.width
    line.color
    path: [] // QVariantList with QGeoLocation/QML coord, Must reassign whole list when modifying any item
}

line.addCoordinate(coordinate)
line.containsCoordinate(coordinate)
line.coordinateAt(index)
line.insertCoordinate(index, coordinate)
line.pathLength()
line.removeCoordinate(index)
line.removeCoordinate(coordinate)
line.replaceCoordinate(index, coordinate)
line.setPath(geopath path)

------------------------------------------------------------------------------------------------------------

// MAPQUICKITEM
// import QtLocation 5.11
// Auto translates (no scaling) with Map if added to it
// Requires zoomLevel to be set for scaling
MapQuickItem {
    anchorPoint.x: sourceItem.width / 2   // Position on sourceItem to anchor to coordinate
    anchorPoint.y: sourceItem.height / 2  // Position on sourceItem to anchor to coordinate
    coordinate: QtPositioning.coordinate(0, 0)
    sourceItem: Item {} // QML Item to render
    zoomLevel: map.zoomLevel // Size to render at zoom, set to map's level to scale with map
}    

------------------------------------------------------------------------------------------------------------

// MAPITEMGROUP 
// import QtLocation 5.11
// Groups any map items together, can add to map as a single group
MapItemGroup {
}

------------------------------------------------------------------------------------------------------------
    
// POSITIONSOURCE
// import QtPositioning 5.11
// Provides the device's current position, C++ equivalent is QGeoPositionInfoSource 
PositionSource {
    updateInterval: 1000 // When to query the user position again
    active: true // Whether to query user position
    preferredPositioningMethods: PositionSource.AllPositioningMethods // Position Source Method Enum
    onUpdateTimeout: {} // emitted if the position could not be retrieved within a certain amount of time
}

src.position // Last known device position, updates in intervals when start() is called
src.sourceError // Position Source Error Enum
src.supportedPositioningMethods // Position Source Method Enum
src.start() // Start polling for device position
src.stop() // Stop polling for device position
src.update() // Request a single update

// Position Source Method Enum
PositionSource.NoPositioningMethods            // No positioning methods supported (no source)
PositionSource.SatellitePositioningMethods     // Satellite-based positioning methods such as GPS are supported
PositionSource.NonSatellitePositioningMethods  // Non-satellite-based methods are supported
PositionSource.AllPositioningMethods           // Both satellite-based and non-satellite methods are supported

// Position Source Error Enum
PositionSource.AccessError         // Application lacked the required privileges
PositionSource.ClosedError         // Connection / location services were closed
PositionSource.NoError             // No error has occurred
PositionSource.UnknownSourceError  // An unidentified error occurred
PositionSource.SocketError         // An error occurred while connecting to an nmea source using a socket
