#ifndef SHOP_H
#define SHOP_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Robot_model.h"
#include "robot_part.h"
#include "Customer.h"
#include "Sales_associate.h"
#include "Order.h"
using namespace std;

class Shop 
{
    public:
        void create_new_robot_part(robot_part * a);
        void create_new_robot_part(int cmd);
        void create_new_robot_model(string name, int model_number, int t, int h, int l, vector<int> a, vector<int> b);
        void create_new_customer(string name, string phone_number, string email);
        void create_new_sales_associate(string name, int id);
        void create_new_order(string date, int cust, int sa, int model, int status);
        void save (string _filename);
        void open (string _filename);
        void view_parts();
        void view_parts(int index);
        bool bat_valid(int n, int current);
        bool arm_valid(int n, int current);
        bool is_valid(int n, int a);
        void view_models();
        void view_customers();
        void view_sales_associates();
        void view_model_summary();
        void view_specific_model(int index);
        void view_orders();
        int get_part_size();
        
    private:
        vector<robot_part *> store_parts;
        vector<Robot_model *> store_model;
        vector<Customer *> customers;
        vector<Sales_associate *> sales_associates;
        vector<Order *> orders;
        string filename;
};

#endif /* SHOP_H */

