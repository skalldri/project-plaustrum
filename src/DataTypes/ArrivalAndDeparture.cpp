/*
 * ArrivalAndDeparture.cpp
 *
 *  Created on: 2013-11-24
 *      Author: stuart
 */

#include "ArrivalAndDeparture.hpp"

QVariantMap ArrivalAndDeparture::ToVariantMap() const
{
	QVariantMap reply;

	reply["routeId"] = routeId;
	reply["tripId"] = tripId;
	reply["serviceDate"] = serviceDate;
	reply["stopId"] = stopId;
	reply["stopSequence"] = stopSequence;
	reply["blockTripSequence"] = blockTripSequence;
	reply["routeShortName"] = routeShortName;
	reply["routeLongName"] = routeLongName;
	reply["tripHeadsign"] = tripHeadsign;
	reply["arrivalEnabled"] = arrivalEnabled;
	reply["departureEnabled"] = departureEnabled;
	reply["scheduledArrivalTime"] = scheduledArrivalTime;
	reply["scheduledDepartureTime"] = scheduledDepartureTime;
	reply["frequency"] = frequency.ToVariantMap();
	reply["predicted"] = predicted;
	reply["predictedArrivalTime"] = predictedArrivalTime;
	reply["predictedDepartureTime"] = predictedDepartureTime;
	reply["distanceFromStop"] = distanceFromStop;
	reply["numberOfStopsAway"] = numberOfStopsAway;
	reply["tripStatus"] = tripStatus.ToVariantMap();

	return reply;
}



