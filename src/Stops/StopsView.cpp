/*
 * StopsView.cpp
 *
 *  Created on: Jun 5, 2013
 *      Author: nause
 */

#include "StopsView.hpp"

using namespace bb::cascades;

StopsView::StopsView(JsonManager * json, AbstractPane * parent)
{
	//Set private json
	this->json = json;
	this->root = parent;
	//Initialize button and connect signal to slot
	//Connect all the Query managers here
	Button* getStopCode = parent->findChild<Button*>("getStopCode");
	connect(getStopCode, SIGNAL(clicked()), this, SLOT(getStops()));

	//Connect StopSearchReply to PopulateResults
	connect(json, SIGNAL(StopSearchReply(QList<Stop>)), this, SLOT(PopulateResults(QList<Stop>)));

	PopulateFavorites();
}

StopsView::~StopsView() {
	// TODO Auto-generated destructor stub
}

void StopsView::getStops()
{
	//Clear old results
	ArrayDataModel * stopsListModel = root->findChild<ArrayDataModel*>("stopsListModel");
	stopsListModel->clear();

	//Get text from TextField
	TextField * textStopCode = root->findChild<TextField*>("textStopCode");
	QString stopCode = textStopCode->text();

	//Use json.
	json->GetStopByCode(stopCode);
}

void StopsView::PopulateFavorites()
{
	ListView * favoritesListView = root->findChild<ListView*>("favoriteStopsListView");
	ArrayDataModel * favoritesListModel = root->findChild<ArrayDataModel*>("favoriteStopsListModel");
	//Accept a list of stops as an argument

	//foreach entry in stops list
		//append a stop to the stopsListModel

	for(int i = 0; i < 20; i++)
	{
		favoritesListModel->append(QVariant("Stop " + QString().number(i)));
	}
}

void StopsView::PopulateResults(QList<Stop> inputList)
{
	ListView * stopsListView = root->findChild<ListView*>("stopsListView");
	ArrayDataModel * stopsListModel = root->findChild<ArrayDataModel*>("stopsListModel");
	stopsListModel->clear();

	//TODO: implement a way to request results be cleared separately (possibly from the Search bar)

	foreach(Stop current, inputList)
	{
		qDebug() << "Adding element " << current.name;
		stopsListModel->append(QVariant(current.name + " (" + current.code + ")"));
	}
}
