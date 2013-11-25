/*
 * MapDataProvider.cpp
 *
 *  Created on: 2013-07-10
 *      Author: stuart
 */

#include "MapDataProvider.hpp"

MapDataProvider::MapDataProvider(const QString &id, bb::cascades::maps::MapView* map, JsonManager* json, QObject *parent)
  : bb::cascades::maps::DataProvider(id, parent)
{
	mapView = map;
	jsonManager = json;

	QObject::connect(jsonManager, SIGNAL(StopSearchReply(StopList)), this, SLOT(stopsFound(StopList)));
}

void MapDataProvider::viewUpdated()
{
	qDebug() << "View Updated!";

	bb::platform::geo::BoundingBox currBounds = mapView->boundingBox();
	bb::platform::geo::Point centerPoint = currBounds.center();
	jsonManager->GetStopByBoundedBox(centerPoint.latitude(), centerPoint.longitude(), currBounds.height(), currBounds.width());
}

void MapDataProvider::stopsFound(StopList list)
{
	foreach(Stop aStop, list)
	{
		bb::platform::geo::GeoLocation* newDrop = new bb::platform::geo::GeoLocation(aStop.id, aStop.name, bb::platform::geo::Point(aStop.lat, aStop.lon));
		this->add(newDrop);
	}
}

void MapDataProvider::mapTouched(bb::cascades::TouchEvent* event)
{
	qDebug() << "mapTouched";

	if(event->touchType() == bb::cascades::TouchType::Up)
		viewUpdated();
}
