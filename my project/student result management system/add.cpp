#include<iostream>
// #include<fstream>
#include<conio.h>
#include<cstdlib>
#include<string>

using namespace std;

class Student{
    private:
        int total;
        int id1;
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
            display();
            break;

            case 3:
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
    // fstream file;
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

    // creating a file to store student details
    
    // file.open("result.txt", ios::out);
    // file<<c_name<<"\n"<<clg_n<<"\n"<<name<<"\n"<<rollno<<"\n"<<m_name<<"\n"<<dd<<" "<<mm <<" "<<yy<<"\n"<<f_name<<"\n"<<reg<<"\n"<<grade<<"\n"<<result<<"\n"<<csp<<"\n"<<ada<<"\n"<< se<<"\n"<<java<<"\n"<<cs<<"\n"<<im<<"\n"<<sum<<"\n"<<per;
    // file.close();
}
void Student::display(){
    system("cls");
    // fstream file;
    string count;
    string stu, tech;
    int choice;
    cout<<"\t\t\t\t--------------------------------------"<<endl;
    cout<<"\t\t\t\t\t | who are you |"<<endl;
    cout<<"\t\t\t\t--------------------------------------"<<endl;

    cout<<"\t\t\t\t 1. Student "<<endl;
        cout<<"\t\t\t\t 2. Teacher "<<endl;
        // cout<<"\t\t\t\t 3. Delete Record "<<endl;
        cout<<"\t\t\t\t 3. Previous Menu "<<endl;
        cout<<"\n\n\t\t\t\t--------------------------------------"<<endl;
        cout<<"\t\t\t\t CHOOSE OPTION: [1/2/3]"<<endl;
        cout<<"\t\t\t\t--------------------------------------"<<endl;

        cout<<"\t\t\t\t Enter your choice : ";
        cin>>choice;
    switch(choice){
        case 1 :
        student();
        break;

        case 2 :
        teacher();
        break;

        case 3 :
        menu();
        break;

        default:
        cout<<"\n Invalid choice.....\t Please try again"<<endl;
    }
}
void Student::teacher(){
    system("cls");
    fstream file;
    file.open("result.txt", ios::in);
    if(!file){
        cout<<"\n\t\t\t No Data is Found....... "<<endl;
        file.close();
    }
    else{
        while(!file.eof() ){
            getline(file, c_name);
            getline(file, clg_n);
            getline(file,name);
            getline(file,rollno);
            getline(file,m_name);
            file>>dd>>mm>>yy;
            file.ignore();
            getline(file, f_name);
            getline(file, reg);
            getline(file, grade);
            getline(file, result);
            file>>csp>>ada>>se>>java>>cs>>im>>sum>>per;
            file.ignore();

            cout<<"\t\t\t\t--------------------------------------"<<endl;
            cout<<"\t\t\t\t\t | Student Result Table |"<<endl;
            cout<<"\t\t\t\t--------------------------------------"<<endl;

            cout<<"\n\t +-----------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n\t |  Student Name     |    Mother's Name    |   Course Name  | Total Marks | PERCENTAGE | GRADE |";
            cout<<"\n\t +-----------------------------------------------------------------------------------------------------------------------------"<<endl;

        }
    }
}
void Student::student(){
    system("cls");
    fstream file;
    cout<<"\t\t\t\t--------------------------------------"<<endl;
    cout<<"\t\t\t\t\t | Student Result Table |"<<endl;
    cout<<"\t\t\t\t--------------------------------------"<<endl;

    file.open("result.txt", ios::in);
    if(!file){
        cout<<"\n\t\t\t No Data is Found....... "<<endl;
        file.close();
    }
    else{
        
        // file.ignore();
        // cout<<reg<<endl;
        // string data=0;
        while(!file.eof() ){
            getline(file, c_name);
            getline(file, clg_n);
            getline(file,name);
            getline(file,rollno);
            getline(file,m_name);
            file>>dd>>mm>>yy;
            file.ignore();
            getline(file, f_name);
            getline(file, reg);
            getline(file, grade);
            getline(file, result);

            file>>csp>>ada>>se>>java>>cs>>im>>sum>>per;
            file.ignore();

            cout<<"\n\n\t Class  : "<<c_name<<endl;
            cout<<"\n\t COLLEGE NAME  : "<<clg_n<<endl;

            cout<<"\n\n\t STUDENT'S NAME  : "<<name;
            cout<<"\t\t\t\t\t\t ROLL NO.  : "<<rollno<<endl;

            cout<<"\n\t MOTHER'S NAME  : "<<m_name;
            cout<<"\t\t\t\t\t\t DATE of BIRTH : "<<dd<<"/"<<mm<<"/"<<yy<<"/"<<endl;

            cout<<"\n\t FATHER'S NAME  : "<<f_name;
            cout<<"\t\t\t\t\t\t REGULATION  : "<<reg<<endl;

            cout<<"\n\t +-----------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n\t |  SUBJECT NAME     | MARKS OBTAINED | OUT-OF | PERCENTAGE | GRADE |";
            cout<<"\n\t +-----------------------------------------------------------------------------------------------------------------------------"<<endl;

            cout<<"\t |      CSP          |   "<<csp<<"           | 100    |  "<<"          |"<<"       |"<< endl;
            cout<<"\t |      ADA          |   "<<ada<<"           | 100    |  "<<"          |"<<"       |"<< endl;
            cout<<"\t |      SE           |   "<<se<<"           | 100    |    "<< per<<"%     |   "<<grade<<"   |"<<endl;
            cout<<"\t |      JAVA         |   "<<java<<"           | 100    |  "<<"          |"<<"       |"<<endl;
            cout<<"\t |      CS           |   "<<cs<<"           | 100    |  "<<"          |"<<"       |"<<endl;
            cout<<"\t |      IM           |   "<<im<<"           | 100    |  "<<"          |"<<"       |"<<endl;
            cout<<"\n\t +-----------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n\t\t Total marks  : "<<sum<<"\t\t\t\t\t RESULT  : "<<result<<endl;
            cout<<"\t\t Percentage  : "<<per<<"\t\t\t\t\t Grade  : "<<grade<<endl;
            cout<<"\n\t\t Dated : ";
            cout<<"\t\t\t\t\t       Principle Signature "<<endl;

            cout<<"\n\t +-----------------------------------------------------------------------------------------------------------------------------";

            // getline(file, c_name);
            // getline(file, clg_n);
            // getline(file,name);
            // getline(file,rollno);
            // getline(file,m_name);
            // file>>dd>>mm>>yy;
            // file.ignore();
            // getline(file, f_name);
            // getline(file, reg);
            // getline(file, grade);
            // getline(file, result);

            // file>>csp>>ada>>se>>java>>cs>>im>>sum>>per;
        }
        file.close();
    }
    
}
void Student::deleted(){
    system("cls");
    fstream file, file1;
    string roll_no;
    int found=0;

    cout<<"----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t Delete Student record"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    file.open("result.txt" , ios::in);
    if(!file){
        cout<<"\n\t\t\t No Data is Found"<<endl;
        file.close();
    }
    else{

        cout<<"\n\t\t\t --> Enter the Rollno. of student which you want you to delete tha data  : ";
        cin>>roll_no;
        file1.open("temp.txt", ios::out );
        
        // file>>name>> m_name>> f_name>> c_name>> rollno>> dd>> mm>> yy>> grade>> result>> reg >> per>> csp>> ada>> se>> java>> cs>> im>> sum>>clg_n;
        while(!file.eof()){
        getline(file, c_name);
        getline(file, clg_n);
        getline(file,name);
        getline(file,rollno);
        getline(file,m_name);
        file>>dd>>mm>>yy;
        file.ignore();
        getline(file, f_name);
        getline(file, reg);
        getline(file, grade);
        getline(file, result);

        file>>csp>>ada>>se>>java>>cs>>im>>sum>>per;
            if(roll_no != rollno){
                file1<<c_name<<"\n"<<clg_n<<"\n"<<name<<"\n"<<rollno<<"\n"<<m_name<<"\n"<<dd<<" "<<mm <<" "<<yy<<"\n"<<f_name<<"\n"<<reg<<"\n"<<grade<<"\n"<<result<<"\n"<<csp<<"\n"<<ada<<"\n"<< se<<"\n"<<java<<"\n"<<cs<<"\n"<<im<<"\n"<<sum<<"\n"<<per;
            }
            else{
                found++;
                cout<<"\n\t\t\t Record is finally deleted "<<endl;
            }
            // getline(file, c_name);
            // getline(file, clg_n);
            // getline(file,name);
            // getline(file,rollno);
            // getline(file,m_name);
            // file>>dd>>mm>>yy;
            // file.ignore();
            // getline(file, f_name);
            // getline(file, reg);
            // getline(file, grade);
            // getline(file, result);

            // file>>csp>>ada>>se>>java>>cs>>im>>sum>>per;
            // file>>name>> m_name>> f_name>> c_name>> rollno>> dd>> mm>> yy>> grade>> result>> reg >> per>> csp>> ada>> se>> java>> cs>> im>> sum>> clg_n;
        }
        if(found==0){
            cout<<"\n\t\t\t Student rollno is not found "<<endl;
        }
        file.close();
        file1.close();

        remove("result.txt");
        rename("temp.txt", "result.txt");
    }
}

int main(){

    Student a;
    a.menu();
    // a.insert();
    // a.display();
    // Student b;
    // b.insert();
    // b.display();
    getch();
    return 0;
}