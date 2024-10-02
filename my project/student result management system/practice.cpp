#include<iostream>
#include<fstream>

using namespace std;

int main(){
    fstream file;
   

    // file1.open("abc.txt", ios::out | ios::in | ios::app );
    // //  file.open();
    // string a;

    // file1<<"hello world";
    // file1.close();

    // file1.open("abc.txt", ios::in);
    // file1>>a;
    // // file1.close();
   
    // file1.close();
    //  cout<<a;

    string a;
    file.open("abc.txt", ios::out );
    
    file<<"hello my name is not yogesh\n";
    file<<"hello\n";
    file<<"you are just \n";
    file.close();

    file.open("abc.txt", ios::in);
    // ifstream in("abc.txt");
    // while(file.eof()==0){
        getline(file, a);
        cout<<a<<endl;
        string b;
        getline(file, b);
        cout<<b<<endl;

        string c;
        file>>c;
        cout<<c<<endl;
    // }

    // fstream file1("abc.txt");
    // getline(file1, a);

    // cout<<a;
   

    // file1.close();

    // cout<<a;
    return 0;
}