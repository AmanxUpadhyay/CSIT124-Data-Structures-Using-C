/* Write a program to implement the operation of queue-Insert, Delete and explain the Priority Queues.
 * Ans: A priority queue is a special type of queue in which each element is associated with a priority and is served according to its priority. If elements with the same priority occur, they are served according to their order in the queue. Generally, the value of the element itself is considered for assigning the priority. For example, The element with the highest value is considered as the highest priority element. However, in other cases, we can assume the element with the lowest value as the highest priority element. In other cases, we can set priorities according to our needs.

 !Difference between Priority Queue and Normal Queue
 !In a queue, the first-in-first-out rule is implemented whereas, in a priority queue, the values are removed on the basis of priority. The element with the highest priority is removed first.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 4
/*
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 04/03/2021
*/
int Queue[MAX];
int rear = -1, front = -1;

void insert(){
    int element;

    if (rear == MAX - 1){
        printf("Queue Overflow \n");
    }
    else{
        if (front == -1){
            front = 0;
        }
        printf("Insert the Value in queue : ");
        scanf("%d", &element);
        rear = rear + 1;
        Queue[rear] = element;
    }
}

void delete (){
    if (front == -1 || front > rear){
        printf("Queue Underflow \n");
        return;
    }else{
        printf("Element deleted from queue is : %d\n", Queue[front]);
        front = front + 1;
    }
}

void display(){
    int i;

    if (front == -1){
        printf("Queue is empty \n");
    }else{
        printf("Queue is : ");
        for (i = front; i <= rear; i++){
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}

int main(){
    system("cls");

    int choice;
    while (1){
        printf("------------------------------------\n");
        printf("    QUEUE IMPLEMENTATION PROGRAM    \n");
        printf("------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    }
}