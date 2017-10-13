#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>

ViStatus status;
ViSession defaultRM;
ViSession viDG1022;
ViFindList fList;
ViUInt32 numInst;
ViChar desc[VI_FIND_BUFLEN];


int funoff(void)
{

status=viOpenDefaultRM(&defaultRM);

 if(status !=VI_SUCCESS) return EXIT_FAILURE;

  status=viFindRsrc(defaultRM,"USB0::0x0400::0x09C4::DG1D182403424::INSTR",&fList,&numInst,desc);
 
  status=viOpen(defaultRM,desc,VI_NULL,VI_NULL,&viDG1022);

  status= viWrite(viDG1022,"OUTP OFF\n",8,VI_NULL);

return 0;
}


