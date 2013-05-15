/*
 * JsonManager.hpp
 *
 *  Created on: 2013-05-14
 *      Author: stuart
 */

#ifndef JSONMANAGER_HPP_
#define JSONMANAGER_HPP_

#include <QObject>
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
	JsonManager();
	virtual ~JsonManager();

public slots:
	void requestFinished(QNetworkReply*);
	void networkError(QNetworkReply::NetworkError);

private:
	QNetworkAccessManager* serverAccess;

signals:
	void error(QNetworkReply::NetworkError);
	void variantReplyMap(QVariant);

};

#endif /* JSONMANAGER_HPP_ */
