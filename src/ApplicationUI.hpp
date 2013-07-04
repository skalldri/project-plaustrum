// Tabbed pane project template
#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include "AppSettings.hpp"
#include "JsonManager.hpp"

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
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() {}

public slots:
	void getStops();

private:
    AppSettings * appSettings;
    JsonManager * json;

};

#endif /* ApplicationUI_HPP_ */
