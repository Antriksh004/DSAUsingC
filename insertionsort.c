// IINSERTION SORT IN C

#include <stdio.h>

int main()
{
    int arr[] = {6,5, 4,3,2,1};

    int key, i, temp, j, k, ins_key;
    for (ins_key = 1; ins_key < 6; ins_key++)
    {
        key = ins_key;

        temp = arr[key];
        // printf("the temp is %d",temp);

        for (i = 0; i <= key; i++)
        {

            if (arr[i] > arr[key])
            {
                for (j = key; j > i; j--)
                {
                    arr[j] = arr[j - 1];
                }
                arr[i] = temp;
            }

            else
            {
                continue;
            }
        }
        for (k = 0; k < 6; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    return 0;
}