// Tabbed pane project template
#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include "StopInfo/StopInfoView.hpp"
#include "AppSettings.hpp"

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

private:
    AppSettings * appSettings;
    QSettings * loadSettings();


};

#endif /* ApplicationUI_HPP_ */
