#ifndef RTW_HEADER_Subsystem_h_
#define RTW_HEADER_Subsystem_h_
#ifndef Subsystem_COMMON_INCLUDES_
# define Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif
#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif
typedef struct tag_RTM RT_MODEL;
typedef struct {
real_T Tz_states[2];
real_T Rz_states[2];
real_T uSz_states[2]; 
} DW;
typedef struct {
real_T In1;
real_T In2; 
} ExtU;
typedef struct {
 real_T Out1; 
} ExtY;
struct tag_RTM {
const char_T * volatile errorStatus;
};
extern DW rtDW;
extern ExtU rtU;
extern ExtY rtY;
extern void Subsystem_initialize(void);
extern void Subsystem_step(void);
extern void Subsystem_terminate(void);
extern RT_MODEL *const rtM;
#endif  
