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
        Robot_model (string _name, int _model_number, Torso _torso, Head _head, Locomotor _locomotor, Arm _arm, Battery _battery) :
        name(_name), model_number(_model_number), torso(_torso), head(_head), locomotor(_locomotor), arm(_arm), battery(_battery) {}
        double cost();
        double max_speed();
        double max_battery_life();
        void print();
    
    private:
        string name;
        int model_number;
        Torso torso;
        Head head;
        Locomotor locomotor;
        Arm arm;
        Battery battery;
        
};

#endif /* ROBOT_MODEL_H */

