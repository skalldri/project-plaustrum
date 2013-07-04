/*
 * StopsView.cpp
 *
 *  Created on: Jun 5, 2013
 *      Author: nause
 */

#include "StopsView.hpp"

using namespace bb::cascades;

StopsView::StopsView(AbstractPane * parent)
{
	favoritesListView = parent->findChild<ListView*>("favoriteStopsListView");
	favoritesListModel = parent->findChild<ArrayDataModel*>("favoriteStopsListModel");

	stopsListView = parent->findChild<ListView*>("stopsListView");
	stopsListModel = parent->findChild<ArrayDataModel*>("stopsListModel");

	PopulateFavorites();
}

StopsView::~StopsView() {
	// TODO Auto-generated destructor stub
}

void StopsView::PopulateFavorites()
{
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
	//TODO: implement a way to request results be cleared separately (possibly from the Search bar)
	stopsListModel->clear();

	foreach(Stop current, inputList)
	{
		qDebug() << "Adding element " << current.name;
		stopsListModel->append(QVariant(current.name + " (" + current.code + ")"));
	}
}
