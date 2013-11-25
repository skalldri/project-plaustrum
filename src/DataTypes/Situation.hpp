/*
 * Situation.hpp
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#ifndef SITUATION_HPP_
#define SITUATION_HPP_

#include <QVariantMap>
#include "Affects.hpp"
#include "Consequence.hpp"

class Situation {
public:
	QString id;
	unsigned int creationTime;
	QString environmentReason;
	QString summary;
	QString description;
	Affects affects;
	ConsequenceList consequences;
public:
	QVariantMap ToVariantMap() const;
};

#endif /* SITUATION_HPP_ */
