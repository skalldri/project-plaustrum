/*
 * StopsView.cpp
 *
 *  Created on: Jun 5, 2013
 *      Author: nause
 */

#include "StopsView.hpp"

using namespace bb::cascades;

StopsView::StopsView(JsonManager * json, Page * view, NavigationPane * navPane)
{
	//Set private variables
	this->json = json;
	this->view = view;
	this->navPane = navPane;

	//Connect StopSearchReply to PopulateResults
	connect(json, SIGNAL(StopSearchReply(QList<Stop>)), this, SLOT(PopulateResults(QList<Stop>)));
}

StopsView::~StopsView() {
	// TODO Auto-generated destructor stub
}

void StopsView::getStops()
{
	//Clear old results
	ArrayDataModel * stopsListModel = view->findChild<ArrayDataModel*>("stopsListModel");
	stopsListModel->clear();

	//Get text from TextField
	TextField * textStopCode = view->findChild<TextField*>("textStopCode");
	QString stopCode = textStopCode->text();

	//Use json.
	json->GetStopByCode(stopCode);
}

void StopsView::PopulateResults(QList<Stop> inputList)
{
	ListView * stopsListView = view->findChild<ListView*>("stopsListView");
	ArrayDataModel * stopsListModel = view->findChild<ArrayDataModel*>("stopsListModel");
	stopsListModel->clear();

	//TODO: implement a way to request results be cleared separately (possibly from the Search bar)

	foreach(Stop current, inputList)
	{
		qDebug() << "Adding element " << current.name;
		stopsListModel->append(QVariant(current.name + " (" + current.code + ")"));
	}
}
