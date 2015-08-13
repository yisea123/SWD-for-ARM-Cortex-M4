#include "unity.h"
#include <stdint.h>
#include "DWT_Unit.h"
#include "DWT_Utilities.h"
#include "CoreDebug.h"
#include "CoreDebug_Utilities.h"
#include "Misc_Utilities.h"
#include "Clock.h"
#include "Emulator.h"
#include "Register_ReadWrite.h"
#include "swd_Utilities.h"
#include "Bit_Operations.h"
#include "mock_configurePort.h"
#include "mock_IO_Operations.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*------------------setAddressWatchpoint--------------*/
void test_setAddressWatchpoint_given_DWT_COMP0_address_0x12345677_mask_WATCHPOINTMASK_BIT0_WATCHPOINT_READ()
{

  //Faking CSW to Byte Size
  cswDataSize = CSW_BYTE_SIZE ;

  //Enable Global enable for DWT
  emulateswdRegisterWrite(TAR_REG,AP,4,0xE000EDFF);
  emulateswdRegisterWrite(DRW_REG,AP,4,0);

  //Set CSW to Word Size
	emulateswdRegisterWrite(SELECT_REG, DP, OK, BANK_0);
	emulateswdRegisterWrite(CSW_REG, AP, OK, (CSW_DEFAULT_MASK | CSW_WORD_SIZE));
  
  //Set CORE_DEBUG_MODE
  emulateswdRegisterWrite(TAR_REG,AP,4,DHCSR_REG);
	emulateswdRegisterWrite(DRW_REG,AP,4,SET_CORE_DEBUG);
  
  //Disable comparator first
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC0);
	emulateswdRegisterWrite(DRW_REG,AP,4,0);
  
  //Program comparator 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_COMP0);
	emulateswdRegisterWrite(DRW_REG,AP,4,0x12345677);
 
  //Program mask 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_MASK0);
	emulateswdRegisterWrite(DRW_REG,AP,4,WATCHPOINT_MASK_BIT0);
  
  //Program function
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC0);
	emulateswdRegisterWrite(DRW_REG,AP,4,WATCHPOINT_READ);
  
  TEST_ASSERT_EQUAL(0,setAddressWatchpoint(DWT_COMP0,0x12345677,WATCHPOINT_MASK_BIT0,WATCHPOINT_READ));
}

/*------------------setDataWatchpoint_MatchingOneComparator--------------*/

void test_setDataWatchpoint_MatchingOneComparator()
{
  uint32_t configData = 0 ;
  configData = (2 << 16) + (2 << 12) + (WATCHPOINT_WORD << 10) + (DATA_COMPARISON << 8) + WATCHPOINT_WRITE ;
  
  //Faking CSW to Byte Size
  cswDataSize = CSW_BYTE_SIZE ;

  //Enable Global enable for DWT
  emulateswdRegisterWrite(TAR_REG,AP,4,0xE000EDFF);
  emulateswdRegisterWrite(DRW_REG,AP,4,0);

  //Set CSW to Word Size
	emulateswdRegisterWrite(SELECT_REG, DP, OK, BANK_0);
	emulateswdRegisterWrite(CSW_REG, AP, OK, (CSW_DEFAULT_MASK | CSW_WORD_SIZE));
  
  //Set CORE_DEBUG_MODE
  emulateswdRegisterWrite(TAR_REG,AP,4,DHCSR_REG);
	emulateswdRegisterWrite(DRW_REG,AP,4,SET_CORE_DEBUG);
  
  //Disable matching comparator
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC2);
	emulateswdRegisterWrite(DRW_REG,AP,4,0);
  
  //Program matching comparator 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_COMP2);
	emulateswdRegisterWrite(DRW_REG,AP,4,0xFFFFFFFF);
  
  //Program matching mask 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_MASK2);
	emulateswdRegisterWrite(DRW_REG,AP,4,WATCHPOINT_MASK_BIT14_BIT0);
  
  //Program comparator 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_COMP1);
	emulateswdRegisterWrite(DRW_REG,AP,4,0xABCDEF12);
  
  //Program mask 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_MASK1);
	emulateswdRegisterWrite(DRW_REG,AP,4,WATCHPOINT_MASK_NOTHING);
  
  //Program function
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC1);
	emulateswdRegisterWrite(DRW_REG,AP,4,configData);
  
  TEST_ASSERT_EQUAL(0,setDataWatchpoint_MatchingOneComparator(DWT_COMP2,0xFFFFFFFF,WATCHPOINT_MASK_BIT14_BIT0,
                                                              0xABCDEF12,WATCHPOINT_WORD,WATCHPOINT_WRITE));
}

/*------------------setDataWatchpoint_MatchingTwoComparator--------------*/
void test_setDataWatchpoint_MatchingTwoComparator()
{
  uint32_t configData = 0 ;
  configData = (3 << 16) + (2 << 12) + (WATCHPOINT_BYTE << 10) + (DATA_COMPARISON << 8) + WATCHPOINT_READWRITE ;
  
  //Faking CSW to Byte Size
  cswDataSize = CSW_BYTE_SIZE ;

  //Enable Global enable for DWT
  emulateswdRegisterWrite(TAR_REG,AP,4,0xE000EDFF);
  emulateswdRegisterWrite(DRW_REG,AP,4,0);

  //Set CSW to Word Size
	emulateswdRegisterWrite(SELECT_REG, DP, OK, BANK_0);
	emulateswdRegisterWrite(CSW_REG, AP, OK, (CSW_DEFAULT_MASK | CSW_WORD_SIZE));
  
  //Set CORE_DEBUG_MODE
  emulateswdRegisterWrite(TAR_REG,AP,4,DHCSR_REG);
	emulateswdRegisterWrite(DRW_REG,AP,4,SET_CORE_DEBUG);
  
  //Disable 1st matching comparator
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC2);
	emulateswdRegisterWrite(DRW_REG,AP,4,0);
  
  //Program 1st matching comparator 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_COMP2);
	emulateswdRegisterWrite(DRW_REG,AP,4,0xBEEEEEEF);
  
  //Program 1st matching mask 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_MASK2);
	emulateswdRegisterWrite(DRW_REG,AP,4,WATCHPOINT_MASK_BIT0);
  
  //Disable 2nd matching comparator
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC3);
	emulateswdRegisterWrite(DRW_REG,AP,4,0);
  
  //Program 2nd matching comparator 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_COMP3);
	emulateswdRegisterWrite(DRW_REG,AP,4,0xA55AA55A);
  
  //Program 2nd matching mask 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_MASK3);
	emulateswdRegisterWrite(DRW_REG,AP,4,WATCHPOINT_MASK_NOTHING);
  
  //Program comparator 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_COMP1);
	emulateswdRegisterWrite(DRW_REG,AP,4,0xABCDEF12);
  
  //Program mask 
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_MASK1);
	emulateswdRegisterWrite(DRW_REG,AP,4,WATCHPOINT_MASK_NOTHING);
  
  //Program function
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC1);
	emulateswdRegisterWrite(DRW_REG,AP,4,configData);
  
  TEST_ASSERT_EQUAL(0,setDataWatchpoint_MatchingTwoComparator(DWT_COMP2,0xBEEEEEEF,WATCHPOINT_MASK_BIT0,
                                                              DWT_COMP3,0xA55AA55A, WATCHPOINT_MASK_NOTHING,
                                                              0xABCDEF12,WATCHPOINT_BYTE,WATCHPOINT_READWRITE));
}

/*------------------isDataWatchpointOccurred--------------*/
void test_isDataWatchpointOccurred_given_DWTTRAP_DEBUGEVENT_1_MATCHED_should_return_1()
{
  //Faking CSW to Byte Size
  cswDataSize = CSW_WORD_SIZE ;
  
  //DWTTRAP_DEBUGEVENT = 1
  emulateswdRegisterWrite(TAR_REG,AP,4,DFSR_REG);
  emulateswdRegisterRead(DRW_REG,AP,4,1,0x1234);
  emulateswdRegisterRead(DRW_REG,AP,4,1,convertMSB_LSB(0x4));
  
  //read DWT_FUNC1 and MATCHED bit set
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC1);
  emulateswdRegisterRead(DRW_REG,AP,4,1,0x1234);
  emulateswdRegisterRead(DRW_REG,AP,4,1,convertMSB_LSB(0x1000000));
  
  TEST_ASSERT_EQUAL(1,isDataWatchpointOccurred());
}

void test_isDataWatchpointOccurred_given_DWTTRAP_DEBUGEVENT_1_NOT_MATCHED_should_return_0()
{
  //DWTTRAP_DEBUGEVENT = 1
  emulateswdRegisterWrite(TAR_REG,AP,4,DFSR_REG);
  emulateswdRegisterRead(DRW_REG,AP,4,1,0x1234);
  emulateswdRegisterRead(DRW_REG,AP,4,1,convertMSB_LSB(0x4));
  
  //read DWT_FUNC1 and MATCHED bit not set
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC1);
  emulateswdRegisterRead(DRW_REG,AP,4,1,0x1234);
  emulateswdRegisterRead(DRW_REG,AP,4,0,convertMSB_LSB(0xA));
  
  TEST_ASSERT_EQUAL(0,isDataWatchpointOccurred());
}

void test_isDataWatchpointOccurred_given_DWTTRAP_DEBUGEVENT_0_should_return_0()
{
  //DWTTRAP_DEBUGEVENT = 0
  emulateswdRegisterWrite(TAR_REG,AP,4,DFSR_REG);
  emulateswdRegisterRead(DRW_REG,AP,4,1,0x1234);
  emulateswdRegisterRead(DRW_REG,AP,4,1,convertMSB_LSB(0x0));
  
  TEST_ASSERT_EQUAL(0,isDataWatchpointOccurred());
}

/*------------------isAddressWatchpointOccurred--------------*/
void test_isAddressWatchpointOccurred_given_DWT_COMP3__DWTTRAP_DEBUGEVENT_1_MATCHED_should_return_1()
{
  //DWTTRAP_DEBUGEVENT = 1
  emulateswdRegisterWrite(TAR_REG,AP,4,DFSR_REG);
  emulateswdRegisterRead(DRW_REG,AP,4,1,0x1234);
  emulateswdRegisterRead(DRW_REG,AP,4,1,convertMSB_LSB(0x4));
  
  //read DWT_FUNC3 and MATCHED bit set
  emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC3);
  emulateswdRegisterRead(DRW_REG,AP,4,1,0x1234);
  emulateswdRegisterRead(DRW_REG,AP,4,1,convertMSB_LSB(0x1000000));
  
  TEST_ASSERT_EQUAL(1,isAddressWatchpointOccurred(DWT_COMP3));
}


/*------------------disableDWTComparator--------------*/
void test_disableDWTComparator_given_DWT_COMP1_should_write_0_to_DWT_FUNC1()
{
  //Faking CSW to Word Size
  cswDataSize = CSW_WORD_SIZE ;
  
  //Program function
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC1);
	emulateswdRegisterWrite(DRW_REG,AP,4,0);
  
  TEST_ASSERT_EQUAL(0,disableDWTComparator(DWT_COMP1));
}

void test_disableDWTComparator_given_DWT_COMP3_should_write_0_to_DWT_FUNC3()
{ 
  //Program function
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC3);
	emulateswdRegisterWrite(DRW_REG,AP,4,0);
  
  TEST_ASSERT_EQUAL(0,disableDWTComparator(DWT_COMP3));
}

/*------------------disableAllDWTComparators--------------*/
void test_disableAllDWTComparators_should_write_0_to_DWT_FUNC0_FUNC1_FUNC2_FUNC3()
{
  //Program DWT_FUNC0
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC0);
	emulateswdRegisterWrite(DRW_REG,AP,4,0);
  
  //Program DWT_FUNC1
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC1);
	emulateswdRegisterWrite(DRW_REG,AP,4,0);
  
  //Program DWT_FUNC2
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC2);
	emulateswdRegisterWrite(DRW_REG,AP,4,0);
  
  //Program DWT_FUNC3
	emulateswdRegisterWrite(TAR_REG,AP,4,DWT_FUNC3);
	emulateswdRegisterWrite(DRW_REG,AP,4,0);
  
  disableAllDWTComparators();
}