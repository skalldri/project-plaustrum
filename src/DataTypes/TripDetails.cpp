/*
 * TripDetails.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: nause
 */

#include "TripDetails.hpp"

QVariantMap TripDetails::ToVariantMap() const
{
	QVariantMap reply;

	reply["tripId"] = tripId;
	reply["serviceDate"] = serviceDate;
	reply["frequency"] = frequency.ToVariantMap();
	reply["status"] = status.ToVariantMap();
	reply["timeZone"] = timeZone;
	reply["tripStopTimes"] = QVariantList();

	foreach(StopTime stopTime, tripStopTimes)
		{
			reply["tripStopTimes"].toList().append(stopTime.ToVariantMap());
		}

	reply["situationIds"] = serviceDate;

	return reply;
}
