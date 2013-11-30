/*
 * Stop.hpp
 *
 *  Created on: 2013-11-24
 *      Author: stuart
 */

#ifndef STOP_HPP_
#define STOP_HPP_

#include <QVariantMap>
#include <DataTypes/Route.hpp>
#include <QList>

class Stop
{
	public:
		QString id;
		double lat;
		double lon;
		QString direction;
		QString name;
		QString code;
		unsigned int locationType;
		QString wheelchairBoarding;
		RouteList routeInfo;
		//TODO: Add route info here

	public:
		QVariantMap ToVariantMap() const;
};

typedef QList<Stop> StopList;

#endif /* STOP_HPP_ */
