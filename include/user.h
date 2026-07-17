
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User
{
	protected:
		
		string username;
		string password;
		string email;

	public:
		User();
		
		void setname(string name);
		void setpassword(string p);
		void setemail(string e);
		
		string getname();
		string getpassword();
		string getemail();
		
		bool validateLogin(string name, string password);
};

#endif
