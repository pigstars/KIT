

#include "CConfig.h"

bool CConfig::ReadConfigFile()
{
	char buf[MAXLINE];
	FILE * fp;
	string filelocal = FileLocal;
	bool cwdFlag = true; 	// true 表示路径为当前目录 否则表示 全局目录

	if(filelocal.length() == 0)
	{
		fprintf(stderr,"filename is not true");
		return false;
	}
	if(access(filelocal.c_str(),R_OK) < 0)
	{
		char cwdBuf[80];
		getcwd(cwdBuf,sizeof(cwdBuf));
		filelocal = cwdBuf + filelocal;
		if(access(filelocal.c_str(),R_OK) < 0)
		{
			fprintf(stderr,"file can't read");
		}
	}	
	if((fp = fopen(filelocal.c_str(),"r")) < 0)
	{
		fprintf(stderr,"open filed");
	}
	
	while(fgets(buf,MAXLINE,fp) != NULL)
	{
		char *Cloc = strchr(buf,COMMENT);
		if(Cloc == buf)
			continue;
		if(Cloc != NULL)
			*Cloc = '\0';
		
		char *Dloc = strchr(buf,DELIMITER);
		if(Dloc == NULL)
			continue;
		string value;
		string key;
		*Dloc = '\0';
		key = buf;
		value = Dloc+1;
		CommonFunc::StringTrim(key);
		CommonFunc::StringTrim(value);
		ConfigSetting[key] = value;
	}
	
	return true;
}

map<string,string> & CConfig::GetConfigSetting()
{
	return ConfigSetting;
}

void CConfig::ShowConfigContent()
{
	map<string,string>::iterator ite;
	for(ite = ConfigSetting.begin();ite != ConfigSetting.end();ite++)
	{
		printf("%s\n",ite -> first.c_str());
		printf("%s\n",ite -> second.c_str());
	}
}

void CConfig::UseDefaultConfig()
{
	printf("Default Config:");
	
	
}