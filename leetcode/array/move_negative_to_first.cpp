#include<iostream>
#include<vector>

using namespace std;

void moveNegativeToFirst(vector<int> &arr){

    int low = 0;
    int high = arr.size() - 1;

    while(low < high){

        if(arr[high] < 0){
            while(arr[low] < 0 && low < high){
                low++;
            }
            swap(arr[low], arr[high]);
        } 
        else{
            high--;
        }
    }
}

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int rowStart = 0;
        int colStart = 0;
        int colEnd = c-1;
        int rowEnd = r-1;
        // int d = 1;
        
        int size = matrix.size() * matrix[0].size();
        
        while(rowStart <= rowEnd && colStart <= colEnd){
           
           for(int col = colStart; col <= colEnd; col++){
               ans.push_back(matrix[rowStart][col]);
            //   d++;
           }
           rowStart++;
           if(rowStart > rowEnd || colStart > colEnd){
                break;
           }
           
           for(int row = rowStart; row <= rowEnd; row++){
               ans.push_back(matrix[row][colEnd]);
            //   d++;
           }
           colEnd--;
            if(rowStart > rowEnd || colStart > colEnd){
                break;
           }
           
           for(int col = colEnd; col >= colStart; col--){
               ans.push_back(matrix[rowEnd][col]);
            //   d++;
           }
           rowEnd--;
            if(rowStart > rowEnd || colStart > colEnd){
                break;
           }
           
           for(int row = rowEnd; row >= rowStart; row--){
               ans.push_back(matrix[row][colStart]);
            //   d++;
           }
           colStart++;
            if(rowStart > rowEnd || colStart > colEnd){
                break;
           }
       }
       
       return ans;
        
    }

int main(){

    // vector<int> arr = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    // moveNegativeToFirst(arr);

    // for(int i = 0; i < arr.size(); ++i){
    //     cout<<arr[i]<<", ";
    // }cout<<endl;

    vector<vector<int> > matrix = {{1, 2, 3, 4},
                                   {5, 6, 7, 8},
                                   {9, 10, 11, 12},
                                   {13, 14, 15,16}};

    for(auto i : matrix){
        for(auto j : i){
            cout<<j<<", ";
        }cout<<endl;
    }
    
    vector<int> ans = spirallyTraverse(matrix, 4, 4); 
    

    for(auto i : ans){
        cout<<i<<", ";
    }cout<<endl;
    return 0;
}