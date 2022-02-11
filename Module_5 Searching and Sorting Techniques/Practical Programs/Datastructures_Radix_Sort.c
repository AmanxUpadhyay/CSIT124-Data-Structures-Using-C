/* Write a program to implement Radix sort an array */

#include <stdio.h>
#include <stdlib.h>
/**
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 12/03/2021
*/
void display(int Array[], int number_of_element)
{
    printf("------------------------------------\n");
    for (int i = 0; i < number_of_element; i++)
    {
        printf("%d ", Array[i]);
    }
}

int getMax(int Array[], int n)
{
    int i;
    int max = Array[0];
    for (i = 1; i < n; i++)
    {
        if (Array[i] > max)
            max = Array[i];
    }
    return max;
}

void radixSort(int Array[], int number_of_element)
{
    int i, digitPlace = 1;
    int result[number_of_element];

    int largestNum = getMax(Array, number_of_element);

    while (largestNum / digitPlace > 0)
    {
        int count[10] = {0};

        for (i = 0; i < number_of_element; i++)
            count[(Array[i] / digitPlace) % 10]++;

        for (i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        for (i = number_of_element - 1; i >= 0; i--)
        {
            result[count[(Array[i] / digitPlace) % 10] - 1] = Array[i];
            count[(Array[i] / digitPlace) % 10]--;
        }
        for (i = 0; i < number_of_element; i++)
        {
            Array[i] = result[i];
            digitPlace *= 10;

            for (int k = 0; k < number_of_element; k++)
            {
                printf("%d ", Array[k]);
            }
            printf("\n");
        }
    }
    printf("After Radix Sorting: \n");
    display(Array, number_of_element);
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
        printf("\n1. Radix Sort\n2. Display Array\n3. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &Choice);

        if (Choice == 1)
        {
            radixSort(Array, number_of_element);
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