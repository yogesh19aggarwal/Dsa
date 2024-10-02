#include<iostream>

using namespace std;

int main(){

    // question 1
    // Write a program in C++ to print a welcome text in a separate line.
    cout<<"WELCOME"<<endl;

    // question 2
    // Write a program in C++ to print the sum of two numbers.
    int a,b,sum;
    cout<<"enter first number : ";
    cin>>a;
    cout<<"enter second number : ";
    cin>>b;

    sum= a+b;
    cout<<"the sum of two numbers is : "<<sum<<endl;

    // question 3
    // Write a program in C++ to find Size of fundamental data types.
    cout<<endl;
    cout<<"size of int is : "<<sizeof(int)<<endl;
    cout<<"size of char is : "<<sizeof(char)<<endl;
    cout<<"size of bool is : "<<sizeof(bool)<<endl;
    cout<<"size of float is : "<<sizeof(float)<<endl;
    cout<<"size of long is : "<<sizeof(long)<<endl;
    cout<<"size of long long is : "<<sizeof(long long)<<endl;
    cout<<"size of double is : "<<sizeof(double)<<endl;
    cout<<"size of long double is : "<<sizeof(long double)<<endl;

    // question 4
    // Write a program in C++ to check the upper and lower limits of integer.
    cout<<endl;
    cout << " The maximum limit of int data type :                  " << INT_MAX << endl;
	cout << " The minimum limit of int data type :                  " << INT_MIN << endl;
	cout << " The maximum limit of unsigned int data type :         " << UINT_MAX << endl;
	cout << " The maximum limit of long long data type :            " << LLONG_MAX << endl;
	cout << " The minimum limit of long long data type :             " << LLONG_MIN << endl;
	cout << " The maximum limit of unsigned long long data type :   " << ULLONG_MAX << endl;
	cout << " The Bits contain in char data type :                  " << CHAR_BIT << endl;
	cout << " The maximum limit of char data type :                 " << CHAR_MAX << endl;
	cout << " The minimum limit of char data type :                 " << CHAR_MIN << endl;
	cout << " The maximum limit of signed char data type :          " << SCHAR_MAX << endl;
	cout << " The minimum limit of signed char data type :          " << SCHAR_MIN << endl;
	cout << " The maximum limit of unsigned char data type :        " << UCHAR_MAX << endl;
	cout << " The minimum limit of short data type :                " << SHRT_MIN << endl;
    cout << " The maximum limit of short data type :                " << SHRT_MAX << endl;
    cout << " The maximum limit of unsigned short data type :       " << USHRT_MAX << endl;
    cout<<endl;

    // question 5
    // Write a program in C++ to display various type or arithmetic operation using mixed data type.

    int m1=4, m2=7;
    double d1=4.5, d2=7.8;
    cout <<" "<< m1 << " + " << m2 << " = " << m1+m2 << endl;  
    cout <<" "<< d1 << " + " << d2 << " = " << d1+d2 << endl;  
    cout <<" "<< m1 << " + " << d2 << " = " << m1+d2 << endl;  
    
    cout <<" "<< m1 << " - " << m2 << " = " << m1-m2 << endl;  
    cout <<" "<< d1 << " - " << d2 << " = " << d1-d2 << endl;  
    cout <<" "<< m1 << " - " << d2 << " = " << m1-d2 << endl;  
    
    cout <<" "<< m1 << " * " << m2 << " = " << m1*m2 << endl; 
    cout <<" "<< d1 << " * " << d2 << " = " << d1*d2 << endl;  
    cout <<" "<< m1 << " * " << d2 << " = " << m1*d2 << endl;  
    
    cout <<" "<< m1 << " / " << m2 << " = " << m1/m2 << endl;  
    cout <<" "<< d1 << " / " << d2 << " = " << d1/d2 << endl;  
    cout <<" "<< m1 << " / " << d2 << " = " << m1/d2 << endl;  
    cout << endl;




    return 0;
}