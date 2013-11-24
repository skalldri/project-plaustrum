/*
 * StopsView.cpp
 *
 *  Created on: Jun 5, 2013
 *      Author: nause
 */

#include "StopsView.hpp"

using namespace bb::cascades;

StopsView::StopsView(JsonManager * json, NavigationPane * navPane)
{
	//Set private variables
	this->json = json;
	this->navPane = navPane;

	QmlDocument * qmlStopsList = QmlDocument::create("asset:///stopsList.qml");
	qmlStopsList->setContextProperty("StopsView", this);
	view = qmlStopsList->createRootObject<Page>();
	navPane->push(view);

	//Connect StopSearchReply to PopulateResults
	connect(json, SIGNAL(StopSearchReply(QList<Stop>)), this, SLOT(PopulateResults(QList<Stop>)));
}

StopsView::~StopsView() {
	// TODO Auto-generated destructor stub
}

void StopsView::PopulateResults(QList<Stop> stopList)
{
	this->stopList = stopList;
	ListView * stopsListView = view->findChild<ListView*>("stopsListView");
	ArrayDataModel * stopsListModel = view->findChild<ArrayDataModel*>("stopsListModel");
	stopsListModel->clear();

	//TODO: implement a way to request results be cleared separately (possibly from the Search bar)

	foreach(Stop current, stopList)
	{
		QVariantMap stop = current.ToVariantMap();
		qDebug() << "Adding " << stop["name"].toString();
		stopsListModel->append(stop);
	}
}

void StopsView::showStop(qint32 index)
{
	new StopItemView(json, navPane);

	QVariantMap stop = stopList.at(index).ToVariantMap();
	QString stopId = stop["id"].toString();
	json->GetArrivalsAndDepartures(stopId);
}

