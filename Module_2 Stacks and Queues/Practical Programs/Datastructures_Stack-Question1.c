/* Write a program to implement Stack using array and also show overflow and underflow in respective push and pop operations. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/**
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 03/03/2021
*/
#define SIZE 5
int stack[SIZE];
int top = -1;

void push(int element){
    if (top >= SIZE){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = element;

    printf("Data Inserted to stack.\n");
}

int pop(){
    if (top < 0){
        printf("Stack is Underflow.\n");
    }
    return stack[top--];
}

int main(){
    system("cls");
    int choice, data;

    while(1){
        printf("------------------------------------\n");
        printf("    STACK IMPLEMENTATION PROGRAM    \n");
        printf("------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Size\n");
        printf("4. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice){
            case 1: 
                printf("Enter data to push into stack: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2: 
                data = pop();

                // If stack is not empty
                if (data != INT_MIN)
                    printf("Data Removed: %d\n", data);
                break;

            case 3: 
                printf("Stack size: %d\n", top + 1);
                break;

            case 4: 
                printf("Exiting from app.\n");
                exit(0);
                break;

            default: 
                printf("Invalid choice, please try again.\n");
        }

        printf("\n\n");
    }


    return 0;
}
