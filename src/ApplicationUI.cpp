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

    //Setup the map

    QObject* mapViewAsQObject = root->findChild<QObject*>(QString("mapView"));

    if (mapViewAsQObject)
    {
        mapView = qobject_cast<bb::cascades::maps::MapView*>(mapViewAsQObject);

        if (mapView)
        {
        	mapView->setCaptionGoButtonVisible(true);

            // Create a data provider just for the device
            // location object. When the clear function is
            // called, this object is not removed.
        	bb::cascades::maps::DataProvider* deviceLocDataProv = new bb::cascades::maps::DataProvider("device-location-data-provider");
            mapView->mapData()->addProvider(deviceLocDataProv);

            // Create a geolocation just for the device's location.
            deviceLocation = new bb::platform::geo::GeoLocation("device-location-id");
            deviceLocation->setName("Current Device Location");

            deviceLocDataProv->add(deviceLocation);
        }
        else
		{
			qDebug() << "Couldn't cast to MapView";
		}
    }
    else
    {
    	qDebug() << "Couldn't find child";
    }

    /*Load tab items.*/
    //Tab: Stops
    PopulateFavoriteStops();
}

//TODO: Remove test function getStops()
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
	NavigationPane * navStops = root->findChild<NavigationPane*>("navStops");
    new StopsView(json, navStops);
    json->GetStopByCode(stopCode);
}

//TODO: Delete test page.
void ApplicationUI::showTestPage()
{
	/*QmlDocument * qml = QmlDocument::create("asset:///testPage.qml");

	// Creates the root using the page node
	Page * testPage = qml->createRootObject<Page>();

	NavigationPane * navigationPane = root->findChild<NavigationPane*>("navTest");
	// Push the test page
	navigationPane->push(testPage);*/

	//NavigationPane * navStops = root->findChild<NavigationPane*>("navTest");
	//new MapView(json, navStops);
}

void ApplicationUI::updateDeviceLocation(double lat, double lon) {
    if (mapView) {
        qDebug() << "ApplicationUI::updateDeviceLocation("
            " " << lat << ", " << lon << " )";
        if (deviceLocation) {
            deviceLocation->setLatitude(lat);
            deviceLocation->setLongitude(lon);
        }
        mapView->setLatitude(lat);
        mapView->setLongitude(lon);
    }
}



