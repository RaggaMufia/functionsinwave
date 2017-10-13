#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>

ViStatus status;
ViSession defaultRM;
ViSession viDG1022;
ViFindList fList;
ViUInt32 numInst;
ViChar desc[VI_FIND_BUFLEN];
ViChar resultBuffer[256];
ViUInt32 resultCount;

int idn(ViSession* viDG1022)
{
 status=viOpenDefaultRM(&defaultRM);

 if(status !=VI_SUCCESS) return EXIT_FAILURE;

  status=viFindRsrc(defaultRM,"USB[0-9]::0x0400?*INSTR",&fList,&numInst,desc);
 
  status=viOpen(defaultRM,desc,VI_NULL,VI_NULL,viDG1022);

   printf("\nOpened: %s", desc);

  sleep(2);
  status= viWrite(*viDG1022,"*IDN?\n",6,VI_NULL);
  sleep(2);
  status= viRead(*viDG1022,resultBuffer,256,&resultCount );
  sleep(2);
  printf("\nFound instrument: %s", resultBuffer);

  return 0;
}
