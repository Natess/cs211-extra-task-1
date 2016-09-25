#include <iostream>
#include <locale> 
#include <cassert>
#include <cmath>

using namespace std;

//Return the number of seconds later that a time in seconds
//time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

//Tests for seconds_difference
void Test_seconds_difference()
{
	//>>> seconds_difference(1800.0, 3600.0)
	//1800.0
	assert(seconds_difference(1800.0, 3600.0) == 1800.0);

	//>>> seconds_difference(3600.0, 1800.0)
	//	- 1800.0
	assert(seconds_difference(3600.0, 1800.0) == -1800.0);

	//>>> seconds_difference(1800.0, 2160.0)
	//	360.0
	assert(seconds_difference(1800.0, 2160.0) == 360.0);

	//>>> seconds_difference(1800.0, 1800.0)
	//0.0
	assert(seconds_difference(1800.0, 1800.0) == 0.0);

	cout << "Tests for seconds_difference completed successfully!" << endl;
}

//Return the number of hours later that a time in seconds
//time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600;
}

//Tests for hours_difference
void Test_hours_difference()
{
	// >>> hours_difference(1800.0, 3600.0)
	//0.5
	assert(hours_difference(1800.0, 3600.0) == 0.5);

	//>>> hours_difference(3600.0, 1800.0)
	//-0.5
	assert(hours_difference(3600.0, 1800.0) == -0.5);

	//>>> hours_difference(1800.0, 2160.0)
	//0.1
	assert(hours_difference(1800.0, 2160.0) == 0.1);

	//>>> hours_difference(1800.0, 1800.0)
	//0.0
	assert(hours_difference(1800.0, 1800.0) == 0.0);

	cout << "Tests for hours_difference completed successfully!" << endl;
}

//Return the total number of hours in the specified number
//of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
	return hours + (minutes * 100.0 / 60) / 100 + (seconds * 100.0 / 3600) / 100;
}

//Tests for to_float_hours
void Test_to_float_hours()
{
	//>>> to_float_hours(0, 15, 0)
	//0.25
	assert(to_float_hours(0, 15, 0) == 0.25);

	//>>> to_float_hours(2, 45, 9)
	//2.7525
	assert(to_float_hours(2, 45, 9) == 2.7525);

	//>>> to_float_hours(1, 0, 36)
	//1.01
	assert(to_float_hours(1, 0, 36) == 1.01);

	cout << "Tests for to_float_hours completed successfully!" << endl;
}

//hours is a number of hours since midnight.Return the
//hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
	return fmod(hours, 24.0);
}

//Tests for to_24_hour_clock
void Test_to_24_hour_clock()
{
	//>>> to_24_hour_clock(24)
	//0
	assert(to_24_hour_clock(24) == 0);

	//>>> to_24_hour_clock(48)
	//0
	assert(to_24_hour_clock(48) == 0);

	//>>> to_24_hour_clock(25)
	//1
	assert(to_24_hour_clock(25) == 1);

	//>>> to_24_hour_clock(4)
	//4
	assert(to_24_hour_clock(4) == 4);

	//>>> to_24_hour_clock(28.5)
	//4.5
	assert(to_24_hour_clock(28.5) == 4.5);

	cout << "Tests for to_24_hour_clock completed successfully!" << endl;
}

//It is used to determine the hours part
double get_hours(int seconds)
{
	return fmod(floor(seconds / 3600), 24);
}

//Tests for get_hours
void Test_get_hours()
{
	//>>> get_hours(3800)
	//1
	assert(get_hours(3800) == 1);

	//>>> get_hours(3867)
	//1
	assert(get_hours(3867) == 1);

	cout << "Tests for get_hours completed successfully!" << endl;
}

//It is used to determine the minutes part
double get_minutes(int seconds)
{
	return (seconds / 60) % 60;
}

//Tests for get_minutes
void Test_get_minutes()
{
	//>>> get_minutes(3800)
	//3
	assert(get_minutes(3800) == 3);

	//>>> get_minutes(3867)
	//4
	assert(get_minutes(3867) == 4);

	cout << "Tests for  get_minutes completed successfully!" << endl;
}

//They are used to determine the seconds part 
double get_seconds(int seconds)
{
	return seconds % 60;
}

//Tests for get_seconds
void Test_get_seconds()
{
	//>>> get_seconds(3800)
	//20
	assert(get_seconds(3800) == 20);

	//>>> get_seconds(3867)
	//1
	assert(get_seconds(3867) == 27);

	cout << "Tests for  get_seconds completed successfully!" << endl;
}

//Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time)
{
	return  fmod((utc_offset * -1 + time), 24);
}

//Tests for time_to_utc
void Test_time_to_utc()
{
	//>>> time_to_utc(+0, 12.0)
	//   12.0
	assert(time_to_utc(+0, 12.0) == 12.0);

	//>>> time_to_utc(+1, 12.0)
	//11.0
	assert(time_to_utc(+1, 12.0) == 11.0);

	//>>> time_to_utc(-1, 12.0)
	//13.0
	assert(time_to_utc(-1, 12.0) == 13.0);

	//>>> time_to_utc(-11, 18.0)
	//  5.0
	assert(time_to_utc(-11, 18.0) == 5.0);

	//>>> time_to_utc(-1, 0.0)
	//  1.0
	assert(time_to_utc(-1, 0.0) == 1.0);

	//>>> time_to_utc(-1, 23.0)
	//  0.0
	assert(time_to_utc(-1, 23.0) == 0.0);

	cout << "Tests for  time_to_utc completed successfully!" << endl;
}

//Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
	return  fmod((utc_offset + time + 24), 24);
}

//Tests for time_from_utc
void Test_time_from_utc()
{
	//>>> time_from_utc(+0, 12.0)
	//   12.0
	assert(time_from_utc(+0, 12.0) == 12.0);

	//>>> time_from_utc(+1, 12.0)
	//13.0
	assert(time_from_utc(+1, 12.0) == 13.0);

	//>>> time_from_utc(-1, 12.0)
	//11.0
	assert(time_from_utc(-1, 12.0) == 11.0);

	//>>> time_from_utc(+6, 6.0)
	//12.0
	assert(time_from_utc(+6, 6.0) == 12.0);

	//>>> time_from_utc(-7, 6.0)
	//23.0
	assert(time_from_utc(-7, 6.0) == 23.0);

	//>>> time_from_utc(-1, 0.0)
	//23.0
	assert(time_from_utc(-1, 0.0) == 23.0);

	//>>> time_from_utc(-1, 23.0)
	//22.0
	assert(time_from_utc(-1, 23.0) == 22.0);

	//>>> time_from_utc(+1, 23.0)
	//0.0
	assert(time_from_utc(+1, 23.0) == 0.0);

	cout << "Tests for time_from_utc completed successfully!" << endl;
}

int main()
{
	Test_seconds_difference();
	cout << endl;

	Test_hours_difference();
	cout << endl;

	Test_to_float_hours();
	cout << endl;

	Test_to_24_hour_clock();
	cout << endl;

	Test_get_hours();
	cout << endl;

	Test_get_minutes();
	cout << endl;

	Test_get_seconds();
	cout << endl;

	Test_time_to_utc();
	cout << endl;

	Test_time_from_utc();
}
