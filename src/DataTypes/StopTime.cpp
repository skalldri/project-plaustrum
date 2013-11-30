/*
 * StopTime.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: nause
 */

#include "StopTime.hpp"

QVariantMap StopTime::ToVariantMap() const
{
	QVariantMap reply;

	reply["arrivalTime"] = arrivalTime;
	reply["departureTime"] = departureTime;
	reply["stopId"] = stopId;

	return reply;
}
