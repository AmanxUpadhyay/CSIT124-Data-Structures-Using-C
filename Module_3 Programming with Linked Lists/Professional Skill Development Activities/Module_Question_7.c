/* Write a program to increment the data part of every node present in a linked list by 10. Display the data both before incrimination and after. */
#include <stdio.h>
#include <stdlib.h>
/*
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 19/05/2021
*/
typedef struct Node {
   int value;
   struct Node *next;
}List;

//following head variable is globally declared so that we do not have to pass it in function calling
struct Node* head = NULL;

//following function will add every passed element in linked list
void insert(int new_val){
   List* new_node = (List*) malloc(sizeof(List));
   new_node->value = new_val;
   new_node->next = head;
   head = new_node;
}

//following function will Increase value by 10 for every node in linked list
void increment(){
    List* ptr;
    ptr = head;
    while (ptr != NULL) // if node is not the last node
    {
        ptr->value += 10;
        ptr = ptr->next;
    }
}
/*
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 19/05/2021
*/
void display_linked_list(){
   List* temp;
   temp = head;
   
   while (temp != NULL){
        printf("%d",temp->value);
        if(temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
   }
   
   printf("\n");
}

int main(){
    insert(10);
    insert(20);
    insert(40);
    insert(30);
    insert(45);
    insert(35);
/*
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 19/05/2021
*/
    printf("Linked List created is : \n");
    display_linked_list();
    printf("\n");
    
    increment();
    
    printf("Increased Linked list is : \n");
    display_linked_list();
   
    return 0;
}