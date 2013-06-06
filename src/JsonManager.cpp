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

void JsonManager::GetAllAgencies()
{
	QString URL = mySettings->GetAPIURlBase() + "agencies-with-coverage.json?key=TEST";
}

void JsonManager::GetAllStops()
{
	QString URL = mySettings->GetAPIURlBase() + "agencies-with-coverage.json?key=TEST";
}

void JsonManager::GetTest()
{
	QString URL = mySettings->GetAPIURlBase() + "arrivals-and-departures-for-stop/1_75403.json?key=TEST";

	qDebug() << URL;

	QNetworkRequest req;
	req.setUrl(QUrl(URL));

	QNetworkReply* myReply = serverAccess->get(req);
	connect(myReply, SIGNAL(finished()), this, SLOT(testReply()));
}

void JsonManager::testReply()
{
	QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
	QVariant myVar = validateReply(reply);

	if(myVar.isValid())
		emit testReplyMap(myVar);
}

QVariant JsonManager::validateReply(QNetworkReply* reply)
{
	if(reply->error() != QNetworkReply::NoError)
	{
		qDebug() << "Critical network error";
		emit error(reply->error());
		reply->deleteLater();
		return QVariant();
	}

	//No errors in reply, attempt to parse JSON
	QByteArray netData = reply->readAll();
	reply->deleteLater();

	JsonDataAccess jda;
	QVariant replyData = jda.loadFromBuffer(netData);

	qDebug() << replyData;
	qDebug(netData);

	return replyData;
}

JsonManager::~JsonManager()
{
	//Cleanup network stuff
	delete serverAccess;
}
