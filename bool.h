/*******************************
Header boolean
Implemented by Mohammad Hamka Izzuddin Bin Mohamad Yahya (73571)
*******************************/

#include<stdbool.h>
#include<string.h>
#include<iostream>
#include<cstring>
#include<regex>

using namespace std;

bool checkExistUsername(const string& username)
{
	ifstream patReg("PatientRegistration.txt");
	
	int i = 0, j = 0;
    string data[50][7];
    while(getline(patReg, data[i][j]))
    {
        j++;
        if(j>7){i++; j = 0;}
    }
        
    patReg.close();

    for(int x=0; x<=i; x++)
    {
        if(data[x][0]==username)
        {
        	return false;
        }
        else
        {
            if(x==i)
            {
            	return true;
            }
        }
    }
}

bool checkEmail(const string& email)
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	
	return regex_match(email, pattern);
}

bool checkMobile(string input, int size)
{
	int i;
	bool valid = true;
	
	for(i=0; i<=size; i++)
	{
		if(input[i] == '\0')
		{
			break;	
		}
		
		valid = valid && isdigit(input[i]);
	}
	
	const regex pattern("(01[^1])[0-9]{7}");
	const regex pattern2("(011)[0-9]{8}");
	
	if(regex_match(input, pattern)||regex_match(input, pattern2))
	{
		return true;
	}
	
	else
	{
		return false;
	}
	
	return valid;
}
