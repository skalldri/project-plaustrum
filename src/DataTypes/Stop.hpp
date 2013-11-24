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

class Stop
{
	public:
		QString id;
		double lat;
		double lon;
		QString direction;
		QString name;
		QString code;
		QString locationType;
		QString wheelchairBoarding;
		QList<Route> routeInfo;
		//TODO: Add route info here

	public:
		QVariantMap ToVariantMap();
};

#endif /* STOP_HPP_ */
