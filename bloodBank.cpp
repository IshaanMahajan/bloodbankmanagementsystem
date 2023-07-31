#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;


class blood_bank;
void admin(void);
void admin_login(void);
void user(void);
//void createFile(void);
void add_record();
void search_bgrp(void);
void deleter(void);
void displayFile(void);
void home(void);
void info(void);
#define filepath "C:/ProjBB/Data.DAT"
#define temppath "C:/ProjBB/temp.DAT" 


class blood_bank{
    //string name,address,gender,contact;
	char name[20], bgrp[5], gender,contact[10];
	int id,age;

    public :
        void accept(){       //accepting the details of the donor
            cout << "\n\t|\t  PLEASE ENTER THE REQUIRED DETAILS-> ";
            cout << "\n\t|\t Enter the name of the donor : ";
            cin >> name;
            cout << "\n\t|\t Enter the ID           : ";
            cin >> id;
            cout << "\n\t|\t Enter the contact number    : ";
            cin >> contact;
            cout << "\n\t|\t Enter the gender            : ";
            cin >> gender;
            cout << "\n\t|\t Enter the age               : ";
            cin >> age;
            cout << "\n\t|\t Enter blood group           : ";
            cin >> bgrp;
        }

        void display(){        //display the details
            cout.width(15);
            cout << name;
            cout << "    |";
            cout.width(15);
            cout << bgrp;
            cout << "    |";
            cout.width(15);
            cout << id;
            cout << "    |";
            cout.width(15);
            cout << gender;
            cout << "    |";
            cout.width(10);
            cout << age;
            cout << "    |";
            cout.width(15);
            cout << contact;
            cout << "    |"<<endl;
        }

        char* getbgrp(){
            char *bg = bgrp;
            return bg;
        }

        inline int getid(){
            return id;
        }
};

void home(){
    while(1){
        cout << "######################################################################"<<endl;
        cout << "\n\t\t    *********** HOME ************\n";
        cout << "\t========================================================="<<endl;
        cout << "\t|\tWELCOME TO BLOOD BANK MANAGEMENT SYSTEM\t\t|\n";
        cout << "\t=========================================================\n"<<endl;
        cout << "\t========================================================="<<endl;
        cout << "\t|\t\t1-> User      2-> Admin\t\t\t|\n";
        cout << "\t|\t   3-> View Compatible Blood Types\t\t|\n";
        cout << "\t|\t\t       4-> EXIT\t\t\t\t|\n";
        cout << "\t=========================================================\n"<<endl;
        cout << "======================================================================"<<endl;
        cout << "\n\t\t\t  Enter Your Choice :";
        int n;
        cin>>n;
        switch(n){
            case 1: user();
                break;

            case 2: admin_login();
                break;

            case 3: info();
                break;

            case 4:
                exit(0);

            default: cout<<"\t\t   ****Please Select a valid Option****\n";
                break;
       }
    }
}
void info(){
    cout<<"\n\t\t\t\tCOMPATIBLE BLOOD TYPE DONORS\n";
    //cout.fill('-');
    //cout.width(75);
    //cout<<1<<endl;
    //cout.fill(0);
    cout<<"   ------------------------------------------------------------------------------------------\n";
    string bloodType[8]={"A+","O+","B+","AB+","A-","O-","B-","AB-"};
    string donateBloodTo[8]={"A+,AB+","O+,A+,B+,AB+","B+,AB+","AB+","A+,A-,AB+,AB-","Everyone","B+,B-,AB+,AB-","AB+,AB-"};
    string receiveBloodFrom[8]={"A+,A-,O+,O-","O+,O-","B+,B-,O+,O-","Everyone","A-,O-","O-","B-,O-","AB-,A-,B-,O-"};

    cout.width(15);
    cout<<"BLOOD TYPE"<<"       |";
    cout.width(30);
    cout<<"DONATE BLOOD TO"<<"       |";
    cout.width(30);
    cout<<"RECEIVE BLOOD FROM\n";
    cout<<"   ------------------------------------------------------------------------------------------\n";

    for(int i=0;i<8;i++){
        cout.width(15);
        cout<<bloodType[i]<<"       |";

        cout.width(30);
        cout<<donateBloodTo[i]<<"       |";

        cout.width(30);
        cout<<receiveBloodFrom[i]<<endl;
    }
    cout<<"   ------------------------------------------------------------------------------------------\n";
    cout<<endl;
}

void admin_login(){
    string userName;
    string userPassword;
    int loginAttempt = 0;
    char admin1;

    while(loginAttempt < 5)
    {
        cout << "\n\t\t\t  ```` HEY ADMIN ````\n";
        cout << "\n\t|  Please enter your user name     :";
        cin >> userName;
        cout << "\t|  Please enter your user password :";
        cin >> userPassword;

        if (userName == "admin1" && userPassword == "admin1"){
            cout<<"\n======================================================================"<<endl;
            cout << "\t\t\t````` Welcome Admin `````\n";
            admin();
            break;
        }
        else{
            cout << "\n\t\t#### Invalid login attempt. Please try again. ####\n" << '\n';
            cout<<"\n======================================================================"<<endl;
            loginAttempt++;
        }
    }
    if (loginAttempt == 5){
        cout << "\n\t   ##### Too many login attempts! The program will now terminate. ####\n";
        exit(0);
    }
}

void admin(){
    int ch;
	while(1){ //displaying the menu
        cout << "\n\t\t*********** MAIN MENU ************"
                "\n\t\t |   1. Add new record           |"
                "\n\t\t |   2. Search by blood group    |"
                "\n\t\t |   3. Delete a record          |"
                "\n\t\t |   4. Display all the records  |"
                "\n\t\t |   5. Return to Home           |"
                "\n\t\t |   6. Exit from Program        |"
                "\n\n\t\t  -->  Enter your choice here : ";
        cin >> ch;

        switch(ch){
            case 1: add_record();
                break;

            case 2: search_bgrp();
                break;

            case 3: deleter();
                break;

            case 4: displayFile();
                break;

            case 5: home();
                break;

            case 6: 
                exit(0);

            default: cout<<"\n\t\t  ****Please Select a valid Option****\n";
                break;
        }
	}
}

void user(){
    
    while(1){
        int n;
        cout << "\n\t\t\t  ```` WELCOME USER `````\n";
        cout << "\t\t\t1-> Donor      2-> Patient\n";
        cout << "\t\t\t  3-> Return to Home\n";
        cout << "\n\t\t\t  Enter Your Choice :";
        cin >> n;
        switch(n){
            case 1: add_record();
                break;

            case 2: search_bgrp();
                break;

            case 3: home();
                break;

            default: cout<<"\t\t   ****Please Select a valid Option****\n";
                break;
        }
    }
}

/*
void createFile(){   //to create new file
    int n;
    blood_bank obj;

    cout << "\n\t\t Enter the number of donors : ";
    cin >> n;

    ofstream file;
    file.open("Data.DAT", ios::out);
    for(int i=0; i<n; i++){
        obj.accept();
        cout<<endl<<endl<<"---------------Checkpoint-----------"<<endl<<endl;
        obj.display();
        file.write((char *)&obj, sizeof(obj));
    }
    file.close();
}
*/

void displayFile(){    //to display all the details from the file
    blood_bank obj;

    ifstream file;
    file.open(filepath, ios::in);
    cout<<endl<<endl;
    cout.width(15);
    cout<<"Name"<<"    |";
    cout.width(15);
    cout<<"Blood Group"<<"    |";
    cout.width(15);
    cout<<"ID"<<"    |";
    cout.width(15);
    cout<<"Gender"<<"    |";
    cout.width(10);
    cout<<"Age"<<"    |";
    cout.width(15);
    cout<<"Contact No."<<"    |"<<endl;
    cout<<"\t ----------------------------------------------------------------------------------------------------------\n";
    while(file){
        file.read((char*)&obj, sizeof(obj));
        if(file.eof() != 0)
            break;
        obj.display();
    }
    file.close();
}



void search_bgrp(){    //search for blood group

    char bgrp_s[5];
    int flag=0;
    blood_bank obj;
    char *b;
    b = obj.getbgrp();

    ifstream file;
    file.open(filepath, ios::in);

    cout << "\n\t\t Enter the blood group to be searched : ";
    cin >> bgrp_s;
    file.read((char *)&obj, sizeof(obj));
    cout<<endl<<endl;
    cout.width(15);
    cout<<"Name"<<"    |";
    cout.width(15);
    cout<<"Blood Group"<<"    |";
    cout.width(15);
    cout<<"ID"<<"    |";
    cout.width(15);
    cout<<"Gender"<<"    |";
    cout.width(10);
    cout<<"Age"<<"    |";
    cout.width(15);
    cout<<"Contact No."<<"    |"<<endl;
    cout<<"\t ----------------------------------------------------------------------------------------------------------\n";
    
    while(!file.eof()){
        if(strcmp(bgrp_s, obj.getbgrp())==0){
            flag=1;
            obj.display();
        }
        file.read((char *)&obj, sizeof(obj));
    }

    file.close();

    if(flag == 0)
        cout << "\n\t\t No blood group of that category available.\n\n ";
}

void deleter()    //to delete a particular record from the file
{
    ifstream file1;
    ofstream file2;

    file1.open(filepath, ios::in);
    file2.open(temppath, ios::out);

    int id_del;
    blood_bank obj;

    cout << "\n\t\t Enter Id number to delete : ";
    cin >> id_del;

    file1.read((char *)&obj, sizeof(obj));
    while(!file1.eof()){
        if(id_del != obj.getid()){
            cout << "\n\t\t\t Writing ";
            obj.display();
            file2.write((char *)&obj, sizeof(obj));
        }
        else{
            cout << "\n\t\t\t Reading ";
            obj.display();
            cout<<"\n\t\tPress Any Key....For Search"<<endl;
        }
        file1.read((char *)&obj, sizeof(obj));
    }

    file1.close();
    file2.close();
    remove(filepath);
    rename(temppath, filepath);
    cout << "\n\t\t\t Process complete. ";
}

void add_record()   //add new entry in the file
{
    blood_bank obj;
    obj.accept(); 
    ofstream file;
    file.open(filepath, ios::app);
    file.write((char*)&obj, sizeof(obj));
    file.close();
}


int main(){
    home();
    return 0;
}