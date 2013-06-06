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

void JsonManager::getUrl(QString function, QString specifier)
{
	QString option = "";

	if(specifier == "" || specifier.isEmpty())
	{
		option = "/" + specifier;
	}

	QString URL = mySettings->GetAPIURlBase() + function + option + "." + DATA_TYPE + KEY_URL + mySettings->GetAPIKey();

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
}

void JsonManager::GetAllStops(QString agencyId)
{
	//TODO: Check agencyID is valid (we've seen it before)
	getUrl(ALL_STOPS, agencyId);
}

void JsonManager::processAllStopsReply(QVariant input)
{
	QList<TransitAgency>* outputList = new QList<TransitAgency>();

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

		outputList->append(localAgency);
	}
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
