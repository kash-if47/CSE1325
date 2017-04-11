#include <stdlib.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "Order.h"

double Order::robot_cost()
{
    return robot_model->cost();
}

double Order::extended_price()
{
    return (robot_model->cost() * 1.5);
}

string Order::print()
{
    string result = "";
    result += "\nOrder number: " + ::to_string(order_number) + "\nOrder Date: " + date + "\n\n*******Customer Info********" + customer->to_string() + "\n******Sales Associate Info******" + sales_associate->to_string() + "\nStatus: ";
    if(Status == 0)
    {
        result += "Pending";
    }
    else
    {
        result += "Fulfilled";
    }
    
    return result;
}
