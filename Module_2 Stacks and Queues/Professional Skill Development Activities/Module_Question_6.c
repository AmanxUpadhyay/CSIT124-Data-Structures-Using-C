/* What is Tower of Hanoi problem in C? Write a program to implement it. 
 *  Ans: The Tower of Hanoi also called the Tower of Brahma or Lucas' Tower and sometimes pluralized as Towers, or simply pyramid puzzle is a mathematical game or puzzle. It consists of three rods and a number of disks of different diameters, which can slide onto any rod. The puzzle starts with the disks stacked on one rod in order of decreasing size, the smallest at the top, thus approximating a conical shape.
*/

#include <stdio.h>
#include <stdlib.h>
/*
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 26/02/2021
*/
void TowerOfHanoi(int diskNumbers, int TowerOne, int TowerTwo, int TowerThree){
    if(diskNumbers > 0){
        TowerOfHanoi(diskNumbers-1, TowerOne, TowerThree, TowerTwo);
        printf("\n---------------------------------------\n");
        printf("Moving a Disc from: %d to: %d", TowerOne, TowerThree);
        printf("\n---------------------------------------\n");
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