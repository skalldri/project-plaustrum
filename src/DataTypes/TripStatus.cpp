/*
 * TripStatus.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#include "TripStatus.hpp"

QVariantMap TripStatus::ToVariantMap() const {
	QVariantMap reply;

	reply["activeTripId"] = activeTripId;
	reply["blockTripSequence"] = blockTripSequence;
	reply["serviceDate"] = serviceDate;
	reply["frequency"] = frequency.ToVariantMap();
	reply["scheduledDistanceAlongTrip"] = scheduledDistanceAlongTrip;
	reply["totalDistanceAlongTrip"] = totalDistanceAlongTrip;
	reply["position"] = geoVariantMap(position);
	reply["orientation"] = orientation;
	reply["closestStop"] = closestStop;
	reply["closestStopTimeOffset"] = closestStopTimeOffset;
	reply["nextStop"] = nextStop;
	reply["nextStopTimeOffset"] = nextStopTimeOffset;
	reply["phase"] = phase;
	reply["status"] = status;
	reply["predicted"] = predicted;
	reply["lastUpdateTime"] = lastUpdateTime;
	reply["lastLocationUpdateTime"] = lastLocationUpdateTime;
	reply["lastKnownLocation"] = geoVariantMap(lastKnownLocation);
	reply["lastKnownOrientation"] = lastKnownOrientation;
	reply["distanceAlongTrip"] = distanceAlongTrip;
	reply["scheduleDeviation"] = scheduleDeviation;
	reply["vehicleId"] = vehicleId;
	reply["situationIds"] = situationIds.ToVariantMap();

	return reply;
}

QVariantMap TripStatus::geoVariantMap(QtMobilitySubset::QGeoCoordinate geoCoordinate) const
{
	QVariantMap geo;
	geo["lat"] = geoCoordinate.latitude();
	geo["lon"] = geoCoordinate.longitude();
	return geo;
}

