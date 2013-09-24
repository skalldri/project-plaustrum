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

class StopsView : public QObject
{
	Q_OBJECT
public:
	StopsView(JsonManager * json, Page * view, NavigationPane * navPane);
	virtual ~StopsView();
	void PopulateFavorites();

public slots:
	void getStops();
	void PopulateResults(QList<QVariantMap> inputList);

private:
	JsonManager * json;
	Page * view;
	NavigationPane * navPane;
};

#endif /* STOPSVIEW_HPP_ */

