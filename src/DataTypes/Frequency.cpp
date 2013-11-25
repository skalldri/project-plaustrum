/*
 * Frequency.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#include "Frequency.hpp"

QVariantMap Frequency::ToVariantMap() const
{
	QVariantMap reply;

	reply["startTime"] = startTime;
	reply["endTime"] = endTime;
	reply["headway"] = headway;

	return reply;
}

