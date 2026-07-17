
/*Class User header file*/
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User
{
	protected:
		/*Protected attributes*/
		string username;
		string password;
		string email;

	public:
		//Public methods
		
		//Constructor
		User();
		
		/*Setter*/
		void setname(string name);
		void setpassword(string p);
		void setemail(string e);
		
		/*Getter*/
		string getname();
		string getpassword();
		string getemail();
		
		//Public function
		bool validateLogin(string name, string password);
};

#endif
