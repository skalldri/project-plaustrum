/*
 * StopInfoView.hpp
 *
 *  Created on: 2013-05-24
 *      Author: stuart
 */

#ifndef STOPINFOVIEW_HPP_
#define STOPINFOVIEW_HPP_

#include <QObject>
#include "StopInfoModel.hpp"


class StopInfoView : public QObject
{
	Q_OBJECT

public:
	StopInfoView();
	virtual ~StopInfoView();

private:
	StopInfoModel* myDataModel;

};

#endif /* STOPINFOVIEW_HPP_ */
