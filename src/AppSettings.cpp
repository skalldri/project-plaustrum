/*
 * AppSettings.cpp
 *
 *  Created on: 2013-06-03
 *      Author: stuart
 */

#include "AppSettings.hpp"

AppSettings::AppSettings()
{
	mySettings = new QSettings(SETTINGS_FILE, QSettings::IniFormat);
	QFileInfo testFile(SETTINGS_FILE);
	if(testFile.exists())
	{
		qDebug() << "Settings file found!";
	}
	else
	{
		qDebug() << "No Settings file at " << testFile.absoluteFilePath();
	}

	//Verify all app settings: if setting is present, assign it to it's variable.
	//If not present, create it in the ini file.

	if(!mySettings->contains("apiUrlList"))
	{
		mySettings->setValue("apiUrlList", QStringList());
		qDebug() << "No value found for apiUrlList";
		//TODO: emit error when corrupted settings file is detected, in all the IF statements here
	}
	apiUrlList = mySettings->value("apiUrlList", QStringList()).toStringList();
	qDebug() << "API URL List: " << apiUrlList;

	if(!mySettings->contains("apiUrlBase"))
	{
		mySettings->setValue("apiUrlBase", QString());
		qDebug() << "No value found for apiUrlBase";
	}
	apiUrlBase = mySettings->value("apiUrlBase", "").toString();
	qDebug() << "API URL Base: " << apiUrlBase;
}

AppSettings::~AppSettings()
{
	delete mySettings;
}

QString AppSettings::GetAPIKey()
{
	return API_KEY;
}

QString AppSettings::GetAPIURlBase()
{
	return apiUrlBase;
}

/**
 * Checks if the user needs to select a server to connect to
 *
 * This function checks to see if it has a valid API URL. If it thinks the user needs to input a URL, it returns true.
 *
 * @return True if the user needs to choose an API URL from the apiUrlList
 */

bool AppSettings::UserChoosesURL()
{
	if(apiUrlBase == "USER" || apiUrlBase.isEmpty() || apiUrlBase == "")
	{
		return true;
	}

	return false;
}

/**
 * Changes the base API url (when conditions are met)
 *
 * This function changes the API base URL to it's input when the input is also present in the apiUrlList.
 * In debug mode, it will change the URL to whatever it's given
 *
 * @param url The input url you wish to change to
 * @return True on success, False on failure
 */

bool AppSettings::ChangeBaseURL(QString url)
{
	if(debugMode || apiUrlList.contains(url, Qt::CaseSensitive))
	{
		apiUrlBase = url;
		return true;
	}

	return false;
}

void AppSettings::EnableDebugMode()
{
	debugMode = true;
}
