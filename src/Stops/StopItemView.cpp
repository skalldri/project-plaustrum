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
	QObject::connect(json, SIGNAL(ArrivalsAndDeparturesReply(QList<ArrivalAndDeparture>, Stop)), this, SLOT(setDepartureTimes(QList<ArrivalAndDeparture>, Stop)));
}

StopItemView::~StopItemView() {
	// TODO Auto-generated destructor stub
}

void StopItemView::setDepartureTimes(QList<ArrivalAndDeparture> departureList, Stop stop)
{
	this->departureList = departureList;
	this->stop = stop;

	Label* stopId = view->findChild<Label*>("stopId");
	stopId->setText(stop.code);
	Label* stopName = view->findChild<Label*>("stopName");
	stopName->setText(stop.name);

	ListView* departuresListView = view->findChild<ListView*>("departuresListView");
	ArrayDataModel* departuresListModel = view->findChild<ArrayDataModel*>("departuresListModel");
	departuresListModel->clear();

	foreach(ArrivalAndDeparture current, departureList)
	{
		QVariantMap departure = current.ToVariantMap();
		qDebug() << "Adding " << departure["routeShortName"].toString();
		departuresListModel->append(departure);
	}
}
