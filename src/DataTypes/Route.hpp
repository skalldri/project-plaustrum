/*
 * Route.hpp
 *
 *  Created on: 2013-11-24
 *      Author: stuart
 */

#ifndef ROUTE_HPP_
#define ROUTE_HPP_

#include <QVariantMap>
#include <QList>

class Route
{
	public:
		QString shortName;
		QString id;
		QString description;
		//TODO: consider adding a URL data type here

	public:
		const QVariantMap ToVariantMap();
};

typedef QList<Route> RouteList;

#endif /* ROUTE_HPP_ */
