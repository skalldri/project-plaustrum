/*
 * StopItemView.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: nause
 */

#include "StopItemView.hpp"

StopItemView::StopItemView(JsonManager * json, NavigationPane * navPane) {
	//Set private variables
	this->json = json;
	this->navPane = navPane;

	QmlDocument * qmlStopInfo = QmlDocument::create("asset:///stopsInfo.qml");
	view = qmlStopInfo->createRootObject<Page>();
	navPane->push(view);

	//Connect StopSearchReply to setDepartureTimes
	QObject::connect(json, SIGNAL(ArrivalsAndDeparturesReply(QList<QVariantMap>, Stop)), this, SLOT(setDepartureTimes(QList<QVariantMap>, Stop)));
}

StopItemView::~StopItemView() {
	// TODO Auto-generated destructor stub
}

void StopItemView::setDepartureTimes(QList<QVariantMap> inputList, Stop stop)
{
	qDebug() << "SLOT";
	departureList = inputList;
	this->stop = stop;
	ListView * departuresListView = view->findChild<ListView*>("departuresListView");
	ArrayDataModel * departuresListModel = view->findChild<ArrayDataModel*>("departuresListModel");
	departuresListModel->clear();

	foreach(QVariantMap current, inputList)
	{
		qDebug() << "Adding " << current["routeShortName"].toString();
		departuresListModel->append(current);
	}
}
