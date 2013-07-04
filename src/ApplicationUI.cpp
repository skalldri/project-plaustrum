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
	json->GetAllStops("3");
	json->GetStopByCode("501");
	json->GetStopByRadius(47.653435, -122.305641);
	//json->GetStopByBoundedBox(47.653435, -122.305641, )
	json->GetAllAgencies();
}




