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

void JsonManager::processAllAgenciesReply(QVariant input)
{
	QList<TransitAgency> outputList;

	if(input.toMap()["code"].toInt() != 200)
	{
		qWarning() << "All-Agencies Reply Status Code " << input.toMap()["data"].toInt();
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

void JsonManager::processStopSearchReply(QVariant input)
{
	QList<QVariantMap> outputList;

	if(input.toMap()["code"].toInt() != 200)
	{
		qWarning() << "Stop Search Reply Status Code " << input.toMap()["data"].toInt();
		return;
	}

	foreach(QVariant item, input.toMap()["data"].toMap()["stops"].toList())
	{
		QVariantMap stopMap = item.toMap();

		/*Stop localStop;
		localStop.id = stopMap["id"].toString();
		localStop.code = stopMap["code"].toString();
		localStop.name = stopMap["name"].toString();
		localStop.lat = stopMap["lat"].toDouble();
		localStop.lon = stopMap["lon"].toDouble();
		localStop.locationType = stopMap["locationType"].toString();
		localStop.direction = stopMap["direction"].toString();
		localStop.wheelchairBoarding = stopMap["wheelchairBoarding"].toString();

		//TODO: add route info to the localStop objects

		qDebug() << "Found stop " << localStop.name << " with ID " << localStop.id;*/
		qDebug() << "Found stop " << stopMap["id"].toString();
		outputList.append(stopMap);
	}

	emit StopSearchReply(outputList);
}

void JsonManager::GetAllStops(QString agencyId)
{
	//TODO: Check agencyID is valid (we've seen it before)
	getUrl(ALL_STOPS, agencyId);
}

void JsonManager::processAllStopsReply(QVariant input)
{

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
