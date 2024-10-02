#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool isSafe(int **arr , int x , int y , int n){// n is number of queens
    for(int rows = 0; rows < x; rows++){
        if(arr[rows][y] == 1){
            return false;
        }
    }
    int rows = x;
    int cols = y;
    while(rows >= 0 && cols >= 0){
        if(arr[rows][cols] == 1){
            return false;
        }
        rows--;
        cols--;
    }
    rows = x;
    cols = y;
    while(rows >= 0 && cols < n){
        if(arr[rows][cols] == 1){
            return false;
        }
        rows--;
        cols++;
    }

    return true;
}

bool nqueen(int **arr , int x , int n){// n is number of queens
    
    if(x >= n){
        return true;
    }

    for(int col = 0; col < n; col++){
        if(isSafe(arr , x , col , n)){
            arr[x][col] = 1;

            if(nqueen(arr , x+1 , n)){
                return true;
            }

            arr[x][col] = 0;
        }
    }

    return false;
}

int main(){

    // histtogram
        vector<int> height;
        int start = 0;
        int end = height.size()-1;
        int max = INT_MIN;
        while(start < end){
            int area = min(height[start] , height[end])*(end-start);
            if(area > max){
                max = area;
            }
            if(height[start] > height[end]){
                end--;
            }
            else{
                start++;
            }
        }
    return 0;
}