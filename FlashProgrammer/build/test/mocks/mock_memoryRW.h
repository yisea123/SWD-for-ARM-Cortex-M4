/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_MEMORYRW_H
#define _MOCK_MEMORYRW_H

#include "memoryRW.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC)
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_memoryRW_Init(void);
void mock_memoryRW_Destroy(void);
void mock_memoryRW_Verify(void);




#define readMemoryData_IgnoreAndReturn(cmock_retval) readMemoryData_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void readMemoryData_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t cmock_to_return);
#define readMemoryData_ExpectAndReturn(address, cmock_retval) readMemoryData_CMockExpectAndReturn(__LINE__, address, cmock_retval)
void readMemoryData_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t address, uint32_t cmock_to_return);
typedef uint32_t (* CMOCK_readMemoryData_CALLBACK)(uint32_t address, int cmock_num_calls);
void readMemoryData_StubWithCallback(CMOCK_readMemoryData_CALLBACK Callback);
#define writeMemoryData_Ignore() writeMemoryData_CMockIgnore()
void writeMemoryData_CMockIgnore(void);
#define writeMemoryData_Expect(address, data) writeMemoryData_CMockExpect(__LINE__, address, data)
void writeMemoryData_CMockExpect(UNITY_LINE_TYPE cmock_line, uint32_t address, uint32_t data);
typedef void (* CMOCK_writeMemoryData_CALLBACK)(uint32_t address, uint32_t data, int cmock_num_calls);
void writeMemoryData_StubWithCallback(CMOCK_writeMemoryData_CALLBACK Callback);

#endif
