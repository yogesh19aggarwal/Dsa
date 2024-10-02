#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val){

    for(int i = 0; i < 9; i++){

        // row check
        if(board[row][i] == val){
            return false;
        }
        
        // col check
        if(board[i][col] == val){
            return false;
        }

        // 3*3 matrix check
        if(board[3 * (row/3) + i/3][3 * (col/3) + i%3]){
            return false;
        }
    }
    return true;
}

bool Solve(vector<vector<int>> &board){
    // int n = board[0].size();

    for(int row = 0; row <= 9; row++){
        for(int col = 0; col <= 9; col++){

            // cell empty
            if(board[row][col] == 0){
                for(int val = 1; val <= 9; val++){
                    if(isSafe(row , col , board , val)){
                        board[row][col] = val;

                        // recurssive call
                        bool aageSolutionPossible = Solve(board);
                        if(aageSolutionPossible){
                            return true;
                        }
                        else{
                            // backtrack

                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){

    return 0;
}