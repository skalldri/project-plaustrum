/*
 * DataTypes.hpp
 *
 *  Created on: 2013-06-03
 *      Author: stuart
 */

#ifndef DATATYPES_HPP_
#define DATATYPES_HPP_

struct Route_s
{
	QString shortName;
	QString id;
	QString description;

	//TODO: consider adding a URL data type here

} typedef Route;

struct ArrivalAndDeparture_s
{
	QString routeId;
	QString routeShortName;
	unsigned int scheduledArrivalTime;
	unsigned int predictedArrivalTime;
	unsigned int scheduledDepartureTime;
	unsigned int predictedDepartureTime;

} typedef ArrivalAndDeparture;

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
	QList<Route> routeInfo;
	//TODO: Add route info here

} typedef Stop;





#endif /* DATATYPES_HPP_ */
