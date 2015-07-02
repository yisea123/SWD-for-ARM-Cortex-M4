#include "stdint.h"
#include "unity.h"
#include "Clock.h"
#include "Emulator.h"
#include "swd_Utilities.h"
#include "Bit_Operations.h"
#include "Register_ReadWrite.h"
#include "mock_configurePort.h"
#include "mock_IO_Operations.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_calculateParity_SWDRequest_given_0000_should_return_0()
{

	TEST_ASSERT_EQUAL(0,calculateParity_SWDRequest(0,0,0,0));
}

void test_calculateParity_SWDRequest_given_0100_should_return_1()
{

	TEST_ASSERT_EQUAL(1,calculateParity_SWDRequest(0,1,0,0));
}

void test_calculateParity_SWDRequest_given_0111_should_return_1()
{

	TEST_ASSERT_EQUAL(1,calculateParity_SWDRequest(0,1,1,1));
}


void test_calculateParity_SWDRequest_given_1111_should_return_0()
{

	TEST_ASSERT_EQUAL(0,calculateParity_SWDRequest(1,1,1,1));
}

void test_calculateParity_32bitData_given_0x0_should_return_0()
{
	TEST_ASSERT_EQUAL(0,calculateParity_32bitData(0));
}

void test_calculateParity_32bitData_given_0x1_should_return_1()
{
	TEST_ASSERT_EQUAL(1,calculateParity_32bitData(1));
}

void test_calculateParity_32bitData_given_0xF1E2D3C4_should_return_1()
{
	//1111 0001 1110 0010 1101 0011 1100 0100

	TEST_ASSERT_EQUAL(1,calculateParity_32bitData(0xF1E2D3C4));
}

void test_getSWDAddress_Bit_given_0x2_should_return_0_for_bit3_0_for_bit2()
{
	int Address_bit3 , Address_bit2 ;

	getSWD_AddressBit(&Address_bit3,&Address_bit2,0x2);

	TEST_ASSERT_EQUAL(0,Address_bit3);
	TEST_ASSERT_EQUAL(0,Address_bit2);
}


void test_getSWDAddress_Bit_given_0x4_should_return_0_for_bit3_1_for_bit2()
{
	int Address_bit3 , Address_bit2 ;

	getSWD_AddressBit(&Address_bit3,&Address_bit2,0x4);

	TEST_ASSERT_EQUAL(0,Address_bit3);
	TEST_ASSERT_EQUAL(1,Address_bit2);
}

void test_getSWDAddress_Bit_given_0x8_should_return_1_for_bit3_0_for_bit2()
{
	int Address_bit3 , Address_bit2 ;

	getSWD_AddressBit(&Address_bit3,&Address_bit2,0x8);

	TEST_ASSERT_EQUAL(1,Address_bit3);
	TEST_ASSERT_EQUAL(0,Address_bit2);
}

void test_getSWDAddress_Bit_given_0xC_should_return_1_for_bit3_1_for_bit2()
{
	int Address_bit3 , Address_bit2 ;

	getSWD_AddressBit(&Address_bit3,&Address_bit2,0xC);

	TEST_ASSERT_EQUAL(1,Address_bit3);
	TEST_ASSERT_EQUAL(1,Address_bit2);
}


void test_getSWD_Request_given_Address_0x00_DP_Read_should_return_0xA5()
{
	//DP = 0 , AP = 1
	//WRiTE = 0 ,READ = 1

	//**Note LSB
	//Start bit	|	APnDP	|	RW	|	Addr2	|	Addr3	|	Parity	|	Stop	|	Park	|
	//    1     |	0		|	1	| 	0		|	0		|	1		|	0		|	1		|

	TEST_ASSERT_EQUAL(0xA5,getSWD_Request(0x00,DP,READ));
}


void test_getSWD_Request_given_Address0x08_AP_Write_should_return_0x93()
{
	//DP = 0 , AP = 1
	//WRiTE = 0 ,READ = 1

	//**Note LSB
	//Start bit	|	APnDP	|	RW	|	Addr2	|	Addr3	|	Parity	|	Stop	|	Park	|
	//    1     |	1		|	0	| 	0		|	1		|	0		|	0		|	1		|


	TEST_ASSERT_EQUAL(0x93,getSWD_Request(0x08,AP,WRITE));

}

void test_getSWD_Request_given_Address0x04_DP_READ_should_return_0x8D()
{
	//DP = 0 , AP = 1
	//WRiTE = 0 ,READ = 1

	//**Note LSB
	//Start bit	|	APnDP	|	RW	|	Addr2	|	Addr3	|	Parity	|	Stop	|	Park	|
	//    1     |	0		|	1	| 	1		|	0		|	0		|	0		|	1		|


	TEST_ASSERT_EQUAL(0x8D,getSWD_Request(0x04,DP,READ));
}

void test_swdCheckErrorFlag_should_return_0x8_when_bit_7_of_the_readData_is_set_to_1() {
  int i = 0, data = 0;

  emulateWrite(0x8D, 8); //SWD 8bit protocol
  emulateTurnAroundRead();
  emulateSwdInput();
  emulateRead(0x4, 3); //Acknowledgement
  emulateRead(0x1000000, 32); //Read DATA (LSB)
  emulateRead(0x1, 1); //Parity
  emulateTurnAroundWrite();
  emulateSwdOutput();
  emulateIdleClock(8);

  data = swdCheckErrorFlag();

  TEST_ASSERT_EQUAL(0x8, data);
}


void test_swdCheckErrorFlag_should_return_0x4_when_bit_5_of_the_readData_is_set_to_1() {
  int i = 0, data = 0;

  emulateWrite(0x8D, 8); //SWD 8bit protocol
  emulateTurnAroundRead();
  emulateSwdInput();
  emulateRead(0x4, 3); //Acknowledgement
  emulateRead(0x4000000, 32); //Read DATA (LSB)
  emulateRead(0x1, 1); //Parity
  emulateTurnAroundWrite();
  emulateSwdOutput();
  emulateIdleClock(8);

  data = swdCheckErrorFlag();

  TEST_ASSERT_EQUAL(0x4, data);
}

void test_swdCheckErrorFlag_should_return_0x2_when_bit_4_of_the_readData_is_set_to_1() {
  int i = 0, data = 0;

  emulateWrite(0x8D, 8); //SWD 8bit protocol
  emulateTurnAroundRead();
  emulateSwdInput();
  emulateRead(0x4, 3); //Acknowledgement
  emulateRead(0x8000000, 32); //Read DATA (LSB)
  emulateRead(0x1, 1); //Parity
  emulateTurnAroundWrite();
  emulateSwdOutput();
  emulateIdleClock(8);

  data = swdCheckErrorFlag();

  TEST_ASSERT_EQUAL(0x2, data);
}

void test_swdCheckErrorFlag_should_return_0x10_when_bit_1_of_the_readData_is_set_to_1() {
  int i = 0, data = 0;

  emulateWrite(0x8D, 8); //SWD 8bit protocol
  emulateTurnAroundRead();
  emulateSwdInput();
  emulateRead(0x4, 3); //Acknowledgement
  emulateRead(0x40000000, 32); //Read DATA (LSB)
  emulateRead(0x1, 1); //Parity
  emulateTurnAroundWrite();
  emulateSwdOutput();
  emulateIdleClock(8);

  data = swdCheckErrorFlag();

  TEST_ASSERT_EQUAL(0x10, data);
}

void test_swdCheckErrorFlag_should_return_0xC_when_bit_7_5_of_the_readData_is_set_to_1() {
  int i = 0, data = 0;

  emulateWrite(0x8D, 8); //SWD 8bit protocol
  emulateTurnAroundRead();
  emulateSwdInput();
  emulateRead(0x4, 3); //Acknowledgement
  emulateRead(0x5000000, 32); //Read DATA (LSB)
  emulateRead(0x1, 1); //Parity
  emulateTurnAroundWrite();
  emulateSwdOutput();
  emulateIdleClock(8);

  data = swdCheckErrorFlag();

  TEST_ASSERT_EQUAL(0xC, data);
}

void test_swdCheckErrorFlag_should_return_0xE_when_bit_7_5_4_of_the_readData_is_set_to_1() {
  int i = 0, data = 0;

  emulateWrite(0x8D, 8); //SWD 8bit protocol
  emulateTurnAroundRead();
  emulateSwdInput();
  emulateRead(0x4, 3); //Acknowledgement
  emulateRead(0xD000000, 32); //Read DATA (LSB)
  emulateRead(0x1, 1); //Parity
  emulateTurnAroundWrite();
  emulateSwdOutput();
  emulateIdleClock(8);
  data = swdCheckErrorFlag();

  TEST_ASSERT_EQUAL(0xE, data);
}

void test_swdCheckErrorFlag_should_return_0x1E_when_bit_7_5_4_1_of_the_readData_is_set_to_1() {
  int i = 0, data = 0;

  emulateWrite(0x8D, 8); //SWD 8bit protocol
  emulateTurnAroundRead();
  emulateSwdInput();
  emulateRead(0x4, 3); //Acknowledgement
  emulateRead(0x4D000000, 32); //Read DATA (LSB)
  emulateRead(0x1, 1); //Parity
  emulateTurnAroundWrite();
  emulateSwdOutput();
  emulateIdleClock(8);
  data = swdCheckErrorFlag();

  TEST_ASSERT_EQUAL(0x1E, data);
}

void test_isApRead_given_read_and_AP_should_return_1()  {
  int result = isApRead(READ, AP);
  TEST_ASSERT_EQUAL(1, result);
}

void test_isApRead_given_Write_and_AP_should_return_0()  {
  int result = isApRead(WRITE, AP);
  TEST_ASSERT_EQUAL(0, result);
}

void test_isApRead_given_read_and_DP_should_return_0()  {
  int result = isApRead(READ, DP);
  TEST_ASSERT_EQUAL(0, result);
}

void test_retriesSwdReadWrite_given_read_operation_should_read_3_times_and_return_acknowledgement()  {
  int parity = 0, result = 0;
  uint32_t readData = 0;
  
  emulateSWDRegister_Read(DP_SELECT, DP, WAIT, 1, MSB_LSB_Conversion(0xABC));
  emulateSWDRegister_Read(DP_SELECT, DP, WAIT, 1, MSB_LSB_Conversion(0xABC));
  emulateSWDRegister_Read(DP_SELECT, DP, WAIT, 1, MSB_LSB_Conversion(0xABC));
  
  result = retriesSwdReadWrite(READ, DP_SELECT, DP, parity, readData);
  TEST_ASSERT_EQUAL(WAIT_RESPONSE, result);
}

void test_retriesSwdReadWrite_given_write_operation_should_read_3_times_and_return_acknowledgement()  {
  int parity = 0, result = 0;
  uint32_t readData = 0;
  
  emulateSWDRegister_Write(CSW_REG, AP, WAIT, 0xDEADBEEF);
  emulateSWDRegister_Write(CSW_REG, AP, OK, 0xDEADBEEF);
  
  result = retriesSwdReadWrite(WRITE, CSW_REG, AP, parity, 0xDEADBEEF);
  TEST_ASSERT_EQUAL(OK_RESPONSE, result);
}

/*******************************************************************************************************
 * Read CTRL/STAT Register (0x8D)
 * *****************************************************************************************************
 * |  Start bit   |  APnDP   |   RW     |    Addr2   |   Addr3   |   Parity    |   Stop    |   Park    |
 * -----------------------------------------------------------------------------------------------------
 * |      1      |    0      |    1     |     1      |     0     |     0       |    0      |     1     |
 * *****************************************************************************************************
 *
 * Write AP ABORT Register (0x81)
 * *****************************************************************************************************
 * |  Start bit   |  APnDP   |   RW     |    Addr2   |   Addr3   |   Parity    |   Stop    |   Park    |
 * -----------------------------------------------------------------------------------------------------
 * |      1      |    0      |    0     |     0      |     0     |     0       |    0      |     1     |
 * *****************************************************************************************************
 */
void test_swdClearFlags_given_WDERRCLR_bit_set_to_1_should_write_0x1000000_to_AP_ABORT_register() {
  int i = 0, data = 0;

  //Read CTRL/STAT Register
  emulateWrite(0x8D, 8); //SWD 8bit protocol
  emulateTurnAroundRead();
  emulateSwdInput();
  emulateRead(0x4, 3); //Acknowledgement
  emulateRead(0x1000000, 32); //Read DATA (LSB)
  emulateRead(0x1, 1); //Parity
  emulateTurnAroundWrite();
  emulateSwdOutput();
  emulateIdleClock(8);
  
  //Write AP ABORT Register
  emulateWrite(0x81, 8); //SWD 8bit protocol
  emulateTurnAroundRead();
  emulateSwdInput();
  emulateRead(0x4, 3); //Acknowledgement
  emulateTurnAroundWrite();
  emulateSwdOutput();  
  emulateWrite(0x8, 32); //Write DATA (LSB)
  emulateWrite(0x1, 1); //Parity
  emulateIdleClock(8);
  
  swdClearFlags(FAULT_RESPONSE, 0, 0, 0, 0, 0);
}

void test_swdClearFlags_given_WAIT_RESPOND_should_retries_3_times_and_abort() {
  int parity = 0;
  uint32_t readData = 0;
  
  //First AP read
  emulateSWDRegister_Read(TAR_REG, AP, WAIT, 1, MSB_LSB_Conversion(0xABC));
  emulateSWDRegister_Read(TAR_REG, AP, WAIT, 1, MSB_LSB_Conversion(0xABC));
  //Second AP read
  emulateSWDRegister_Read(TAR_REG, AP, WAIT, 1, MSB_LSB_Conversion(0xABC));
  emulateSWDRegister_Read(TAR_REG, AP, WAIT, 1, MSB_LSB_Conversion(0xABC));
  //Third AP read
  emulateSWDRegister_Read(TAR_REG, AP, WAIT, 1, MSB_LSB_Conversion(0xABC));
  emulateSWDRegister_Read(TAR_REG, AP, WAIT, 1, MSB_LSB_Conversion(0xABC));
  
  emulateSWDRegister_Write(DP_ABORT, DP, OK, DAPABOT);
  emulateSWDRegister_Read(TAR_REG, AP, WAIT, 1, MSB_LSB_Conversion(0xABC));
  emulateSWDRegister_Read(TAR_REG, AP, WAIT, 1, MSB_LSB_Conversion(0xABC));
  
  swdClearFlags(WAIT_RESPONSE, READ, TAR_REG, AP, parity, readData);
}

void test_swdClearFlags_given_WAIT_RESPOND_should_write_retries_3_times_if_success_dont_abort() {
  int parity = 0;
  uint32_t readData = 0;
  
  emulateSWDRegister_Write(DRW_REG, AP, WAIT, 0xDEADBEEF);
  emulateSWDRegister_Write(DRW_REG, AP, WAIT, 0xDEADBEEF);
  emulateSWDRegister_Write(DRW_REG, AP, OK, 0xDEADBEEF);
  
  swdClearFlags(WAIT_RESPONSE, WRITE, DRW_REG, AP, parity, 0xDEADBEEF);
}