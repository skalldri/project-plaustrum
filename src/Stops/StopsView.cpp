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
	connect(json, SIGNAL(StopSearchReply(QList<QVariantMap>)), this, SLOT(PopulateResults(QList<QVariantMap>)));
}

StopsView::~StopsView() {
	// TODO Auto-generated destructor stub
}

void StopsView::PopulateResults(QList<QVariantMap> inputList)
{
	stopList = inputList;
	ListView * stopsListView = view->findChild<ListView*>("stopsListView");
	ArrayDataModel * stopsListModel = view->findChild<ArrayDataModel*>("stopsListModel");
	stopsListModel->clear();

	//TODO: implement a way to request results be cleared separately (possibly from the Search bar)

	foreach(QVariantMap current, inputList)
	{
		//qDebug() << "Adding element " << current.name;
		//stopsListModel->append(QVariant(current.name + " (" + current.code + ")"));
		qDebug() << "Adding " << current["name"].toString();
		stopsListModel->append(current);
	}
}

void StopsView::showStop(qint32 index)
{
	new StopItemView(json, navPane);

	QString stopId = stopList.at(index)["code"].toString();
	json->GetArrivalsAndDepartures(stopId);
}

