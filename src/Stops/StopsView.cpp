/*
 * StopsView.cpp
 *
 *  Created on: Jun 5, 2013
 *      Author: nause
 */

#include "StopsView.hpp"

using namespace bb::cascades;

StopsView::StopsView(AbstractPane * parent) {
	stopsListView = parent->findChild<ListView*>("stopsListView");
	stopsListModel = parent->findChild<ArrayDataModel*>("stopsListModel");

	//connect search box with json manager
	//connect json manager with PopulateStopsListView


	PopulateStopsListView();
}

StopsView::~StopsView() {
	// TODO Auto-generated destructor stub
}

void StopsView::PopulateStopsListView()
{
	//Accept a list of stops as an argument

	//foreach entry in stops list
		//append a stop to the stopsListModel

	for(int i = 0; i < 20; i++)
	{
		stopsListModel->append(QVariant("Stop" + QString().number(i)));
	}
}
