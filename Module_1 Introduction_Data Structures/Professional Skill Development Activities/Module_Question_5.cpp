/* Write a Function in C++ which accepts an Integer array and its size as arguments and 
swap the elements of every location with its following odd location. */

#include <bits/stdc++.h>
using namespace std;
/**
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 23/02/2021
*/
void swapingArray(int Array[], int number){
    int placeHolder, i;

    for(i = 0; i < number; i++){
        for(i = 0; i < number-1; i+=2){
            placeHolder = Array[i];
            Array[i] = Array[i+1];
            Array[i+1] = placeHolder;
        }
    }
    for(i = 0; i < number; i++){
        cout << Array[i] << "\t";
    }
}

int main(){
    system("cls");
    
    int Array[10], arraySize;

    cout << "-------------------------------" << endl;
    cout << "****** Enter Size of Array: "; cin >> arraySize;
    cout << "-------------------------------" << endl;

    cout << "****** Enter Element of Array: " << endl;
    for(int i = 0; i < arraySize; i++){
        cin >> Array[i];
    }
    cout << "-------------------------------" << endl;

    swapingArray(Array, arraySize);
}