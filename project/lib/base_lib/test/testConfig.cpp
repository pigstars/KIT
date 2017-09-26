#include <iostream>
#include "../CConfig.h"

using namespace std;
int main(int argc, char *argv[]) {
	CConfig s("../config.ini");
	s.ReadConfigFile();
	s.ShowConfigContent();
	//Common::GetSingle<CConfig>().ReadConfigFile();
	return 0;
}
/*
std::string & StringTrim (std::string & temp)
{
	if(temp.empty())
	{
		return temp;
	}
	
	temp.erase(0,temp.find_first_not_of(" "));  
	temp.erase(temp.find_last_not_of(" ") + 1); 
	return temp;
}
*/