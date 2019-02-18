#include <stdio.h>


int SearchLinear(const int arr[], int size, int value);
int SearchBinar(const int arr[], int value, int start_elem, int last_elem);
void Sort(int arr[], int size);
void ChangeElement(int arr[], int size, int value, int element);


int main()
{
    int test_array[8] = {0, 1, 3, 4, 7, 10, 11, 16};

    printf("Number of element: %d\n", SearchBinar(test_array, 4, 0, 7));

    int test_array_2[9] = {3, -4, 12, 10, 255, -3, 34, 90, 2};

    for (int i = 0; i < 8; i++) printf("%d\t", test_array[i]);
    printf("\n");

    ChangeElement(test_array, 8, 9, 3);

    for (int i = 0; i < 8; i++) printf("%d\t", test_array[i]);



    return 0;
}

int SearchLinear(const int arr[], const int size, int value)
{
    int element;
    for (element = 0; element < size; element++) {
        if ( arr[element] == value) break;
    }

    return element;
}

int SearchBinar(const int arr[], const int value, int start_elem, int last_elem)
{
    if ( start_elem >= last_elem ) return start_elem;

    int center = (int) ( (last_elem + start_elem) * 0.5 );

    if ( arr[center] > value ) last_elem = center - 1;
    else if ( arr[center] == value ) return center;
    else start_elem = center + 1;

    return SearchBinar(arr, value, start_elem, last_elem);
}

void Sort(int arr[], const int size)
{
    int temp = 0;

    for (int k = size-1; k >= 0; k--)
    {
        for (int m = 0; m < k; m++)
        {
            if ( arr[m] < arr[m+1] ) {
                temp = arr[m];
                arr[m] = arr[m+1];
                arr[m+1] = temp;
            }
        }
    }
}

void ChangeElement(int arr[], int size, int value, int element)
{
    arr[element-1] = value;

    if ( arr[element-1] < arr[element-2] ) Sort(arr, element);
    else if ( arr[element-1] > arr[element+1] ) Sort(arr, element);
    else printf("\nkek");
}