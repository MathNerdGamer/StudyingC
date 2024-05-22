#include <stdio.h>
#include <stdlib.h>

void merge_sort(long *, size_t);
void merge_recurse(long *, size_t, size_t);
void merge(long *, size_t, size_t, size_t);

int main(int const argc, [[maybe_unused]] char const **argv)
{
    constexpr size_t SIZE = 10;
    long array[SIZE] = {99999, 7, 1, 1231, 67, 11, 8910, 73, 72, 70};

    printf("Pre-sort: ");
    for( size_t i = 0; i < SIZE; i++ )
    {
        printf("%ld", array[i]);

        if( i < SIZE - 1 )
        {
            printf(", ");
        }
    }
    printf("\n");

    merge_sort(array, SIZE);

    printf("Post-sort: ");
    for( size_t i = 0; i < SIZE; i++ )
    {
        printf("%ld", array[i]);

        if( i < SIZE - 1 )
        {
            printf(", ");
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}

void merge_sort(long *array, size_t size)
{
    merge_recurse(array, 0, size - 1);
}

void merge_recurse(long *array, size_t start, size_t array_end)
{
    if( start < array_end )
    {
        size_t mid = start + (array_end - start) / 2;

        merge_recurse(array, start, mid);
        merge_recurse(array, mid + 1, array_end);

        merge(array, start, mid, array_end);
    }
}

void merge(long *array, size_t left_start, size_t left_end, size_t array_end)
{
    size_t right_start = left_end + 1;
    if( array[left_end] <= array[right_start] )
    {
        return;
    }

    while( left_start <= left_end && right_start <= array_end )
    {
        if( array[left_start] <= array[right_start] )
        {
            left_start++;
        }
        else
        {
            long temp = array[right_start];
            size_t index = right_start;

            while( index > left_start )
            {
                array[index] = array[index - 1];
                index--;
            }
            array[left_start] = temp;

            left_start++;
            left_end++;
            right_start++;
        }
    }
}
