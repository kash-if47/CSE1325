#ifndef ORDER_H
#define ORDER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "Robot_model.h"
#include "Customer.h"
#include "Sales_associate.h"

using namespace std;

class Order {
    public:
        
        Order (int _order_number, string _date, Customer * _customer, Sales_associate * _sales_associate, Robot_model * _robot_model, int _status):
        order_number(_order_number), date(_date), customer(_customer), sales_associate(_sales_associate), robot_model(_robot_model), Status(_status) {}
        double robot_cost();
        double extended_price();
        string print();
        string get_constructor()
        {
            string result;
            result += ::to_string(order_number) + "\n" + date  + "\n" + ::to_string(customer->customer_number) + "\n" + ::to_string(sales_associate->sa_idx) + "\n" + ::to_string(robot_model->model_idx) + "\n" + ::to_string(Status) + "\n" + "=\n";
            return result;
        }
    
    private:
        int order_number;
        string date;
        Customer * customer;
        Sales_associate * sales_associate;
        Robot_model * robot_model;
        int Status;

};

#endif /* ORDER_H */

