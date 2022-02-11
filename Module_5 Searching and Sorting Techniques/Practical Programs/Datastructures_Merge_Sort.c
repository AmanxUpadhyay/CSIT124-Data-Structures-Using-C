/*Write a program to Implement Merge Sort*/

#include <stdio.h>
#include <stdlib.h>
/**
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 25/03/2021
*/
void display(int Array[], int number_of_element)
{
    printf("------------------------------------\n");
    for (int i = 0; i < number_of_element; i++)
    {
        printf("%d ", Array[i]);
    }
}

void join(int Array[], int lower, int mid, int upper)
{
    int size, *b, first, second, idx, i;
    size = upper - lower + 1;
    b = (int *)malloc(size * sizeof(int));

    first = lower, second = mid + 1, idx = 0;

    while (first <= mid && second <= upper)
    {
        if (Array[first] <= Array[second])
        {
            b[idx] = Array[first];
            first++;
            idx++;
        }
        else
        {
            b[idx] = Array[second];
            second++;
            idx++;
        }
    }

    while (first <= mid)
    {
        b[idx] = Array[first];
        idx++;
        first++;
    }

    while (second <= upper)
    {
        b[idx] = Array[second];
        idx++;
        second++;
    }
    idx = 0;

    for (i = lower; i <= upper; i++)
    {
        Array[i] = b[idx];
        idx++;
    }
    free(b);
}

void mergeSort(int Array[], int lower, int upper)
{
    int mid;

    if (lower < upper)
    {
        mid = (lower + upper) / 2;
        mergeSort(Array, lower, mid);
        mergeSort(Array, mid + 1, upper);
        join(Array, lower, mid, upper);
    }
    else
    {
        return;
    }
}

int main()
{
    system("cls");

    int Choice, i, number_of_element;

    printf("------------------------------------\n");
    printf("Enter no. of Element to sort: ");
    scanf("%d", &number_of_element);
    printf("------------------------------------\n");

    int Array[number_of_element];

    for (int i = 0; i < number_of_element; i++)
    {
        printf("Enter %d Element: ", i + 1);
        scanf("%d", &Array[i]);
    }
    printf("------------------------------------\n");
    printf("Please Select Option Given Below: \n");

    while (1)
    {
        printf("\n------------------------------------\n");
        printf("\n1. Merge Sort\n2. Display Array\n3. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &Choice);

        if (Choice == 1)
        {
            mergeSort(Array, 0, number_of_element - 1);
        }
        else if (Choice == 2)
        {
            display(Array, number_of_element);
        }
        else if (Choice == 3)
        {
            return 0;
        }
        else
        {
            printf("\nPlease Select Correct Option\n");
        }
    }
}