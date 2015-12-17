#ifndef Tpiu_H
#define Tpiu_H

#include "Gpio.h"
#include "CoreDebug.h"

#define SWO_TRACE_PORT                    PORTB /* Physical pin is beside PG15*/
#define SWO_TRACE_PIN                     PIN_3 

#define TRACE_PORT                        PORTE
#define TRACE_CLOCK_PIN                   PIN_2
#define TRACE_DATA0_PIN                   PIN_3

/* TPIU trace port size selection
 */
#define TPIU_PORT_SIZE_1                  ((uint32_t) 0x00000001)
#define TPIU_PORT_SIZE_2                  ((uint32_t) 0x00000002)
/* TPIU_PORT_SIZE_3 is not supported */
#define TPIU_PORT_SIZE_4                  ((uint32_t) 0x00000004)

/* TPIU trace port protocol selection
   - The standard UART (NRZ) capture mechanism, 5% accuracy is needed.
   - The Manchester encoded version is tolerant up to 10%.
 */
#define SYNC_PROTOCOL                     ((uint32_t) 0x00000000)
#define MANCHESTER_PROTOCOL               ((uint32_t) 0x00000001)
#define NRZ_PROTOCOL                      ((uint32_t) 0x00000002)

/* TRACE Pin mode assignment */
#define ASYNC_MODE                        ((uint32_t) 0x00000000)
#define SYNC_MODE_WITH_1DATA              ((uint32_t) 0x00000040)
#define SYNC_MODE_WITH_2DATA              ((uint32_t) 0x00000080)
#define SYNC_MODE_WITH_4DATA              ((uint32_t) 0x000000C0)

/* ############### Configure target TPIU through Serial Wire Debug (SWD) ############### */
#define enableTraceDebug()                    memoryWriteWord((uint32_t)&CoreDebug->DEMCR, DEMCR_TRCENA_MASK) /* Enable TRCEN bit in DEMCR */
#define enableTraceIOandMode(__MODE__)        memoryWriteWord((uint32_t)&DBGMCU->CR, (DBGMCU_CR_TRACE_IOEN | __MODE__))    /* Enable trace I/O (SWO, TRACECLK, TRACEDATA) */
#define tpiuPortSize(__PORT_SIZE__)           memoryWriteWord((uint32_t)&TPI->CSPSR, __PORT_SIZE__)           /* Configure TPIU trace port size */
#define tpiuFormatter(__CONFIG_BIT__)         memoryWriteWord((uint32_t)&TPI->FFCR, __CONFIG_BIT__)           /* Configure TPIU output format */
#define tpiuProtocol(__PROTOCOL__)            memoryWriteWord((uint32_t)&TPI->SPPR, __PROTOCOL__)             /* Configure TPIU trace port protocol */
#define tpiuAsynPrescaler(__VALUE__)          memoryWriteWord((uint32_t)&TPI->ACPR, __VALUE__)
#define tpiuSupportedPortSize(__PORT_SIZE__)  memoryWriteWord((uint32_t)&TPI->SSPSR, __PORT_SIZE__)

void tpiuConfigTracePort(void);
void tpiuInit(void);

#endif // Tpiu_H
