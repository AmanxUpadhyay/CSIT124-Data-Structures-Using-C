//* Write a program to calculate the upper triangle of a square matrix.

#include <bits/stdc++.h>
using namespace std;
/*
 * Created by Visual Studio Code
 * Author: Aman Upadhyay
 * Email: aman.upadhyay@s.amity.edu
 * Date: 18/05/2021
*/
void UpperTriangle(int Array[4][4], int row, int col){
    int i, j;

    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(i > j){
                cout << "0 ";
            }else{
                cout << Array[i][j] << " ";
            }
        }cout << endl;
    }
}

int main(){
    system("cls");

    int temp[4][4], size;
    cout << "-------------------------------" << endl;
    cout << "Enter the Size of Array: "; cin >> size;
    cout << "-------------------------------" << endl;
    cout << "Enter Elements of Array: " << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> temp[i][j];
        }
    }
    cout << "-------------------------------" << endl;
    UpperTriangle(temp, size, size);
}