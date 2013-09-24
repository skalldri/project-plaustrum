/*
 * MapView.hpp
 *
 *  Created on: 2013-07-10
 *      Author: stuart
 */

#ifndef MAPVIEW_HPP_
#define MAPVIEW_HPP_

#include <QObject>
#include <QMetaType>
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/Button>
#include <bb/cascades/NavigationPane>
#include "src/Stops/StopsView.hpp"
#include "AppSettings.hpp"
#include "JsonManager.hpp"
#include "DataTypes.hpp"

class MapView {
public:
	MapView(JsonManager * json, NavigationPane * navPane);
	virtual ~MapView();

public:
	QmlDocument * qmlMapView;
	Page * mapViewPage;
	NavigationPane * navPane;
};

#endif /* MAPVIEW_HPP_ */
