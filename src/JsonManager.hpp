/*
 * JsonManager.hpp
 *
 *  Created on: 2013-05-14
 *      Author: stuart
 */

#ifndef JSONMANAGER_HPP_
#define JSONMANAGER_HPP_

#include "AppSettings.hpp"
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <bb/data/JsonDataAccess>
#include <QVariant>
#include <QtCore>
#include <QUrl>

using namespace bb::data;

class JsonManager : public QObject
{

	Q_OBJECT

public:
	JsonManager(AppSettings* appSettings);
	virtual ~JsonManager();

public slots:
	void GetTest();
	void GetAllStops();
	void GetAllAgencies();

private:
	QVariant validateReply(QNetworkReply* reply);

	AppSettings* mySettings;
	QNetworkAccessManager* serverAccess;

private slots:
	void testReply();

signals:
	void error(QNetworkReply::NetworkError);
	void variantReplyMap(QVariant);
	void testReplyMap(QVariant);

};

#endif /* JSONMANAGER_HPP_ */
