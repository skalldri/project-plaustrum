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

struct Stop_s
{
	QString id;
	double lat;
	double lon;
	QString direction;
	QString name;
	QString code;
	QString locationType;
	QString wheelchairBoarding;
	//TODO: Add route info here

} typedef Stop;


struct Route_s
{
	//TODO: fill in the Route Struct

} typedef Route;


#endif /* DATATYPES_HPP_ */
