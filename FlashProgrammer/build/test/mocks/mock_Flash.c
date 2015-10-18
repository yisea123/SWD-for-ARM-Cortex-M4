/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_Flash.h"

typedef struct _CMOCK_flashGetSector_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  uint32_t ReturnVal;
  int CallOrder;
  uint32_t Expected_Address;

} CMOCK_flashGetSector_CALL_INSTANCE;

typedef struct _CMOCK_flashErrorHandler_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_flashErrorHandler_CALL_INSTANCE;

typedef struct _CMOCK_flashMassErase_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  uint32_t Expected_banks;

} CMOCK_flashMassErase_CALL_INSTANCE;

typedef struct _CMOCK_flashErase_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  uint32_t Expected_flashAddress;
  int Expected_size;

} CMOCK_flashErase_CALL_INSTANCE;

typedef struct _CMOCK_flashWrite_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  uint32_t* Expected_data;
  uint32_t Expected_address;
  int Expected_size;

} CMOCK_flashWrite_CALL_INSTANCE;

typedef struct _CMOCK_flashCopyFromSramToFlash_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  uint32_t Expected_src;
  uint32_t Expected_dest;
  int Expected_size;

} CMOCK_flashCopyFromSramToFlash_CALL_INSTANCE;

typedef struct _CMOCK_flashWriteProgram_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  uint32_t Expected_typeProgram;
  uint32_t Expected_address;
  uint32_t Expected_data;

} CMOCK_flashWriteProgram_CALL_INSTANCE;

static struct mock_FlashInstance
{
  int flashGetSector_IgnoreBool;
  uint32_t flashGetSector_FinalReturn;
  CMOCK_flashGetSector_CALLBACK flashGetSector_CallbackFunctionPointer;
  int flashGetSector_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE flashGetSector_CallInstance;
  int flashErrorHandler_IgnoreBool;
  CMOCK_flashErrorHandler_CALLBACK flashErrorHandler_CallbackFunctionPointer;
  int flashErrorHandler_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE flashErrorHandler_CallInstance;
  int flashMassErase_IgnoreBool;
  CMOCK_flashMassErase_CALLBACK flashMassErase_CallbackFunctionPointer;
  int flashMassErase_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE flashMassErase_CallInstance;
  int flashErase_IgnoreBool;
  CMOCK_flashErase_CALLBACK flashErase_CallbackFunctionPointer;
  int flashErase_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE flashErase_CallInstance;
  int flashWrite_IgnoreBool;
  CMOCK_flashWrite_CALLBACK flashWrite_CallbackFunctionPointer;
  int flashWrite_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE flashWrite_CallInstance;
  int flashCopyFromSramToFlash_IgnoreBool;
  CMOCK_flashCopyFromSramToFlash_CALLBACK flashCopyFromSramToFlash_CallbackFunctionPointer;
  int flashCopyFromSramToFlash_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE flashCopyFromSramToFlash_CallInstance;
  int flashWriteProgram_IgnoreBool;
  CMOCK_flashWriteProgram_CALLBACK flashWriteProgram_CallbackFunctionPointer;
  int flashWriteProgram_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE flashWriteProgram_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_Flash_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.flashGetSector_IgnoreBool)
    Mock.flashGetSector_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.flashGetSector_CallInstance, cmock_line, "Function 'flashGetSector' called less times than expected.");
  if (Mock.flashGetSector_CallbackFunctionPointer != NULL)
    Mock.flashGetSector_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.flashErrorHandler_IgnoreBool)
    Mock.flashErrorHandler_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.flashErrorHandler_CallInstance, cmock_line, "Function 'flashErrorHandler' called less times than expected.");
  if (Mock.flashErrorHandler_CallbackFunctionPointer != NULL)
    Mock.flashErrorHandler_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.flashMassErase_IgnoreBool)
    Mock.flashMassErase_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.flashMassErase_CallInstance, cmock_line, "Function 'flashMassErase' called less times than expected.");
  if (Mock.flashMassErase_CallbackFunctionPointer != NULL)
    Mock.flashMassErase_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.flashErase_IgnoreBool)
    Mock.flashErase_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.flashErase_CallInstance, cmock_line, "Function 'flashErase' called less times than expected.");
  if (Mock.flashErase_CallbackFunctionPointer != NULL)
    Mock.flashErase_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.flashWrite_IgnoreBool)
    Mock.flashWrite_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.flashWrite_CallInstance, cmock_line, "Function 'flashWrite' called less times than expected.");
  if (Mock.flashWrite_CallbackFunctionPointer != NULL)
    Mock.flashWrite_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.flashCopyFromSramToFlash_IgnoreBool)
    Mock.flashCopyFromSramToFlash_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.flashCopyFromSramToFlash_CallInstance, cmock_line, "Function 'flashCopyFromSramToFlash' called less times than expected.");
  if (Mock.flashCopyFromSramToFlash_CallbackFunctionPointer != NULL)
    Mock.flashCopyFromSramToFlash_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.flashWriteProgram_IgnoreBool)
    Mock.flashWriteProgram_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.flashWriteProgram_CallInstance, cmock_line, "Function 'flashWriteProgram' called less times than expected.");
  if (Mock.flashWriteProgram_CallbackFunctionPointer != NULL)
    Mock.flashWriteProgram_CallInstance = CMOCK_GUTS_NONE;
}

void mock_Flash_Init(void)
{
  mock_Flash_Destroy();
}

void mock_Flash_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.flashGetSector_CallbackFunctionPointer = NULL;
  Mock.flashGetSector_CallbackCalls = 0;
  Mock.flashErrorHandler_CallbackFunctionPointer = NULL;
  Mock.flashErrorHandler_CallbackCalls = 0;
  Mock.flashMassErase_CallbackFunctionPointer = NULL;
  Mock.flashMassErase_CallbackCalls = 0;
  Mock.flashErase_CallbackFunctionPointer = NULL;
  Mock.flashErase_CallbackCalls = 0;
  Mock.flashWrite_CallbackFunctionPointer = NULL;
  Mock.flashWrite_CallbackCalls = 0;
  Mock.flashCopyFromSramToFlash_CallbackFunctionPointer = NULL;
  Mock.flashCopyFromSramToFlash_CallbackCalls = 0;
  Mock.flashWriteProgram_CallbackFunctionPointer = NULL;
  Mock.flashWriteProgram_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

uint32_t flashGetSector(uint32_t Address)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_flashGetSector_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashGetSector_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.flashGetSector_CallInstance);
  Mock.flashGetSector_CallInstance = CMock_Guts_MemNext(Mock.flashGetSector_CallInstance);
  if (Mock.flashGetSector_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return (uint32_t)Mock.flashGetSector_FinalReturn;
    Mock.flashGetSector_FinalReturn = cmock_call_instance->ReturnVal;
    return (uint32_t)cmock_call_instance->ReturnVal;
  }
  if (Mock.flashGetSector_CallbackFunctionPointer != NULL)
  {
    return Mock.flashGetSector_CallbackFunctionPointer(Address, Mock.flashGetSector_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'flashGetSector' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashGetSector' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashGetSector' called later than expected.");
  {
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_Address, Address, cmock_line, "Function 'flashGetSector' called with unexpected value for argument 'Address'.");
  }
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_flashGetSector(CMOCK_flashGetSector_CALL_INSTANCE* cmock_call_instance, uint32_t Address)
{
  cmock_call_instance->Expected_Address = Address;
}

void flashGetSector_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_flashGetSector_CALL_INSTANCE));
  CMOCK_flashGetSector_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashGetSector_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.flashGetSector_CallInstance = CMock_Guts_MemChain(Mock.flashGetSector_CallInstance, cmock_guts_index);
  Mock.flashGetSector_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.flashGetSector_IgnoreBool = (int)1;
}

void flashGetSector_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t Address, uint32_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_flashGetSector_CALL_INSTANCE));
  CMOCK_flashGetSector_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashGetSector_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.flashGetSector_CallInstance = CMock_Guts_MemChain(Mock.flashGetSector_CallInstance, cmock_guts_index);
  Mock.flashGetSector_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_flashGetSector(cmock_call_instance, Address);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void flashGetSector_StubWithCallback(CMOCK_flashGetSector_CALLBACK Callback)
{
  Mock.flashGetSector_CallbackFunctionPointer = Callback;
}

void flashErrorHandler(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_flashErrorHandler_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashErrorHandler_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.flashErrorHandler_CallInstance);
  Mock.flashErrorHandler_CallInstance = CMock_Guts_MemNext(Mock.flashErrorHandler_CallInstance);
  if (Mock.flashErrorHandler_IgnoreBool)
  {
    return;
  }
  if (Mock.flashErrorHandler_CallbackFunctionPointer != NULL)
  {
    Mock.flashErrorHandler_CallbackFunctionPointer(Mock.flashErrorHandler_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'flashErrorHandler' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashErrorHandler' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashErrorHandler' called later than expected.");
}

void flashErrorHandler_CMockIgnore(void)
{
  Mock.flashErrorHandler_IgnoreBool = (int)1;
}

void flashErrorHandler_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_flashErrorHandler_CALL_INSTANCE));
  CMOCK_flashErrorHandler_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashErrorHandler_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.flashErrorHandler_CallInstance = CMock_Guts_MemChain(Mock.flashErrorHandler_CallInstance, cmock_guts_index);
  Mock.flashErrorHandler_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void flashErrorHandler_StubWithCallback(CMOCK_flashErrorHandler_CALLBACK Callback)
{
  Mock.flashErrorHandler_CallbackFunctionPointer = Callback;
}

void flashMassErase(uint32_t banks)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_flashMassErase_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashMassErase_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.flashMassErase_CallInstance);
  Mock.flashMassErase_CallInstance = CMock_Guts_MemNext(Mock.flashMassErase_CallInstance);
  if (Mock.flashMassErase_IgnoreBool)
  {
    return;
  }
  if (Mock.flashMassErase_CallbackFunctionPointer != NULL)
  {
    Mock.flashMassErase_CallbackFunctionPointer(banks, Mock.flashMassErase_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'flashMassErase' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashMassErase' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashMassErase' called later than expected.");
  {
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_banks, banks, cmock_line, "Function 'flashMassErase' called with unexpected value for argument 'banks'.");
  }
}

void CMockExpectParameters_flashMassErase(CMOCK_flashMassErase_CALL_INSTANCE* cmock_call_instance, uint32_t banks)
{
  cmock_call_instance->Expected_banks = banks;
}

void flashMassErase_CMockIgnore(void)
{
  Mock.flashMassErase_IgnoreBool = (int)1;
}

void flashMassErase_CMockExpect(UNITY_LINE_TYPE cmock_line, uint32_t banks)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_flashMassErase_CALL_INSTANCE));
  CMOCK_flashMassErase_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashMassErase_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.flashMassErase_CallInstance = CMock_Guts_MemChain(Mock.flashMassErase_CallInstance, cmock_guts_index);
  Mock.flashMassErase_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_flashMassErase(cmock_call_instance, banks);
}

void flashMassErase_StubWithCallback(CMOCK_flashMassErase_CALLBACK Callback)
{
  Mock.flashMassErase_CallbackFunctionPointer = Callback;
}

void flashErase(uint32_t flashAddress, int size)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_flashErase_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashErase_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.flashErase_CallInstance);
  Mock.flashErase_CallInstance = CMock_Guts_MemNext(Mock.flashErase_CallInstance);
  if (Mock.flashErase_IgnoreBool)
  {
    return;
  }
  if (Mock.flashErase_CallbackFunctionPointer != NULL)
  {
    Mock.flashErase_CallbackFunctionPointer(flashAddress, size, Mock.flashErase_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'flashErase' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashErase' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashErase' called later than expected.");
  {
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_flashAddress, flashAddress, cmock_line, "Function 'flashErase' called with unexpected value for argument 'flashAddress'.");
  }
  {
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_size, size, cmock_line, "Function 'flashErase' called with unexpected value for argument 'size'.");
  }
}

void CMockExpectParameters_flashErase(CMOCK_flashErase_CALL_INSTANCE* cmock_call_instance, uint32_t flashAddress, int size)
{
  cmock_call_instance->Expected_flashAddress = flashAddress;
  cmock_call_instance->Expected_size = size;
}

void flashErase_CMockIgnore(void)
{
  Mock.flashErase_IgnoreBool = (int)1;
}

void flashErase_CMockExpect(UNITY_LINE_TYPE cmock_line, uint32_t flashAddress, int size)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_flashErase_CALL_INSTANCE));
  CMOCK_flashErase_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashErase_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.flashErase_CallInstance = CMock_Guts_MemChain(Mock.flashErase_CallInstance, cmock_guts_index);
  Mock.flashErase_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_flashErase(cmock_call_instance, flashAddress, size);
}

void flashErase_StubWithCallback(CMOCK_flashErase_CALLBACK Callback)
{
  Mock.flashErase_CallbackFunctionPointer = Callback;
}

void flashWrite(uint32_t* data, uint32_t address, int size)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_flashWrite_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashWrite_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.flashWrite_CallInstance);
  Mock.flashWrite_CallInstance = CMock_Guts_MemNext(Mock.flashWrite_CallInstance);
  if (Mock.flashWrite_IgnoreBool)
  {
    return;
  }
  if (Mock.flashWrite_CallbackFunctionPointer != NULL)
  {
    Mock.flashWrite_CallbackFunctionPointer(data, address, size, Mock.flashWrite_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'flashWrite' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashWrite' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashWrite' called later than expected.");
  {
    if (cmock_call_instance->Expected_data == NULL)
      { UNITY_TEST_ASSERT_NULL(data, cmock_line, "Expected NULL. Function 'flashWrite' called with unexpected value for argument 'data'."); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX32_ARRAY(cmock_call_instance->Expected_data, data, 1, cmock_line, "Function 'flashWrite' called with unexpected value for argument 'data'."); }
  }
  {
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_address, address, cmock_line, "Function 'flashWrite' called with unexpected value for argument 'address'.");
  }
  {
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_size, size, cmock_line, "Function 'flashWrite' called with unexpected value for argument 'size'.");
  }
}

void CMockExpectParameters_flashWrite(CMOCK_flashWrite_CALL_INSTANCE* cmock_call_instance, uint32_t* data, uint32_t address, int size)
{
  cmock_call_instance->Expected_data = data;
  cmock_call_instance->Expected_address = address;
  cmock_call_instance->Expected_size = size;
}

void flashWrite_CMockIgnore(void)
{
  Mock.flashWrite_IgnoreBool = (int)1;
}

void flashWrite_CMockExpect(UNITY_LINE_TYPE cmock_line, uint32_t* data, uint32_t address, int size)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_flashWrite_CALL_INSTANCE));
  CMOCK_flashWrite_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashWrite_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.flashWrite_CallInstance = CMock_Guts_MemChain(Mock.flashWrite_CallInstance, cmock_guts_index);
  Mock.flashWrite_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_flashWrite(cmock_call_instance, data, address, size);
}

void flashWrite_StubWithCallback(CMOCK_flashWrite_CALLBACK Callback)
{
  Mock.flashWrite_CallbackFunctionPointer = Callback;
}

void flashCopyFromSramToFlash(uint32_t src, uint32_t dest, int size)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_flashCopyFromSramToFlash_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashCopyFromSramToFlash_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.flashCopyFromSramToFlash_CallInstance);
  Mock.flashCopyFromSramToFlash_CallInstance = CMock_Guts_MemNext(Mock.flashCopyFromSramToFlash_CallInstance);
  if (Mock.flashCopyFromSramToFlash_IgnoreBool)
  {
    return;
  }
  if (Mock.flashCopyFromSramToFlash_CallbackFunctionPointer != NULL)
  {
    Mock.flashCopyFromSramToFlash_CallbackFunctionPointer(src, dest, size, Mock.flashCopyFromSramToFlash_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'flashCopyFromSramToFlash' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashCopyFromSramToFlash' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashCopyFromSramToFlash' called later than expected.");
  {
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_src, src, cmock_line, "Function 'flashCopyFromSramToFlash' called with unexpected value for argument 'src'.");
  }
  {
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_dest, dest, cmock_line, "Function 'flashCopyFromSramToFlash' called with unexpected value for argument 'dest'.");
  }
  {
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_size, size, cmock_line, "Function 'flashCopyFromSramToFlash' called with unexpected value for argument 'size'.");
  }
}

void CMockExpectParameters_flashCopyFromSramToFlash(CMOCK_flashCopyFromSramToFlash_CALL_INSTANCE* cmock_call_instance, uint32_t src, uint32_t dest, int size)
{
  cmock_call_instance->Expected_src = src;
  cmock_call_instance->Expected_dest = dest;
  cmock_call_instance->Expected_size = size;
}

void flashCopyFromSramToFlash_CMockIgnore(void)
{
  Mock.flashCopyFromSramToFlash_IgnoreBool = (int)1;
}

void flashCopyFromSramToFlash_CMockExpect(UNITY_LINE_TYPE cmock_line, uint32_t src, uint32_t dest, int size)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_flashCopyFromSramToFlash_CALL_INSTANCE));
  CMOCK_flashCopyFromSramToFlash_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashCopyFromSramToFlash_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.flashCopyFromSramToFlash_CallInstance = CMock_Guts_MemChain(Mock.flashCopyFromSramToFlash_CallInstance, cmock_guts_index);
  Mock.flashCopyFromSramToFlash_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_flashCopyFromSramToFlash(cmock_call_instance, src, dest, size);
}

void flashCopyFromSramToFlash_StubWithCallback(CMOCK_flashCopyFromSramToFlash_CALLBACK Callback)
{
  Mock.flashCopyFromSramToFlash_CallbackFunctionPointer = Callback;
}

void flashWriteProgram(uint32_t typeProgram, uint32_t address, uint32_t data)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_flashWriteProgram_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashWriteProgram_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.flashWriteProgram_CallInstance);
  Mock.flashWriteProgram_CallInstance = CMock_Guts_MemNext(Mock.flashWriteProgram_CallInstance);
  if (Mock.flashWriteProgram_IgnoreBool)
  {
    return;
  }
  if (Mock.flashWriteProgram_CallbackFunctionPointer != NULL)
  {
    Mock.flashWriteProgram_CallbackFunctionPointer(typeProgram, address, data, Mock.flashWriteProgram_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'flashWriteProgram' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashWriteProgram' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'flashWriteProgram' called later than expected.");
  {
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_typeProgram, typeProgram, cmock_line, "Function 'flashWriteProgram' called with unexpected value for argument 'typeProgram'.");
  }
  {
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_address, address, cmock_line, "Function 'flashWriteProgram' called with unexpected value for argument 'address'.");
  }
  {
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_data, data, cmock_line, "Function 'flashWriteProgram' called with unexpected value for argument 'data'.");
  }
}

void CMockExpectParameters_flashWriteProgram(CMOCK_flashWriteProgram_CALL_INSTANCE* cmock_call_instance, uint32_t typeProgram, uint32_t address, uint32_t data)
{
  cmock_call_instance->Expected_typeProgram = typeProgram;
  cmock_call_instance->Expected_address = address;
  cmock_call_instance->Expected_data = data;
}

void flashWriteProgram_CMockIgnore(void)
{
  Mock.flashWriteProgram_IgnoreBool = (int)1;
}

void flashWriteProgram_CMockExpect(UNITY_LINE_TYPE cmock_line, uint32_t typeProgram, uint32_t address, uint32_t data)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_flashWriteProgram_CALL_INSTANCE));
  CMOCK_flashWriteProgram_CALL_INSTANCE* cmock_call_instance = (CMOCK_flashWriteProgram_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.flashWriteProgram_CallInstance = CMock_Guts_MemChain(Mock.flashWriteProgram_CallInstance, cmock_guts_index);
  Mock.flashWriteProgram_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_flashWriteProgram(cmock_call_instance, typeProgram, address, data);
}

void flashWriteProgram_StubWithCallback(CMOCK_flashWriteProgram_CALLBACK Callback)
{
  Mock.flashWriteProgram_CallbackFunctionPointer = Callback;
}

