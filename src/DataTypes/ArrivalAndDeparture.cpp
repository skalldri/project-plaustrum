/*
 * ArrivalAndDeparture.cpp
 *
 *  Created on: 2013-11-24
 *      Author: stuart
 */

#include "ArrivalAndDeparture.hpp"

const QVariantMap ArrivalAndDeparture::ToVariantMap()
{
	QVariantMap reply;

	reply["routeId"] = routeId;
	reply["routeShortName"] = routeShortName;
	reply["scheduledArrivalTime"] = scheduledArrivalTime;
	reply["predictedArrivalTime"] = predictedArrivalTime;
	reply["scheduledDepartureTime"] = scheduledDepartureTime;
	reply["predictedDepartureTime"] = predictedDepartureTime;

	return reply;
}



