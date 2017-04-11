#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <cstdlib>
#include <iostream>
#include <string>


class Customer 
{
    public:
        Customer(string _name, int _customer_number, string _phone_number, string _email_address) :
        name(_name), customer_number(_customer_number), phone_number(_phone_number), email_address(_email_address) {}
        string to_string()
        {
            string result = "";
            result += "\nCustomer ID: " + ::to_string(customer_number) + "\nCustomer Name: " + name + "\nPhone Number: " + phone_number + "\nEmail: " + email_address + "\n";
            return result;
        }
        string get_constructor()
        {
            string result;
            result += ::to_string(customer_number) + "\n" + name  + "\n" + phone_number + "\n" + email_address + "\n=\n";
            return result;
        }
        int customer_number;
    private:
        string name;
        string phone_number;
        string email_address;

};

#endif /* CUSTOMER_H */

