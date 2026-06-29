#ifndef DIGITALHEALTHADVISOR_H
#define DIGITALHEALTHADVISOR_H

//user account management class
class UserAccount{
	public :
		void registeration();
		bool login();
        void forget();
};

//base class for health services
class HealthService{
	public :
		void symptom_checker();
		
        void bmi_calculator();
        void bmi_HealthTips(string category);
        
        void Health_Tips();
        void diet_Tips();
        void Exercise_Tips();
        void Mental_Health_Tips();
};

//Main Health Advisor Class
class HealthAdvisor : public HealthService {  //inheritance
	private :
		UserAccount user;   //using UserAccount Class inside 
		bool isLoggedIn ;
	public :
		HealthAdvisor();
		void showMenu();
};
//helper function
void spaceline(int , char );
#endif

