/* Write a program to implement Queue, using Linked List. Implement Insertion, deletion and display operations. */

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
    int info;
    struct Node *ptr;
} * front, *rear, *temp, *front1;

int count = 0;

/* Create an empty queue */
void create()
{
    front = rear = NULL;
}

/* Returns queue size */
void queuesize()
{
    printf("\n Queue size : %d", count);
}

/* Enqueueing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct Node *)malloc(1 * sizeof(struct Node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp = (struct Node *)malloc(1 * sizeof(struct Node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;

        rear = temp;
    }
    count++;
}

/* Displaying the queue elements */
void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf(" Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf(" %d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}

/* Dequeing the queue */
void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else if (front1->ptr != NULL)
    {
        front1 = front1->ptr;
        printf("\n Dequeue value : %d", front->info);
        free(front);
        front = front1;
    }
    else
    {
        printf("\n Dequeue value : %d", front->info);
        free(front);
        front = NULL;
        rear = NULL;
    }
    count--;
}

/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return (front->info);
    else
        return 0;
}

/* Display if queue is empty or not */
void empty()
{
    if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
        printf(" Queue not empty");
}

void main()
{
    int no, ch, e;
    system("cls");

    printf("------------------------------------\n");
    printf("    QUEUE IMPLEMENTATION PROGRAM    \n");
    printf("------------------------------------");
    printf("\n 1 - Enqueue");
    printf("\n 2 - Deque");
    printf("\n 3 - Front element");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    printf("\n 7 - Queue size");
    create();
    printf("\n------------------------------------");

    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf(" Enter data : ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf(" Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        default:
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
