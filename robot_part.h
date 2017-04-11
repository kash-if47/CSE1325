#ifndef ROBOT_PART_H
#define ROBOT_PART_H

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class robot_part 
{
    public:
        robot_part (int _model_idx, string _name, int _model_number, double _cost, string _description, string _image_filename) :
        name(_name), model_number(_model_number), cost(_cost), description(_description), image_filename(_image_filename) {}
        virtual string to_string()
        {
            string result;
            result =  "\nPart Type: N/A\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description + "\n";
            return result;
        }
        virtual int get_idx()
        {
            return 0;
        }
        virtual int get_max_bat()
        {
            return 0;
        }
        virtual int get_max_arms()
        {
            return 0;
        }
        double get_cost()
        {
            return cost;
        }
        virtual string get_constructor() = 0;
        int model_idx;

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
        Head (int _model_idx, string _name, int _model_number, double _cost, string _description, string _image_filename, double _power) :
        robot_part(_model_idx, _name, _model_number, _cost, _description, _image_filename), power(_power) {}
        string to_string() override
        {
            string result;
            result =  "\nPart Type: Head\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nPower: " + ::to_string(power) + "\n";
            return result;
        }
        int get_idx() override
        {
            return idx;
        }
        string get_constructor() override
        {
            string result;
            result += ::to_string(idx) + "\n" + ::to_string(model_idx) + "\n" + name + "\n" + ::to_string(model_number) + "\n" + ::to_string(cost) + "\n" + description + "\n" + image_filename + "\n" + ::to_string(power) + "\n" + "=\n";
            return result;
        }
    private:
        const int idx = 1;
        double power;
};

class Locomotor : public robot_part
{
    friend class Robot_model;
    public:
        Locomotor (int _model_idx, string _name, int _model_number, double _cost, string _description, string _image_filename, double _max_power) :
        robot_part(_model_idx, _name, _model_number, _cost, _description, _image_filename), max_power(_max_power) {}
        string to_string() override
        {
            string result;
            result =  "\nPart Type: Locomotor\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nMax Power: " + ::to_string(max_power) + "\n";
            return result;
        }
        int get_idx() override
        {
            return idx;
        }
        string get_constructor() override
        {
            string result;
            result += ::to_string(idx)+ "\n" + ::to_string(model_idx) + "\n" + name + "\n" + ::to_string(model_number) + "\n" + ::to_string(cost) + "\n" + description + "\n" + image_filename + "\n" + ::to_string(max_power) + "\n" + "=\n";
            return result;
        }
    private:
        const int idx = 2;
        double max_power;
};

class Torso : public robot_part
{
    friend class Robot_model;
    public:
        Torso (int _model_idx, string _name, int _model_number, double _cost, string _description, string _image_filename, int _battery_compartments, int _max_arms) :
        robot_part(_model_idx, _name, _model_number, _cost, _description, _image_filename), battery_compartments(_battery_compartments), max_arms(_max_arms) {}
        string to_string() override
        {
            string result;
            result =  "\nPart Type: Torso\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nBattery compartments: " + ::to_string(battery_compartments) + "\nMax arms: " + ::to_string(max_arms) + "\n";
            return result;
        }
        int get_idx() override
        {
            return idx;
        }
        int get_max_bat() override
        {
            return battery_compartments;
        }
        int get_max_arms () override
        {
            return max_arms;
        }
        string get_constructor() override
        {
            string result;
            result += ::to_string(idx)+ "\n" + ::to_string(model_idx) + "\n" + name + "\n" + ::to_string(model_number) + "\n" + ::to_string(cost) + "\n" + description + "\n" + image_filename + "\n" + ::to_string(battery_compartments) + "\n" + ::to_string(max_arms) + "\n" + "=\n";
            return result;
        }
    private:
        const int idx = 3;
        int battery_compartments;
        int max_arms;
};

class Battery : public robot_part
{
    friend class Robot_model;
    public:
        Battery (int _model_idx, string _name, int _model_number, double _cost, string _description, string _image_filename, double _power_available, double _max_energy) :
        robot_part(_model_idx, _name, _model_number, _cost, _description, _image_filename), power_available(_power_available), max_energy(_max_energy) {}
        string to_string() override
        {
            string result;
            result =  "\nPart Type: Battery\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nPower Available: " + ::to_string(power_available) + "\nMax Energy: " + ::to_string(max_energy) + "\n";
            return result;
        }
        int get_idx() override
        {
            return idx;
        }   
        string get_constructor() override
        {
            string result;
            result += ::to_string(idx)+ "\n" + ::to_string(model_idx) + "\n" + name + "\n" + ::to_string(model_number) + "\n" + ::to_string(cost) + "\n" + description + "\n" + image_filename + "\n" + ::to_string(power_available) + "\n" + ::to_string(max_energy) + "\n" + "=\n";
            return result;
        }
    private:
        const int idx = 5;
        double power_available;
        double max_energy;
};

class Arm : public robot_part
{
    friend class Robot_model;
    public:
        Arm (int _model_idx, string _name, int _model_number, double _cost, string _description, string _image_filename, double _max_power) :
        robot_part(_model_idx, _name, _model_number, _cost, _description, _image_filename), max_power(_max_power) {}
        string to_string() override
        {
            string result;
            result =  "\nPart Type: Arm\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nMax Power: " + ::to_string(max_power) + "\n";
            return result;
        }
        int get_idx() override
        {
            return idx;
        } 
        string get_constructor() override
        {
            string result;
            result += ::to_string(idx)+ "\n" + ::to_string(model_idx) + "\n" + name + "\n" + ::to_string(model_number) + "\n" + ::to_string(cost) + "\n" + description + "\n" + image_filename + "\n" + ::to_string(max_power) + "\n" + "=\n";
            return result;
        }
    private:
        const int idx = 4;
        double max_power;
};


#endif /* ROBOT_PART_H */

