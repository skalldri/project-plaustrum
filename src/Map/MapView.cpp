/*
 * MapView.cpp
 *
 *  Created on: 2013-07-10
 *      Author: stuart
 */

#include "MapView.hpp"

MapView::MapView(JsonManager * json, NavigationPane * navPaneInput)
{
		navPane = navPaneInput;
		qmlMapView = QmlDocument::create("asset:///mapView.qml");
		mapViewPage = qmlMapView->createRootObject<Page>();
		navPane->push(mapViewPage);
}

MapView::~MapView() {
	// TODO Auto-generated destructor stub
}

