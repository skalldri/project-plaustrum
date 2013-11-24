// Tabbed pane project template
#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <QMetaType>
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/Button>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/maps/DataProvider>
#include <bb/cascades/maps/MapView>
#include <bb/cascades/maps/MapData>
#include <bb/platform/geo/GeoLocation>
#include "src/Stops/StopsView.hpp"
#include "AppSettings.hpp"
#include "JsonManager.hpp"
#include "DataTypes.hpp"
#include "src/Map/MapView.hpp"

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI(bb::cascades::Application * app);
    virtual ~ApplicationUI() {}
    Q_INVOKABLE void showStopsList(QString stopCode);
    Q_INVOKABLE void showTestPage();
    Q_INVOKABLE void updateDeviceLocation(double lat, double lon);
    JsonManager * json;

public slots:
	Q_INVOKABLE void getStops();

private:
	void PopulateFavoriteStops();
    AppSettings * appSettings;
    AbstractPane * root;
    bb::cascades::maps::MapView* mapView;
    bb::platform::geo::GeoLocation* deviceLocation;

};

#endif /* ApplicationUI_HPP_ */
