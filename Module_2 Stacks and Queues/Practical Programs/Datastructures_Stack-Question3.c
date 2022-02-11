/* Write a program using recursion to reverse a string. */

#include <stdio.h>
#include <stdlib.h>
/**
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 26/02/2021
*/
void reverseString(){
    char string;
    scanf("%c", &string);
    if(string != '\n'){
        reverseString();
        printf("%c", string);
    }
}

int main(){
    system("cls");

    printf("Enter any String: ");
    reverseString();
}