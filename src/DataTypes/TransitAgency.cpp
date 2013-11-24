/*
 * TransitAgency.cpp
 *
 *  Created on: 2013-11-24
 *      Author: stuart
 */

#include "TransitAgency.hpp"

QVariantMap TransitAgency::ToVariantMap() const
{
	QVariantMap reply;

	reply["id"] = id;
	reply["name"] = name;
	reply["disclaimer"] = disclaimer;
	reply["lang"] = lang;
	reply["phone"] = phone;
	reply["privateService"] = privateService;
	reply["timezone"] = timezone;
	reply["url"] = url;
	reply["lat"] = lat;
	reply["lon"] = lon;
	reply["latSpan"] = latSpan;
	reply["lonSpan"] = lonSpan;

	return reply;
}
