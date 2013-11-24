/*
 * JsonManager.hpp
 *
 *  Created on: 2013-05-14
 *      Author: stuart
 */

#ifndef JSONMANAGER_HPP_
#define JSONMANAGER_HPP_

#include "AppSettings.hpp"
#include "DataTypes.hpp"
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <bb/data/JsonDataAccess>
#include <QVariant>
#include <QtCore>
#include <QUrl>

#define DATA_TYPE "json"
#define KEY_URL "?key="

#define ALL_AGENCIES "agencies-with-coverage"
#define ALL_STOPS "stop-ids-for-agency"
#define STOP_SEARCH "stops-for-location"
#define STOPS_FOR_ROUTE "stops-for-route"
#define ROUTE_SEARCH "routes-for-location"
#define ARRIVALS_AND_DEPARTURES "arrivals-and-departures-for-stop"

using namespace bb::data;

//FIXME: This class should be a singleton

class JsonManager : public QObject
{
	Q_OBJECT

public:
	JsonManager(AppSettings* appSettings);
	virtual ~JsonManager();

public slots:
	void GetAllStops(QString agencyID);
	void GetAllAgencies();
	void GetStopByCode(QString stopCode);
	void GetStopByRadius(double lat, double lon, double radius = -1.0);
	void GetStopByBoundedBox(double lat, double lon, double latSpan, double lonSpan);
	void GetStopsForRoute(QString routeId);
	void GetRouteByBoundedBox(double lat, double lon, double latSpan, double lonSpan);
	void GetRouteByRadius(double lat, double lon, double radius);
	void GetRouteByCode(QString routeCode, double lat, double lon);
	void GetArrivalsAndDepartures(QString stopId, int minutesBefore = 5, int minutesAfter = 32);

private:
	QVariant validateReply(QNetworkReply* reply);

	Stop parseStop(QVariantMap stopMap);
	Route parseRoute(QVariantMap routeEntry);
	ArrivalAndDeparture parseArrivalAndDeparture(QVariantMap arrivalAndDepartureMap);

	void processAllAgenciesReply(QVariant input);
	void processAllStopsReply(QVariant input);
	void processStopSearchReply(QVariant input);
	void processStopsForRouteReply(QVariant input);
	void processRouteSearchReply(QVariant input);
	void processArrivalsAndDeparturesReply(QVariant input);

	void getUrl(QString function, QString specifier = "", QString parameters = "");

	AppSettings* mySettings;
	QNetworkAccessManager* serverAccess;

private slots:
	void networkReply();

signals:
	void error(QNetworkReply::NetworkError);
	void variantReplyMap(QVariant);
	void testReplyMap(QVariant);
	void ApiFailure(int); //Returns the error code from the API
	void AllAgenciesReply(QList<TransitAgency>); //Returns a list of transit agencies
	//TODO: Make QList<Stop> function
	void StopSearchReply(QList<Stop>); //Returns a list of stops
	void StopsForRouteReply(QList<Stop>, QString); //Returns a list of stops and the Route ID it was called for
	void RouteSearchReply(QList<Route>); //Returns a list of routes
	void ArrivalsAndDeparturesReply(QList<ArrivalAndDeparture>, Stop); //Returns a list of ArrivalAndDeparture objects for a stop, along with a reference to the stop

};

#endif /* JSONMANAGER_HPP_ */
