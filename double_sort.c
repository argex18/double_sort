#include "double_sort.h"

int* double_sort(int array1[], int array2[], int remove_duplicates) {

}
int* quicksort(int array[], int dim, int reversing) {
    int pivot = array[0];
    int lowest_index = 0;
    int highest_index = dim - 1;
    int i,tmp;
    i = dim;

    for(i=highest_index; i>=lowest_index+1; i--)
    {
        if(pivot >= array[i])
        {
            i--;

            tmp = array[i];
            array[i] = array[i];
            array[i] = tmp;
        }

        if(i == lowest_index + 1)
        {
            tmp = pivot;
            array[lowest_index] = array[i-1];
            array[i-1] = pivot;
        }
    }

    return array;

}
int get_strarray(const char* array_arg, char* strarrays[])
{
    int n_param = 0;
    char number[10]; // buffer to temporarily store the numbers
    int i;
    int dim = 50;
    char* arrays[MAX_NUMBER] = {
        calloc(dim, sizeof(char)),
        calloc(dim, sizeof(char))
    };
    char* start = array_arg;
    char* end, *origin, *buffer;

    
    while(n_param < MAX_NUMBER) {
        end = array_arg;
        if(*end == ']')
        {
            n_param++;
        }

        if(*end == ',' || *end == ']') {
            i = 0;
            while(*(++start) != *end)
            {
                if(*start == '[' || *start == ']')
                {
                    continue;
                }
                number[i] = *start;
                i++;
            }
            number[i] = ':';

            i = n_param;
            if(*end == ']') {
                i = n_param - 1;
            }

            if( strlen(arrays[i]) == 0 ) {
                origin = arrays[i];
            }

            if( strlen(arrays[i]) >= dim-5 ) {
                dim += 50;

                buffer = strdup( arrays[i] );
                arrays[i] = realloc(arrays[i], dim * sizeof(char));
                arrays[i] = strcpy(arrays[i], buffer);
            }
 
            arrays[i] = strcat( arrays[i], number );
            do {
                if( *(arrays[i]) == ':' ) {
                    *(arrays[i]) = ',';
                }
            } while ( *(++arrays[i]) != '\0' || *(arrays[i] - 1) != ',' );
            arrays[i] = origin;

            // fprintf(stdout, "%s\n", arrays[i]);

            //clearing number buffer
            for(i=0; number[i] != '\0'; i++) {
                number[i] = '\0';
            } 
        }
        array_arg++;
    }

    fprintf(stdout, "[%s][%s]\n", arrays[0], arrays[1]);
    fflush(stdout);

    // here a code for adding the \0 null character
    i = 0;
    arrays[i] = origin;
    while(i<MAX_NUMBER) {
        if( *(arrays[i]) == '\0' ) {
            *(arrays[i] - 1) = '\0';
            arrays[i] = origin;
            i++;
        } else {
            *(++arrays[i]);
        }
    }

    fprintf(stdout, "[%s][%s]\n", arrays[0], arrays[1]);
    fflush(stdout);

    if(arrays != NULL)
    {
        i = 0;
        while(i<MAX_NUMBER) {
            strarrays[i] = strdup( arrays[i] );
            i++;
        }
        return 1;
    }
    else
    {
        strarrays = NULL;
        return -1;
    }
}
int* get_array(char* str)
{

}
int main() {
    const char* args = "[12,23,35,48,50,11,12,20,30,40,50][13,15,28,32,44,22,55,91]";
    char* array[MAX_NUMBER];
    char read;

    int flag = get_strarray(args, array);
    if(flag && array != NULL) {
        int i;
        fprintf(stdout, "Arrays:\n");
        for(i=0; i<MAX_NUMBER; i++) {
            fprintf(stdout, "[%s]\n", array[i]);
        }
    } else {
        fprintf(stdout, "unknown error while getting string arrays");
    }
    return 0;
}