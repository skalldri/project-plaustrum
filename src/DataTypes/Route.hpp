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
#include <QUrl>
#include <QString>

class Route
{
	public:
		QString id;
		QString name; //Defaults to shortName.
		QString shortName; //Either shortName or longName required.
		QString longName;
		QString description;
		unsigned int type;
		QUrl url;
		QString color;
		QString textColor;
		QString agencyId;

	public:
		QVariantMap ToVariantMap() const;
};

typedef QList<Route> RouteList;

#endif /* ROUTE_HPP_ */
