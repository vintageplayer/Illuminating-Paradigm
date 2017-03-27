#ifdef __APPLE__
	#define SYS_OS 1
#elif defined __unix__
	#define SYS_OS 2
#elif defined __CYGWIN__
	#ifdef _WIN32 || defined _WIN64
		#define SYS_OS 3
	#define SYS_OS 2
#else
	#define 0
#endif

#include<iostream>
// Graphics Libraries

using namespace std;

int main(int argc,char** argv)
{
	cout<<endl;
	return 0;
}
