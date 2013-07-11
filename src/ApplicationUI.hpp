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
#include "src/Stops/StopsView.hpp"
#include "AppSettings.hpp"
#include "JsonManager.hpp"
#include "DataTypes.hpp"

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
    JsonManager * json;

public slots:
	Q_INVOKABLE void getStops();

private:
	void PopulateFavoriteStops();
    AppSettings * appSettings;
    AbstractPane * root;

};

#endif /* ApplicationUI_HPP_ */
