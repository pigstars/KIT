

#include <stdio.h>

#define myprintf(...) printf("[lch]:File:%s, Line:%d, Function:%s," \
     __VA_ARGS__, __FILE__, __LINE__ ,__FUNCTION__);

int main()
{
	myprintf("abbbbb");
}