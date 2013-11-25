/*
 * StopItemView.hpp
 *
 *  Created on: Nov 23, 2013
 *      Author: nause
 */

#ifndef STOPITEMVIEW_HPP_
#define STOPITEMVIEW_HPP_

#include <QObject>
#include <bb/cascades/Application>
#include <bb/cascades/ArrayDataModel>
#include <bb/cascades/Button>
#include <bb/cascades/ListView>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/Page>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/TextField>
#include "../DataTypes.hpp"
#include "../JsonManager.hpp"

namespace bb { namespace cascades { class Application; }}

using namespace bb::cascades;

class StopItemView : public QObject
{
	Q_OBJECT
public:
	StopItemView(JsonManager * json, NavigationPane * navPane);
	virtual ~StopItemView();

public slots:
	void setDepartureTimes(ArrivalAndDepartureList inputList, Stop stop);

private:
	JsonManager * json;
	Page * view;
	NavigationPane * navPane;
	Stop stop;
	ArrivalAndDepartureList departureList;
};

#endif /* STOPITEMVIEW_HPP_ */
