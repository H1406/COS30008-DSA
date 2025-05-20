#include<iostream>
using namespace std;

int main(){
    int rows= 5;
    int cols = 5;
    int **arr = new int*[rows];
    for(int i=0;i<rows;i++){
        arr[i] = new int[cols];
    }
    int value = 1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            arr[i][j] = ++value;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}