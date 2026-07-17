#include <fstream>
#include <string>

using namespace std;


bool validateLogin(string username,string password)
{

    ifstream file("PatientRegistration.txt");

    string u,p;

    while(getline(file,u))
    {

    getline(file,p);

    if(u==username && p==password)
    {
        return true;
    }

    }

    return false;

}