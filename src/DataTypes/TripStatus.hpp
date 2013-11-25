/*
 * TripStatus.hpp
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#ifndef TRIPSTATUS_HPP_
#define TRIPSTATUS_HPP_

#include <QVariantMap>
#include <QList>
#include <QtLocationSubset/QGeoCoordinate>
#include "Frequency.hpp"
#include "Situation.hpp"

class TripStatus {
public:
	QString activeTripId;
	unsigned int blockTripSequence;
	unsigned int serviceDate;
	Frequency frequency; //OPTIONAL
	unsigned int scheduledDistanceAlongTrip; //OPTIONAL
	unsigned int totalDistanceAlongTrip;
	QtMobilitySubset::QGeoCoordinate position; //OPTIONAL
	unsigned int orientation; //OPTIONAL
	QString closestStop;
	unsigned int closestStopTimeOffset;
	QString nextStop; //OPTIONAL
	unsigned int nextStopTimeOffset; //OPTIONAL
	QString phase;
	QString status;
	bool predicted;
	unsigned int lastUpdateTime;
	unsigned int lastLocationUpdateTime;
	QtMobilitySubset::QGeoCoordinate lastKnownLocation; //OPTIONAL
	unsigned int lastKnownOrientation; //OPTIONAL
	unsigned int distanceAlongTrip;
	unsigned int scheduleDeviation;
	QString vehicleId; //OPTIONAL
	Situation situationIds; //OPTIONAL
public:
	QVariantMap ToVariantMap() const;
private:
	QVariantMap geoVariantMap(QtMobilitySubset::QGeoCoordinate geoCoordinate) const;
};

#endif /* TRIPSTATUS_HPP_ */
