#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER 2

int* quicksort(int array[], int dim, int reversing);
int* double_sort(int array1[], int array2[], int remove_duplicates);
int get_strarray(const char* array_arg, char* strarrays[]);
void get_array(char* str, int* array);