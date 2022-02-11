/* Write a program to implement selection sort on an integer array and show the content of array after each pass. */

#include <stdio.h>
#include <stdlib.h>
/**
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 11/03/2021
*/
void display(int Array[], int number_of_element)
{
    printf("------------------------------------\n");
    for (int i = 0; i < number_of_element; i++)
    {
        printf("%d ", Array[i]);
    }
}

void selectionSort(int Array[], int number_of_element)
{
    int i, j, temp;

    for (i = 0; i < number_of_element - 1; i++)
    {
        for (j = i + 1; j < number_of_element; j++)
        {
            if (Array[i] > Array[j])
            {
                temp = Array[i];
                Array[i] = Array[j];
                Array[j] = temp;
            }
        }
        for (int k = 0; k < number_of_element; k++)
        {
            printf("%d ", Array[k]);
        }
        printf("\n");
    }
    printf("After Selection Sort Element are: \n");
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
        printf("\n1. Selection Sort\n2. Display Array\n3. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &Choice);

        if (Choice == 1)
        {
            selectionSort(Array, number_of_element);
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