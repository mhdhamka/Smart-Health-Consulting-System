#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>

using namespace std;


class Payment
{

private:

    string paymentAppointmentID;
    string paymentDate;
    string paymentTime;
    string paymentIllness;
    string paymentDoctor;
    string paymentSpecialization;

    double paymentTotalPrice;


public:

    Payment();


    void setPaymentAppointmentID(string);
    void setPaymentDate(string);
    void setPaymentTime(string);
    void setPaymentIllness(string);
    void setPaymentDoctor(string);
    void setPaymentSpecialization(string);
    void setPaymentTotalPrice(double);

    string getPaymentAppointmentID();
    string getPaymentDate();
    string getPaymentTime();
    string getPaymentIllness();
    string getPaymentDoctor();
    string getPaymentSpecialization();

    double getPaymentTotalPrice();

    void makePayment();
    void viewPayment();

};


#endif
