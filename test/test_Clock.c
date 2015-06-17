#include "unity.h"
#include "Clock.h"
#include "mock_IO_Operations.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_clockGenerator_1cycle_should_turn_off_SWCLK_and_turn_on_SWCLK()
{
	SWCLK_OFF_Expect();
	SWCLK_ON_Expect();
	
	clockGenerator_1cycle();
}

void test_turnAround_should_call_SWCLK_OFF_SWCLK_ON()
{
	SWCLK_OFF_Expect();
	SWCLK_ON_Expect();
	
	turnAround();
}

void test_extraIdleClock_given_1_clock_should_set_SWDIO_Low_and_turn_off_SWCLK_and_turn_on_SWCLK()
{
	SWDIO_Low_Expect();
	
	SWCLK_OFF_Expect();
	SWCLK_ON_Expect();
	
	extraIdleClock(1);
}