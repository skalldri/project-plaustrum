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


using namespace bb::data;

class JsonManager : public QObject
{
	Q_OBJECT

public:
	JsonManager(AppSettings* appSettings);
	virtual ~JsonManager();

public slots:
	void GetAllStops(QString agencyID);
	void GetAllAgencies();

private:
	QVariant validateReply(QNetworkReply* reply);
	void processAllAgenciesReply(QVariant input);
	void processAllStopsReply(QVariant input);
	void getUrl(QString function, QString specifier = "");

	AppSettings* mySettings;
	QNetworkAccessManager* serverAccess;

private slots:
	void networkReply();

signals:
	void error(QNetworkReply::NetworkError);
	void variantReplyMap(QVariant);
	void testReplyMap(QVariant);
	void AllAgenciesReply(QList<TransitAgency>*);

};

#endif /* JSONMANAGER_HPP_ */
