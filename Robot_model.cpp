#include "Robot_model.h"
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

double Robot_model::cost()
{
    return(torso.cost + head.cost + locomotor.cost + arm.cost + battery.cost);
}
double Robot_model::max_speed()
{
    return 0;
}
double Robot_model::max_battery_life()
{
    return 0;
}

void Robot_model::print()
{
    printf("Model Name: %s\nModel Number: %d\nTorso: %s\nHead: %s\nLocomotor: %s\nArm: %s\nBattery: %s\n", name.c_str(), model_number, (torso.name).c_str(), (head.name).c_str(), (locomotor.name).c_str(), (arm.name).c_str(), (battery.name).c_str());
}