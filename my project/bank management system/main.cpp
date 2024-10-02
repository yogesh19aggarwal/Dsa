#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

class Bank{
private:
    int total;
    string id;
    struct person{
        string name, ID, address;
        long long int contact;
        long long int cash;
    }person[100];
public:
    Bank(){
        total=0;
    }
    void choice();
    void perData();
    void display();
    void update();
    void search();
    void transaction();
    void remove();
};
void Bank::choice(){
    // system("cls");
    
    int ch;
    while(1){
        char ans;
        
        system("cls");
        cout<<"\n\n\t--------------------------------------"<<endl;
        cout<<"\t    | BANK MANAGEMENT SYSTEM  |"<<endl;
        cout<<"\t--------------------------------------"<<endl;
        cout<<"1.  Create new account"<<endl;
        cout<<"2.  View customers list"<<endl;
        cout<<"3.  Update information of existing account"<<endl;
        cout<<"4.  Check the details of an existing acccount"<<endl;
        cout<<"5.  For transactions"<<endl;
        cout<<"6.  Remove existing account"<<endl;
        cout<<"7.  Exit"<<endl;
        cout<<"\n\t--------------------------------------"<<endl;
        cout<<"\t CHOOSE OPTION: [1/2/3/4/5/6/7]"<<endl;
        cout<<"\t--------------------------------------"<<endl;
        cout<<"\n\t Enter your choice : ";
        cin>>ch;

        switch(ch){
        case 1:
            do{
                perData();
                cout<<"Add new record?(Y/N)"<<endl;
                cin>>ans;
            }while(ans=='Y'|| ans=='y');
            break;
        case 2 :
            if(total==0){
                cout<<"no data found"<<endl;
            }
            display();
            break;
        case 3:
            if(total==0){
                cout<<"no data found"<<endl;
            }
            update();
            break;
        case 4:
            if(total==0){
                cout<<"no data found"<<endl;
            }
            search();
            break;
        case 5:
            if(total==0){
                cout<<"no data found"<<endl;
            }
            transaction();
            break;
        case 6:
            if(total==0){
                cout<<"no data found"<<endl;
            }
            remove();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout<<"Invalid Input"<<endl;
            break;
        }
    }
}
void Bank::perData(){
    system("cls");
    // cout<<"Enter the details of person "<<total+1<<endl;
    cout<<"\n\n\t--------------------------------------"<<endl;
    cout<<"\t    |Enter the details of person   |"<<total+1<<endl;
    cout<<"\t--------------------------------------"<<endl;
    
    cin.ignore();
    cout<<"Name : ";
    getline(cin, person[total].name);
    // cin.ignore();

    cout<<"ID : ";
    cin>>person[total].ID;

    cin.ignore();
    cout<<"Address : ";
    getline(cin, person[total].address);
    // cin.ignore();

    cout<<"Contact : ";
    cin>>person[total].contact;

    cout<<"Cash : ";
    cin>>person[total].cash;

    total++;
    getch();
}
void Bank::display(){
    system("cls");
    
        for(int i=0; i<total; i++){
            cout<<" Data of person "<<i+1<<endl;

            cout<<"Name : "<<person[i].name<<endl;

            cout<<"ID : "<<person[i].ID<<endl;

            cout<<"Address : "<<person[i].address<<endl;

            cout<<"Contact : "<<person[i].contact<<endl;

            cout<<"Cash : "<<person[i].cash<<endl;
    }
    getch();
}
void Bank::update(){
    system("cls");
    // cout<<"Enter the id of person whose data you want to update "
    cout<<"\n\n\t-------------------------------------------------------------"<<endl;
    cout<<"\t    | UPDATING DATA  |"<<endl;
    cout<<"\t-----------------------------------------------------------------"<<endl;

    cout<<"enter the id : ";
    cin>>id;

    for(int i=0; i<total; i++){
        if(id==person[i].ID){
            cout<<"PREVIOUS DATA "<<endl;

            cout<<"Name : "<<person[i].name<<endl;

            cout<<"ID : "<<person[i].ID<<endl;

            cout<<"Address : "<<person[i].address<<endl;

            cout<<"Contact : "<<person[i].contact<<endl;

            cout<<"Cash : "<<person[i].cash<<endl;

            cout<<"\n\n Enter new data "<<endl;

            cin.ignore();
            cout<<"Name : ";
            getline(cin, person[i].name);
            

            cout<<"ID : ";
            cin>>person[i].ID;

            cin.ignore();
            cout<<"Address : ";
            getline(cin, person[i].address);
            

            cout<<"Contact : ";
            cin>>person[i].contact;

            // cout<<"Cash : ";
            // cin>>person[i].cash;

            break;
        }
        if(i==total-1){
            cout<<"No Such Record Found "<<endl;
        }
    }
    getch();
}
void Bank::search(){
    system("cls");
    cout<<"\n\n\t-------------------------------------------------------------"<<endl;
    cout<<"\t    | SEARCHING DATA  |"<<endl;
    cout<<"\t-----------------------------------------------------------------"<<endl;

    cout<<"enter the id : ";
    cin>>id;

    for(int i=0; i<total; i++){
        if(id==person[i].ID){
            cout<<" Data of person "<<i+1<<endl;

            cout<<"Name : "<<person[i].name<<endl;

            cout<<"ID : "<<person[i].ID<<endl;

            cout<<"Address : "<<person[i].address<<endl;

            cout<<"Contact : "<<person[i].contact<<endl;

            cout<<"Cash : "<<person[i].cash<<endl;

            break;
        }
        if(i==total-1){
            cout<<"No Such Record Found "<<endl;
        }
    }
    getch();
}
void Bank::transaction(){
    system("cls");
    int c;
    long int cash1;

    cout<<"enter the id : ";
    cin>>id;

    for(int i=0; i<total; i++){
        if(id==person[i].ID){
            cout<<"Name : "<<person[i].name<<endl;

            cout<<"Address : "<<person[i].address<<endl;

            cout<<"Contact : "<<person[i].contact<<endl;

            cout<<"Existing Cash : "<<person[i].cash<<endl;

            cout<<"\nPress 1 to Deposit "<<endl;
            cout<<"Press 2 to Withdraw "<<endl;
            cout<<"\nENTER YOUR CHOICE : ";
            cin>>c;

            switch(c){
            case 1:
                cout<<"Enter the amount you want to deposit : ";
                cin>>cash1;
                person[i].cash += cash1;
                cout<<"Your new amount is : "<<person[i].cash<<endl;
                break;
            case 2:
                back:
                cout<<"Enter the amount you want to withdraw : ";
                cin>>cash1;
                if(cash1 <= person[i].cash){
                    person[i].cash -= cash1;
                    cout<<"Your new amount is : "<<person[i].cash<<endl;
                }
                else{
                    cout<<"amount you want to withdraw is not available"<<endl;
                    cout<<"Existing Amount : "<<person[i].cash<<endl;
                    Sleep(3000);
                    goto back;
                }
                break;
            default :
                cout<<" Invalid Input "<<endl;
                break;
            
            }
            break;
        }
        if(i==total-1){
            cout<<"No Such Record Found "<<endl;
        }
    }
    getch();
}
void Bank::remove(){
    system("cls");
    int c;
    cout<<"Press 1 to remove specific record "<<endl;
    cout<<"press 2 to remove full record "<<endl;

    cout<<"Enter your choice : ";
    cin>>c;

    switch(c){
    case 1:
        cout<<"enter the id : ";
        cin>>id;
        for(int i=0; i<total; i++){
            if(id==person[i].ID){
                for(int j=i; j<total; j++){
                    person[j].name = person[j+1].name;
                    person[j].ID = person[j+1].ID;
                    person[j].address = person[j+1].address;
                    person[j].contact = person[j+1].contact;
                    person[j].cash = person[j+1].cash;
                    // total--;
                // break;
                }
                total--;
                break;
            }
            if(i==total-1){
                cout<<"No Such Record Found "<<endl;
            }
        }
        break;
    case 2:
        total=0;
        cout<<"All record is deleted"<<endl;
        break;
    default:
        cout<<"Invalid Input"<<endl;
    }
}

int main(){
    Bank b;
    b.choice();
    return 0;
}