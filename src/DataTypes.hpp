/*
 * DataTypes.hpp
 *
 *  Created on: 2013-06-03
 *      Author: stuart
 */

#ifndef DATATYPES_HPP_
#define DATATYPES_HPP_

struct TransitAgency_s
{
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

} typedef TransitAgency;


#endif /* DATATYPES_HPP_ */
