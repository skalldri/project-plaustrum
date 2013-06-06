/*
 * AppSettings.hpp
 *
 *  Created on: 2013-06-03
 *      Author: stuart
 */

//FIXME: This class should be a singleton
//TODO: This class should be a QObject so it can emit events (like errors)

#ifndef APPSETTINGS_HPP_
#define APPSETTINGS_HPP_
#include <QtCore>

//TODO: get a real API key here
#define SETTINGS_FILE "./app/native/assets/appSettings.ini"
#define API_KEY "TEST"

class AppSettings {
public:
				AppSettings();
	virtual 	~AppSettings();
	QString 	GetAPIKey();
	QString 	GetAPIURlBase();
	bool		UserChoosesURL();
	bool 		ChangeBaseURL(QString url);
	void		EnableDebugMode();

private:
	QSettings *  mySettings;
	QStringList  apiUrlList;
	QString		 apiUrlBase;
	bool 		 debugMode;
};

#endif /* APPSETTINGS_HPP_ */
