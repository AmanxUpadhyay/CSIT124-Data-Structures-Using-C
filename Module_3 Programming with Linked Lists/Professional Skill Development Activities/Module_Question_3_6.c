/* Write a program to implement Linear Linked List, showing all the operations, like creation, display, insertion, deletion and searching.

   1.Create the list
   2.Insert element at the beginning
   3.Insert element at the end
   4.Insert element after a specific element
   5.Remove element from the beginning
   6.Remove element from the end
   7.Remove a specific element
   8.Count the number of elements
   9.Find the sum of the elements
*/
#include <stdio.h>
#include <stdlib.h>
/*
* Created by Visual Studio Code
* Author: Aman Upadhyay
* Email: aman.upadhyay@s.amity.edu
* Date: 05/04/2021
*/

/* Creating Node for Linked List */
struct Node
{
    int Data;
    struct Node *link;
} * NewNode;

void Display(struct Node *Head)
{
    printf("\n--------------------------------------");
    printf("\nLinked List:\n");

    while (Head != NULL)
    {
        printf("%d ", Head->Data);
        Head = Head->link;
    }
    printf("\n");
}

void Insert_at_Beginning(struct Node **Head, int Num)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->Data = Num;
    temp->link = *Head;
    *Head = temp;
}

void Insert_at_End(struct Node **Head, int Num)
{
    struct Node *temp, *r;

    if (*Head == NULL)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->Data = Num;
        temp->link = NULL;
        *Head = temp;
    }
    else
    {
        temp = *Head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        r = (struct Node *)malloc(sizeof(struct Node));
        r->Data = Num;
        r->link = NULL;
        temp->link = r;
    }
}

void Insert_at_Location(struct Node **Head, int location, int Num)
{
    struct Node *temp, *r;
    int i;
    temp = *Head;

    for (i = 0; i < location; i++)
    {
        temp = temp->link;

        if (temp == NULL)
        {
            printf("\n--------------------------------------");
            printf("\nThere are Less than %d Elements in List.", location);
            return;
        }
    }
    r = (struct Node *)malloc(sizeof(struct Node));
    r->Data = Num;
    r->link = temp->link;
    temp->link = r;
}

void Delete_from_Beginning(struct Node **Head)
{
    if (*Head == NULL)
    {
        printf("\n--------------------------------------");
        printf("List is Empty");
    }
    struct Node *temp = *Head;
    *Head = (*Head)->link;

    int element = temp->Data;
    free(temp);
    printf("\n--------------------------------------");
    printf("\n %d Deleted", element);
}

void Delete_from_End(struct Node **Head)
{
    if (*Head == NULL)
    {
        printf("\n--------------------------------------");
        printf("Linked List is Empty");
    }
    if ((*Head)->link == NULL)
    {
        free(*Head);
    }
    struct Node *second_last_ele = *Head;

    while (second_last_ele->link->link != NULL)
    {
        second_last_ele = second_last_ele->link;
    }
    int element = second_last_ele->link->Data;
    free(second_last_ele->link);
    second_last_ele->link = NULL;

    printf("\n--------------------------------------");
    printf("\n %d Deleted", element);
}

void Delete_Element(struct Node **Head, int data)
{
    struct Node *temp = *Head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->Data == data)
    {
        *Head = temp->link;
        free(temp);
    }
    else
    {
        while (temp != NULL && temp->Data != data)
        {
            prev = temp;
            temp = temp->link;
        }
        if (temp == NULL)
        {
            printf("\n--------------------------------------");
            printf("No such element is present");
        }
        prev->link = temp->link;
        free(temp);
    }
}

void Count_Elements(struct Node *Head)
{
    int count = 0;
    struct Node *current = Head;
    while (current != NULL)
    {
        count++;
        current = current->link;
    }
    printf("\n--------------------------------------");
    printf("\n Number of elements are: %d", count);
}

void Sum_of_Elements(struct Node *Head)
{
    int sum = 0;
    struct Node *current = Head;
    while (current != NULL)
    {
        sum = sum + current->Data;
        current = current->link;
    }
    printf("\n--------------------------------------");
    printf("\n Sum of elements are: %d", sum);
}

int main()
{
    system("cls");
    struct Node *p;
    p = NULL;
    int Data, choice, location;

    while (1)
    {
        printf("\n--------------------------------------");
        printf("\n     WELCOME TO SINGLY LINKED LIST    ");
        printf("\n--------------------------------------");
        printf("\n   1.Display the list                 ");
        printf("\n   2.Insert element at the beginning  ");
        printf("\n   3.Insert element at the end        ");
        printf("\n   4.Insert element after a specific element");
        printf("\n   5.Remove element from the beginning");
        printf("\n   6.Remove element from the end      ");
        printf("\n   7.Remove a specific element        ");
        printf("\n   8.Count the number of elements     ");
        printf("\n   9.Find the sum of the elements     ");
        printf("\n   10.Exit                            ");
        printf("\n--------------------------------------");
        printf("\n Enter Your Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            Display(p);
        }
        else if (choice == 2)
        {
            printf("\n--------------------------------------");
            printf("\nEnter Number to Insert at Front: ");
            scanf("%d", &Data);
            Insert_at_Beginning(&p, Data);
        }
        else if (choice == 3)
        {
            printf("\n--------------------------------------");
            printf("\nEnter Number to Insert at End: ");
            scanf("%d", &Data);
            Insert_at_End(&p, Data);
        }
        else if (choice == 4)
        {
            printf("\n--------------------------------------");
            printf("\nEnter the Location to Insert Element: ");
            scanf("%d", &location);
            printf("\nEnter Number to Insert at Location: ");
            scanf("%d", &Data);
            Insert_at_Location(&p, location, Data);
        }
        else if (choice == 5)
        {
            printf("\n--------------------------------------");
            Delete_from_Beginning(&p);
        }
        else if (choice == 6)
        {
            printf("\n--------------------------------------");
            Delete_from_End(&p);
        }
        else if (choice == 7)
        {
            printf("\n--------------------------------------");
            printf("\nEnter the Element to be Deleted: ");
            scanf("%d", &Data);

            Delete_Element(&p, Data);
        }
        else if (choice == 8)
        {
            Count_Elements(p);
        }
        else if (choice == 9)
        {
            Sum_of_Elements(p);
        }
        else
        {
            printf("\n Please Select Correct Option");
        }
    }
}