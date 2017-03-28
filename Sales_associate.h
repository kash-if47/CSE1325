#ifndef SALES_ASSOCIATE_H
#define SALES_ASSOCIATE_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "Order.h"


class Sales_associate 
{
    public:
        Sales_associate(string _name, int _employee_number):
        name(_name), employee_number(_employee_number) {}
    private:
        string name;
        int employee_number;

};

#endif /* SALES_ASSOCIATE_H */

