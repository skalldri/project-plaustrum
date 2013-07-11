// Tabbed pane project template
#include "ApplicationUI.hpp"

namespace bb { namespace cascades { class Application; }}
using namespace bb::cascades;

ApplicationUI::ApplicationUI(bb::cascades::Application *app)
: QObject(app)
{
    // create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime
    QmlDocument * qml = QmlDocument::create("asset:///main.qml").parent(this);

    // create root object for the UI
    root = qml->createRootObject<AbstractPane>();
    // set created root object as a scene
    app->setScene(root);

    //Open a QSettings object with application settings
    appSettings = new AppSettings();
    json = new JsonManager(appSettings);
    StopsView * myStopsView = new StopsView(root);

    connect(json, SIGNAL(StopSearchReply(QList<Stop>)), myStopsView, SLOT(PopulateResults(QList<Stop>)));

    //Connect all the Query managers here
    Button* getTestDataButton = root->findChild<Button*>("getTestData");
    connect(getTestDataButton, SIGNAL(clicked()), this, SLOT(getStops()));
}

void ApplicationUI::getStops()
{
	qDebug() << "Get all Stops";
	json->GetAllStops("3");

	qDebug() << "Get Stop by Code 501";
	json->GetStopByCode("501");

	qDebug() << "Get Stop by Radius";
	json->GetStopByRadius(47.653435, -122.305641);
	//json->GetStopByBoundedBox(47.653435, -122.305641, )

	qDebug() << "Get All Agencies";
	json->GetAllAgencies();

	qDebug() << "Get Stops for Route 1_44";
	json->GetStopsForRoute("1_44");

	/*
	 * Doesn't work for now: needs a real lat and lon

	qDebug() << "Get Route By Code 1_44";
	json->GetRouteByCode("1_44");

	*/

	qDebug() << "Get Arrivals and Departures for Stop 1_75403";
	json->GetArrivalsAndDepartures("1_75403");
}





