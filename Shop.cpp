#include<vector>
#include "Shop.h"
#include <string>

using namespace std;
void Shop::create_new_robot_part(robot_part * a)
{
    store_parts.push_back(a);
    return;
}

void Shop::create_new_robot_part(int cmd)
{
    system("clear");
    
    if(cmd == 1)
    {
        cout << "==============================\n        Creating Head\n==============================\n\nEnter component name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        cout << "Enter model number: ";
        int model_number;
        cin >> model_number;
        cout << "Enter component cost ($): ";
        double cost;
        cin >> cost;
        string description;
        cout << "Enter component description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter image filename: ";
        string image_filename;
        cin.ignore();
        getline(cin, image_filename);
        double power;
        cout << "Enter power (W): ";
        cin >> power;
        Head *a = new Head(name, model_number, cost, description, image_filename, power);
        store_parts.push_back(a);
        cout << "Part Added!\n\nPress Y to return to main menu: ";
        string junk;
        cin >> junk;
        return;
    }
    else if(cmd == 2)
    {
        cout << "==============================\n     Creating Locomotor\n==============================\n\nEnter component name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        cout << "Enter model number: ";
        int model_number;
        cin >> model_number;
        cout << "Enter component cost ($): ";
        double cost;
        cin >> cost;
        string description;
        cout << "Enter component description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter image filename: ";
        string image_filename;
        cin.ignore();
        getline(cin, image_filename);
        double power;
        cout << "Enter Max power (W): ";
        cin >> power;
        Locomotor * a = new Locomotor(name, model_number, cost, description, image_filename, power);
        store_parts.push_back(a);
        cout << "Part Added!\n\nPress Y to return to main menu: ";
        string junk;
        cin >> junk;
        return;
    }
    else if(cmd == 3)
    {
        cout << "==============================\n       Creating Torso\n==============================\n\nEnter component name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        cout << "Enter model number: ";
        int model_number;
        cin >> model_number;
        cout << "Enter component cost ($): ";
        double cost;
        cin >> cost;
        string description;
        cout << "Enter component description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter image filename: ";
        string image_filename;
        cin.ignore();
        getline(cin, image_filename);
        double power;
        cout << "Enter power (W): ";
        cin >> power;
        Head a(name, model_number, cost, description, image_filename, power);
        store_parts.push_back(&a);
        cout << "Part Added!\n\nPress Y to return to main menu: ";
        string junk;
        cin >> junk;
        return;
    }
    else if(cmd == 4)
    {
        cout << "==============================\n       Creating Battery\n==============================\n\nEnter component name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        cout << "Enter model number: ";
        int model_number;
        cin >> model_number;
        cout << "Enter component cost ($): ";
        double cost;
        cin >> cost;
        string description;
        cout << "Enter component description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter image filename: ";
        string image_filename;
        cin.ignore();
        getline(cin, image_filename);
        double power;
        cout << "Enter power (W): ";
        cin >> power;
        Head a(name, model_number, cost, description, image_filename, power);
        store_parts.push_back(&a);
        cout << "Part Added!\n\nPress Y to return to main menu: ";
        string junk;
        cin >> junk;
        return;
    }
    else if(cmd == 5)
    {
        cout << "==============================\n         Creating Arm\n==============================\n\nEnter component name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        cout << "Enter model number: ";
        int model_number;
        cin >> model_number;
        cout << "Enter component cost ($): ";
        double cost;
        cin >> cost;
        string description;
        cout << "Enter component description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter image filename: ";
        string image_filename;
        cin.ignore();
        getline(cin, image_filename);
        double power;
        cout << "Enter power (W): ";
        cin >> power;
        Head a(name, model_number, cost, description, image_filename, power);
        store_parts.push_back(&a);
        cout << "Part Added!\n\nPress Y to return to main menu: ";
        string junk;
        cin >> junk;
        return;
    }
    else
    {
        cout << "Invalid Option!";
    }
    return;
}

void Shop::create_new_robot_model()
{
    return;
}

void Shop::create_new_customer()
{
    return;
}

void Shop::create_new_sales_associate()
{
    return;
}


void Shop::create_new_order()
{
    return;
}

void Shop::save (string _filename)
{
    return;
}
        
void Shop::open (string _filename)
{
    return;
}

void Shop::view_parts()
{
    system("clear");
    cout << "Total Parts: " << store_parts.size() << endl;
    for(int i = 0; i < store_parts.size(); i ++)
    {
        cout << store_parts[i]->to_string();
    }
    cout << "\nPress Y to return to main menu: ";
    string junk;
    cin >> junk;
    return;
}