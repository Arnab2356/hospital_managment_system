#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
using namespace std;

class saaar_management
{
private:
    // Data members for patient's details
    string name; // for name
    string contact; // for contact number
    string blood; // for blood group
    string aadhar; // for aadhar number
    string dr; // for doctor name
    string disease; // for doctor name
    int age; // for doctor age
	int id; // for doctor id
    string address; // for doctor address

public:
    // Member  Functions
    void menu(); // for mane menu
    void waitForEnter(); 
    void insert(); // for insert new patient's details
    void display(); // for display all patient's details
    void modify(); // for modify patient's details
   	void search(); // for search patient's details
    void deleted(); // for delete patient's details
};

void saaar_management::menu() //mane Menu
{
    //login declaration
    //login screen
    while (true)
    {
        int choice;
        char x; // Options to choose an action
        system("cls"); // open a new screen 
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t>> HOSPITAL MANAGEMENT SYSTEM <<" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1. NEW ENTRY AND TOKEN GENERATION" << endl;
        cout << "\t\t\t\t\t 2. DISPLAY PATIENT\'S INFORMATION" << endl;
        cout << "\t\t\t\t\t 3. MODIPHY PATIENT\'S HISTORY/DATABASE" << endl;
        cout << "\t\t\t\t\t 4. SEARCH PATIENT\'S INFORMATION" << endl;
        cout << "\t\t\t\t\t 5. DELETE PATIENT\'S HISTORY/DATABASE" << endl;
        cout << "\t\t\t\t\t 6. EXIT" << endl;

        cout << "\t\t\t\t\t......................................................." << endl;
        cout << "\t\t\t\t\t>> ENTER THE NUMBER OF THE OPTION WHICH YOU CHOESE : <<" << endl;
        cout << "\t\t\t\t\t......................................................." << endl;
        // Taking the action input
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 1:
        	// use a loop for taking several patient's input 
            do
            {
                insert(); //call insert funtion
                cout << "\n\n\t\t\t Add Another Patient Record Press  (Y, N) : ";
                cin >> x; // Taking the action input
            } while (x == 'y' || x == 'Y');
            waitForEnter();
            break;
        case 2:
            display(); //call display funtion
            break;
        case 3:
            modify(); //call modify funtion
            break;
        case 4:
            search(); //call search funtion
            break;
        case 5:
            deleted(); //call deleted funtion
            break;
        case 6:
            system("cls");
            cout<<"\n\t\t\tTHANK YOU FOR GIVINIG US AN OPPORTUNITY TO SERVE YOU\n\t\t\t\t\tPLEASE VISIT US AGAIN \n";
            cout << "\n\n\t\t\t>> HOSPITAL MANAGEMENT SYSTEM - By  SAAARC CLINIC <<\n\n";
            Sleep(10);
            exit(0); // exit from this system
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
        getch();
    }
}

void saaar_management::insert() // This function inserts patient's data
{
    system("cls");
    id=0;
    fstream file;
    file.open("saaar_Record.txt"); // Opens "saar_Record" File
    while(file) //Execute a loop until EOF(End of File)
    //Read patient's details from file
	file >> name >> id >> blood >> age >> aadhar  >> contact >> disease >> dr >> address;
    file.close(); //closes the file
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl; //displays "----------"
    cout << "------------------------------------------------------------- Patient Insert Data -----------------------------------------------------------------" << endl; //displays"------ Patient Insert Data------"
    cout << "\n Enter Name of Patient : "; //displays patient's name
	cin >> name; // Takes the name of patient from the user
	
    cout << "\n Enter Patient\'s Blood group : "; //displays patient's blood group
    cin >> blood ; // Takes the blood group of patient from the user
    
    cout << "\n Enter Patient\'s Age : "; //displays patient's age
    cin >> age; // Takes the age of patient from the user
    
    cout << "\n Enter Patient\'s Aadhar No. : "; //displays patient's aadhaar number
    cin >> aadhar; // Takes the patient aadhaar number from the user
	
	cout << "\n Enter Patient\'s Contact Number : "; //displays patient's contact number
	cin >> contact; // Takes the contact number from the user
    
	cout << "\n Enter Patient\'s Disease : "; //displays patient's disease
	cin >> disease; // Takes the disease name from the user
	
	cout << "\n Enter Doctor\'s Name: "; //displays the name of the doctor
	cin >> dr; // Takes the doctor name from the user
	
	cout << "\n Enter Patient\'s address: "; //displays patient's address
	cin >> address; // Takes the patient's address from the user
    
	id++; //increments patient's id by 1
	// First it opens the file in append mode and then in write mode
    file.open("saaar_Record.txt", ios::app | ios::out); 
    // Write patient's details in file
	file << endl << name << endl << id << endl << blood  << endl << age << endl << aadhar << endl <<contact << endl << disease << endl << dr << endl << address << endl; //stores each and every details of the patient in the file
    file.close(); //closes the file
}

// DISPLAY DATA
void saaar_management::display()
{
    //THE BELOW COMMAND WILL OPEN A BLANK SCREEN
    system("cls");
    //A VARIABLE NAMED 'total' OF VALUE '1' AND TYPE 'INTEGER' HAS BEEN TAKEN HERE
    int total = 1;
    //A VARIABLE 'fstream' DENOTES THE FILE WHICH HELPS IN INSERTING THE DATA IN THE FILE
    fstream file;
    //A DISPLAY OF '---------------' IS GIVEN
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    //A DISPLAY OF '-------- Patient Record Data ---------' IS GIVEN
    cout << "------------------------------------------------------------- Patient Record Data -----------------------------------------------------------------" << endl;
    //TO OPEN 'saaar_Record' FILE
    file.open("saaar_Record.txt", ios::in);
    //CHECKS THE 'if' CONDITION 
    if (!file)
    {
        //A DISPLAY OF 'No Data is Present' IS SHOWN AFTER THE IF CONDITION IS NOT SATISFIED
        cout << "\n\t\t\tNo Data is Present... ";
        //TO CLOSE THE FILE
        file.close();
    }
    //CHECKS THE 'else' CONDITION
    else
    {
        //TO DISPLAY THE FOLLOWING DETAILS OF THE PATIENT FROM THE FILE-"NAME, ID, BLOOD, AGE, AADHAR, CONTACT, DISEASE, DR. & ADDRESS"
        file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
        //A DISPLAY OF '---------------' IS GIVEN
        cout << "\n -----------------------------------------------------------------------------------------------------------------------------------------------";
        //A DISPLAY OF '|| ID || NAME || BLOOD GROUP || AGE || AADHAR NUMBER || CONTACT NUMBER || DISEASE || DOCTOR NAME || ADDRESS ||' IS GIVEN
        cout << "\n || ID || NAME || BLOOD GROUP || AGE || AADHAR NUMBER || CONTACT NUMBER || DISEASE || DOCTOR NAME || ADDRESS ||";
        //A DISPLAY OF '---------------' IS GIVEN
        cout << "\n -----------------------------------------------------------------------------------------------------------------------------------------------";
        //CHECK THE 'while' LOOP
        while (!file.eof())
        {
            //TO GIVE A GAP OF ONE LINE
            cout << "\n";
            //TO PRINT THE PATIENT'S-'ID, NAME, BLOOD GROUP, AGE, AADHAR NUMBER, CONTACT NUMBER, DISEASE, DOCTOR NAME & ADDRESS'
            cout <<" SAAARC-"<< id << "\t " << name << "\t\t " << blood << "\t\t " << age << "\t "<< aadhar <<"\t\t " << contact << "\t " << disease << "\t Dr. " << dr << "\t " << address;
            //TO DISPLAY THE FOLLOWING DETAILS OF THE PATIENT FROM THE FILE-"NAME, ID, BLOOD, AGE, AADHAR, CONTACT, DISEASE, DR. & ADDRESS"
            file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
        }
    }
    //TO CLOSE THE FILE
    file.close();
    //WAIT FOR A USER INPUT TO CLOSE
    waitForEnter();
}
void temp(){
	cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------- Patient Modify Data -----------------------------------------------------------------" << endl;
}

void saaar_management::modify() // Modify data
{
    system("cls");
    int checkId;
	int x, y, z;   
	int found = 0; // Initialize found 0
    // Creation of two fstream class object
	fstream file, file1;
    temp(); // Call temp function
    // Open the file in read mode
	file.open("saaar_Record.txt", ios::in);
    // Execute if the file is Empty
	if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close(); // File closedg
    }
    else
    {
        cout << "\nEnter patient\'s id: SAAARC-";
        //Take input id of which patient's data we want to search
		cin >> checkId; 
        // Open file in write mode
		file1.open("record.txt", ios::out);
		//Read patient's details from file
        file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
        
        //Execute a loop until EOF(End of File)
		while (!file.eof())
        {
        	//Execute if the user given id & patient's id is equal
            if (checkId == id)
            {
            	loop : 
				cout << "\n\tWhich data you want to modify : "<<endl;
            	cout << "\t 1. NAME" << endl;
        		cout << "\t 2. BLOOD GROUP" << endl;
        		cout << "\t 3. AGE" << endl;
        		cout << "\t 4. AADHAR NUMBER" << endl;
        		cout << "\t 5. CONTACT NUMBER" << endl;
        		cout << "\t 6. DISEASE" << endl;
        		cout << "\t 7. DOCTOR NAME" << endl;
        		cout << "\t 8. ADDRESS" << endl;
				loop2 :
				cout << "Enter your choice : ";
        		// Taking the action input
        		cin >> x;
                // Calling relevant function as per choice
				
				if(x==1){
					cout << "\n Enter Name of Patient: "; //displays patient's name
                	cin >> name; // Takes the name of patient from the user
				}
				else if (x==2){
                	cout << "\n Enter Patient\'s Blood Group: "; //displays patient's blood group
                	cin >> blood; // Takes the blood group of patient from the user
				}
                else if(x==3){
					cout << "\n Enter Patient\'s Age: "; //displays patient's age
                	cin >> age; // Takes the age of patient from the user
				}
				else if(x==4){
					cout << "\n Enter Patient\'s Aadhar number : "; //displays patient's aadhaar number
                	cin >> aadhar; //displays patient's contact number
				}
                else if(x==5){
					cout << "\n Enter Patient\'s Contact number: "; // Takes the patient aadhaar number from the user
                	cin >> contact; // Takes the contact number from the user
                }
                else if(x==6){
					cout << "\n Enter Patient\'s Disease : "; //displays patient's disease
					cin >> disease; // Takes the disease name from the user
                }
                else if(x==7){
					cout << "\n Enter Doctor\'s Name: "; //displays the name of the doctor
					cin >> dr; // Takes the doctor name from the user
                }
                else if(x==8){
					cout << "\n Enter Patient\'s Address: "; //displays patient's address
                	cin >> address; // Takes the patient's address from the user
				}
				//Execute if above conditions doesn't satisfied
				else{
					cout << "\nInvalid Input.. Please Try Again.."; //display the line 
					goto loop2; //start from the loop2
				}
				
				//display below lines
                cout << "\n\nSuccessfully Modify Details Of Patient";
                cout << "\n\n\t\t\t If you want to modify another data :-"<<endl;
                cout << "\t\t\t\t 1. Press (1) for Yes"<<endl;
                cout << "\t\t\t\t 2. press (0) for No "<< endl;
                loop1 :
				cout << " Enter your choice : ";
                // Taking the action input
				cin >> z;
                // Calling relevant function as per choice
				if(z==1){
                	system("cls");
                	temp(); //call temp funtion
                	goto loop; //start from the loop
				}
				else if(z==0){
					// Write patient's details in file
					file1 <<endl<< name << endl << id << endl << blood  << endl << age << endl << aadhar << endl <<contact << endl << disease << endl << dr << endl << address << endl;
                	found++; //Increment found one step 
				}
				else{
					cout << "\nInvalid Input.. Please Try Again.."; //display the line
					goto loop1; //start from the loop1
				}
            }
            else
            {
                // Write patient's details in file
				file1 <<endl<< name << endl << id << endl << blood  << endl << age << endl << aadhar << endl << contact << endl << disease << endl << dr << endl << address << endl;

            }
            //Read patient's details from file
        	file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
        }
        //Execute if found not increment
        if (found == 0)
        {
            cout << "\n\n\tPatient\'s ID Not Found.. Please Try Again"; ///display the line
        }
        
        file1.close(); //Close file
        file.close(); //Close file
        //Remove previous file 
        remove("saaar_Record.txt");
        //Rename new file to previous file 
        rename("record.txt", "saaar_Record.txt");
    }
    waitForEnter();
}

void saaar_management::search() // Search data
{                                  //Displays all details according to Patient's id
    system("cls");
    fstream file;
    int checkId,x,found=0;
    string checkname;
	cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------- Patient Search Data -----------------------------------------------------------------" << endl;
    file.open("saaar_Record.txt", ios::in); // Opens "saar_Record" File
    loop : //terminating the loop
    // display the line which written is in the quotation
	cout << "\n\t\t\t-| Press [1] for search by id |-"<<endl; 
    cout << "\t\t\t-| Press [2] for search by name |-"<<endl; 
    cout << "Enter your option : "<< endl; 
    cin >> x; // taking input of the x variable
	if(x==1){ // checking the condition of the loop 
	// display the line which written is in the quotation to get the patient's id
		cout << "\n\nEnter Patient\'s ID: SAAARC-"; 
    	cin >> checkId; // checking the ID
	}
	// checking the condition of the loop 
    else if(x==2){ 
    	// display the line which written is in the quotation to get the Patient\'s name
		cout << "\n\nEnter Patient\'s name : "; 
    	cin >> checkname; // checking the name
	}
	//not satisfying any condion then display the invalid output
	else{
		cout << "\nInvalid Input.. Please Try Again.."; 
		goto loop;
	}
    if (!file) //checking the condition
    {
    	// display the line which written is in the quotation
        cout << "\n\t\t\tNo Data is Present... "; 
        file.close(); //close the file
    }
    else
    {
    	//Read patient's details from file
        file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;

        while (!file.eof()) // loop for end of the file
        {
        	//checking the id and name to search the patient's information
            if (checkId == id || checkname == name) 
            {
              //display below lines
			    cout << "\n---------------------\n";
                cout << "Patient\'s Name : " << name << endl;
                cout << "Patient\'s ID. : SAAARC-" << id << endl;
                cout << "Patient\'s Blood Group : " << blood <<endl;
                cout << "Patient\'s Age : " << age << endl;
                cout << "Patient\'s Aadhar number : " << aadhar << endl;
				cout << "Patient\'s Contact number : " << contact << endl;
                cout << "Patient\'s Disease : " << disease << endl;
        		cout << "Doctor Name : " << dr << endl;
                cout << "Patient\'s Address: " <<  address << endl;
                cout << "---------------------\n" <<endl;
                found++; //incrementing found by 1
            }
            //Read patient's details from file
            file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
        }
        if (!found) //checking condition 
        {
        	// if any lop not satisfying the condition then it displays the ID not found
            cout << "\n\n\tPatient\'s ID Not Found.. Please Try Again"; 
        }
    }
    file.close(); // close the file
    waitForEnter(); // wating for enter to proceed further program
}

void saaar_management::deleted() // Delete data
{
    system("cls"); // close the system
    int checkId; //check patient data
    fstream file, file1;
    int found = 0;
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;//delete ‘’-------'’
    cout << "------------------------------------------------------------- Patient Delete Data -----------------------------------------------------------------" << endl;// delete ‘’----- patient  data----‘’
    file.open("saaar_Record.txt", ios::in);// On read mode “saaar_record” file
    if (!file)//check if file present
    {
        cout << "\n\t\t\tNo Data is Present..";// displays no data present
        file.close();// closes the file
    }
    else
    {
        cout << "\nEnter Patient\'s Id : SAARC-"; //delete patient Id
        cin >> checkId;//check the Id of patient from the user
        file1.open("record.txt", ios::out);//Open the file in write mode
        file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;//
        while (!file.eof())//check the condition of while loop
        {
            if (checkId != id)// check patient id
            {
				file1 <<endl<< name << endl << id << endl << blood  << endl << age << endl << aadhar << endl << contact << endl << disease << endl << dr << endl << address << endl; //stores each and every details of the patient in the file
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data"; //Delete data
            }
            file >> name >> id >> blood >> age >> aadhar >> contact >> disease >> dr >> address;
        }
        if (found == 0)
        {
            cout << "\n\n\tPatient\'s ID Not Found.. Please Try Again"; //delete patient’s data
        }
       
    } file1.close();
        file.close();//close the file
        remove("saaar_Record.txt");//remove the file
        rename("record.txt", "saaar_Record.txt");//rename the file
        waitForEnter(); 
}

void saaar_management::waitForEnter()
{
    cout << "\n\nPress enter to go back: ";
    cin.get();
}


int main()
{
    // Call the function
    saaar_management system;
    system.menu();
    return 0;
}
