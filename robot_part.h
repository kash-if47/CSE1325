#ifndef ROBOT_PART_H
#define ROBOT_PART_H

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class robot_part 
{
    public:
        robot_part (string _name, int _model_number, double _cost, string _description, string _image_filename) :
        name(_name), model_number(_model_number), cost(_cost), description(_description), image_filename(_image_filename) {}
    
    protected: 
        string name;
        int model_number;
        double cost;
        string description;
        string image_filename;

};

class Head : public robot_part
{
    friend class Robot_model;
    public:
        Head (string _name, int _model_number, double _cost, string _description, string _image_filename, double _power) :
        robot_part(_name, _model_number, _cost, _description, _image_filename), power(_power) {}
        string to_string()
        {
            string result;
            result =  "\nPart Type: Head\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nPower: " + ::to_string(power) + "\n";
            return result;
        }
    private:
        double power;
};

class Locomotor : public robot_part
{
    friend class Robot_model;
    public:
        Locomotor (string _name, int _model_number, double _cost, string _description, string _image_filename, double _max_power) :
        robot_part(_name, _model_number, _cost, _description, _image_filename), max_power(_max_power) {}
        string to_string()
        {
            string result;
            result =  "\nPart Type: Locomotor\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nMax Power: " + ::to_string(max_power) + "\n";
            return result;
        }
    private:
        double max_power;
};

class Torso : public robot_part
{
    friend class Robot_model;
    public:
        Torso (string _name, int _model_number, double _cost, string _description, string _image_filename, int _battery_compartments, int _max_arms) :
        robot_part(_name, _model_number, _cost, _description, _image_filename), battery_compartments(_battery_compartments), max_arms(_max_arms) {}
        string to_string()
        {
            string result;
            result =  "\nPart Type: Head\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nBattery compartments: " + ::to_string(battery_compartments) + "Max arms: " + ::to_string(max_arms) + "\n";
            return result;
        }
    private:
        int battery_compartments;
        int max_arms;
};

class Battery : public robot_part
{
    friend class Robot_model;
    public:
        Battery (string _name, int _model_number, double _cost, string _description, string _image_filename, double _power_available, double _max_energy) :
        robot_part(_name, _model_number, _cost, _description, _image_filename), power_available(_power_available), max_energy(_max_energy) {}
    private:
        double power_available;
        double max_energy;
};

class Arm : public robot_part
{
    friend class Robot_model;
    public:
        Arm (string _name, int _model_number, double _cost, string _description, string _image_filename, double _max_power) :
        robot_part(_name, _model_number, _cost, _description, _image_filename), max_power(_max_power) {}
    private:
        double max_power;
};


#endif /* ROBOT_PART_H */

