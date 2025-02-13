#include <stdio.h>
#include "unity.h"
#include "mypow.h"

//Unity required fuctions
void setUp(void) {}
void tearDown(void) {}
//Prototypes for all of the test functions
void powtest1(void);
void powtest2(void);
void powtest3(void);

int main(void){
	UNITY_BEGIN();
	RUN_TEST(powtest1);
	RUN_TEST(powtest2);
	RUN_TEST(powtest3);
	return UNITY_END();
}

void powtest1(void){
	TEST_ASSERT_FLOAT_WITHIN_MESSAGE(0.01, 8.0, mypow(2, 3), "test 1-1");
	TEST_ASSERT_FLOAT_WITHIN_MESSAGE(0.01, -8.0, mypow(-2, 3), "test 1-2");
	TEST_ASSERT_FLOAT_WITHIN_MESSAGE(0.01, 234256.0, mypow(22, 4), "test 1-3");
	TEST_ASSERT_FLOAT_WITHIN_MESSAGE(0.01, 4782969, mypow(3, 14), "test 1-4");
}

void powtest2(void){
	TEST_ASSERT_TRUE(isnan(mypow(0, -2)));
	TEST_ASSERT_TRUE(isnan(mypow(0, 0)));
	TEST_ASSERT_FALSE(isnan(mypow(-2, 0)));
}

void powtest3(void){
	TEST_ASSERT_FLOAT_WITHIN_MESSAGE(0.01, 0.25, mypow(2, -2), "test 3-1");
	TEST_ASSERT_FLOAT_WITHIN_MESSAGE(0.01, 0.0625, mypow(4, -2), "test 3-2");
	TEST_ASSERT_FLOAT_WITHIN_MESSAGE(0.01, 0.111111, mypow(3, -2), "test 3-3");
}
