/* Write a program to implement Stack, using Linked List. Implement Push, Pop and display operations. */

#include <stdio.h>
#include <stdlib.h>
/*
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 18/05/2021
*/
struct Node
{
    int data;
    struct Node *next;
} *head = NULL; // Initially the list is empty

void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value; // get value for the node
    if (head == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head; // Make the node as head
    }
    head = newNode;
    printf("\n--------------------------------------");
    printf("\nNode is Inserted!");
}

void pop()
{
    if (head == NULL)
    {
        printf("\nStack Empty!\n");
    }
    else
    {
        struct Node *temp = head;
        printf("\n--------------------------------------");
        printf("\nNode Deleted! : %d", temp->data);
        printf("\n");
        head = temp->next; // After popping, make the next node as head
        free(temp);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\n--------------------------------------");
        printf("\nStack Empty!");
    }
    else
    {
        printf("The stack is \n");
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            printf("\n%d --> ", temp->data);
            temp = temp->next;
        }
        printf("%d --> NULL\n\n", temp->data);
        printf("\n--------------------------------------");
    }
}

int main()
{
    int choice, value;
    printf("\n--------------------------------------");
    printf("\nIMPLEMENTING STACKS USING LINKED LISTS");

    while (1)
    {
        printf("\n--------------------------------------");
        printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT");
        printf("\n--------------------------------------");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\nInvalid Choice\n");
        }
    }
}