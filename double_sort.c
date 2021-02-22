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
        (char*) calloc(dim, sizeof(char)),
        (char*) calloc(dim, sizeof(char))
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
            number[i] = ',';
            number[i+1] = '\0';

            i = n_param;
            if(*end == ']') {
                i = n_param - 1;
            }

            if( strlen(arrays[i]) >= dim-5 ) {
                dim += 50;

                buffer = strdup( arrays[i] );
                arrays[i] = realloc(arrays[i], dim * sizeof(char));
                arrays[i] = strcpy(arrays[i], buffer);
            }
 
            arrays[i] = strcat( arrays[i], number );

            // fprintf(stdout, "%s\n", arrays[i]);

            //clearing number buffer
            for(i=0; number[i] != '\0'; i++) {
                number[i] = '\0';
            } 
        }
        array_arg++;
    }

    // here a code for adding the \0 null character
    i = 0;
    while(i<MAX_NUMBER) {
        origin = arrays[i];
        do {
            if( *(origin) == '\0' ) {
                *(origin - 1) = '\0';
                i++;
                break;
            } else {
                *(++origin);
            }
        } while (1);
    }

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
        *(strarrays) = NULL;
        return -1;
    }
}
void get_array(char* str, int* array)
{
    char buffer[10], *buff, *origin;
    buff = buffer;
    origin = &buffer[0];

    while(1) {
        if(*(str) == ',') {
            *(array) = atoi(buffer);
            buff = origin;
            *(array++);
            *(str++);
            continue;
        }
        *(buff) = *(str);
        *(buff++);
        *(str++); 

        if(*(str) == '\0') {
            *(array) = atoi(buffer);
            break;
        }
    }
}
int main() {
    const char* args = "[12,42,35,48,50,11,12,20,30,40,50][13,15,28,32,44,22,55,91]";
    char* array[MAX_NUMBER];
    int* arr_values[MAX_NUMBER];

    int flag = get_strarray(args, array);

    if(flag && *(array) != NULL) {

        int i;
        fprintf(stdout, "Arrays:\n");
        for(i=0; i<MAX_NUMBER; i++) {
            fprintf(stdout, "[%s]\n", array[i]);
            arr_values[i] = (int*) calloc( strlen(array[i]), sizeof(int) );
            get_array(array[i], arr_values[i]);
        }
        fprintf(stdout, "===============================");
        printf("\n");

        int j;
        fprintf(stdout, "Int Arrays:\n");
        for(i=0; i<MAX_NUMBER; i++) {

            printf("Array[%d]: ", i);
            // data type dimensions on my 64-bit machine with this gcc version
            // sizeof operates on the data type, not on the variable content
            printf("%d;%d;%d: ", sizeof(char*), sizeof(int*), sizeof(double*)); // sizeof returns the dimension in byte

            for(j=0; j < strlen(array[i]) && arr_values[i][j] != 0; j++) {

                printf("%d,", arr_values[i][j]);

            }
            printf("\n");
            
        }
    } 
    else 
    {
        fprintf(stdout, "Error: unknown error while getting string arrays");
    }

    return 0;
}