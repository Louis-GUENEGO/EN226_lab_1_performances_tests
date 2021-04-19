#include "timer.h"

#ifdef WIN32
	static double g_pcFreq = 0.0;
	static __int64 g_counterStart = 0;
#else
	static struct timeval t1, t2;
	static double elapsedTime;
#endif

void StartTimer() {
	#ifdef WIN32
		LARGE_INTEGER li;
		if (!QueryPerformanceFrequency(&li)) {
			printf( "QueryPerformanceFrequency failed !\n" );
		}
		g_pcFreq = (double)(li.QuadPart);
		QueryPerformanceCounter(&li);
		g_counterStart = li.QuadPart;
	#else
		gettimeofday( &t1, NULL );
	#endif
}

double GetTimer() {
	#ifdef WIN32
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		return (double)(li.QuadPart - g_counterStart) / g_pcFreq * 1000.0;
	#else
		gettimeofday( &t2, NULL );
		elapsedTime = (double)(t2.tv_sec - t1.tv_sec) * 1000.0;  
		elapsedTime += (double)(t2.tv_usec - t1.tv_usec) / 1000.0;
		return elapsedTime;
	#endif
}