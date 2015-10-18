#ifndef swd_H
#define swd_H

#include "Delay.h"
#include "swd_Utilities.h"
#include "configurePort.h"
#include "IoOperations.h"
#include "MemoryReadWrite.h"

void switchJTAGtoSWD(void);
SwdError swdInit(void);

#endif // swd_H
