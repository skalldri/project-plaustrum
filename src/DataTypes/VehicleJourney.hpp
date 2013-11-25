/*
 * VehicleJourney.hpp
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#ifndef VEHICLEJOURNEY_HPP_
#define VEHICLEJOURNEY_HPP_

#include <QVariantMap>
#include <QList>
#include <QStringList>

class VehicleJourney {
public:
	QString lineId;
	unsigned int direction;
	QStringList stopIds;
public:
	QVariantMap ToVariantMap() const;
};

typedef QList<VehicleJourney> VehicleJourneyList;

#endif /* VEHICLEJOURNEY_HPP_ */
