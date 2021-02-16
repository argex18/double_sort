#include "double_sort.h"

int* double_sort(int array1[], int array2[], int remove_duplicates) {

}
int* quicksort(int array[], int dim, int reversing) {
    int pivot = array[0];
    int lowest_index = 0;
    int highest_index = dim - 1;
    int i,j,tmp;
    j = dim;

    for(i=highest_index; i>=lowest_index+1; i--)
    {
        if(pivot >= array[i])
        {
            j--;

            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }

        if(i == lowest_index + 1)
        {
            tmp = pivot;
            array[lowest_index] = array[j-1];
            array[j-1] = pivot;
        }
    }

    return array;

}
void get_strarray(const char* array_arg, char* return_array[])
{
    int n_param,i,j = 0;
    char read;
    char str_number[10];
    char* arrays[MAX_NUMBER];

    while(read != ']' && n_param < MAX_NUMBER)
    {
        read = array_arg[i];
        if(read == '[')
        {
            i++;
            continue;
        }

        if(read == ']')
        {
            n_param++;
            if(n_param >= MAX_NUMBER)
            {
                fprintf(stderr, "error: the maximum allowed array number is set to %d", MAX_NUMBER);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            str_number[j] = read;
            if(read == ',')
            {
                arrays[n_param] = strcat(arrays[n_param], str_number);
                j = 0;
            }
            else
            {
                j++;
            }
        }
        i++;
    }

    return_array = arrays;
}
int* get_array(char* str)
{

}