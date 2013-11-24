/*
 * Route.cpp
 *
 *  Created on: 2013-11-24
 *      Author: stuart
 */

#include "Route.hpp"

const QVariantMap Route::ToVariantMap()
{
	QVariantMap reply;

	reply["id"] = id;
	reply["shortName"] = shortName;
	reply["description"] = description;

	return reply;
}


