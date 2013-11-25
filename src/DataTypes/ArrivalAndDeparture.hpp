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
#include "Frequency.hpp"
#include "TripStatus.hpp"

class ArrivalAndDeparture
{
	public:
		QString routeId;
		QString tripId;
		unsigned int serviceDate;
		QString stopId;
		unsigned int stopSequence;
		unsigned int blockTripSequence;
		QString routeShortName; //OPTIONAL
		QString routeLongName; //OPTIONAL
		QString tripHeadsign; //OPTIONAL
		bool arrivalEnabled;
		bool departureEnabled;
		unsigned int scheduledArrivalTime;
		unsigned int scheduledDepartureTime;
		Frequency frequency; //OPTIONAL
		bool predicted;
		unsigned int predictedArrivalTime;
		unsigned int predictedDepartureTime;
		unsigned int distanceFromStop;
		unsigned int numberOfStopsAway;
		TripStatus tripStatus; //OPTIONAL
	public:
		QVariantMap ToVariantMap() const;
};

typedef QList<ArrivalAndDeparture> ArrivalAndDepartureList;

#endif /* ARRIVALANDDEPARTURE_HPP_ */
