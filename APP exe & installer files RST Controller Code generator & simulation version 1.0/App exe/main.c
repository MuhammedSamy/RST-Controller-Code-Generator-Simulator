#include <stddef.h>
#include <stdio.h>
#include "Subsystem.h"
#include "rtwtypes.h"
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;
if (OverrunFlag) {
rtmSetErrorStatus(rtM, "Overrun");
return;
  }
  OverrunFlag = true;
Subsystem_step();
OverrunFlag = false;
}
int_T main(int_T argc, const char *argv[]) 
{
  (void)(argc);  (void)(argv);
Subsystem_initialize();
printf("Warning: The simulation will run forever. ");
  fflush((NULL));
while (rtmGetErrorStatus(rtM) == (NULL)) {
  }
Subsystem_terminate();
  return 0;
} 
