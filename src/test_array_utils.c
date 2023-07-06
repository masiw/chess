#include "unity.h"
#include "array_utils.h"

/**
 * @brief Set up function.
 * 
 */
void setUp(void)
{
}

/**
 * @brief Tear down function.
 * 
 */
void tearDown(void)
{
}

/**
 * @brief Test function to sort array of strings.
 * 
 */ 
void test_sort_array_of_strings(void)
{
	// unsorted array
	char *arr[] = {"ghi", "abc", "jkl", "def", "stu", "pqr", "vwx", "mno", "yz"};
	char *sorted_arr[] = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz"};
	sort_array_of_strings(arr, 9);
	TEST_ASSERT_EQUAL_STRING_ARRAY(sorted_arr, arr, 9);
}

/**
 * @brief Run the test suite.
 */
int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_sort_array_of_strings);
	return UNITY_END();
}

