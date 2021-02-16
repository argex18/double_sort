#include "double_sort.h"

int main( int argn, const char* args[] )
{
    const char* script_name = args[0];
    const char* mode = args[1];
    char* arrays[MAX_NUMBER];
    int* array[MAX_NUMBER];

    // getting arrays
    get_strarray(args[2], arrays);
    // terminate with an array of 2 strings (char arrays)
    // example array[0] = "1,2,3,4,5,6"
    // example array[1] = "3,4,5,6,7,8"

    // conversion const char* to int* array
    // int i;
    // for(i=0; i<MAX_NUMBER; i++)
    // {
    //     array[i] = get_array(arrays[i]);
    // }
    //

    int i;
    printf("printing arrays:\n");
    for(i=0; i<MAX_NUMBER; i++)
    {
        fprintf(stdout, "array[%d]: %s\n", i, arrays[i]);
    }

    // int dim[MAX_NUMBER];
    // dim[0] = args[3];
    // dim[1] = args[4];

    // if(argn > 5)
    // {
    //     fprintf(stderr, "error: too many arguments passed to the script: %d\n", argn);
    //     fprintf(stderr, "Exiting...\n");
    //     exit(EXIT_FAILURE);
    // }

    /*
    // printing sorted array
    // fprintf(stdout, "Printing result:\n");
    // printf("[");
    // for(i=0; i<dim; i++)
    // {
    //     printf("%d, ", array[i]);
    // }
    // printf("]\n");
    */

    return 0;
}