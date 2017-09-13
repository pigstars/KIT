#include <iostream>
#include <string>
#include <vector>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>

using namespace boost;

int main()
{
	mutex mu;
	
	try {
		using namespace std;
		this_thread::sleep(posix_time::seconds(2));
		mu.lock();
		cout << "Some operations" << endl;
		mu.unlock();
	} catch (int) {
		mu.unlock();
		return 0;
	}
}