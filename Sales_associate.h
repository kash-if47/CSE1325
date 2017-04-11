#ifndef SALES_ASSOCIATE_H
#define SALES_ASSOCIATE_H
#include <cstdlib>
#include <iostream>
#include <string>


class Sales_associate 
{
    public:
        Sales_associate(string _name, int _employee_number):
        name(_name), employee_number(_employee_number) {}
        string to_string()
        {
            string result = "";
            result += "\nAssociate Employee ID: " + ::to_string(employee_number) + "\nAssociate Name: " + name + "\n";
            return result;
        }
        int sa_idx = -1;
        string get_constructor()
        {
            string result;
            result += ::to_string(sa_idx) + "\n" + name + "\n" + ::to_string(employee_number) + "\n=\n" ;
            return result;
        }
    private:
        string name;
        int employee_number;

};

#endif /* SALES_ASSOCIATE_H */

