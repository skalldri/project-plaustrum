/*
 * StopsView.cpp
 *
 *  Created on: Jun 5, 2013
 *      Author: nause
 */

#include "StopsView.hpp"

using namespace bb::cascades;

StopsView::StopsView(AbstractPane * parent) {
	stopsListView = parent->findChild<ListView*>("favoriteStopsListView");
	stopsListModel = parent->findChild<ArrayDataModel*>("favoriteStopsListModel");
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
