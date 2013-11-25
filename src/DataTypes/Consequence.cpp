/*
 * Consequence.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#include "Consequence.hpp"

QVariantMap Consequence::ToVariantMap() const
{
	QVariantMap reply;

	reply["condition"] = condition;
	reply["diversionPath"] = diversionPath;
	reply["diversionStopIds"] = QVariantList();
	foreach(QString diversionStopId, diversionStopIds)
	{
		reply["diversionStopIds"].toList().append(diversionStopId);
	}

	return reply;
}
