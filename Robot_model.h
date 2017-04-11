#ifndef ROBOT_MODEL_H
#define ROBOT_MODEL_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "robot_part.h"
#include <vector>
using namespace std;

class Robot_model 
{
    public:
        Robot_model (string _name, int _model_number, robot_part * _torso, robot_part * _head, robot_part * _locomotor, vector<robot_part*> _arm, vector<robot_part*> _battery) :
        name(_name), model_number(_model_number), torso(_torso), head(_head), locomotor(_locomotor), arm(_arm), battery(_battery) {}
        double cost();
        double max_speed();
        double max_battery_life();
        string print();
        string print_summary();
        string get_constructor() 
        {
            string result;
            result += ::to_string(model_idx) + "\n" + name + "\n" + ::to_string(model_number) + "\n" + ::to_string(3) + "\n" + ::to_string(torso->model_idx) + "\n" + ::to_string(1) + "\n" + ::to_string(head->model_idx) + "\n" + ::to_string(2) + "\n" + ::to_string(locomotor->model_idx) + "\n";
            for(int i = 0; i < arm.size(); i ++)
            {
                result += ::to_string(4) + "\n" + ::to_string(arm[i]->model_idx) + "\n";
            }
            for(int i = 0; i < battery.size(); i ++)
            {
                result += ::to_string(5) + "\n" + ::to_string(battery[i]->model_idx) + "\n";
            }
            result +=  "=\n";
            return result;
        }
        int model_idx = -1;
    private:
        string name;
        int model_number;
        robot_part *torso;
        robot_part *head;
        robot_part *locomotor;
        vector<robot_part*> arm;
        vector<robot_part*> battery;
        
};

#endif /* ROBOT_MODEL_H */

