import QtQuick 2.0
import QtLocation 5.11
import QtPositioning 5.11

Rectangle
{
    id:window

    property double latitude:51.5072
    property double longitude:0.1276

    property Component locationmaker: maker
    Plugin
    {
        id:googlemapview
        name:"osm"
    }
    Map
    {
        id:mapview
        anchors.fill: parent
        plugin: googlemapview
        center: QtPositioning.coordinate(latitude, longitude)
        zoomLevel: 5
    }
}
