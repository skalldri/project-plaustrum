/*
 * JsonManager.cpp
 *
 *  Created on: 2013-05-14
 *      Author: stuart
 */

#include "JsonManager.hpp"

JsonManager::JsonManager(AppSettings* myApp)
{
	//Create network manager
	serverAccess = new QNetworkAccessManager(this);
	mySettings = myApp;
}

void JsonManager::getUrl(QString function, QString specifier, QString parameters)
{
	QString option = "";

	if(specifier != "" && !specifier.isEmpty())
	{
		option = "/" + specifier;
	}

	QString URL = mySettings->GetAPIURlBase() + function + option + "." + DATA_TYPE + KEY_URL + mySettings->GetAPIKey() + parameters;

	qDebug() << URL;

	QNetworkRequest req;
	req.setUrl(QUrl(URL));

	QNetworkReply* myReply = serverAccess->get(req);
	connect(myReply, SIGNAL(finished()), this, SLOT(networkReply()));
}

void JsonManager::GetAllAgencies()
{
	getUrl(ALL_AGENCIES);
}

void JsonManager::GetArrivalsAndDepartures(QString stopId, int minutesBefore, int minutesAfter)
{
	QString request = "";

	if(minutesBefore != 5)
	{
		request += "&minutesBefore=" + QString().number(minutesBefore);
	}

	if(minutesAfter != 35)
	{
		request += "&minutesAfter=" + QString().number(minutesAfter);
	}

	getUrl(ARRIVALS_AND_DEPARTURES, stopId, request);
}

void JsonManager::GetStopByCode(QString stopCode)
{
	//TODO: error checking of input
	//TODO: real lat and lon? take from the device GPS

	getUrl(STOP_SEARCH, "", "&lat=0&lon=0&query=" + stopCode);
}

void JsonManager::GetStopByRadius(double lat, double lon, double radius)
{
	//TODO: error checking of input
	QString request = "&lat=" + QString().number(lat) + "&lon=" + QString().number(lon);

	if(radius > 0)
	{
		request += "&radius=" + QString().number(radius);
	}

	getUrl(STOP_SEARCH, "", request);
}

void JsonManager::GetStopByBoundedBox(double lat, double lon, double latSpan, double lonSpan)
{
	//TODO: error checking of input

	QString request = "&lat=" + QString().number(lat) + "&lon=" + QString().number(lon) +
			"&latSpan=" + QString().number(latSpan) + "&lonSpan=" + QString().number(lonSpan);

	getUrl(STOP_SEARCH, "", request);
}

void JsonManager::GetRouteByCode(QString routeCode, double lat, double lon)
{
	//TODO: error checking of input
	//TODO: real lat and lon? take from the device GPS
	QString request = "&lat=" + QString().number(lat) + "&lon=" + QString().number(lon) + "&query=" + routeCode;

	getUrl(ROUTE_SEARCH, "", request);
}

void JsonManager::GetRouteByRadius(double lat, double lon, double radius)
{
	//TODO: error checking of input
	QString request = "&lat=" + QString().number(lat) + "&lon=" + QString().number(lon);

	if(radius > 0)
	{
		request += "&radius=" + QString().number(radius);
	}

	getUrl(ROUTE_SEARCH, "", request);
}

void JsonManager::GetRouteByBoundedBox(double lat, double lon, double latSpan, double lonSpan)
{
	//TODO: error checking of input

	QString request = "&lat=" + QString().number(lat) + "&lon=" + QString().number(lon) +
			"&latSpan=" + QString().number(latSpan) + "&lonSpan=" + QString().number(lonSpan);

	getUrl(ROUTE_SEARCH, "", request);
}

void JsonManager::GetAllStops(QString agencyId)
{
	//TODO: Check agencyID is valid (we've seen it before)
	getUrl(ALL_STOPS, agencyId);
}

void JsonManager::GetStopsForRoute(QString routeId)
{
	//TODO: Check routeID is valid (we've seen it before)
	getUrl(STOPS_FOR_ROUTE, routeId);
}

void JsonManager::processStopsForRouteReply(QVariant input)
{
	QList<Stop> outputList;

	if(input.toMap()["code"].toInt() != 200)
	{
		qWarning() << "Stops for Route Reply Status Code " << input.toMap()["code"].toInt();
		return;
	}

	foreach(QVariant item, input.toMap()["data"].toMap()["stops"].toList())
	{
		QVariantMap stopMap = item.toMap();
		outputList.append(parseStop(stopMap));
	}

	emit StopsForRouteReply(outputList, input.toMap()["data"].toMap()["entry"].toMap()["routeId"].toString());
}

void JsonManager::processAllAgenciesReply(QVariant input)
{
	QList<TransitAgency> outputList;

	if(input.toMap()["code"].toInt() != 200)
	{
		qWarning() << "All-Agencies Reply Status Code " << input.toMap()["code"].toInt();
		return;
	}

	foreach(QVariant item, input.toMap()["data"].toList())
	{
		QVariantMap agencyMap = item.toMap()["agency"].toMap();

		TransitAgency localAgency;
		localAgency.disclaimer = agencyMap["disclaimer"].toString();
		localAgency.id = agencyMap["id"].toString();
		localAgency.lang = agencyMap["lang"].toString();
		localAgency.name = agencyMap["name"].toString();
		localAgency.phone = agencyMap["phone"].toString();
		localAgency.privateService = agencyMap["privateService"].toBool();
		localAgency.timezone = agencyMap["timezone"].toString();
		localAgency.url = agencyMap["url"].toString();

		localAgency.lat = item.toMap()["lat"].toDouble();
		localAgency.lon = item.toMap()["lon"].toDouble();
		localAgency.latSpan = item.toMap()["latSpan"].toDouble();
		localAgency.lonSpan = item.toMap()["lonSpan"].toDouble();

		qDebug() << "Found agency " << localAgency.name << " with ID " << localAgency.id;

		outputList.append(localAgency);
	}

	emit AllAgenciesReply(outputList);
}

void JsonManager::processStopSearchReply(QVariant input)
{
	QList<Stop> outputList;

	if(input.toMap()["code"].toInt() != 200)
	{
		qWarning() << "Stop Search Reply Status Code " << input.toMap()["code"].toInt();
		return;
	}

	foreach(QVariant item, input.toMap()["data"].toMap()["stops"].toList())
	{
		QVariantMap stopMap = item.toMap();
		outputList.append(parseStop(stopMap));
	}

	emit StopSearchReply(outputList);
}

void JsonManager::processRouteSearchReply(QVariant input)
{
	QList<Route> outputList;

	if(input.toMap()["code"].toInt() != 200)
	{
		qWarning() << "Stop Search Reply Status Code " << input.toMap()["code"].toInt();
		return;
	}

	foreach(QVariant item, input.toMap()["data"].toMap()["routes"].toList())
	{
		outputList.append(parseRoute(item.toMap()));
	}

	emit RouteSearchReply(outputList);
}

void JsonManager::processArrivalsAndDeparturesReply(QVariant input)
{
<<<<<<< HEAD
	QList<QVariantMap> outputList;
=======
	QList<ArrivalAndDeparture> outputList;
	Stop myStop;
>>>>>>> master

	if(input.toMap()["code"].toInt() != 200)
	{
		qWarning() << "Arrivals And Departure Reply Status Code " << input.toMap()["code"].toInt();
		return;
	}

	myStop = parseStop(input.toMap()["data"].toMap()["stop"].toMap());

	foreach(QVariant item, input.toMap()["data"].toMap()["arrivalsAndDepartures"].toList())
	{
		outputList.append(parseArrivalAndDeparture(item.toMap()));
	}

<<<<<<< HEAD
		/*Stop localStop;
		localStop.id = stopMap["id"].toString();
		localStop.code = stopMap["code"].toString();
		localStop.name = stopMap["name"].toString();
		localStop.lat = stopMap["lat"].toDouble();
		localStop.lon = stopMap["lon"].toDouble();
		localStop.locationType = stopMap["locationType"].toString();
		localStop.direction = stopMap["direction"].toString();
		localStop.wheelchairBoarding = stopMap["wheelchairBoarding"].toString();
=======
	qDebug() << "Arrivals and Departures for Stop " << myStop.code;
>>>>>>> master

	emit ArivalsAndDeparturesReply(outputList, myStop);
}

<<<<<<< HEAD
		qDebug() << "Found stop " << localStop.name << " with ID " << localStop.id;*/
		qDebug() << "Found stop " << stopMap["id"].toString();
		outputList.append(stopMap);
	}
=======
ArrivalAndDeparture JsonManager::parseArrivalAndDeparture(QVariantMap arrivalAndDepartureMap)
{
	ArrivalAndDeparture localAad;
	localAad.routeId = arrivalAndDepartureMap["routeId"].toString();
	localAad.routeShortName = arrivalAndDepartureMap["routeShortName"].toString();
	localAad.predictedArrivalTime = arrivalAndDepartureMap["predictedArrivalTime"].toUInt();
	localAad.scheduledArrivalTime = arrivalAndDepartureMap["scheduledArrivalTime"].toUInt();
	localAad.predictedDepartureTime = arrivalAndDepartureMap["predictedDepartureTime"].toUInt();
	localAad.scheduledDepartureTime = arrivalAndDepartureMap["scheduledDepartureTime"].toUInt();

	qDebug() << "Arrival for route " << localAad.routeShortName;
>>>>>>> master

	return localAad;
}

void JsonManager::processAllStopsReply(QVariant input)
{
	//TODO: make this actually do something
}


Stop JsonManager::parseStop(QVariantMap stopMap)
{
	Stop localStop;
	localStop.id = stopMap["id"].toString();
	localStop.code = stopMap["code"].toString();
	localStop.name = stopMap["name"].toString();
	localStop.lat = stopMap["lat"].toDouble();
	localStop.lon = stopMap["lon"].toDouble();
	localStop.locationType = stopMap["locationType"].toString();
	localStop.direction = stopMap["direction"].toString();
	localStop.wheelchairBoarding = stopMap["wheelchairBoarding"].toString();

	qDebug() << "Found stop " << localStop.name << " with ID " << localStop.id;

	foreach(QVariant routeEntry, stopMap["routes"].toList())
	{
		localStop.routeInfo.append(parseRoute(routeEntry.toMap()));
	}

	return localStop;
}

Route JsonManager::parseRoute(QVariantMap routeEntry)
{
	Route localRoute;

	localRoute.id = routeEntry["id"].toString();
	localRoute.description = routeEntry["description"].toString();

	if(localRoute.description == "" || localRoute.description.isEmpty())
	{
		localRoute.description = routeEntry["longName"].toString();
	}

	localRoute.shortName = routeEntry["shortName"].toString();

	qDebug() << "\tRoute Found: " << localRoute.description;

	return localRoute;
}

void JsonManager::networkReply()
{
	QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
	QString requestUrl = reply->request().url().toString();
	QVariant myVar = validateReply(reply);

	if(myVar.isValid())
	{
		//Determine what kind of call this is
		if(requestUrl.contains(ALL_AGENCIES))
		{
			processAllAgenciesReply(myVar);
		}

		if(requestUrl.contains(ALL_STOPS))
		{
			processAllStopsReply(myVar);
		}

		if(requestUrl.contains(STOP_SEARCH))
		{
			processStopSearchReply(myVar);
		}

		if(requestUrl.contains(STOPS_FOR_ROUTE))
		{
			processStopsForRouteReply(myVar);
		}

		if(requestUrl.contains(ROUTE_SEARCH))
		{
			processRouteSearchReply(myVar);
		}

		if(requestUrl.contains(ARRIVALS_AND_DEPARTURES))
		{
			processArrivalsAndDeparturesReply(myVar);
		}
	}
}

QVariant JsonManager::validateReply(QNetworkReply* reply)
{
	if(reply->error() != QNetworkReply::NoError)
	{
		qWarning() << "Critical network error: " << reply->errorString();
		emit error(reply->error());
		reply->deleteLater();
		return QVariant();
	}

	//No errors in reply, attempt to parse JSON
	QByteArray netData = reply->readAll();
	reply->deleteLater();

	JsonDataAccess jda;
	QVariant replyData = jda.loadFromBuffer(netData);

	return replyData;
}

JsonManager::~JsonManager()
{
	//Cleanup network stuff
	delete serverAccess;
}
