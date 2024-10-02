#include<iostream>

using namespace std;

int main(){
    int row, col;
    cout<<"Enter the no. of rows in array : ";
    cin>>row;
    cout<<"Enter the no. of columns in array : ";
    cin>>col;

    int arr[row][col];
    int arr2[row][col];
    int c[row][col];
    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++){
            cout<<"enter the value of array at ["<<i<<"]["<<j<<"] : ";
            cin>>arr[i][j];
        }
        // cout<<endl;
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++){
            cout<<"enter the value of array2 at ["<<i<<"]["<<j<<"] : ";
            cin>>arr2[i][j];
        }
        // cout<<endl;
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++){
            c[i][j] = arr[i][j] + arr2[i][j];
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}