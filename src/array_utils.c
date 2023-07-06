#include "array_utils.h"
#include <string.h>

/**
 * @brief Sort an array of strings in ascending order.
 * @param array The array to sort.
 * @param size The size of the array.
 */
void sort_array_of_strings(char *array[], int size)
{
		int i, j;
		char *temp;

		for (i = 0; i < size; i++)
		{
				for (j = i + 1; j < size; j++) 
				{
						if (strcmp(array[i], array[j]) > 0)
						{
								temp = array[i];
								array[i] = array[j];
								array[j] = temp;
						}
				}
		}
}
