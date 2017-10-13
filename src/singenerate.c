#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>



/*ViSession defaultRM;
ViSession viDG1022;
ViFindList fList;
ViUInt32 numInst;
ViChar desc[VI_FIND_BUFLEN];
*/
ViStatus status;
int singenerate(ViSession*  viDG1022,int freq,float amp,float offset)
{

	/*
status=viOpenDefaultRM(&defaultRM);
if(status !=VI_SUCCESS) return EXIT_FAILURE;
status=viFindRsrc(defaultRM,"USB[0-9]::0x0400?*INSTR",&fList,&numInst,desc);
status=viOpen(defaultRM,desc,VI_NULL,VI_NULL,&viDG1022);
*/
	ViChar commandbuffer[55];
sprintf(commandbuffer,"FREQ  %i",freq); 									//set frequency
status= viWrite(*viDG1022,commandbuffer,sizeof commandbuffer, VI_NULL);
sleep(2);
sprintf(commandbuffer,"VOLT %f",amp); 										//amplitude voltage
status= viWrite(*viDG1022,commandbuffer,sizeof commandbuffer, VI_NULL);
sleep(2);
sprintf(commandbuffer,"VOLT:OFFS %f",offset); 								//offset voltage
status= viWrite(*viDG1022,commandbuffer,sizeof commandbuffer, VI_NULL);
printf("freq=%i amp=%f offset=%f", freq,amp,offset); 						//printing variables
  return 0;
}

