/* CREDITS:
Student Name:   Nguyen Duy Thanh
Student Number: e1601122
School:         VAASA University of Applied Sciences (VAMK), Vaasa, Finland
-------------------------------------------------------------------------------*/

//This is a C++ program to blink the onboard leds of the raspberry pi 3 model B.

/*P.S: If you want to enforce your knowledge on the programming language C++ make sure to visit my
github page: .... . Also, feel free to leave any comments/suggestions and if you wish to use this
code for your own project(s) please be sure to include the credits. Thank you and have a nice day :D */

// ofstream: Stream class to write on files.
// ifstream: Stream class to read from files.
// fstream:  Stream class to read and write from/to files.

#include <fstream>     //To read/write from/to files
#include <unistd.h>    //For the function sleep() to work
#include <time.h>      //For the function ms_sleep() to work

using namespace std;
const int MILISEC=100; //For how long shall the program sleep (in mili-seconds)
const int TIMES=100;   //How many times the loop shall run.

void ms_sleep(int milisec) // function to make the program sleep in mili-seconds
{
	struct timespec res;
	res.tv_sec = milisec/1000;
	res.tv_nsec= (milisec*1000000) % 1000000000;
	clock_nanosleep(CLOCK_MONOTONIC, 0, &res, NULL);
}

void led0()  // function to blink the pi3's ACT led (the green one)
{
	ofstream ledf0;
	//"brightness" is the file you need to write to, and
	//"/sys/class/leds/led0" is where the file is located.
	//=> if you're using a different model of RPi, make sure to check for the proper file location.
	ledf0.open ("/sys/class/leds/led0/brightness");
	ledf0<<"1";
	ledf0.close();
	ms_sleep(MILISEC);
	ledf0.open ("/sys/class/leds/led0/brightness");
	ledf0<<"0";
	ledf0.close();
	ms_sleep(MILISEC);
}

void led1()  // function to blink the pi3's PWR led (the red one)
{
	ofstream ledf1;
	ledf1.open ("/sys/class/leds/led1/brightness");
	ledf1<<"1";
	ledf1.close();
	ms_sleep(MILISEC);
	ledf1.open ("/sys/class/leds/led1/brightness");
	ledf1<<"0";
	ledf1.close();
	ms_sleep(MILISEC);
}

int main(void)
{
	for(int i=0; i<TIMES; ++i)  //Creating a loop for the program to run multiple times.
	{
		led0();
		led1();
//		sleep(1);  //If you want to see the gap between each loop clearly then un-comment the beginning of this line.
	}
	return 0;
}
