#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;
#include "DigitalHealthAdvisor2.h"


                    //Constructor for health adviser class
HealthAdvisor::HealthAdvisor(){
	
	int choice;
	isLoggedIn = false;
	
	do {
		    system("cls");
	    spaceline(100, '=');
	cout<<"\t\t__ Welcome to your DIGITAL HEALTH ADVISOR Login__ \n";
    	spaceline(100, '=');
    cout<<"\nNote: Please REGISTER first to LOGIN. \n";
    cout<<"Only registered users can access HEALTH features!\n\n";
    
 	cout<<" \t\t Explore your Login page:\n";
	cout<<" \n1. Registration .";
	cout<<" \n2. Login .";
	cout<<" \n3. forget your PASSWORD .";
	cout<<" \n4. EXIT\n"; 
	cout<<"ENTER YOUR CHOICE ACCORDING TO THE MENUE :";
	
        if (!(cin >> choice)) { 
            cin.clear(); 
            cout << "\nInvalid input. Please enter a number!\n";
            continue;
        }
	    switch(choice)
	    {
		    case 1:
		    	    system("cls");  
			    user.registeration ();
			        system("pause");
		        break;
		    case 2:
		    	    system("cls");
    	        isLoggedIn = user.login ()  ;
	    	       if (isLoggedIn)
				   {
			            cout<<"\t\t Press any key to get MAIN MENU for DIGITAL HEALTH ADVISOR !\n "<<endl;
			                system("pause");
			            	system("cls");
	                    showMenu();
	               }
		        break;                                 
		    case 3:
		    	    system("cls"); 
			    user.forget ();
			        system("pause");
		    	break;
	    	case 4:
		        cout<<"\t\t THANK YOU ! \n";
		            system("pause");
		        break;

	        default:
	        	cout<<"\t\t Please select from the options give above \n"<<endl;
        }   
    }while (choice != 0);
    
}


                                  //UserAccount class implementation

// function for registration
void UserAccount::registeration (){
	
	string ruserId,rpassword,rid,rpass;
	char address[30], fatherName[30];
	int phoneNumber,age;
	
		spaceline(50, '=');
	cout<<"\t__Register your Account!__ \n";
		spaceline(50, '=');
		
	cout<<" Enter the username : ";
	cin>>ruserId;
	cout<<" Enter the password : ";
	cin>>rpassword;
	cout<<" Father name : " ;
	cin.ignore() ;
	cin.getline(fatherName,30) ;
	cout<<" Age : ";
	cin>>age;
	cout<<" Address : " ;
	cin.ignore() ;
	cin.getline(address,30) ;
	cout<<" Phone number : ";
	cin>>phoneNumber;

	ofstream f1("records.txt" , ios::app);
	f1<<ruserId<<' '<<rpassword<<' '<<fatherName<< ' '<<address<<' '<<phoneNumber<<' '<<age<<endl;

	cout<<"\n\t\t\t Registeration is successfull! \n" ;
	
}


// function for login
bool UserAccount::login(){
	
   	int count;
   	string userId,password,id,pass;
   	
   		spaceline(50, '=');
   	cout<<"\t ___login your account!__ \n";
   		spaceline(50, '=');
   	cout<<"\t\n Login your account to get the MAIN MENU !\n ";
   	cout<<"\n Please enter the usernsame and password  \n"<<endl;
   	
   	cout<<" USERNAME : ";
   	cin>>userId;
   	cout<<" PASSWORD : ";
   	cin>>password;
   	
   	ifstream input("records.txt");
   	
   	while(input>>id>>pass)
   	{
   	    if(id==userId && pass==password)
   	    {
   	    	count=1;
    	}
   }
   input.close();
   
   if(count==1){
   	    cout<<"\n\t"<<userId<<"!"<<"\n\n YOUR LOGIN is successfull  ! \n  THANKS for LOGING IN !\n \n";
   	        return true;
   	}
   else{
   	    cout<<"\n LOGIN ERRORS \n Please check your USERNAME & PASSWORD \n";
   	    system("pause");
   	        return false;
   }
   
}

// function for forget password
 void UserAccount::forget(){
 	
	int count=0;
	string suserId,sId,spass;
	
		spaceline(50, '=');
   	cout<<"\tYou forgot the password ? No worries \n\n ";
	    spaceline(50, '=');
	cout<<"\n Enter the username which you remembered :";
	cin>>suserId;
			
	ifstream f2("records.txt");
		while(f2>>sId>>spass)
		{
			if(sId==suserId)
			{
			    cout<<"\n\n Your account is found! \n";
			   	cout<<"\n\n Your password is : "<<spass<<endl;
			     	f2.close();
				       // system ("pause");
			      	
					    return;					
			
			}
		}
			f2.close();
			if (count==0)
			{
			    cout<<"\n\t Sorry! Your account is not found! \n";
			//	
		
			}
	
}  
	            
  
                           //main menue for DIGITAL HEALTH ADVISOR
void HealthAdvisor::showMenu() {
	
	int choice;
	
	do {
		      system ("cls");
		spaceline(100, '=');
	cout<<"\t\t __YOUR VIRTUAL PARTNER IN HEALTH & WELLNESS!__\n";
	    spaceline(100, '=');
 	cout<<" \t\t Let's explore your health toolkit:\n";
 	
	cout<<"\n1. Symptom Checker.";
	cout<<"\n2. BMI Calculator.";
	cout<<"\n3. Health Tips.";
	cout<<"\n0. to EXIT.\n";
	cout<<"Enter your choice according to the menue :";

        if (!(cin >> choice)) { 
            cin.clear(); 
            cout << "\nInvalid input. Please enter a number!\n";
            continue;
        }
	switch(choice)
	{
		case 1:
			   system("cls");
			symptom_checker();
			   system("pause");
			break;
	    case 2:
	    	    system("cls");
	    	 bmi_calculator();
	    	    system ("pause");
	    	break;
	    case 3:
	    	Health_Tips();
	    	 break;
	    case 4:
	    	 cout<<"\t\t THANK YOU ! \n";
		     break;
	    default:
	    	cout<<"\t\t Invalid Choice! \n"<<endl;
		}
			
	}while (choice != 0);

}


                      //Health Service base class implimentation
//Function for symptom checker
void HealthService::symptom_checker(){

    char response;
    //int system_close;
        spaceline(50, '=');
    cout << "\tWELCOME TO THE SYMPTOM CHECKER!\n";
         spaceline(50, '=');
    cout << "Answer the following questions to help determine your condition.\n\n";

    cout << "Do you have a fever? (y/n): ";
    cin >> response;
    bool fever = (response == 'y' || response == 'Y');

    cout << "Do you have a cough? (y/n): ";
    cin >> response;
    bool cough = (response == 'y' || response == 'Y');

    cout << "Do you have a headache? (y/n): ";
    cin >> response;
    bool headache = (response == 'y' || response == 'Y');

    cout << "Do you have a sore throat? (y/n): ";
    cin >> response;
    bool soreThroat = (response == 'y' || response == 'Y');

    cout << "Do you feel fatigued? (y/n): ";
    cin >> response;
    bool fatigue = (response == 'y' || response == 'Y');

    cout << "Do you have a runny nose? (y/n): ";
    cin >> response;
    bool runnyNose = (response == 'y' || response == 'Y');

    cout << "Do you have a body ache? (y/n): ";
    cin >> response;
    bool bodyAche = (response == 'y' || response == 'Y');

    cout << "\n\nBased on your symptoms, here's a possible condition:\n\n";
    if (fever && cough && bodyAche) {
        cout << "\nYou might have the flu. Stay hydrated and get plenty of rest.\n";
    } else if (fever && headache && fatigue) {
        cout << "\nYou might have a viral infection. Drink plenty of fluids and take rest.\n";
    } else if (cough && runnyNose && soreThroat) {
        cout << "\nYou might have a common cold. Use a humidifier and take over-the-counter medication.\n";
    } else if (fever && headache && soreThroat) {
        cout << "\nYou might have tonsillitis. See a doctor for proper diagnosis and treatment.\n";
    } else  {
        cout << "Congratulations! It seems like you're in great health with no symptoms of concern.\n";
        cout<<"Keep up the healthy habits and continue taking care of yourself.\n";
        cout<<"Stay happy and stay healthy!"<<endl;
        
    
    } 
   
}
//function for bmi calculator
void HealthService::bmi_calculator() {

	double weight,heightfeet, heightmeters,bmi;
	 
		spaceline(50, '=');
	cout<<"\t WELCOME TO THE BMI CALCULATOR! \n";
	    spaceline(50, '=');

	cout<<"Enter your weight in kg : ";
	cin>>weight;
	cout<<"Enter your height in feet : ";
	cin>>heightfeet;
	
	heightmeters=(heightfeet * 0.3048);
	bmi=weight/pow(heightmeters , 2);
	
	cout<<"Your Body Mass Index is : "<<bmi<<endl;
	
	if(bmi<18.5){
		cout<<"\n\tcategory  :   Under weight"<<endl;
		bmi_HealthTips( "Underweight");
	}
	else if(bmi>=18.5 && bmi<=24.9){
		cout<<"\n\tcatrgory  : normal weight"<<endl;
		bmi_HealthTips("Normal Weight");
	}
	else if(bmi>=25 && bmi<=29.9){
		cout<<"\n\tcategory  : overweight"<<endl;
		bmi_HealthTips( "Overweight");
	}
	else{
		cout<<"\n\tcategory  : obese"<<endl;
		bmi_HealthTips("Obese");
	}
	
}

//function inside the bmi calculator
void HealthService::bmi_HealthTips(string category) {
	
    string underweightTips[] = {
        "\nEat more calories than your body burns.\n",
        "Include healthy fats like nuts and avocados in your diet.\n",
        "Consider protein shakes to increase muscle mass.\n"
  };
    int sizeOfUnderweightTips = 3;
    
    string normalTips[] = {
        "Maintain a balanced diet with fruits and vegetables.\n",
        "Exercise regularly to stay fit.\n",
        "Stay hydrated and get enough sleep.\n"
    };
    int sizeOfNormalTips = 3;
    
    string overweightTips[] = {
        "\nReduce portion sizes to control calorie intake.\n",
        "Incorporate cardio exercises into your routine.\n",
        "Avoid sugary and processed foods.\n"
    };
    int sizeOfOverweightTips = 3;
    
     string obeseTips[] = {
        "Consult a dietitian for a personalized diet plan.\n",
        "Engage in regular physical activities.\n",
        "Monitor your calorie intake daily.\n"
    };
    int sizeOfObeseTips = 3;

 cout << "\nHealth Tips:\n";
    if (category == "Underweight") {
        for (int tip = 0; tip < sizeOfUnderweightTips; tip++) {
            cout << "- " << underweightTips[tip]<< endl;
        }
    } else if (category == "Normal Weight") {
        for (int tip = 0; tip < sizeOfNormalTips; tip++) {
            cout << "- " << normalTips[tip]<< endl;
        }
    } else if (category == "Overweight") {
        for (int tip = 0; tip < sizeOfOverweightTips; tip++) {
            cout << "- " << overweightTips[tip]<< endl;
        }
   } else if (category == "Obese") {
        for (int tip = 0; tip < sizeOfObeseTips; tip++) {
            cout << "- " << obeseTips[tip]<< endl;
        }
    }
    
}

//function for health tips main menue 
void HealthService::Health_Tips() {
	
    int choice;
   
     do {
     	        system("cls");
     	        
    	    spaceline(50, '=');
        cout << "\t\t__Health Tips Menu__\n" ;
             spaceline(50, '=');
             
        cout << "1. Diet Tips" << endl;
        cout << "2. Exercise Tips" << endl;
        cout << "3. Mental Health Tips" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) { 
            cin.clear(); 
            cout << "\nInvalid input. Please enter a number!\n";
            continue; 
        }
        switch (choice) {
            case 1:
            	    system("cls");
                diet_Tips();
                    system("pause");
                Health_Tips();
                break;
            case 2:
                	system("cls");
                Exercise_Tips();
                    system("pause");
                Health_Tips();
                break;
            case 3:
            	    system("cls");
                Mental_Health_Tips();
                    system("pause");
                Health_Tips();
                break;
            case 4:
                cout << "\nExiting program. Goodbye!" << endl;
                     system("pause");
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
                break;
            }
         }while (choice != 0);

}

//functions inside the Health tips
void HealthService::diet_Tips(){
	
		spaceline(50, '=');
    cout << "\t\t__Diet Tips__" << endl;
        spaceline(50, '=');
        
                cout << "\n - Eat more fruits and vegetables.\n" << endl;
                cout << " - Avoid sugary drinks.\n" << endl;
                cout << " - Drink plenty of water.\n" << endl;
                cout << " - Limit processed foods.\n" << endl;
                cout << " - Cook at home using fresh ingredients.\n" << endl;
                
}

void HealthService::Exercise_Tips(){
	
	    spaceline(50, '=');
	cout << "\t\t__Exercise Tips__" << endl;
	     spaceline(50, '=');
	     
                cout << "\n - Try to walk 30 minutes a day.\n" << endl;
                cout << " - Stretch regularly.\n" << endl;
                cout << " - Add strength training into your routine.\n" << endl;
                cout << " - Find an exercise you enjoy and stick to it.\n" << endl;
                cout << " - Aim for at least 150 minutes of moderate-intensity exercise per week.\n" << endl;
                 
}

void HealthService::Mental_Health_Tips(){
	
	    spaceline(50, '=');
	cout << "\t\t__Mental Health Tips__" << endl;
     	spaceline(50, '=');
     	
                cout << "\n - Practice mindfulness and meditation.\n" << endl;
                cout << " - Connect with friends and family.\n" << endl;
                cout << " - Get enough sleep.\n" << endl;
                cout << " - Engage in activities that bring you joy.\n" << endl;
                cout << " - Seek professional help when needed.\n" << endl;
                 
}
//function out of the class
void spaceline(int n=50, char ch='='){	
	for(int i=1;i<=n;i++){
	cout<<ch; 
	}cout<<endl;

}