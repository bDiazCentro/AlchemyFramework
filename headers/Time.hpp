#ifndef TIME_H
#define TIME_H
#include <chrono>
#include <iostream>

namespace Time
{
	typedef std::chrono::high_resolution_clock clock_;
	typedef std::chrono::duration<double, std::ratio<1>> second_;
	std::chrono::time_point<clock_>  initialTime;
	float deltatime = 0, timescale = 1.0f;
	void GetInitValue()
	{
		initialTime = clock_::now();
	}

	void Elapsed()
	{
		deltatime = std::chrono::duration_cast<second_>(clock_::now() - initialTime).count();
	}
	
}


#endif