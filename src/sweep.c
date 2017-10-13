#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>


ViStatus status;
/*
ViSession defaultRM;
ViSession viDG1022;
ViFindList fList;
ViUInt32 numInst;
ViChar desc[VI_FIND_BUFLEN];
ViChar resultBuffer[256];
ViUInt32 resultCount;
*/
int sweep(ViSession* viDG1022, int start,int stop,int time)
{
	
ViChar commandbuffer[55];
/*
   status=viOpenDefaultRM(&defaultRM);
 if(status !=VI_SUCCESS) return EXIT_FAILURE;
  status=viFindRsrc(defaultRM,"USB[0-9]::0x0400?*INSTR",&fList,&numInst,desc);
  status=viOpen(defaultRM,desc,VI_NULL,VI_NULL,&viDG1022);
  sleep(2);
  */

	status= viWrite(*viDG1022,"SWE:STAT ON",30,VI_NULL);  
 	sleep(2);
 	status= viWrite(*viDG1022,"SWE:SPAC LIN",30,VI_NULL);
 	sleep(2);
	sprintf(commandbuffer,"FREQ:STAR %i,",start); 									//start sweep
	status= viWrite(*viDG1022,commandbuffer,sizeof commandbuffer, VI_NULL);
	sleep(2);
 	sprintf(commandbuffer,"FREQ:STOP %i,",stop); 									//stop sweep
 	status= viWrite(*viDG1022,commandbuffer,sizeof commandbuffer, VI_NULL);
 	sleep(2);
 	sprintf(commandbuffer,"SWE:TIME %i,",time); 									//sweep time
 	status= viWrite(*viDG1022,commandbuffer,sizeof commandbuffer, VI_NULL);
	sleep(2);
	printf("start=%i stop=%i time=%i",start,stop,time); 							//printing variables
return 0;
}

//start sweep