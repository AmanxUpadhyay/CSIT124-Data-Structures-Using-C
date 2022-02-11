/* Write a program to insert and remove elements from a circular queue. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 4
/**
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 05/03/2021
*/
int CircularQueue[MAX];
int front = -1, rear = -1;

void Enqueue(int element){
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)){
        printf("Queue Overflow \n");
        return;
    }
    if (front == -1){
        front = 0;
        rear = 0;
    }
    else{
        rear = rear + 1;
    }
    CircularQueue[rear] = element;
}

void Dequeue(){
    if (front == -1){
        printf("Queue Underflow \n");
        return;
    }
    printf("Element deleted from queue: %d \n", CircularQueue[front]);

    if (front == rear){
        front = -1;
        rear = -1;
    }
    else{
        if (front == MAX - 1){
            front = 0;
        }else{
            front = front + 1;
        }
    }
}

void Display(){
    int frontPos = front, rearPos = rear;

    if (front == -1){
        printf("Queue is empty \n");
        return;
    }
    printf("Queue Elements: ");

    if (front <= rear){
        while (frontPos <= rearPos){
            printf("%d ", CircularQueue[frontPos]);
            frontPos++;
        }
    }
    else{
        while (frontPos <= MAX - 1){
            printf("%d ", CircularQueue[frontPos]);
            frontPos++;
        }
        frontPos = 0;
        while (frontPos <= rearPos){
            printf("%d", CircularQueue[frontPos]);
            frontPos++;
        }
    }
    printf("\n");
}

int main(){
    system("cls");

    int choice, element;
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
            printf("Insert Element in Queue: ");
            scanf("%d", &element);
            Enqueue(element);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    }
}