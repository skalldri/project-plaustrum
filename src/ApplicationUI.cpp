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
    qml->setContextProperty("ApplicationUI", this);
    // create root object for the UI
    root = qml->createRootObject<AbstractPane>();
    // set created root object as a scene
    app->setScene(root);

    //Open a QSettings object with application settings
    appSettings = new AppSettings();
    json = new JsonManager(appSettings);

    /*Load tab items.*/
    //Tab: Stops
    PopulateFavoriteStops();
}

//TODO: Remove test function getStops()
void ApplicationUI::getStops()
{
	//json->GetAllStops("3");
	json->GetStopByCode("501");
	//json->GetStopByRadius(47.653435, -122.305641);
	//json->GetStopByBoundedBox(47.653435, -122.305641, )
	//json->GetAllAgencies();
}

void ApplicationUI::PopulateFavoriteStops()
{
	ListView * favoritesListView = root->findChild<ListView*>("favoriteStopsListView");
	ArrayDataModel * favoritesListModel = root->findChild<ArrayDataModel*>("favoriteStopsListModel");
	//Accept a list of stops as an argument

	//foreach entry in stops list
		//append a stop to the stopsListModel

	for(int c = 0; c < 10; c++)
	{
		favoritesListModel->append(QVariant("Stop " + QString().number(c)));
	}
}

void ApplicationUI::showStopsList(QString stopCode)
{
	QmlDocument * qmlStopsList = QmlDocument::create("asset:///stopsList.qml");
	Page * stopListPage = qmlStopsList->createRootObject<Page>();
	NavigationPane * navStops = root->findChild<NavigationPane*>("navStops");
	navStops->push(stopListPage);
    new StopsView(json, stopListPage, navStops);
    json->GetStopByCode(stopCode);
}

//TODO: Delete test page.
void ApplicationUI::showTestPage()
{
	QmlDocument * qml = QmlDocument::create("asset:///testPage.qml");

	// Creates the root using the page node
	Page * testPage = qml->createRootObject<Page>();

	NavigationPane * navigationPane = root->findChild<NavigationPane*>("navTest");
	// Push the test page
	navigationPane->push(testPage);
}




