/*
 * Stops.cpp
 *
 *  Created on: 2013-11-24
 *      Author: stuart
 */

#include "Stop.hpp"

const QVariantMap Stop::ToVariantMap()
{
	QVariantMap reply;

	reply["id"] = id;
	reply["name"] = name;
	reply["lat"] = lat;
	reply["lon"] = lon;
	reply["direction"] = direction;
	reply["code"] = code;
	reply["locationType"] = locationType;
	reply["wheelchairBoarding"] = wheelchairBoarding;

	reply["routeInfo"] = QVariantList();

	foreach(Route r, routeInfo)
	{
		reply["routeInfo"].toList().append(r.ToVariantMap());
	}

	return reply;
}

