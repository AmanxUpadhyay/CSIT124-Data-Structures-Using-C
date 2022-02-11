/* Write a program to implement Insertion sort an array */

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

void insertionSort(int Array[], int number_of_element)
{
    int i, j, temp;

    for (i = 1; i < number_of_element; i++)
    {
        temp = Array[i];
        j = i - 1;
        while (j >= 0 && Array[j] > temp)
        {
            Array[j + 1] = Array[j];
            j--;
        }
        Array[j + 1] = temp;
        for (int k = 0; k < number_of_element; k++)
        {
            printf("%d ", Array[k]);
        }
        printf("\n");
    }
    printf("After Insertion Sorting: \n");
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
        printf("\n1. Insertion Sort\n2. Display Array\n3. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &Choice);

        if (Choice == 1)
        {
            insertionSort(Array, number_of_element);
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