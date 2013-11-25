/*
 * Consequence.hpp
 *
 *  Created on: Nov 24, 2013
 *      Author: nause
 */

#ifndef CONSEQUENCE_HPP_
#define CONSEQUENCE_HPP_

#include <QVariantMap>
#include <QStringList>
#include <QList>

class Consequence {
public:
	QString condition;
	QString diversionPath;
	QStringList diversionStopIds;
public:
	QVariantMap ToVariantMap() const;
};

typedef QList<Consequence> ConsequenceList;

#endif /* CONSEQUENCE_HPP_ */
