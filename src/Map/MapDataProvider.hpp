/*
 * MapDataProvider.hpp
 *
 *  Created on: 2013-07-10
 *      Author: stuart
 */

#ifndef MAPDATAPROVIDER_HPP_
#define MAPDATAPROVIDER_HPP_

#include <QObject>
#include <QMetaType>
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/Button>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/maps/DataProvider>
#include <bb/cascades/maps/MapView>
#include <bb/cascades/maps/MapData>
#include <bb/platform/geo/GeoLocation>
#include <bb/cascades/TouchEvent>

#include "AppSettings.hpp"
#include "JsonManager.hpp"
#include "DataTypes.hpp"

class MapDataProvider: public bb::cascades::maps::DataProvider
{
	Q_OBJECT

	public:
		MapDataProvider(const QString &id, bb::cascades::maps::MapView* map, JsonManager* json, QObject *parent=0);

	public slots:
		void viewUpdated();
		void mapTouched(bb::cascades::TouchEvent*);

	private:
		bb::cascades::maps::MapView* mapView;
		JsonManager* jsonManager;

	private slots:
		void stopsFound(StopList list);
};

#endif /* MAPDATAPROVIDER_HPP_ */
