/*
 * TransitAgency.h
 *
 *  Created on: 2013-11-24
 *      Author: stuart
 */

#ifndef TRANSITAGENCY_HPP_
#define TRANSITAGENCY_HPP_

#include <QVariantMap>

class TransitAgency
{
	public:
		QString id;
		QString name;
		QString disclaimer;
		QString lang;
		QString phone;
		bool privateService;
		QString timezone;
		QString url;
		double lat;
		double lon;
		double latSpan;
		double lonSpan;

	public:
		QVariantMap ToVariantMap();
};


#endif /* TRANSITAGENCY_HPP_ */
