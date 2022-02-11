#include <stdio.h>
#include <stdlib.h>

// Circular Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Insertion at the beginning
void insert_beginning(int data) {
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    }
    else {
        ptr->data = data;
        ptr->next = head;
        if (head != NULL) {
            head->next->prev = ptr;
        }
        head = ptr;
        ptr->prev = head;
        printf("\nNode inserted\n");
    }
}

// Insertion at the end
void insert_last(int data) {
    struct Node* ptr, * temp;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    }
    else {
        ptr->data = data;
        ptr->next = head;
        if (head != NULL) {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
        }
        else {
            ptr->prev = ptr;
            head = ptr;
        }
        printf("\nNode inserted\n");
    }
}

// Insertion at any position
void insert_any(int data, int pos) {
    struct Node* ptr, * temp;
    int i;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    }
    else {
        ptr->data = data;
        if (head == NULL) {
            ptr->next = head;
            ptr->prev = head;
            head = ptr;
        }
        else {
            temp = head;
            for (i = 1; i < pos; i++) {
                temp = temp->next;
            }
            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next->prev = ptr;
            temp->next = ptr;
        }
        printf("\nNode inserted\n");
    }
}

// Deletion at the beginning
void delete_beginning() {
    struct Node* temp;
    if (head == NULL) {
        printf("\nList is empty");
    }
    else {
        temp = head;
        head = head->next;
        head->prev = temp->prev;
        temp->prev->next = head;
        free(temp);
        printf("\nNode deleted\n");
    }
}

// Deletion at the end
void delete_last() {
    struct Node* temp, * ptr;
    if (head == NULL) {
        printf("\nList is empty");
    }
    else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

// Deletion at any position
void delete_any(int pos) {
    struct Node* temp, * ptr;
    int i;
    if (head == NULL) {
        printf("\nList is empty");
    }
    else {
        temp = head;
        for (i = 1; i < pos; i++) {
            temp = temp->next;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

// Display the list
void display() {
    struct Node* ptr;
    if (head == NULL) {
        printf("\nList is empty");
    }
    else {
        ptr = head;
        printf("\nList is : ");
        do {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
        printf("\n");
    }
}

// Search for a node
int search(int data) {
    struct Node* ptr;
    int i = 1;
    if (head == NULL) {
        printf("\nList is empty");
        return 0;
    }
    else {
        ptr = head;
        do {
            if (ptr->data == data) {
                printf("\nNode found at position %d", i);
                return 1;
            }
            ptr = ptr->next;
            i++;
        } while (ptr != head);
        printf("\nNode not found");
        return 0;
    }
}

// Reverse the list
void reverse() {
    struct Node* ptr, * temp;
    if (head == NULL) {
        printf("\nList is empty");
    }
    else {
        ptr = head;
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        temp = head;
        while (temp->next != head) {
            ptr->next = temp;
            ptr = ptr->prev;
            temp = temp->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
        head = temp;
        printf("\nList reversed");
    }
}

// Main function
int main() {
    int choice, data, pos;
    while (1) {
        printf("\n1. Insert at the beginning\n2. Insert at the end\n3. Insert at any position\n4. Delete at the beginning\n5. Delete at the end\n6. Delete at any position\n7. Display\n8. Search\n9. Reverse\n10. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the data : ");
            scanf("%d", &data);
            insert_beginning(data);
            break;
        case 2:
            printf("\nEnter the data : ");
            scanf("%d", &data);
            insert_last(data);
            break;
        case 3:
            printf("\nEnter the data : ");
            scanf("%d", &data);
            printf("\nEnter the position : ");
            scanf("%d", &pos);
            insert_any(data, pos);
            break;
        case 4:
            delete_beginning();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            printf("\nEnter the position : ");
            scanf("%d", &pos);
            delete_any(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("\nEnter the data : ");
            scanf("%d", &data);
            search(data);
            break;
        case 9:
            reverse();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("\nWrong choice");
        }
    }
    return 0;
}