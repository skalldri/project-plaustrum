/*
 * JsonManager.cpp
 *
 *  Created on: 2013-05-14
 *      Author: stuart
 */

#include "JsonManager.hpp"

JsonManager::JsonManager()
{
	//Create network manager
	serverAccess = new QNetworkAccessManager(this);
	serverAccess->setNetworkAccessible(QNetworkAccessManager::Accessible);

	if(serverAccess->networkAccessible() != QNetworkAccessManager::Accessible)
	{
		qDebug() << "DEBUG Error: network is unaccessible";
	}

	//Possibly: check server is alive
	//Emit signal when connected?

	//Connect signals from QNetworkAccessManager to internal slots

	QObject::connect(serverAccess, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));

	QString URL = "http://api.onebusaway.org/api/where/arrivals-and-departures-for-stop/1_75403.json?key=TEST";
	QNetworkRequest req;
	req.setUrl(QUrl(URL));

	QNetworkReply* initialReply = serverAccess->get(req);

	QObject::connect(initialReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(networkError(QNetworkReply::NetworkError)));

	qDebug() << "DEBUG TestA";
}

JsonManager::~JsonManager()
{
	//Cleanup network stuff
}

void JsonManager::requestFinished(QNetworkReply* reply)
{
	qDebug() << "DEBUG TestB";

	if(reply->error() != QNetworkReply::NoError)
	{
		qDebug() << "DEBUG Critical error";
		emit error(reply->error());
		reply->deleteLater();
		return;
	}

	//No errors in reply, attempt to parse JSON

	//DEBUG ONLY

	QByteArray netData = reply->readAll();

	qDebug(netData);

	JsonDataAccess jda;
	QVariant replyData = jda.loadFromBuffer(netData);

	emit variantReplyMap(replyData);
	reply->deleteLater();
}

void JsonManager::networkError(QNetworkReply::NetworkError err)
{
	qDebug() << "DEBUG NETWORK ERROR";
}
