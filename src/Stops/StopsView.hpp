/*
 * StopsView.hpp
 *
 *  Created on: Jun 5, 2013
 *      Author: nause
 */

#warning I AM HERE

#ifndef STOPSVIEW_HPP_
#define STOPSVIEW_HPP_

#include <QObject>
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/ListView>
#include <bb/cascades/ArrayDataModel>

namespace bb { namespace cascades { class Application; }}

using namespace bb::cascades;

class StopsView : public QObject
{
	Q_OBJECT
public:
	StopsView(AbstractPane * parent);
	virtual ~StopsView();
	void PopulateStopsListView();

private:
	ListView * stopsListView;
	ArrayDataModel * stopsListModel;
};

#endif /* STOPSVIEW_HPP_ */

