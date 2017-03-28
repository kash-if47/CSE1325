#ifndef SHOP_H
#define SHOP_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Robot_model.h"
#include "robot_part.h"

using namespace std;

class Shop 
{
    public:
        void create_new_robot_part(robot_part * a);
        void create_new_robot_model();
        void create_new_customer();
        void create_new_sales_associate();
        void create_new_order();
        void save (string _filename);
        void open (string _filename);
        void view_parts();
        
    private:
        vector<robot_part*> store_parts;
        vector<Robot_model> store_model;
        string filename;
};

#endif /* SHOP_H */

