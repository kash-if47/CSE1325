#include <cstdlib>
#include <iostream>
#include <string>
#include "robot_part.h"
#include "Shop.h"
using namespace std;

class view
{
    public:
        view(Shop _shop): shop(_shop) {}
        int menu()
        {
            int input;
            cout << "==============================\n      Welcome to K-Bot\n==============================\n";
            cout << "Create: \n(1)  Order\n(2)  Customer\n(3)  Sales Associate\n(4)  Robot Model\n(5)  Robot Component\n";
            cout << "View: \n(6)  Orders\n(7)  Customers\n(8)  Sales Associates\n(9)  Robot Models\n(10) Robot Parts\n(11) Load File\n(12) Save\n(-1) To Quit\n(99) To Test Program\nPlease select Option: ";
            cin >> input;
            return input;
        }
        void view_only_menu()
        {
            cout << "==============================\n      Welcome to K-Bot\n==============================\n";
            cout << "Create: \n(1)  Order\n(2)  Customer\n(3)  Sales Associate\n(4)  Robot Model\n(5)  Robot Component\n";
            cout << "View: \n(6)  Orders\n(7)  Customers\n(8)  Sales Associates\n(9)  Robot Models\n(10) Robot Parts\n(-1) To Quit\n(99) To Test Program\nPlease select Option: ";
        }
        int part_menu()
        {
            int input;
            cout << "==============================\n          Select Part\n==============================\n(1) Head\n(2) Locomotor\n(3) Arm\n(4) Battery\n(4) Torso\nSelect option: ";
            cin >> input;
            return input;
        }
        int model_menu()
        {
            int input;
            cout << "==============================\n    Select Part to Build\n==============================\n(1)  Head\n(2)  Locomotor\n(3)  Torso\n(4)  Arm\n(5)  Battery\n\n(0)  To Build\n(-1) Go to Main menu\nSelect option: ";
            cin >> input;
            return input;
        }
    private:
        Shop shop;   
};

int cmd(Shop &_shop,view _view, int _cmd)
{
    if (_cmd == -1)
    {
        return -1;
    }
    else if(_cmd == 11)
    {
        _shop.open("hello");
        cout << "\n****File Loaded!****\n\n(Enter Y to continue): ";
        string junk;
        cin >> junk; 
        return 0;
    }
    else if(_cmd == 12)
    {
        _shop.save("hello");
        cout << "\n****File Saved!****\n\n(Enter Y to continue): ";
        string junk;
        cin >> junk; 
        return 0;
    }
    else if(_cmd == 6)
    {
        system("clear");
        _shop.view_orders();
    }
    else if(_cmd == 1)
    {
        system("clear");
        cout << "==============================\n      Creating Order\n==============================\n\nEnter Today's date: ";
        string date;
        cin.ignore();
        getline(cin, date);
        system("clear");
        cout << "==============================\n      Creating Order\n==============================\n\nSelect Customer ";
        _shop.view_customers();
        int c_select;
        cout <<"\nEnter Customer Id: ";
        cin >> c_select;
        system("clear");
        cout << "==============================\n      Creating Order\n==============================\n\nSelect Sales Associate ";
        _shop.view_sales_associates();
        int s_select;
        cout <<"\nEnter Associate Index: ";
        cin >> s_select;
        system("clear");
        cout << "==============================\n      Creating Order\n==============================\n\nSelect Model  ";
        _shop.view_model_summary();
        int m_select;
        cout <<"Enter Model Index: ";
        cin >> m_select;
        system("clear");
        cout << "==============================\n      Creating Order\n==============================\n\nOrder Status (0) Pending | (1) Completed ";
        int st_select;
        cout <<"\nEnter Status: ";
        cin >> st_select;
        system("clear");
        cout << "==============================\n      Creating Order\n==============================\n\nOrder Created! (Enter Y to continue): ";
        _shop.create_new_order(date, c_select, s_select, m_select, st_select);
        string junk;
        cin >> junk;
    }
    else if(_cmd == 99)
    {
        Head * head1;
        head1 = new Head(_shop.get_part_size(),"head_test1", 233, 34.45, "Test Head", "model_image.jpg", 44.4);
        _shop.create_new_robot_part(head1);
        Head * head2;
        head2 = new Head(_shop.get_part_size(),"head_test2", 233323, 33.45, "Test Head2", "model_image.jpg", 44.4);
        _shop.create_new_robot_part(head2);
        Head * head3;
        head3 = new Head(_shop.get_part_size(),"head_test3", 23423, 49.45, "Test Head3", "model_image.jpg", 44.4);
        _shop.create_new_robot_part(head3);
        Head * head4;
        head4 = new Head(_shop.get_part_size(),"head_test4", 243223, 39.45, "Test Head4", "model_image.jpg", 44.4);
        //Head *head1 = malloc(sizeof(Head));
        //Head head1("head_test1", 23323, 34.45, "Test Model", "model_image.jpg", 44.4);
        _shop.create_new_robot_part(head4);
        Locomotor *Loc1 = new Locomotor(_shop.get_part_size(),"Test Loco", 33443, 33.4, "Test Desc", "Test_image.png", 44.3);
        _shop.create_new_robot_part(Loc1);
        Torso *Tor1 = new Torso(_shop.get_part_size(),"Torso_test1", 23323, 34.45, "Test Model", "model_image.jpg", 2, 2);
        _shop.create_new_robot_part(Tor1);
        
        Battery *Bat1 = new Battery(_shop.get_part_size(),"Battery_test1", 23323, 34.45, "Test Model", "model_image.jpg", 22.2, 33.3);
        _shop.create_new_robot_part(Bat1);
        Arm* arm1 = new Arm(_shop.get_part_size(),"Arm_test1", 23323, 34.45, "Test Model", "model_image.jpg", 33.43);
        _shop.create_new_robot_part(arm1);
        
        Locomotor *Loc2 = new Locomotor(_shop.get_part_size(),"Test Loco 2", 333, 22.4, "Test Desc", "Test_image.png", 32.3);
        _shop.create_new_robot_part(Loc2);
        Locomotor *Loc3 = new Locomotor(_shop.get_part_size(),"Test Loco 3", 334893, 11.4, "Test Desc", "Test_image.png", 44.3);
        _shop.create_new_robot_part(Loc3);
        _shop.create_new_customer("John Smith", "(925)-334-5454", "john.smith@yahoo.com");
        _shop.create_new_customer("Kashif Iqbal", "(614)-446-8374", "kashif.iqbal@mavs.uta.edu");
        _shop.create_new_customer("Rob Clark", "(668)-334-4354", "rob.clark@gmail.com");
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
    }
    else if(_cmd == 2)
    {
        system("clear");
        cout << "==============================\n      Creating Customer\n==============================\n\nEnter Customer's name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        cout << "Enter Phone Number: ";
        string phone_number;
        cin.ignore();
        getline(cin, phone_number);
        cout << "Enter Email Address: ";
        string email;
        cin.ignore();
        getline(cin, email);
        _shop.create_new_customer(name, phone_number, email);
        cout << "\n****Customer Created!****\n(Enter Y to continue): ";
        string junk;
        cin >> junk;   
    }
    else if(_cmd == 3)
    {
        system("clear");
        cout << "==============================\n  Creating Sales Associate\n==============================\n\nEnter Associate's name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        cout << "Enter Employee ID: ";
        int id;
        cin >> id;
        _shop.create_new_sales_associate(name, id);
        cout << "\n****Sales Associate Created!****\n(Enter Y to continue): ";
        string junk;
        cin >> junk; 
    }
    else if(_cmd == 7)
    {
        system("clear");
        _shop.view_customers();
        cout << "\n(Enter Y to continue): ";
        string junk;
        cin >> junk;
    }
    else if(_cmd == 8)
    {
        system("clear");
        _shop.view_sales_associates();
        cout << "\n(Enter Y to continue): ";
        string junk;
        cin >> junk;
    }
    else if(_cmd == 4)
    {
        system("clear");
        int part = _view.model_menu();
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
        while (part != -1)
        {
            if (part == 1)
            {
                _shop.view_parts(1);
                cout << "\nSelect which Part Index: ";
                cin >> h;
                h1 = _shop.is_valid(h, 1);
                if(h1 == false)
                {
                    cout << "Invalid Entry -- Try again! (Press Y to continue): ";
                    string junk;
                    cin >> junk;
                }
            }
            else if(part == 2)
            {
                _shop.view_parts(2);
                cout << "\nSelect which Part Index: ";
                cin >> l;
                l1 = _shop.is_valid(l, 2);
                if(l1 == false)
                {
                    cout << "Invalid Entry -- Try again! (Press Y to continue): ";
                    string junk;
                    cin >> junk;
                }
            }
            else if(part == 3)
            {
                _shop.view_parts(3);
                cout << "\nSelect which Part Index: ";
                cin >> t;
                t1 = _shop.is_valid(t, 3);
                if(t1 == false)
                {
                    cout << "Invalid Entry -- Try again! (Press Y to continue): ";
                    string junk;
                    cin >> junk;
                }
            }
            else if(part == 4)
            {
                if(!t1)
                {
                    cout << "Please select a valid Torso first! (Press Y to continue): ";
                    string junk;
                    cin >> junk; 
                }
                else
                {
                    if(_shop.arm_valid(t1, a.size()))
                    {
                        int temp;
                        _shop.view_parts(4);
                        cout << "\nSelect which Part Index: ";
                        cin >> temp;
                        a1 = _shop.is_valid(temp, 4);
                        if(a1 == false)
                        {
                            cout << "Invalid Entry -- Try again! (Press Y to continue): ";
                            string junk;
                            cin >> junk;
                        }
                        else
                        {
                            a.push_back(temp);
                        }
                    }
                    else
                    {
                        cout << "Error! -- Already at max arms! (Press Y to continue): ";
                        string junk;
                        cin >> junk;
                    }
                }
            }
            else if(part == 5)
            {
                if(!t1)
                {
                    cout << "Please select a valid Torso first! (Press Y to continue): ";
                    string junk;
                    cin >> junk; 
                }
                else
                {
                    if(_shop.bat_valid(t1, b.size()))
                    {
                        int temp;
                        _shop.view_parts(5);
                        cout << "\nSelect which Part Index: ";
                        cin >> temp;
                        b1 = _shop.is_valid(temp, 5);
                        if(b1 == false)
                        {
                            cout << "Invalid Entry -- Try again! (Press Y to continue): ";
                            string junk;
                            cin >> junk;
                        }
                        else
                        {
                            b.push_back(temp);
                        }
                    }
                    else
                    {
                        cout << "Error! -- Already at max Batteries! (Press Y to continue): ";
                        string junk;
                        cin >> junk;
                    }
                }
            }
            
            system("clear");
            part = _view.model_menu();
            if (part == 0)
            {
                if(h1 && l1 && t1 && a1 && b1)
                {
                    cout << "Enter Model Name: ";
                    string name;
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Model Number: ";
                    int model_number;
                    cin >> model_number;
                    cin.ignore();
                    _shop.create_new_robot_model(name, model_number, h, l, t, a, b);
                    cout << "\n****Model " << name << " Created!****\n(Enter Y to continue): ";
                    part = -1;
                    string junk;
                    cin >> junk;
                }
                else
                {
                    cout << "\nHead: " << h1 << "\nLocomotor:  " << l1 << "\nTorso: " << t1 << "\nArm: " << a1 << "\nBattery: " << b1 << endl;
                    cout << "****Not enough parts to create model!****\nEnter Y to continue adding parts: ";
                    string junk;
                    cin >> junk;
                }
            }
        }
        return 0;
    }
    else if(_cmd == 5)
    {
        system("clear");
        int part = _view.part_menu();
        if(part == 1)
    {
        system("clear");
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
        Head *a = new Head(_shop.get_part_size(), name, model_number, cost, description, image_filename, power);
        _shop.create_new_robot_part(a);
        cout << "Part Added!\n\nPress Y to return to main menu: ";
        string junk;
        cin >> junk;
        return 0;
    }
    else if(part == 2)
    {
        system("clear");
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
        Locomotor * a = new Locomotor(_shop.get_part_size(),name, model_number, cost, description, image_filename, power);
        _shop.create_new_robot_part(a);
        cout << "Part Added!\n\nPress Y to return to main menu: ";
        string junk;
        cin >> junk;
        return 0;
    }
    else if(part == 3)
    {
        system("clear");
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
        cout << "Enter Battery Compartments: ";
        int battery_compartments;
        cin >> battery_compartments;
        cout << "Enter Max Arms: ";
        int max_arms;
        cin >> max_arms;
        Torso *a = new Torso(_shop.get_part_size(),name, model_number, cost, description, image_filename, battery_compartments, max_arms);
        _shop.create_new_robot_part(a);
        cout << "Part Added!\n\nPress Y to return to main menu: ";
        string junk;
        cin >> junk;
        return 0;
    }
    else if(part == 4)
    {
        system("clear");
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
        double power_available;
        cout << "Enter power available(W): ";
        cin >> power_available;
        double max_energy;
        cout << "Enter max energy: ";
        cin >> max_energy;
        Battery * a = new Battery(_shop.get_part_size(),name, model_number, cost, description, image_filename, power_available, max_energy);
        _shop.create_new_robot_part(a);
        cout << "Part Added!\n\nPress Y to return to main menu: ";
        string junk;
        cin >> junk;
        return 0;
    }
    else if(part == 5)
    {
        system("clear");
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
        double max_power;
        cout << "Enter max power (W): ";
        cin >> max_power;
        Arm * a = new Arm(_shop.get_part_size(), name, model_number, cost, description, image_filename, max_power);
        _shop.create_new_robot_part(a);
        cout << "Part Added!\n\nPress Y to return to main menu: ";
        string junk;
        cin >> junk;
        return 0;
    }
    else
    {
        cout << "Invalid Option!";
    }
    }
    else if(_cmd == 10)
    {
        system("clear");
        _shop.view_parts();
    }
    else if(_cmd == 9)
    {
        system("clear");
        int selection;
        _shop.view_model_summary();
        cout << "Enter index to view detail or (-1) for main menu: ";
        cin >> selection;
        if (selection == -1)
        {
            return 0;
        }
        system("clear");
        _shop.view_specific_model(selection);
    }
    return 0;
}



int main(int argc, char** argv) 
{
    
    Shop main_shop;
    view _view(main_shop);
    int rtn = 0;
    while(rtn != -1)
    {
        system("clear");
        rtn = cmd(main_shop, _view, _view.menu());
    }
    
    //Tesla.print();
    
    return 0;
}

