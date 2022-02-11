/* Write Array Function in C++ which accepts and the Integer array and Its number as argument/parameters and assign the elements. 
If array is 1 2 3 4  5

 * 1 2 3 4 5 6
 * 1 2 3 4 5 0
 * 1 2 3 4 0 0
 * 1 2 3 0 0 0
 * 1 2 0 0 0 0
 * 1 0 0 0 0 0
*/

#include <bits/stdc++.h>
using namespace std;
/*
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 23/02/2021
*/
void FunctionOfArray(int Array[6], int number){
    int TwoDArray[number][number];

    for(int i = 0; i < number; i++){
        for(int j = 0; j < number; j++){
            if((i+j) >= number){
                TwoDArray[i][j] = 0;
            }else{
                TwoDArray[i][j] = Array[j];
            }cout << TwoDArray[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "-------------------------------" << endl;
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

    FunctionOfArray(Array, arraySize);
}