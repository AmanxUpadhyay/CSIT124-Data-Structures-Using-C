/* Write a program to implement Quick Sort an array. */

#include <stdio.h>
#include <stdlib.h>
/*
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 20/03/2021
*/
void display(int Array[], int number_of_element)
{
    printf("------------------------------------\n");
    for (int i = 0; i < number_of_element; i++)
    {
        printf("%d ", Array[i]);
    }
}

int parition(int Array[], int Lower, int Upper)
{
    int p, q, num, temp;
    p = Lower + 1;
    q = Upper;
    num = Array[Lower];

    while (q >= p)
    {
        while (Array[p] < num)
        {
            p++;
        }
        while (Array[q] > num)
        {
            q--;
        }
        if (q > p)
        {
            temp = Array[p];
            Array[p] = Array[q];
            Array[q] = temp;
        }
    }
    temp = Array[Lower];
    Array[Lower] = Array[q];
    Array[q] = temp;

    return q;
}

void quickSort(int Array[], int Lower, int Upper)
{
    int i;
    if (Upper > Lower)
    {
        i = parition(Array, Lower, Upper);
        for (int j = Lower; j <= Upper; j++)
        {
            printf("%d ", Array[j]);
        }
        printf("\n");
        quickSort(Array, Lower, i - 1);
        quickSort(Array, i + 1, Upper);
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
        printf("\n1. Quick Sort\n2. Display Array\n3. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &Choice);

        if (Choice == 1)
        {
            quickSort(Array, 0, number_of_element - 1);
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