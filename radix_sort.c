// The Radix sort is a non-comparative sorting algorithm. The Radix sort algorithm is the most preferred algorithm for the unsorted list.
// It sorts the elements by initially grouping the individual digits of the same place value. The idea of Radix Sort is to do digit by digit sort starting from least significant digit(LSD) to the most significant digit(MSD), according to their increasing/decreasing order. Radix sort is a small method that is used several times when alphabetizing an oversized list of names. Specifically, the list of names is initially sorted according to the first letter of every name, that is, the names are organized in twenty-six categories.

// ALGORITHM

// adix_sort (list, n)
// shift = 1
// for loop = 1 to keysize do
//    for entry = 1 to n do
//    bucketnumber = (list[entry].key / shift) mod 10
//    append (bucket[bucketnumber], list[entry])
// list = combinebuckets()
// shift = shift * 10

#include <stdio.h>

// DISPLAYING(PRINTING) ARRAY
int display_arr(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {

        printf("%d\n", a[i]);
    }
}

// getting the greatest element from the array

int get_max(int a[], int n)
{

    int max = a[0];

    for (int i = 1; i < n; i++)
    {

        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

// PROGRAM FOR THE RADIX SORT
void radix_sort(int a[], int n)
{
    int i, k, j, lar, r, nop = 0, divisor = 1, pass;

    int bucket[10][10], bucket_cnt[10];

    lar = get_max(a, n);

    while (lar > 0)
    {
        nop++;
        lar /= 10;
    }
    // filling the remaining spaces with 0
    for (pass = 0; pass < nop; pass++)
    {
        for (i = 0; i < 10; i++)
        {
            bucket_cnt[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            r = (a[i] / divisor) % 10;
            bucket[r][bucket_cnt[r]] = a[i];
            bucket_cnt[r] += 1;
        }
        i = 0;
        for (k = 0; k < 10; k++)
        {
            for (j = 0; j< bucket_cnt[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
                display_arr(a,n);
                printf("\n");
            }
            
        }
        divisor *= 10;
        // printf("after pass %d :", pass + 1);
        // for (i = 0; i < n; i++)
        // {
        //     printf("%d", a[i]);
        //     printf("\n");
        // }
    }

    // display_arr(bucket,20);
}

// MAIN PROGRAM
int main()
{

    int i, n = 5, a[10];
    int arrs[10] = {123, 43, 234, 123334, 1};
    // printf("enter the no. of elements you want to insert");
    // scanf("%d",&n);

    // for(i=0; i<n; i++){
    //     printf("enter items : ");
    //     scanf("%d",&a[i]);

    // }

    radix_sort(arrs, n);
    printf("sorted items : \n");
    display_arr(arrs, n);

    // display_arr(arrs,n);

    return 0;
}