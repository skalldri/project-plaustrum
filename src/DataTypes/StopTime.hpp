/*
 * StopTime.h
 *
 *  Created on: Nov 29, 2013
 *      Author: nause
 */

#ifndef STOPTIME_H_
#define STOPTIME_H_

#include <QList>
#include <QVariantMap>

class StopTime {
public:
	QVariantMap ToVariantMap(void) const;
private:
	unsigned int arrivalTime;
	unsigned int departureTime;
	QString stopId;
};

typedef QList<StopTime> StopTimeList;

#endif /* STOPTIME_H_ */
