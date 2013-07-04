/*
 * StopsView.hpp
 *
 *  Created on: Jun 5, 2013
 *      Author: nause
 */

#ifndef STOPSVIEW_HPP_
#define STOPSVIEW_HPP_

#include <QObject>
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/ListView>
#include <bb/cascades/ArrayDataModel>
#include <bb/cascades/Button>
#include <bb/cascades/TextField>
#include "../DataTypes.hpp"
#include "../JsonManager.hpp"

namespace bb { namespace cascades { class Application; }}

using namespace bb::cascades;

class StopsView : public QObject
{
	Q_OBJECT
public:
	StopsView(JsonManager * json, AbstractPane * parent);
	virtual ~StopsView();
	void PopulateFavorites();

public slots:
	void getStops();
	void PopulateResults(QList<Stop> inputList);

private:
	JsonManager * json;
	AbstractPane * root;
};

#endif /* STOPSVIEW_HPP_ */

