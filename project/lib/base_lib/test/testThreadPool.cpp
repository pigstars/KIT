#include <iostream>
#include "../CThreadPool.h"

using namespace std;

void func(void * arg)
{
	std::cout << "hello" << endl;
}
int main(int argc, char *argv[]) {
	threadPool_t *test = threadPoolInit(8);
	threadPoolAdd(test, func, NULL);
	threadPoolAdd(test, func, NULL);
	threadPoolAdd(test, func, NULL);
	while(1)
	{
		
	}
}