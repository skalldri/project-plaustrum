/*
 * TripDetails.hpp
 *
 *  Created on: Nov 29, 2013
 *      Author: nause
 */

#ifndef TRIPDETAILS_HPP_
#define TRIPDETAILS_HPP_

#include <QVariantMap>

#include "DataTypes/Frequency.hpp"
#include "DataTypes/StopTime.hpp"
#include "DataTypes/TripStatus.hpp"

//TODO: Add parse to JsonManager.

class TripDetails {
public:
	QVariantMap ToVariantMap() const;
private:
	QString tripId;
	unsigned int serviceDate; //Optional
	Frequency frequency; //Optional
	TripStatus status; //Optional
	QString timeZone;
	StopTimeList tripStopTimes;
	QString situationIds;
};

#endif /* TRIPDETAILS_HPP_ */
