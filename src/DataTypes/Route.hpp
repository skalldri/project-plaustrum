/*
 * Route.hpp
 *
 *  Created on: 2013-11-24
 *      Author: stuart
 */

#ifndef ROUTE_HPP_
#define ROUTE_HPP_

#include <QVariantMap>

class Route
{
	public:
		QString shortName;
		QString id;
		QString description;
		//TODO: consider adding a URL data type here

	public:
		QVariantMap ToVariantMap();
};

#endif /* ROUTE_HPP_ */
