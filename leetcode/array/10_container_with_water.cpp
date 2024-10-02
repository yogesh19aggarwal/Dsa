#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {

    int start = 0;
    int end = height.size()-1;
    int sol = 0;
    int area;
    while(start < end){
        area = min(height[start] , height[end] )* (end-start);
        if(area > sol){
            sol = area;
        }
        if( height[start] > height[end]){
            end--;
        }
        else{
            start++;
        }
    }

    return sol;
}
string intToRoman(int num){
    string ans = "";
    while(num >= 1000){
        ans += "M";
        num -= 1000;
    }
    if(num >= 900){
        ans += "CM";
        num -= 900;
    }
    if(num >= 500){
        ans += "D";
        num -= 500;
    }
    if(num >= 400){
        ans += "CD";
        num -= 400;
    }
    while(num >= 100){
        ans += "C";
        num -= 100;
    }
    if(num >= 90){
        ans += "XC";
        num -= 90;
    }
    if(num >= 50){
        ans += "L";
        num -= 50;
    }
    if(num >= 40){
        ans += "Xl";
        num -= 40;
    }
    while(num >= 10){
        ans += "X";
        num -= 10;
    }
    if(num >= 9){
        ans += "IX";
        num -= 9;
    }
    if(num >=5){
        ans += "V";
        num -= 5;
    }
    if(num >= 4){
        ans += "IV";
        num -= 4;
    }
    while(num >= 1){
        ans += "I";
        num -= 1;
    }
    return ans;

}

int main(){
    // vector<int>height = {1,8,6,2,5,4,8,3,7};
    // maxArea(height);

    cout<<intToRoman(3);
    return 0;
}