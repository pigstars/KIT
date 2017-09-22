/*
	CConfig
*/

#ifndef CConfig_H__
#define CConfig_H__


#include <map>
#include <string>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "CCommon.h"

static const int MAXLINE = 1024;
static const char DELIMITER = '=';
static const char COMMENT = '#';
using namespace std;
class CConfig
{

public:
	CConfig(string ss = "")
	{
		FileLocal = ss;
	}
	~CConfig()
	{
		
	}
	bool ReadConfigFile();
	map<string,string> &GetConfigSetting();
	void ShowConfigContent();
	void UseDefaultConfig();
private:
    string FileLocal;
	map<string,string> ConfigSetting;
};




#endif
