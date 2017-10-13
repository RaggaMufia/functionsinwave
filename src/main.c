#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>

#include <idn.h>
#include <funoff.h>
#include <funon.h>
#include <startsin.h>
#include <sweep.h>
#include <trigger.h>
#include <singenerate.h>


int main(void)
{
	/*
ViStatus status;
ViSession defaultRM;
ViSession viDG1022;
ViFindList fList;
ViUInt32 numInst;
ViChar desc[VI_FIND_BUFLEN];
ViChar resultBuffer[256];
ViUInt32 resultCount;
*/
int start=23;  //start sweep
int stop=4444; //stop sweep
int time=1; //time sweep 
int freq=53442; //set frequency
int amp=2;  //amplitude voltage
int offset=2; //offset voltage
ViSession viDG1022;

	idn(&viDG1022); //outputing instrument data
	startsin(); //setting the wave as a sin wave
	sweep(&viDG1022,start,stop,time);  //sweeping from the start freq to the stop freq over a set time
	singenerate(&viDG1022,freq,amp,offset);  //setting the frequnecy, amplitude voltage, and the offset voltage
	trigger(); //starting the trigger
	funon(); //turning the function generator on

return 0;
}