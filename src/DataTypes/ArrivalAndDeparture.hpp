/*
 * ArrivalAndDeparture.hpp
 *
 *  Created on: 2013-11-24
 *      Author: stuart
 */

#ifndef ARRIVALANDDEPARTURE_HPP_
#define ARRIVALANDDEPARTURE_HPP_

#include <QVariantMap>
#include <QList>

class ArrivalAndDeparture
{
	public:
		QString routeId;
		QString routeShortName;
		unsigned int scheduledArrivalTime;
		unsigned int predictedArrivalTime;
		unsigned int scheduledDepartureTime;
		unsigned int predictedDepartureTime;

	public:
		QVariantMap ToVariantMap() const;
};

typedef QList<ArrivalAndDeparture> ArrivalAndDepartureList;

#endif /* ARRIVALANDDEPARTURE_HPP_ */
