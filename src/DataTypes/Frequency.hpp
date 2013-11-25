/*
 * Frequency.h
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#ifndef FREQUENCY_H_
#define FREQUENCY_H_

#include <QVariantMap>

class Frequency {
public:
	unsigned int startTime;
	unsigned int endTime;
	unsigned int headway;
public:
	QVariantMap ToVariantMap() const;
};

#endif /* FREQUENCY_H_ */
