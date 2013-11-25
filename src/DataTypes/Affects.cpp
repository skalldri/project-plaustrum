/*
 * Affects.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#include "Affects.hpp"

QVariantMap Affects::ToVariantMap() const
{
	QVariantMap reply;
	reply["stops"] = QVariantList();
	foreach(Stop stop, stops)
	{
		reply["stops"].toList().append(stop.ToVariantMap());
	}
	reply["vehicleJourneys"] = QVariantList();
	foreach(VehicleJourney vehicleJourney, vehicleJourneys)
	{
		reply["vehicleJourneys"].toList().append(vehicleJourney.ToVariantMap());
	}
	return reply;
}

