/*
 * Affects.hpp
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#ifndef AFFECTS_HPP_
#define AFFECTS_HPP_

#include <QVariantMap>
#include <QList>
#include "DataTypes/Stop.hpp"
#include "DataTypes/VehicleJourney.hpp"

class Affects {
public:
	StopList stops;
	VehicleJourneyList vehicleJourneys;
public:
	QVariantMap ToVariantMap() const;
};

#endif /* AFFECTS_HPP_ */
