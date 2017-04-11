#include "Robot_model.h"
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

double Robot_model::cost()
{
    double Cost = torso->get_cost() + head->get_cost() + locomotor->get_cost();
    for(int i = 0; i < arm.size(); i ++)
    {
        Cost += arm[i]->get_cost();
    }
    for(int i = 0; i < battery.size(); i ++)
    {
        Cost += battery[i]->get_cost();
    }
    return Cost;
}
double Robot_model::max_speed()
{
    return 0;
}
double Robot_model::max_battery_life()
{
    return 0;
}
string Robot_model::print_summary()
{
    string result = "";
    result = "\nModel: " + name + "\nModel #: " + ::to_string(model_number) + "\nCost: $" + ::to_string(cost());
    return result;
}
string Robot_model::print()
{
    string result;
    result =  "\nModel: " + name + "\nModel #: " + ::to_string(model_number) + "\n" + head->to_string() + locomotor->to_string() + torso->to_string();
    for(int i = 0; i < arm.size(); i ++)
    {
        result += arm[i]->to_string();
    }
    for(int i = 0; i < battery.size(); i ++)
    {
        result += battery[i]->to_string();
    }
    return result;
}