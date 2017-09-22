/*
	通用工具方法
*/

#ifndef CCommon_H__
#define CCommon_H__


class CommonFunc
{
public:
	static std::string & StringTrim (std::string & temp)
	{
		if(temp.empty())
		{
			return temp;
		}
		
		temp.erase(0,temp.find_first_not_of(" "));  
		temp.erase(temp.find_last_not_of(" ") + 1); 
		return temp;
	}	
};

namespace Common
{

template <typename T>
class Singleton:private T
{
public:
	static T &Instance()
	{
		static Singleton<T> _instance;
		return _instance;
	}
private:
	Singleton()
	{
		
	}
	~Singleton()
	{
		
	}
};

template <typename T>
T &GetSingle()
{
	return Singleton<T>::Instance();
}

}

#endif