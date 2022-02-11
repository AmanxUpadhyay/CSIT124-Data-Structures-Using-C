/* Write a program to implement Tower of Hanoi problem. */

#include <stdio.h>
#include <stdlib.h>
/**
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 26/02/2021
*/
void TowerOfHanoi(int diskNumbers, int TowerOne, int TowerTwo, int TowerThree){
    if(diskNumbers > 0){
        TowerOfHanoi(diskNumbers-1, TowerOne, TowerThree, TowerTwo);
        printf("\n***************************************\n");
        printf("Moving a Disc from: %d to: %d", TowerOne, TowerThree);
        printf("\n***************************************\n");
        TowerOfHanoi(diskNumbers-1, TowerTwo, TowerOne, TowerThree);
    }
}

int main(){
    system("cls");
    int NumberOfDisk;

    printf("Enter number of Disk: ");
    scanf("%d", &NumberOfDisk);
    TowerOfHanoi(NumberOfDisk, 1, 2, 3);
}