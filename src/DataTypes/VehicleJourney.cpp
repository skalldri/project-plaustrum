/*
 * VehicleJourney.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#include "VehicleJourney.hpp"

QVariantMap VehicleJourney::ToVariantMap() const
{
	QVariantMap reply;

	reply["lineId"] = lineId;
	reply["direction"] = direction;
	reply["stopIds"] = QVariantList();
	foreach(QString stopId, stopIds)
	{
		reply["stopIds"].toList().append(stopId);
	}

	return reply;
}
