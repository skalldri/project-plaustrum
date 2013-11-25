/*
 * Situation.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#include "Situation.hpp"

QVariantMap Situation::ToVariantMap() const
{
	QVariantMap reply;

	reply["id"] = id;
	reply["creationTime"] = creationTime;
	reply["environmentReason"] = environmentReason;
	reply["summary"] = summary;
	reply["description"] = description;
	reply["affects"] = affects.ToVariantMap();
	reply["consequences"] = QVariantList();
	foreach(Consequence consequence, consequences)
	{
		reply["consequences"].toList().append(consequence.ToVariantMap());
	}

	return reply;
}

