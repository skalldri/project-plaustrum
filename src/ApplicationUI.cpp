// Tabbed pane project template
#include "ApplicationUI.hpp"
#include "JsonManager.hpp"


#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/Button>

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

    JsonManager * json = new JsonManager(appSettings);

    //Connect all the Query managers here
    Button* getTestDataButton = root->findChild<Button*>("getTestData");
    connect(getTestDataButton, SIGNAL(clicked()), json, SLOT(GetTest()));
}


