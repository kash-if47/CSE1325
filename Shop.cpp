#include<vector>
#include "Shop.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

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
                string image = store[i];
                i ++;
                double power = stod(store[i]);
                i ++;
                Head * head1;
                head1 = new Head(index, name, model_number, cost, description, image, power);
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
                string image = store[i];
                i ++;
                double max_power = stod(store[i]);
                i ++;
                Locomotor *Loc1 = new Locomotor(index, name, model_number, cost, description, image, max_power);
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
                string image = store[i];
                i ++;
                int battery_compartments = stoi(store[i]);
                i ++;
                int max_arms = stoi(store[i]);
                i ++;
                Torso *Tor1 = new Torso(index, name, model_number, cost, description, image, battery_compartments, max_arms);
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
                string image = store[i];
                i ++;
                double max_power = stod(store[i]);
                i ++;
                Arm* arm1 = new Arm(index, name, model_number, cost, description, image, max_power);
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
                string image = store[i];
                i ++;
                double power_available = stod(store[i]);
                i ++;
                double max_energy = stod(store[i]);
                i ++;
                Battery *Bat1 = new Battery(index, name, model_number, cost, description, image, power_available, max_energy);
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

void Shop::view_customers()
{
    cout <<"Total Customers: " << customers.size() << endl;
    for(int i = 0; i < customers.size(); i ++)
    {
        cout << customers[i]->to_string();
    }
    return;
}

void Shop::view_sales_associates()
{
    cout <<"Total Associates: " << sales_associates.size() << endl;
    for(int i = 0; i < sales_associates.size(); i ++)
    {
        cout << sales_associates[i]->to_string();
        cout << "Associate Index: " << i << endl;
    }
    return;
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
    if(store_parts[n]->get_max_bat() >= (current - 1))
    {
        return true;
    }
    return false;     
}

bool Shop::arm_valid(int n, int current)
{
    if(store_parts[n]->get_max_arms() >= (current - 1))
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
void Shop::view_parts()
{
    system("clear");
    cout << "Total Parts: " << store_parts.size() << endl;
    for(int i = 0; i < store_parts.size(); i ++)
    {
        cout << store_parts[i]->to_string();
        cout << "Part Index: " << i << endl;
    }
    cout << "\nPress Y to return to main menu: ";
    string junk;
    cin >> junk;
    return;
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