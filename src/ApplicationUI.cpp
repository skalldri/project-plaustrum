// Tabbed pane project template
#include "ApplicationUI.hpp"
#include <src/Stops/StopsView.hpp>

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/Button>

namespace bb { namespace cascades { class Application; }}
using namespace bb::cascades;

ApplicationUI::ApplicationUI(bb::cascades::Application *app)
: QObject(app)
{
    // create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime
    QmlDocument * qml = QmlDocument::create("asset:///main.qml").parent(this);

    // create root object for the UI
    AbstractPane * root = qml->createRootObject<AbstractPane>();
    // set created root object as a scene
    app->setScene(root);

    //Open a QSettings object with application settings

    appSettings = new AppSettings();
    json = new JsonManager(appSettings);
    StopsView * myStopsView = new StopsView(root);

    //Connect all the Query managers here
    Button* getTestDataButton = root->findChild<Button*>("getTestData");
    connect(getTestDataButton, SIGNAL(clicked()), this, SLOT(getStops()));
}

void ApplicationUI::getStops()
{
	json->GetAllStops("3");
	json->GetStopByCode("501");
	json->GetAllAgencies();
}




