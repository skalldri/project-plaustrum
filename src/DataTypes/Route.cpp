/*
 * Route.cpp
 *
 *  Created on: 2013-11-24
 *      Author: stuart
 */

#include "Route.hpp"

QVariantMap Route::ToVariantMap() const
{
	QVariantMap reply;

	reply["id"] = id;
	reply["name"] = name;
	reply["shortName"] = shortName;
	reply["longName"] = longName;
	reply["description"] = description;
	reply["type"] = type;
	reply["url"] = url;
	reply["color"] = color;
	reply["textColor"] = textColor;
	reply["agencyId"] = type;

	return reply;
}


