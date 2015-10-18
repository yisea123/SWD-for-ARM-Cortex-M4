/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  CMock_Init(); \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
    CMock_Verify(); \
  } \
  CMock_Destroy(); \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "mock_Flash.h"
#include "mock_memoryRW.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_stubCopy_should_get_flash_sram_start_address_length_and_call_Flash_Copy_func(void);
extern void test_stubErase_should_get_flash_address_and_flash_size_and_call_flashErase_func(void);
extern void test_stubMassErase_should_get_bank_select_from_SRAM_and_call_flashMassErase_func(void);
extern void test_svcServiceHandler_should_call_request_sram_address(void);
extern void test_svcServiceHandler_should_call_request_copy(void);
extern void test_svcServiceHandler_should_call_request_erase(void);
extern void test_svcServiceHandler_should_call_request_mass_erase(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_Flash_Init();
  mock_memoryRW_Init();
}
static void CMock_Verify(void)
{
  mock_Flash_Verify();
  mock_memoryRW_Verify();
}
static void CMock_Destroy(void)
{
  mock_Flash_Destroy();
  mock_memoryRW_Destroy();
}

//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


//=======MAIN=====
int main(void)
{
  UnityBegin("test_swdStub.c");
  RUN_TEST(test_stubCopy_should_get_flash_sram_start_address_length_and_call_Flash_Copy_func, 10);
  RUN_TEST(test_stubErase_should_get_flash_address_and_flash_size_and_call_flashErase_func, 28);
  RUN_TEST(test_stubMassErase_should_get_bank_select_from_SRAM_and_call_flashMassErase_func, 45);
  RUN_TEST(test_svcServiceHandler_should_call_request_sram_address, 61);
  RUN_TEST(test_svcServiceHandler_should_call_request_copy, 72);
  RUN_TEST(test_svcServiceHandler_should_call_request_erase, 89);
  RUN_TEST(test_svcServiceHandler_should_call_request_mass_erase, 104);

  CMock_Guts_MemFreeFinal();
  return (UnityEnd());
}
