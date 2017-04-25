#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Window.H> 
#include <FL/Fl_Box.H> 
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Choice.H>

// /////////////////////////////////////
//              P A R T
// /////////////////////////////////////

using namespace std;
Fl_Window *win;
Fl_Menu_Bar *menubar;
void create_robot_partCB(Fl_Widget* w, void* p);
void cancel_robot_partCB(Fl_Widget* w, void* p);
void create_robot_partCB_loc(Fl_Widget* w, void* p);
void cancel_robot_partCB_loc(Fl_Widget* w, void* p);
void create_robot_partCB_tor(Fl_Widget* w, void* p);
void cancel_robot_partCB_tor(Fl_Widget* w, void* p);
void create_robot_partCB_bat(Fl_Widget* w, void* p);
void cancel_robot_partCB_bat(Fl_Widget* w, void* p);
void create_robot_partCB_arm(Fl_Widget* w, void* p);
void cancel_robot_partCB_arm(Fl_Widget* w, void* p);
void create_robot_model_cb(Fl_Widget* w, void* p);
void head_cb(Fl_Widget* w, void* p);
void loc_cb(Fl_Widget* w, void* p);
void tor_cb(Fl_Widget* w, void* p);
void arm_cb(Fl_Widget* w, void* p);
void bat_cb(Fl_Widget* w, void* p);

class robot_part 
{
    public:
        robot_part (int _model_idx, string _name, int _model_number, double _cost, string _description, double _weight) :
        name(_name), model_number(_model_number), cost(_cost), description(_description), weight(_weight) {}
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
        virtual string get_name() = 0;
        virtual double get_weight() = 0;
        virtual double get_power() = 0;
        virtual double get_speed()
        {
            return -1;
        }
        int model_idx;

    protected: 
        string name;
        int model_number;
        double cost;
        string description;
        double weight;

};

class Head : public robot_part
{
    friend class Robot_model;
    public:
        Head (int _model_idx, string _name, int _model_number, double _cost, string _description, double _weight, double _power) :
        robot_part(_model_idx, _name, _model_number, _cost, _description, _weight), power(_power) {}
        string to_string() override
        {
            string result;
            result =  "\nPart Type: Head\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nPower: " + ::to_string(power) + "\nWeight: " + ::to_string(weight) + "\n";
            return result;
        }
        double get_weight() override
        {
            return weight;
        }
        double get_power() override
        {
            return power;
        }
        string get_name() override
        {
            return name;
        }
        int get_idx() override
        {
            return idx;
        }
        string get_constructor() override
        {
            string result;
            result += ::to_string(idx) + "\n" + ::to_string(model_idx) + "\n" + name + "\n" + ::to_string(model_number) + "\n" + ::to_string(cost) + "\n" + description + "\n" + ::to_string(weight) + "\n" + ::to_string(power) + "\n" + "=\n";
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
        Locomotor (int _model_idx, string _name, int _model_number, double _cost, string _description, double _weight, double _max_power, double _max_speed) :
        robot_part(_model_idx, _name, _model_number, _cost, _description, _weight), max_power(_max_power), max_speed(_max_speed) {}
        string to_string() override
        {
            string result;
            result =  "\nPart Type: Locomotor\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nMax Power: " + ::to_string(max_power) + "\nWeight: " + ::to_string(weight) + "\nMax Speed: " + ::to_string(max_speed)+ "\n";
            return result;
        }
        double get_weight() override
        {
            return weight;
        }
        string get_name() override
        {
            return name;
        }
        int get_idx() override
        {
            return idx;
        }
        double get_power() override
        {
            return max_power;
        }
        double get_speed() override
        {
            return max_speed;
        }
        string get_constructor() override
        {
            string result;
            result += ::to_string(idx)+ "\n" + ::to_string(model_idx) + "\n" + name + "\n" + ::to_string(model_number) + "\n" + ::to_string(cost) + "\n" + description + "\n" + ::to_string(weight) + "\n" + ::to_string(max_power) + "\n" + ::to_string(max_speed) + "\n=\n";
            return result;
        }
    private:
        const int idx = 2;
        double max_power;
        double max_speed;
};

class Torso : public robot_part
{
    friend class Robot_model;
    public:
        Torso (int _model_idx, string _name, int _model_number, double _cost, string _description, double _weight, int _battery_compartments, int _max_arms) :
        robot_part(_model_idx, _name, _model_number, _cost, _description, _weight), battery_compartments(_battery_compartments), max_arms(_max_arms) {}
        string to_string() override
        {
            string result;
            result =  "\nPart Type: Torso\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nBattery compartments: " + ::to_string(battery_compartments) + "\nMax arms: " + ::to_string(max_arms) + "\nWeight: " + ::to_string(weight) + "\n";
            return result;
        }
        double get_weight() override
        {
            return weight;
        }
        string get_name() override
        {
            return name;
        }
        double get_power() override
        {
            return -1;
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
            result += ::to_string(idx)+ "\n" + ::to_string(model_idx) + "\n" + name + "\n" + ::to_string(model_number) + "\n" + ::to_string(cost) + "\n" + description + "\n" + ::to_string(weight) + "\n" + ::to_string(battery_compartments) + "\n" + ::to_string(max_arms) + "\n" + "=\n";
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
        Battery (int _model_idx, string _name, int _model_number, double _cost, string _description, double weight, double _power_available, double _max_energy) :
        robot_part(_model_idx, _name, _model_number, _cost, _description, weight), power_available(_power_available), max_energy(_max_energy) {}
        string to_string() override
        {
            string result;
            result =  "\nPart Type: Battery\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nPower Available: " + ::to_string(power_available) + "\nMax Energy: " + ::to_string(max_energy) + "\nWeight" + ::to_string(weight) + "\n";
            return result;
        }
        double get_weight() override
        {
            return weight;
        }
        string get_name() override
        {
            return name;
        }
        int get_idx() override
        {
            return idx;
        }
        double get_power() override
        {
            return power_available;
        }
        string get_constructor() override
        {
            string result;
            result += ::to_string(idx)+ "\n" + ::to_string(model_idx) + "\n" + name + "\n" + ::to_string(model_number) + "\n" + ::to_string(cost) + "\n" + description + "\n" + ::to_string(weight) + "\n" + ::to_string(power_available) + "\n" + ::to_string(max_energy) + "\n" + "=\n";
            return result;
        }
        double get_energy()
        {
            return max_energy;
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
        Arm (int _model_idx, string _name, int _model_number, double _cost, string _description, double weight, double _max_power) :
        robot_part(_model_idx, _name, _model_number, _cost, _description, weight), max_power(_max_power) {}
        string to_string() override
        {
            string result;
            result =  "\nPart Type: Arm\nPart name: " + name + "\nModel number: " + ::to_string(model_number) + "\nPart cost: $" + ::to_string(cost) + "\nPart Description: " + description +"\nMax Power: " + ::to_string(max_power) + "\nWeight" + ::to_string(weight) + "\n";
            return result;
        }
        double get_weight() override
        {
            return weight;
        }
        string get_name() override
        {
            return name;
        }
        int get_idx() override
        {
            return idx;
        } 
        double get_power() override
        {
            return max_power;
        }
        string get_constructor() override
        {
            string result;
            result += ::to_string(idx)+ "\n" + ::to_string(model_idx) + "\n" + name + "\n" + ::to_string(model_number) + "\n" + ::to_string(cost) + "\n" + description + "\n" + ::to_string(weight) + "\n" + ::to_string(max_power) + "\n" + "=\n";
            return result;
        }
    private:
        const int idx = 4;
        double max_power;
};

// /////////////////////////////////////
//            M O D E L
// /////////////////////////////////////

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
        bool power_limitted();
        double total_weight();
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

double Robot_model::max_battery_life()
{
    double bat_energy_sum = 0;
    for(int i = 0; i < battery.size(); i ++)
    {
        bat_energy_sum += battery[i]->get_power();
    }
    double power = 0;
    power += head->get_power();
    for(int i = 0; i < arm.size(); i ++)
    {
        power += (0.4 * (arm[i]->get_power()));
    }
    power += (0.15 * (locomotor->get_power()));
    return((bat_energy_sum * 1000)/power);
}
bool Robot_model::power_limitted()
{
    double sum = head->get_power() + locomotor->get_power();
    for(int i = 0; i < arm.size(); i ++)
    {
        sum += arm[i]->get_power();
    }
    double bat = 0;
    for(int i = 0; i < battery.size(); i ++)
    {
        bat += battery[i]->get_power();
    }
    if(bat < sum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

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
double Robot_model::total_weight()
{
    double weight = torso->get_weight() + head->get_weight() + locomotor->get_weight();
    for(int i = 0; i < arm.size(); i ++)
    {
        weight += arm[i]->get_weight();
    }
    for(int i = 0; i < battery.size(); i ++)
    {
        weight += battery[i]->get_weight();
    }
    return weight;
}
double Robot_model::max_speed()
{
    double weight = total_weight();
    double loc_weight = locomotor->get_weight();
    if(weight > (loc_weight * 5))
    {
        return (((loc_weight * 5)/weight) * locomotor->get_speed());
    }
    else
    {
        return locomotor->get_speed();
    }
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


// /////////////////////////////////////
//          C U S T O M E R
// /////////////////////////////////////

class Customer 
{
    public:
        Customer(string _name, int _customer_number, string _phone_number, string _email_address) :
        name(_name), customer_number(_customer_number), phone_number(_phone_number), email_address(_email_address) {}
        string to_string()
        {
            string result = "";
            result += "\nCustomer ID: " + ::to_string(customer_number) + "\nCustomer Name: " + name + "\nPhone Number: " + phone_number + "\nEmail: " + email_address + "\n";
            return result;
        }
        string get_constructor()
        {
            string result;
            result += ::to_string(customer_number) + "\n" + name  + "\n" + phone_number + "\n" + email_address + "\n=\n";
            return result;
        }
        int customer_number;
    private:
        string name;
        string phone_number;
        string email_address;

};

// /////////////////////////////////////
//          A S S O C I A T E
// /////////////////////////////////////


class Sales_associate 
{
    public:
        Sales_associate(string _name, int _employee_number):
        name(_name), employee_number(_employee_number) {}
        string to_string()
        {
            string result = "";
            result += "\nAssociate Employee ID: " + ::to_string(employee_number) + "\nAssociate Name: " + name + "\n";
            return result;
        }
        int sa_idx = -1;
        string get_constructor()
        {
            string result;
            result += ::to_string(sa_idx) + "\n" + name + "\n" + ::to_string(employee_number) + "\n=\n" ;
            return result;
        }
    private:
        string name;
        int employee_number;

};

// /////////////////////////////////////
//             O R D E R
// /////////////////////////////////////

class Order {
    public:
        
//        Order (int _order_number, string _date, Customer * _customer, Sales_associate * _sales_associate, Robot_model * _robot_model, int _Status) :
//        order_number(_order_number), date(_date), customer(_customer), sales_associate(_sales_associate), robot_model(_robot_model), Status(_Status) {}
        Order (int _order_number, string _date, Customer * _customer, Sales_associate * _sales_associate, Robot_model * _robot_model, int _Status);
        double robot_cost();
        double extended_price();
        string print();
        string get_constructor()
        {
            string result;
            result += ::to_string(order_number) + "\n" + date  + "\n" + ::to_string(customer->customer_number) + "\n" + ::to_string(sales_associate->sa_idx) + "\n" + ::to_string(robot_model->model_idx) + "\n" + ::to_string(Status_order) + "\n" + "=\n";
            return result;
        }
    
    private:
        int order_number;
        int Status_order;
        string date;
        Customer * customer;
        Sales_associate * sales_associate;
        Robot_model * robot_model;
        
};

Order::Order(int _order_number, string _date, Customer * _customer, Sales_associate * _sales_associate, Robot_model * _robot_model, int _Status)
{
    order_number = _order_number;
    date = _date;
    customer = _customer;
    sales_associate = _sales_associate;
    robot_model = _robot_model;
    Status_order = _Status;
}
double Order::robot_cost()
{
    double cost = robot_model->cost();
    cost = cost * 1.0825;
    double shipping = robot_model->total_weight();
    shipping = shipping/45;
    shipping = shipping * 100;
    cost = cost + shipping;
    return cost;
}

double Order::extended_price()
{
    return (robot_model->cost() * 3);
}


string Order::print()
{
    string result = "";
    result += "\nOrder number: " + ::to_string(order_number) + "\nOrder Date: " + date + "\n\n*******Customer Info********" + customer->to_string() + "\n******Sales Associate Info******" + sales_associate->to_string() + "\nStatus: ";
    if(Status_order == 0)
    {
        result += "Pending";
    }
    else
    {
        result += "Fulfilled";
    }
    
    return result;
}




// /////////////////////////////////////
//              S H O P
// /////////////////////////////////////



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
        string view_parts();
        double part_cost(int part_number);
        void view_parts(int index);
        vector<int> get_part_list(int);
        bool bat_valid(int n, int current);
        bool arm_valid(int n, int current);
        bool is_valid(int n, int a);
        void view_models();
        string view_customers();
        string view_sales_associates();
        void view_model_summary();
        void view_specific_model(int index);
        void view_orders();
        int get_part_size();
        string view_part_name(int index);
        
    private:
        vector<robot_part *> store_parts;
        vector<Robot_model *> store_model;
        vector<Customer *> customers;
        vector<Sales_associate *> sales_associates;
        vector<Order *> orders;
        string filename;
};

vector<int> Shop::get_part_list(int type)
{
    vector<int> result;
    for(int i = 0; i < store_parts.size(); i ++)
    {
        if(store_parts[i]->get_idx() == type)
        {
            result.push_back(i);
        }
    }
    return result;
}
string Shop::view_part_name(int index)
{
    return (store_parts[index]->get_name());
}
void Shop::save (string _filename)
{
    ofstream myfile;
    myfile.open ("save.txt");
    
    for(int i = 0; i < store_parts.size(); i ++)
    {
        store_parts[i]->model_idx = i;
        myfile << store_parts[i]->get_constructor();
    }
    myfile << "===\n";
    for(int i = 0; i < store_model.size(); i ++)
    {
        store_model[i]->model_idx = i;
        myfile << store_model[i]->get_constructor();
    }
    myfile << "===\n";
    for(int i = 0; i < sales_associates.size(); i ++)
    {
        sales_associates[i]->sa_idx = i;
        myfile << sales_associates[i]->get_constructor();
    }
    myfile << "===\n";
    for(int i = 0; i < customers.size(); i ++)
    {
        myfile << customers[i]->get_constructor();
    }
    myfile << "===\n";
    for(int i = 0; i < orders.size(); i ++)
    {
        myfile << orders[i]->get_constructor();
    }
    myfile << "===\n";
    myfile.close();
    return;
}
        
void Shop::open (string _filename)
{
    string line;
    vector <string> store;
    int i = 0;
    ifstream myfile ("save.txt");
    if (myfile.is_open())
    {
        while(getline(myfile, line))
        {
            store.push_back(line);
            i ++;

        }
        i = 0;
//            string junk;
//            cin >> junk;
        while(store[i] != "===")
        {
            if(store[i] == "1")
            {
                i ++;
                int index = stoi(store[i]);
                i ++;
                string name = store[i];
                i ++;
                int model_number = stoi(store[i]);
                i ++;
                double cost = stod(store[i]);
                i ++;
                string description = store[i];
                i ++;
                double weight = stod(store[i]);
                i ++;
                double power = stod(store[i]);
                i ++;
                Head * head1;
                head1 = new Head(index, name, model_number, cost, description, weight, power);
                create_new_robot_part(head1);
                i ++;
//                view_parts();
//                string junk;
//                cin >> junk;
                
            }
            else if(store[i] == "2")
            {
                i ++;
                int index = stoi(store[i]);
                i ++;
                string name = store[i];
                i ++;
                int model_number = stoi(store[i]);
                i ++;
                double cost = stod(store[i]);
                i ++;
                string description = store[i];
                i ++;
                double weight = stod(store[i]);
                i ++;
                double max_power = stod(store[i]);
                i ++;
                double max_speed = stod(store[i]);
                i ++;
                Locomotor *Loc1 = new Locomotor(index, name, model_number, cost, description, weight, max_power, max_speed);
                create_new_robot_part(Loc1);
                i ++;
//                view_parts();
//                string junk;
//                cin >> junk;
//                break;
            }
            else if(store[i] == "3")
            {
                i ++;
                int index = stoi(store[i]);
                i ++;
                string name = store[i];
                i ++;
                int model_number = stoi(store[i]);
                i ++;
                double cost = stod(store[i]);
                i ++;
                string description = store[i];
                i ++;
                double weight = stod(store[i]);
                i ++;
                int battery_compartments = stoi(store[i]);
                i ++;
                int max_arms = stoi(store[i]);
                i ++;
                Torso *Tor1 = new Torso(index, name, model_number, cost, description, weight, battery_compartments, max_arms);
                create_new_robot_part(Tor1);
                i ++;
            }
            else if(store[i] == "4")
            {
                i ++;
                int index = stoi(store[i]);
                i ++;
                string name = store[i];
                i ++;
                int model_number = stoi(store[i]);
                i ++;
                double cost = stod(store[i]);
                i ++;
                string description = store[i];
                i ++;
                double weight = stod(store[i]);
                i ++;
                double max_power = stod(store[i]);
                i ++;
                Arm* arm1 = new Arm(index, name, model_number, cost, description, weight, max_power);
                create_new_robot_part(arm1);
                i ++;
            }
            else if(store[i] == "5")
            {
                i ++;
                int index = stoi(store[i]);
                i ++;
                string name = store[i];
                i ++;
                int model_number = stoi(store[i]);
                i ++;
                double cost = stod(store[i]);
                i ++;
                string description = store[i];
                i ++;
                double weight = stod(store[i]);
                i ++;
                double power_available = stod(store[i]);
                i ++;
                double max_energy = stod(store[i]);
                i ++;
                Battery *Bat1 = new Battery(index, name, model_number, cost, description, weight, power_available, max_energy);
                create_new_robot_part(Bat1);
                i ++;
            }
        }
        i ++;
        while(store[i] != "===")
        {
            int index = stoi(store[i]);
            i++;
            string name = store[i];
            i ++;
            int model_number = stoi(store[i]);
            i ++;
            i ++;
            int t_idx = stoi(store[i]);
            i++;
            i++;
            int h_idx = stoi(store[i]);
            i++;
            i++;
            int l_idx = stoi(store[i]);
            i++;
            vector <int> a;
            vector <int> b;
            while(store[i] == "4")
            {
                i++;
                a.push_back(stoi(store[i]));
                i++;
            }
            while(store[i] == "5")
            {
                i++;
                b.push_back(stoi(store[i]));
                i++;
            }
            i ++;
            create_new_robot_model(name, model_number, t_idx, h_idx, l_idx, a, b);
        }
        i ++;
        while(store[i] != "===")
        {
            i ++;
            string name = store[i];
            i ++;
            int id = stoi(store[i]);
            i++;
            create_new_sales_associate(name, id);
            i++;
        }
        
        i ++;
        
        while(store[i] != "===")
        {
            i ++;
            string name = store[i];
            i ++;
            string phone_number = store[i];
            i++;
            string email = store[i];
            i ++;
            create_new_customer(name, phone_number, email);
            i++;
        }
        i++;
        while(store[i] != "===")
        {
            i ++;
            string date = store[i];
            i ++;
            int cust = stoi(store[i]);
            i ++;
            int sa = stoi(store[i]);
            i ++;
            int model = stoi(store[i]);
            i ++;
            int status = stoi(store[i]);
            i ++;
            create_new_order(date, cust, sa, model, status);
            i ++;
        }

        myfile.close();
    }
    else cout << "Unable to open file"; 

    return;
}


void Shop::create_new_robot_part(robot_part * a)
{
    store_parts.push_back(a);
    return;
}


void Shop::create_new_robot_part(int cmd)
{
    system("clear");
    return;
}

double Shop::part_cost(int part_number)
{
    return(store_parts[part_number]->get_cost());
}
void Shop::create_new_robot_model(string name, int model_number, int t, int h, int l, vector<int> a, vector<int> b)
{
    vector<robot_part*> arm;
    vector<robot_part*> battery;
    for (int i = 0; i < a.size(); i ++)
    {
        robot_part * a1 = store_parts[a[i]];
        arm.push_back(a1);
    }
    for (int i = 0; i < b.size(); i ++)
    {
        robot_part * b1 = store_parts[b[i]];
        battery.push_back(b1);
    }
    Robot_model * A = new Robot_model(name, model_number, store_parts[t], store_parts[h], store_parts[l], arm, battery);
    store_model.push_back(A);
    return;
}

void Shop::create_new_customer(string name, string phone_number, string email)
{
    Customer * a = new Customer(name, customers.size(), phone_number, email);
    customers.push_back(a);
    return;
}

void Shop::create_new_sales_associate(string name, int id)
{
    Sales_associate * a = new Sales_associate(name, id);
    sales_associates.push_back(a);
    return;
}

string Shop::view_customers()
{
    string result = "";
    result += "Total Customers: " + ::to_string(customers.size()) + "\n";
    for(int i = 0; i < customers.size(); i ++)
    { 
        result += customers[i]->to_string();
    }
    return result;
}

string Shop::view_sales_associates()
{
    string result = "";
    result += "Total Associates: " + ::to_string(sales_associates.size()) + "\n";
    for(int i = 0; i < sales_associates.size(); i ++)
    {
        result += sales_associates[i]->to_string() + "Associate Index: " + ::to_string(i) + "\n";
    }
    return result;
}

void Shop::create_new_order(string date, int cust, int sa, int model, int status)
{
    Order * a = new Order(orders.size(), date, customers[cust], sales_associates[sa], store_model[model], status);
    orders.push_back(a);
    return;
}



bool Shop::is_valid(int n, int a)
{
    if (n < 0 || n > store_parts.size())
    {
        return false;
    }
    if(store_parts[n]->get_idx() == a)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool Shop::bat_valid(int n, int current)
{
    if(store_parts[n]->get_max_bat() > current)
    {
        return true;
    }
    return false;     
}

bool Shop::arm_valid(int n, int current)
{
    if(store_parts[n]->get_max_arms() > current)
    {
        return true;
    }
    return false;
}
void Shop::view_parts(int index)
{
    system("clear");
    cout << "Showing applicable parts\n\n";
    for(int i = 0; i < store_parts.size(); i ++)
    {
        if(store_parts[i]->get_idx() == index)
        {   
            cout << store_parts[i]->to_string();
            cout << "Part Index: " << i << endl;
        }
    }
    return;
}
string Shop::view_parts()
{
    string result = "";
    result += "Total Parts: " + ::to_string(store_parts.size()) + "\n";
    for(int i = 0; i < store_parts.size(); i ++)
    {
        result += store_parts[i]->to_string() + "Part Index: " + ::to_string(i) + "\n";
    }

    return result;
}

void Shop::view_model_summary()
{
    cout << "Total Models: " << store_model.size() << endl;
    for(int i = 0; i < store_model.size(); i ++)
    {
        cout << store_model[i]->print_summary();
        cout << "\nModel Index: " << i << endl;
        cout << "\n===========================================================\n";
    }
    return;
}

void Shop::view_specific_model(int index)
{
    cout << store_model[index]->print();
    cout << "\nPress Y to return to main menu: ";
    string junk;
    cin >> junk;
    return;
}
void Shop::view_models()
{
    cout << "Total Models: " << store_model.size() << endl;
    for(int i = 0; i < store_model.size(); i ++)
    {
        cout << store_model[i]->print();
        cout << "\n===========================================================\n";
    }
    cout << "\nPress Y to return to main menu: ";
    string junk;
    cin >> junk;
    return;
}

void Shop::view_orders()
{
    cout << "Total Orders: " << orders.size() << endl;
    for(int i = 0; i < orders.size(); i ++)
    {
        cout << orders[i]->print();
        cout << "\n===========================================================";
    }
    cout << "\nPress Y to return to main menu: ";
    string junk;
    cin >> junk;
    return;
}

int Shop::get_part_size()
{
    return (store_parts.size());
}

Shop _shop;


class Robot_Part_Dialog {
    public:
        Robot_Part_Dialog() { // Create and populate the dialog (but don't show it!)
        dialog = new Fl_Window(340, 270, "Create Head");
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        rp_part_number = new Fl_Int_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        rp_power = new Fl_Float_Input(120, 70, 210, 25, "Power:");
        rp_power->align(FL_ALIGN_LEFT);
        rp_weight = new Fl_Float_Input(120, 100, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        rp_cost = new Fl_Float_Input(120, 130, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_robot_partCB, 0);
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);
        dialog->end();
        dialog->set_non_modal();
 }
        void show() {dialog->show();}
        void hide() {dialog->hide();}
        string name() {return rp_name->value();}
        int part_number() {return atoi(rp_part_number->value());}
        double power() {return atof(rp_power->value());}
        double weight() {return atof(rp_weight->value());}
        double cost() {return atof(rp_cost->value());}
        string description() {return rp_description->value();}

    private:
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_part_number;
        Fl_Input *rp_power;
        Fl_Input *rp_weight;
        Fl_Input *rp_cost;
        Fl_Input *rp_description;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;
};

Robot_Part_Dialog * robot_part_dlg;

void create_robot_part(Fl_Widget* w, void* p) 
{
    robot_part_dlg = new Robot_Part_Dialog{};
    robot_part_dlg->show();

}
void create_robot_partCB(Fl_Widget* w, void* p) { // Replace with call to model!
    string name = robot_part_dlg->name();
    int part_number = robot_part_dlg->part_number();
    double cost = robot_part_dlg->cost();
    string description = robot_part_dlg->description();
    double weight = robot_part_dlg->weight();
    double power = robot_part_dlg->power();
    Head * a;
    a = new Head(_shop.get_part_size(),name , part_number, cost, description, weight, power);
    _shop.create_new_robot_part(a);
    string result = "### Creating Head\n";
    result += "Name : " + robot_part_dlg->name() + '\n';
    result += "Part # : " + ::to_string(robot_part_dlg->part_number()) + '\n';
    result += "Power : " + ::to_string(robot_part_dlg->power()) + '\n';
    result += "Weight : " + ::to_string(robot_part_dlg->weight()) + '\n';
    result += "Cost : " + ::to_string(robot_part_dlg->cost()) + '\n';
    result += "Descript: " + robot_part_dlg->description() + '\n';
    robot_part_dlg->hide();
    fl_message(result.c_str());
}


// Callback to just throw away the data
void cancel_robot_partCB(Fl_Widget* w, void* p) {
 robot_part_dlg->hide();
}

//=====================================================================Locomotor

class Robot_Part_Dialog_Loc {
    public:
        Robot_Part_Dialog_Loc() { // Create and populate the dialog (but don't show it!)
        dialog = new Fl_Window(340, 300, "Create Locomotor");
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        rp_part_number = new Fl_Int_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        rp_power = new Fl_Float_Input(120, 70, 210, 25, "Max Power:");
        rp_power->align(FL_ALIGN_LEFT);
        rp_weight = new Fl_Float_Input(120, 100, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        rp_cost = new Fl_Float_Input(120, 130, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        rp_speed = new Fl_Float_Input(120, 160, 210, 25, "Max Speed:");
        rp_speed->align(FL_ALIGN_LEFT);
        rp_description = new Fl_Multiline_Input(120, 190, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        rp_create = new Fl_Return_Button(145, 270, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_robot_partCB_loc, 0);
        rp_cancel = new Fl_Button(270, 270, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_robot_partCB_loc, 0);
        dialog->end();
        dialog->set_non_modal();
 }
        void show() {dialog->show();}
        void hide() {dialog->hide();}
        string name() {return rp_name->value();}
        int part_number() {return atoi(rp_part_number->value());}
        double power() {return atof(rp_power->value());}
        double weight() {return atof(rp_weight->value());}
        double cost() {return atof(rp_cost->value());}
        double speed() {return atof(rp_speed->value());}
        string description() {return rp_description->value();}

    private:
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_part_number;
        Fl_Input *rp_power;
        Fl_Input *rp_weight;
        Fl_Input *rp_cost;
        Fl_Input *rp_speed;
        Fl_Input *rp_description;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;
};

Robot_Part_Dialog_Loc * robot_part_dlg_loc;

void create_robot_part_loc(Fl_Widget* w, void* p) 
{
    robot_part_dlg_loc = new Robot_Part_Dialog_Loc{};
    robot_part_dlg_loc->show();
    
}
void create_robot_partCB_loc(Fl_Widget* w, void* p) { // Replace with call to model!
    string name = robot_part_dlg_loc->name();
    int part_number = robot_part_dlg_loc->part_number();
    double cost = robot_part_dlg_loc->cost();
    string description = robot_part_dlg_loc->description();
    double weight = robot_part_dlg_loc->weight();
    double power = robot_part_dlg_loc->power();
    double speed = robot_part_dlg_loc->speed();
    Locomotor * a = new Locomotor(_shop.get_part_size(),name, part_number, cost, description, weight, power, speed);
    _shop.create_new_robot_part(a);
    string result = "### Creating Locomotor\n";
    result += "Name : " + robot_part_dlg_loc->name() + '\n';
    result += "Part # : " + ::to_string(robot_part_dlg_loc->part_number()) + '\n';
    result += "Max Power : " + ::to_string(robot_part_dlg_loc->power()) + '\n';
    result += "Weight : " + ::to_string(robot_part_dlg_loc->weight()) + '\n';
    result += "Cost : " + ::to_string(robot_part_dlg_loc->cost()) + '\n';
    result += "Max Speed: " + ::to_string(robot_part_dlg_loc->speed()) + '\n';
    result += "Descript: " + robot_part_dlg_loc->description() + '\n';
    robot_part_dlg_loc->hide();
    fl_message(result.c_str());
}

void cancel_robot_partCB_loc(Fl_Widget* w, void* p) {
 robot_part_dlg_loc->hide();
}


//=====================================================================Arm

class Robot_Part_Dialog_Arm {
    public:
        Robot_Part_Dialog_Arm() { // Create and populate the dialog (but don't show it!)
        dialog = new Fl_Window(340, 270, "Create Arm");
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        rp_part_number = new Fl_Int_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        rp_power = new Fl_Float_Input(120, 70, 210, 25, "Max Power:");
        rp_power->align(FL_ALIGN_LEFT);
        rp_weight = new Fl_Float_Input(120, 100, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        rp_cost = new Fl_Float_Input(120, 130, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_robot_partCB_arm, 0);
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_robot_partCB_arm, 0);
        dialog->end();
        dialog->set_non_modal();
 }
        void show() {dialog->show();}
        void hide() {dialog->hide();}
        string name() {return rp_name->value();}
        int part_number() {return atoi(rp_part_number->value());}
        double power() {return atof(rp_power->value());}
        double weight() {return atof(rp_weight->value());}
        double cost() {return atof(rp_cost->value());}
        string description() {return rp_description->value();}

    private:
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_part_number;
        Fl_Input *rp_power;
        Fl_Input *rp_weight;
        Fl_Input *rp_cost;
        Fl_Input *rp_description;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;
};

Robot_Part_Dialog_Arm * robot_part_dlg_arm;

void create_robot_part_arm(Fl_Widget* w, void* p) 
{
    robot_part_dlg_arm = new Robot_Part_Dialog_Arm{};
    robot_part_dlg_arm->show();
}
void create_robot_partCB_arm(Fl_Widget* w, void* p) { // Replace with call to model!
    string name = robot_part_dlg_arm->name();
    int part_number = robot_part_dlg_arm->part_number();
    double cost = robot_part_dlg_arm->cost();
    string description = robot_part_dlg_arm->description();
    double weight = robot_part_dlg_arm->weight();
    double power = robot_part_dlg_arm->power();
    Arm * a = new Arm(_shop.get_part_size(), name, part_number, cost, description, weight, power);
    _shop.create_new_robot_part(a);
    string result = "### Creating Arm\n";
    result += "Name : " + robot_part_dlg_arm->name() + '\n';
    result += "Part # : " + ::to_string(robot_part_dlg_arm->part_number()) + '\n';
    result += "Max Power : " + ::to_string(robot_part_dlg_arm->power()) + '\n';
    result += "Weight : " + ::to_string(robot_part_dlg_arm->weight()) + '\n';
    result += "Cost : " + ::to_string(robot_part_dlg_arm->cost()) + '\n';
    result += "Descript: " + robot_part_dlg_arm->description() + '\n';
    robot_part_dlg_arm->hide();
    fl_message(result.c_str());
}

// Callback to just throw away the data
void cancel_robot_partCB_arm(Fl_Widget* w, void* p) {
 robot_part_dlg_arm->hide();
}

//=====================================================================Torso

class Robot_Part_Dialog_Tor {
    public:
        Robot_Part_Dialog_Tor() { // Create and populate the dialog (but don't show it!)
        dialog = new Fl_Window(400, 300, "Create Torso");
        rp_name = new Fl_Input(180, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        rp_part_number = new Fl_Int_Input(180, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        rp_bat = new Fl_Int_Input(180, 70, 210, 25, "Battery Compartments:");
        rp_bat->align(FL_ALIGN_LEFT);
        rp_arm = new Fl_Int_Input(180, 100, 210, 25, "Maximum Arms:");
        rp_arm->align(FL_ALIGN_LEFT);
        rp_weight = new Fl_Float_Input(180, 130, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        rp_cost = new Fl_Float_Input(180, 160, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        rp_description = new Fl_Multiline_Input(180, 190, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        rp_create = new Fl_Return_Button(205, 270, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_robot_partCB_tor, 0);
        rp_cancel = new Fl_Button(330, 270, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_robot_partCB_tor, 0);
        dialog->end();
        dialog->set_non_modal();
 }
        void show() {dialog->show();}
        void hide() {dialog->hide();}
        string name() {return rp_name->value();}
        int part_number() {return atoi(rp_part_number->value());}
        int bat() {return atoi(rp_bat->value());}
        int arm() {return atoi(rp_arm->value());}
        double weight() {return atof(rp_weight->value());}
        double cost() {return atof(rp_cost->value());}
        string description() {return rp_description->value();}

    private:
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_part_number;
        Fl_Input *rp_bat;
        Fl_Input *rp_arm;
        Fl_Input *rp_weight;
        Fl_Input *rp_cost;
        Fl_Input *rp_description;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;
};

Robot_Part_Dialog_Tor * robot_part_dlg_tor;

void create_robot_part_tor(Fl_Widget* w, void* p) 
{
    robot_part_dlg_tor = new Robot_Part_Dialog_Tor{};
    robot_part_dlg_tor->show();
}
void create_robot_partCB_tor(Fl_Widget* w, void* p) { // Replace with call to model!
    string name = robot_part_dlg_tor->name();
    int part_number = robot_part_dlg_tor->part_number();
    double cost = robot_part_dlg_tor->cost();
    string description = robot_part_dlg_tor->description();
    double weight = robot_part_dlg_tor->weight();
    int bat = robot_part_dlg_tor->bat();
    int arm = robot_part_dlg_tor->arm();
    Torso *a = new Torso(_shop.get_part_size(),name, part_number, cost, description, weight, bat, arm);
    _shop.create_new_robot_part(a);
    string result = "### Creating Torso\n";
    result += "Name : " + robot_part_dlg_tor->name() + '\n';
    result += "Part # : " + ::to_string(robot_part_dlg_tor->part_number()) + '\n';
    result += "Battery Compartments : " + ::to_string(robot_part_dlg_tor->bat()) + '\n';
    result += "Maximum Arms : " + ::to_string(robot_part_dlg_tor->arm()) + '\n';
    result += "Weight : " + ::to_string(robot_part_dlg_tor->weight()) + '\n';
    result += "Cost : " + ::to_string(robot_part_dlg_tor->cost()) + '\n';
    result += "Descript: " + robot_part_dlg_tor->description() + '\n';
    robot_part_dlg_tor->hide();
    fl_message(result.c_str());
}


// Callback to just throw away the data
void cancel_robot_partCB_tor(Fl_Widget* w, void* p) {
 robot_part_dlg_tor->hide();
}

//=====================================================================Battery

class Robot_Part_Dialog_Bat {
    public:
        Robot_Part_Dialog_Bat() { // Create and populate the dialog (but don't show it!)
        dialog = new Fl_Window(360, 300, "Create Battery");
        rp_name = new Fl_Input(140, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        rp_part_number = new Fl_Int_Input(140, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        rp_power_available = new Fl_Float_Input(140, 70, 210, 25, "Power Available:");
        rp_power_available->align(FL_ALIGN_LEFT);
        rp_max_energy = new Fl_Float_Input(140, 100, 210, 25, "Maximum Energy:");
        rp_max_energy->align(FL_ALIGN_LEFT);
        rp_weight = new Fl_Float_Input(140, 130, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        rp_cost = new Fl_Float_Input(140, 160, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        rp_description = new Fl_Multiline_Input(140, 190, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        rp_create = new Fl_Return_Button(165, 270, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_robot_partCB_bat, 0);
        rp_cancel = new Fl_Button(290, 270, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_robot_partCB_bat, 0);
        dialog->end();
        dialog->set_non_modal();
 }
        void show() {dialog->show();}
        void hide() {dialog->hide();}
        string name() {return rp_name->value();}
        int part_number() {return atoi(rp_part_number->value());}
        int power_available() {return atof(rp_power_available->value());}
        int max_energy() {return atof(rp_max_energy->value());}
        double weight() {return atof(rp_weight->value());}
        double cost() {return atof(rp_cost->value());}
        string description() {return rp_description->value();}

    private:
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_part_number;
        Fl_Input *rp_power_available;
        Fl_Input *rp_max_energy;
        Fl_Input *rp_weight;
        Fl_Input *rp_cost;
        Fl_Input *rp_description;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;
};

Robot_Part_Dialog_Bat * robot_part_dlg_bat;

void create_robot_part_bat(Fl_Widget* w, void* p) 
{
    robot_part_dlg_bat = new Robot_Part_Dialog_Bat{};
    robot_part_dlg_bat->show();
}
void create_robot_partCB_bat(Fl_Widget* w, void* p) { // Replace with call to model!
    string name = robot_part_dlg_bat->name();
    int part_number = robot_part_dlg_bat->part_number();
    double cost = robot_part_dlg_bat->cost();
    string description = robot_part_dlg_bat->description();
    double weight = robot_part_dlg_bat->weight();
    double power_available = robot_part_dlg_bat->power_available();
    double max_energy = robot_part_dlg_bat->max_energy();
    Battery * a = new Battery(_shop.get_part_size(),name, part_number, cost, description, weight, power_available, max_energy);
    _shop.create_new_robot_part(a);
    string result = "### Creating Torso\n";
    result += "Name : " + robot_part_dlg_bat->name() + '\n';
    result += "Part # : " + ::to_string(robot_part_dlg_bat->part_number()) + '\n';
    result += "Power available : " + ::to_string(robot_part_dlg_bat->power_available()) + '\n';
    result += "Maximum Energy : " + ::to_string(robot_part_dlg_bat->max_energy()) + '\n';
    result += "Weight : " + ::to_string(robot_part_dlg_bat->weight()) + '\n';
    result += "Cost : " + ::to_string(robot_part_dlg_bat->cost()) + '\n';
    result += "Descript: " + robot_part_dlg_bat->description() + '\n';
    robot_part_dlg_bat->hide();
    fl_message(result.c_str());
}

class Robot_Model_Dialog 
{
    public:
        Robot_Model_Dialog() { // Create and populate the dialog (but don't show it!)
            dialog = new Fl_Window(540, 370, "Create Model");
            int y = 15;
            rp_name = new Fl_Input(170, y, 210, 25, "Name:");
            rp_name->align(FL_ALIGN_LEFT);
            y+=30;
            rp_model_number = new Fl_Int_Input(170, y, 210, 25, "Part Number:");
            rp_model_number->align(FL_ALIGN_LEFT);
            y+=30;
            rp_head = new Fl_Choice(170, y, 210, 25, "Select Head: ");
            head = _shop.get_part_list(1);
            //cout << head.size();
            for(int i = 0; i < head.size(); i ++)
            {
                rp_head->add((_shop.view_part_name(head[i])).c_str());
            }
            rp_head->value(-1);
            rp_add_head = new Fl_Return_Button(400, y, 60, 25, "Add");
            rp_add_head->callback((Fl_Callback *)head_cb, 0);
            y+=30;
            //=================================================================
            rp_loc = new Fl_Choice(170, y, 210, 25, "Select Locomotor: ");
            loc = _shop.get_part_list(2);
            //cout << loc.size();
            for(int i = 0; i < loc.size(); i ++)
            {
                rp_loc->add((_shop.view_part_name(loc[i])).c_str());
            }
            rp_add_loc = new Fl_Return_Button(400, y, 60, 25, "Add");
            rp_loc->value(-1);
            rp_loc->align(FL_ALIGN_LEFT);
            rp_add_loc->callback((Fl_Callback *)loc_cb, 0);
            y+=30;
            //=================================================================
            rp_tor = new Fl_Choice(170, y, 210, 25, "Select Torso: ");
            tor = _shop.get_part_list(3);
            //cout << tor.size();
            for(int i = 0; i < tor.size(); i ++)
            {
                rp_tor->add((_shop.view_part_name(tor[i])).c_str());
            }
            rp_add_tor = new Fl_Return_Button(400, y, 60, 25, "Add");
            rp_tor->value(-1);
            rp_tor->align(FL_ALIGN_LEFT);
            rp_add_tor->callback((Fl_Callback *)tor_cb, 0);
            y+=30;
            //=================================================================
            rp_arm = new Fl_Choice(170, y, 210, 25, "Select Arm(s): ");
            arm = _shop.get_part_list(4);
            //cout << arm.size();
            for(int i = 0; i < arm.size(); i ++)
            {
                rp_arm->add((_shop.view_part_name(arm[i])).c_str());
            }
            rp_add_arm = new Fl_Return_Button(400, y, 60, 25, "Add");
            rp_arm->value(-1);
            rp_arm->align(FL_ALIGN_LEFT);
            rp_add_arm->callback((Fl_Callback *)arm_cb, 0);
            y+=30;
            //=================================================================
            rp_bat = new Fl_Choice(170, y, 210, 25, "Select Battery(s): ");
            bat = _shop.get_part_list(5);
            //cout << bat.size();
            for(int i = 0; i < arm.size(); i ++)
            {
                rp_bat->add((_shop.view_part_name(bat[i])).c_str());
            }
            rp_add_bat = new Fl_Return_Button(400, y, 60, 25, "Add");
            rp_bat->value(-1);
            rp_bat->align(FL_ALIGN_LEFT);
            rp_add_bat->callback((Fl_Callback *)bat_cb, 0);
            rp_create = new Fl_Return_Button(70, 300, 120, 25, "Create");
            rp_create->callback((Fl_Callback *)create_robot_model_cb, 0);
//            const char* temp = "Total Cost: $ 00.00";
//            box = new Fl_Box(300,y + 30,260,100, temp);
            dialog->end();
            dialog->set_non_modal();
            
        }

        int head_val() {return(rp_head->value());}
        int loc_val() {return(rp_loc->value());}
        int tor_val() {return(rp_tor->value());}
        int arm_val() {return(rp_arm->value());}
        int bat_val() {return(rp_bat->value());}
        void show() {dialog->show();}
        void hide() {dialog->hide();}
        Fl_Return_Button *rp_create;
        Fl_Return_Button *rp_add_head;
        Fl_Return_Button *rp_add_loc;
        Fl_Return_Button *rp_add_tor;
        Fl_Return_Button *rp_add_arm;
        Fl_Return_Button *rp_add_bat;
        vector<int> a;
        vector<int> b;
        int h;
        int l;
        int t;
        bool h1 = false;
        bool l1 = false;
        bool t1 = false;
        bool a1 = false;
        bool b1 = false;
        vector<int> head;
        vector<int> loc;
        vector<int> tor;
        vector<int> arm;
        vector<int> bat;
        Fl_Choice *rp_head;
        Fl_Choice *rp_loc;
        Fl_Choice *rp_tor;
        Fl_Choice *rp_bat;
        Fl_Choice *rp_arm;
        //Fl_Box *box;
        string name() {return rp_name->value();}
        int model_number() {return atoi(rp_model_number->value());}
        double total_cost = 0;
    private:
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_model_number;

        
};

Robot_Model_Dialog * dial;



void create_robot_model(Fl_Widget* w, void* p) 
{
    dial = new Robot_Model_Dialog;
    dial->show();
}
void head_cb(Fl_Widget* w, void* p)
{
    if(dial->head_val() == -1)
    {
        fl_message("Please make a selection first!");
    }
    else
    {
        dial->h = dial->head[dial->head_val()];
        dial->rp_head->deactivate();
        dial->h1 = true;
        double cost = _shop.part_cost(dial->h);
        dial->rp_add_head->deactivate();
    }
}
void loc_cb(Fl_Widget* w, void* p)
{
    if(dial->loc_val() == -1)
    {
        fl_message("Please make a selection first!");
    }
    else
    {
        dial->l = dial->loc[dial->loc_val()];
        dial->rp_loc->deactivate();
        dial->rp_add_loc->deactivate();
        dial->l1 = true;
    }
}
void tor_cb(Fl_Widget* w, void* p)
{
    if(dial->tor_val() == -1)
    {
        fl_message("Please make a selection first!");
    }
    else
    {
        dial->t = dial->tor[dial->tor_val()];
        dial->rp_tor->deactivate();
        dial->rp_add_tor->deactivate();
        dial->t1 = true;
    }
}
void arm_cb(Fl_Widget* w, void* p)
{
    if(!dial->t1)
    {
        fl_message("Select Torso first!");
    }
    else if(!(_shop.arm_valid(dial->t, dial->a.size())))
    {
        fl_message("Maximum Arms Reached!");
        dial->rp_arm->deactivate();
        dial->rp_add_arm->deactivate();
    }
    else
    {
        if(dial->arm_val() == -1)
        {
            fl_message("Please make a selection first!");
        }
        else
        {
            dial->a.push_back(dial->arm[dial->arm_val()]);
            dial->a1 = true;
            if(!(_shop.arm_valid(dial->t, dial->a.size())))
            {
                dial->rp_arm->deactivate();
                dial->rp_add_arm->deactivate();
            }
        }
    }
}
void bat_cb(Fl_Widget* w, void* p)
{
    if(!dial->t1)
    {
        fl_message("Select Torso first!");
    }
    else if(!(_shop.bat_valid(dial->t, dial->b.size())))
    {
        fl_message("Maximum Batteries Reached!");
        dial->rp_bat->deactivate();
        dial->rp_add_bat->deactivate();
    }
    else
    {
        if(dial->bat_val() == -1)
        {
            fl_message("Please make a selection first!");
        }
        else
        {
            dial->b.push_back(dial->bat[dial->bat_val()]);
            dial->b1 = true;
            if(!(_shop.bat_valid(dial->t, dial->b.size())))
            {
                dial->rp_bat->deactivate();
                dial->rp_add_bat->deactivate();
            }
        }
    }
}
void create_robot_model_cb(Fl_Widget* w, void* p) 
{
    if(dial->name() == "")
    {
        fl_message("Model name missing!");
    }
    else if(dial->model_number() == 0)
    {
        fl_message("Model number missing!");
    }
    else if(dial->a1 && dial->b1 && dial->h1 && dial->t1 && dial->l1)
    {
        
        _shop.create_new_robot_model(dial->name(), dial->model_number(), dial->h, dial->l, dial->t, dial->a, dial->b);
        fl_message("Model created!!");
        dial->hide();
    }
    else
    {
        fl_message("Not Enough Parts to create Model!");
    }
}
void cancel_robot_partCB_bat(Fl_Widget* w, void* p) {
 robot_part_dlg_bat->hide();
}
void ViewCustomers(Fl_Widget* w, void* p)
{
    fl_message((_shop.view_customers()).c_str());
}
void ViewSalesAssociates(Fl_Widget* w, void* p)
{
    fl_message((_shop.view_sales_associates()).c_str());
}
void ViewRobotModels(Fl_Widget* w, void* p)
{
    
}
void ViewOrders(Fl_Widget* w, void* p)
{
    
}
void ViewParts(Fl_Widget* w, void* p)
{
    fl_message((_shop.view_parts()).c_str());
}

void help(Fl_Widget* w, void* p)
{
   //fl_message((view.get_help()).c_str());
}

void LoadFile(Fl_Widget* w, void* p)
{
    _shop.open("hello");
    fl_message("File Loaded!");
}

void SaveFile(Fl_Widget* w, void* p)
{
    _shop.save("hello");
    fl_message("File Saved!");
   //fl_message((view.get_help()).c_str());
}

void Egg(Fl_Widget* w, void* p)
{
    Head * head1;
        head1 = new Head(_shop.get_part_size(),"head_test1", 233, 34.45, "Test Head", 33.5, 44.4);
        _shop.create_new_robot_part(head1);
        Head * head2;
        head2 = new Head(_shop.get_part_size(),"head_test2", 233323, 33.45, "Test Head2", 55.4, 44.4);
        _shop.create_new_robot_part(head2);
        Head * head3;
        head3 = new Head(_shop.get_part_size(),"head_test3", 23423, 49.45, "Test Head3", 77.6, 44.4);
        _shop.create_new_robot_part(head3);
        Head * head4;
        head4 = new Head(_shop.get_part_size(),"head_test4", 243223, 39.45, "Test Head4", 10.9, 44.4);
        //Head *head1 = malloc(sizeof(Head));
        //Head head1("head_test1", 23323, 34.45, "Test Model", "model_image.jpg", 44.4);
        _shop.create_new_robot_part(head4);
        Locomotor *Loc1 = new Locomotor(_shop.get_part_size(),"Test Loco", 33443, 33.4, "Test Desc", 18.5, 44.3, 12.2);
        _shop.create_new_robot_part(Loc1);
        Torso *Tor1 = new Torso(_shop.get_part_size(),"Torso_test1", 23323, 34.45, "Test Model", 22.9, 2, 2);
        _shop.create_new_robot_part(Tor1);
        Battery *Bat1 = new Battery(_shop.get_part_size(),"Battery_test1", 23323, 34.45, "Test Model", 34.3, 22.2, 33.3);
        _shop.create_new_robot_part(Bat1);
        Arm* arm1 = new Arm(_shop.get_part_size(),"Arm_test1", 23323, 34.45, "Test Model", 45.3, 33.43);
        _shop.create_new_robot_part(arm1);
        
        Locomotor *Loc2 = new Locomotor(_shop.get_part_size(),"Test Loco 2", 333, 22.4, "Test Desc", 99.3, 32.3, 13.2);
        _shop.create_new_robot_part(Loc2);
        Locomotor *Loc3 = new Locomotor(_shop.get_part_size(),"Test Loco 3", 334893, 11.4, "Test Desc", 12.3, 44.3, 11.9);
        _shop.create_new_robot_part(Loc3);
        _shop.create_new_customer("John Smith", "(925)-334-5454", "john.smith@@yahoo.com");
        _shop.create_new_customer("Kashif Iqbal", "(614)-446-8374", "kashif.iqbal@@mavs.uta.edu");
        _shop.create_new_customer("Rob Clark", "(668)-334-4354", "rob.clark@@gmail.com");
        _shop.create_new_sales_associate("Jake Michael", 991);
        _shop.create_new_sales_associate("Coby Williams", 374);
        _shop.create_new_sales_associate("Jane Hall", 348);
        vector<int> a;
        vector<int> b;
        a.push_back(7);
        a.push_back(7);
        b.push_back(6);
        _shop.create_new_robot_model("Tesla 1", 43, 5, 2, 8, a, b);
        b.push_back(6);
        _shop.create_new_robot_model("Tesla 2", 54, 5, 3, 4, a, b);
        _shop.create_new_order("03/04/2017", 1, 0, 0, 0);
        _shop.create_new_order("03/08/2017", 0, 1, 1, 1);
//    library.easter_egg();
    fl_message("Easter Egg added!");
}
void QuitCB(Fl_Widget* w, void* p)
{
    win->hide();
    exit(0);
}


Fl_Menu_Item menuitems[] = {
    { "&File", FL_ALT + 'f', 0, 0, FL_SUBMENU },
    { "&Load", FL_ALT + 'q', (Fl_Callback *)LoadFile },
    { "&Save", FL_ALT + 'q', (Fl_Callback *)SaveFile },
    { "&Quit", FL_ALT + 'q', (Fl_Callback *)QuitCB },
    { "&Easter Egg", 0, (Fl_Callback *)Egg },
    { 0 },
    { "&Create", FL_ALT + 'p', 0, 0, FL_SUBMENU},
    { "&Robot Parts", FL_ALT + 'p', 0, 0, FL_SUBMENU},
    { "&Head", 0,(Fl_Callback *)create_robot_part},
    { "&Locomotor", 0,(Fl_Callback *)create_robot_part_loc},
    { "&Torso", 0,(Fl_Callback *)create_robot_part_tor},
    { "&Arm", 0,(Fl_Callback *)create_robot_part_arm},
    { "&Battery", 0,(Fl_Callback *)create_robot_part_bat},
    
//    { "&Robot Part", FL_ALT + 'l', (Fl_Callback *)create_robot_part},
//    {"Head", 0,0,0,(Fl_Callback *)create_robot_part}, {"Locomotor"}, {"Torso"}, {"Arm"}, {"Battery"},
    { 0 },
    { "&Robot Model", FL_ALT + 'a', (Fl_Callback *)create_robot_model },
    { "&Customer", FL_ALT + 'i', (Fl_Callback *)ViewCustomers},
    { "&Sales Associate", FL_ALT + 'o', (Fl_Callback *)ViewCustomers },
    { "&Order", FL_ALT + 'o', (Fl_Callback *) ViewCustomers},
    { 0 },
    
    { "&View", 0, 0, 0, FL_SUBMENU },
    { "Robot Parts", 0, (Fl_Callback *)ViewParts },
    { "Robot Models", FL_ALT + 'p', (Fl_Callback *)ViewRobotModels },
    { "Customers", FL_ALT + 'p', (Fl_Callback *)ViewCustomers },
    { "Sales Associates", FL_ALT + 'p', (Fl_Callback *)ViewSalesAssociates },
    { "Orders", FL_ALT + 'p', (Fl_Callback *)ViewOrders },
    { 0 },
    { "&Help", 0, 0, 0, FL_SUBMENU },
    { "Get Help", FL_ALT + 'p', (Fl_Callback *)help},
    { 0 },
    { 0 }
};

int main(int argc, char** argv) 
{
    Fl_Window beacon(1,1);
    beacon.show();
    const int X = 640;
    const int Y = 700;
    win = new Fl_Window{X, Y, "K - Bot INC"};
    win->color(FL_WHITE);
    menubar = new Fl_Menu_Bar(0, 0, X, 30);
    menubar->menu(menuitems);
    win->end();
    win->show();
    int rtn = 0;

    
        return(Fl::run());
}

