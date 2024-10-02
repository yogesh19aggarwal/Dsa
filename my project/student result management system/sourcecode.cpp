#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<string>

using namespace std;

class Student{
private:
    int total;
    string id;
    struct stu{
        string name, m_name, f_name, c_name, rollno, dd, mm, yy, grade, result, reg, clg_n;
        float per;
        int csp, ada, se, java, cs, im, sum;
    }stu[100];
public:
    Student(){
        total=0;
    }
    void menu();
    void insert();
    void display();
    void deleted();
    void student();
    void teacher();
};
void Student::menu(){
    start:
    system("cls");
        int choice;
        char ans;
        cout<<"\n\n\t\t\t\t--------------------------------------"<<endl;
        cout<<"\t\t\t\t    | RESULT MANAGEMENT SYSTEM  |"<<endl;
        cout<<"\t\t\t\t--------------------------------------"<<endl;

        cout<<"\t\t\t\t 1. Enter new record "<<endl;
        cout<<"\t\t\t\t 2. Display Record "<<endl;
        cout<<"\t\t\t\t 3. Delete Record "<<endl;
        cout<<"\t\t\t\t 4. Exit "<<endl;
        cout<<"\n\n\t\t\t\t--------------------------------------"<<endl;
        cout<<"\t\t\t\t CHOOSE OPTION: [1/2/3/4]"<<endl;
        cout<<"\t\t\t\t--------------------------------------"<<endl;

        cout<<"\t\t\t\t Enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1: 
            do{
                insert();
                cout<<"Add new record?(Y/N)"<<endl;
                cin>>ans;
            }while(ans=='Y'|| ans=='y');
            break;

            case 2:
            if(total==0){
                cout<<"no data found"<<endl;
            }
            display();
            break;

            case 3:
            if(total==0){
                cout<<"no data found"<<endl;
            }
            deleted();
            break;

            case 4:
            exit(0);
            break;
            
            default:
            cout<<"\n Invalid choice.....\t Please try again"<<endl;
        }
        getch();
        goto start;
}
void Student::insert(){
    system("cls");
    cout<<"\n\n\t\t\t\t--------------------------------------"<<endl;
    cout<<"\t\t\t\t | ADD STUDENT DETAILS  |"<<endl;
    cout<<"\t\t\t\t--------------------------------------"<<endl;
 
    cout<<"\t\t ENTER YOUR NAME                             : ";
    cin.ignore();
    getline(cin, stu[total].name);
    cout<<"\t\t ENTER MOTHER NAME                           : ";
    // cin.ignore();
    getline(cin, stu[total].m_name);
    cout<<"\t\t ENTER FATHERS NAME                          : ";
    // cin.ignore();
    getline(cin, stu[total].f_name);
    cout<<"\t\t ENTER COURSE NAME                           : ";
    // cin.ignore();
    getline(cin, stu[total].c_name);
    cout<<"\t\t ENTER THE COLLEGE NAME                      : ";
    // cin.ignore();
    getline(cin, stu[total].clg_n);
    cout<<"\t\t ENTER ROLL NUMBER                           : ";
    cin>>stu[total].rollno;
    cout<<"\t\t ENTER THE REGULATION                        : ";
    cin>>stu[total].reg;
    cout<<"\t\t ENTER YOUR DATE OF BIRTH in dd mm yy format : ";
    cin>>stu[total].dd>>stu[total].mm>>stu[total].yy;

    cout<<"\n\n\t\t\t\t--------------------------------------"<<endl;
    cout<<"\t\t\t\t | ENTER YOUR MARKS  |"<<endl;
    cout<<"\t\t\t\t--------------------------------------"<<endl;

    cout<<"CSP  : ";
    cin>>stu[total].csp;
    cout<<"ADA  : ";
    cin>>stu[total].ada;
    cout<<"SE   : ";
    cin>>stu[total].se;
    cout<<"JAVA : ";
    cin>>stu[total].java;
    cout<<"CS   : ";
    cin>>stu[total].cs;
    cout<<"IM   : ";
    cin>>stu[total].im;

    //  calculating percentage and sum
    stu[total].sum = stu[total].csp + stu[total].ada + stu[total].se + stu[total].java + stu[total].cs + stu[total].im;
    stu[total].per = stu[total].sum/6;
    if(stu[total].per>90){
        stu[total].grade="A+";
        stu[total].result = "PASS";
    }
    else if(stu[total].per>80){
        stu[total].grade = "A";
        stu[total].result = "PASS";
    }
    else if(stu[total].per>70){
        stu[total].grade = "B+";
        stu[total].result = "PASS";
    }
    else if(stu[total].per>60){
        stu[total].grade = "B";
        stu[total].result = "PASS";
    }
    else if(stu[total].per>50){
        stu[total].grade = "C+";
        stu[total].result = "PASS";
    }
    else if(stu[total].per>=40){
       stu[total].grade = "C";
        stu[total].result = "PASS";
    }
    else{
        stu[total].grade = " - ";
        stu[total].result = "FAIL";
    }
    total++;
    getch();
}
void Student::display(){
    system("cls");
    cout<<"\t\t\t\t--------------------------------------"<<endl;
    cout<<"\t\t\t\t\t | Student Result Table |"<<endl;
    cout<<"\t\t\t\t--------------------------------------"<<endl;

    for(int i=0; i<total; i++){
        cout<<"\n\n\t Class  : "<<stu[i].c_name<<endl;
        cout<<"\n\t COLLEGE NAME  : "<<stu[i].clg_n<<endl;
        cout<<"\n\n\t STUDENT'S NAME  : "<<stu[i].name;
        cout<<"\t\t\t\t\t\t ROLL NO.  : "<<stu[i].rollno<<endl;
        cout<<"\n\t MOTHER'S NAME  : "<<stu[i].m_name;
        cout<<"\t\t\t\t\t\t DATE of BIRTH : "<<stu[i].dd<<" / "<<stu[i].mm<<" / "<<stu[i].yy<<" / "<<endl;
        cout<<"\n\t FATHER'S NAME  : "<<stu[i].f_name;
        cout<<"\t\t\t\t\t\t REGULATION  : "<<stu[i].reg<<endl;
        cout<<"\n\t +-----------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\t |  SUBJECT NAME     | MARKS OBTAINED | OUT-OF | PERCENTAGE | GRADE |";
        cout<<"\n\t +-----------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\t |      CSP          |   "<<stu[i].csp<<"           | 100    |  "<< stu[i].csp <<"%       |"/*for grade*/<<endl;
        cout<<"\t |      ADA          |   "<<stu[i].ada<<"           | 100    |  "<< stu[i].ada <<"%       |"/*for grade*/<<endl;
        cout<<"\t |      SE           |   "<<stu[i].se<<"           | 100    |  "<< stu[i].se <<"%       |"/*for grade*/<<endl;
        cout<<"\t |      JAVA         |   "<<stu[i].java<<"           | 100    |  "<< stu[i].java <<"%       |"<<"   "<<stu[i].grade<<endl;
        cout<<"\t |      CS           |   "<<stu[i].cs<<"           | 100    |  "<< stu[i].cs <<"%       |"/*for grade*/<<endl;
        cout<<"\t |      IM           |   "<<stu[i].im<<"           | 100    |  "<< stu[i].im << "%       |"/*for grade*/<<endl;
        cout<<"\n\t +-----------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\t\t Total marks  : "<<stu[i].sum<<"\t\t\t\t\t RESULT  : "<<stu[i].result<<endl;
        cout<<"\t\t Percentage  : "<<stu[i].per<<"\t\t\t\t\t Grade  : "<<stu[i].grade<<endl;
        cout<<"\n\t\t Dated : ";
        cout<<"\t\t\t\t\t       Principle Signature "<<endl;
        cout<<"\n\t +-----------------------------------------------------------------------------------------------------------------------------";
    }
    
}
void Student::deleted(){
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
            if(id==stu[i].rollno){
                 for(int j=i; j<total; j++){
                    stu[j].name = stu[j+1].name;
                    stu[j]. m_name = stu[j+1].m_name;
                    stu[j].ada =  stu[j].ada;
                    stu[j].c_name =  stu[j+1].c_name;\
                    stu[j].clg_n = stu[j+1].clg_n;
                    
                 }
            }
        }
    case 2:
        total=0;
        cout<<"All Record is Deleted "<<endl;
        break;
    
    default:
        cout<<"INVALID INPUT"<<endl;
        break;
    }
}

int main(){

    Student a;
    a.menu();
    return 0;
}