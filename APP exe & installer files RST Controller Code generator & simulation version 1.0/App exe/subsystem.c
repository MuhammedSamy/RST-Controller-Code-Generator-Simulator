#include "Subsystem.h"
#include "RSTParameters.h"
DW rtDW;
ExtU rtU;
ExtY rtY;
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
void Subsystem_step(void)
{
real_T rtb_Sum1;
rtb_Sum1 = (((((T1 * rtU.In1 + T2 * rtDW.Tz_states[0])
+T3  * rtDW.Tz_states[1]) - ((R1 * rtU.In2 + R2*rtDW.Rz_states[0]) +
R3 * rtDW.Rz_states[1])) - S2 *rtDW.uSz_states[0])
- S3 * rtDW.uSz_states[1]) / S1;
rtY.Out1 = rtb_Sum1;
rtDW.Tz_states[1] = rtDW.Tz_states[0];
rtDW.Tz_states[0] = rtU.In1;
rtDW.Rz_states[1] = rtDW.Rz_states[0];
rtDW.Rz_states[0] = rtU.In2;
rtDW.uSz_states[1] = rtDW.uSz_states[0];
rtDW.uSz_states[0] = rtb_Sum1;
}
void Subsystem_initialize(void)
{
}
void Subsystem_terminate(void)
{
}
