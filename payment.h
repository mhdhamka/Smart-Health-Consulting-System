/****************************
Class Payment
Implemented by Nurulain Basirah Binti Hamid (73779)
****************************/

/*Class payment header file*/
#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>
using namespace std;

class Payment
{
	private:
		/*Private attributes only in class Payment*/
		string paymentAppointmentID;
		string paymentDate;
		string paymentTime;
		string paymentIllness;
		string paymentDoctor;
		string paymentSpecialization;
		double paymentTotalPrice;
		
	public:
		//Public methods
		
		//Constructor
		Payment();
		
		/*Setter*/
		void setPaymentAppointmentID(string aid);
		void setPaymentDate(string pd);
		void setPaymentTime(string pt);
		void setPaymentIllness (string pi);
		void setPaymentDoctor (string pdoc);
		void setPaymentSpecialization(string ps);  
		void setPaymentTotalPrice(double ptp);
		
		/*Getter*/
		string getPaymentAppointmentID();
		string getPaymentDate();
		string getPaymentTime();
		string getPaymentIllness();
		string getPaymentDoctor();
		string getPaymentSpecialization();
		double getPaymentTotalPrice();
		
		// Public function
		void makePayment();
		void viewPayment();
};

#endif
