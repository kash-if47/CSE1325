#include <cstdlib>
#include <iostream>
#include <string>
#include "Robot_model.h"
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
            cout << "View: \n(6)  Orders\n(7)  Customers\n(8)  Sales Associates\n(9)  Robot Models\n(10) Robot Parts\n(-1) To Quit\n(99) To Test Program\nPlease select Option: ";
            cin >> input;
            return input;
        }
        int part_menu()
        {
            int input;
            cout << "==============================\n          Select Part\n==============================\n(1) Locomotor\n(2) Head\n(3) Arm\n(4) Battery\n(4) Torso\nSelect option: ";
            cin >> input;
            return input;
        }
    private:
        Shop shop;   
};

int cmd(Shop _shop,view _view, int _cmd)
{
    if (_cmd == -1)
    {
        return -1;
    }
    if(_cmd == 99)
    {
        Head head1("head_test1", 23323, 34.45, "Test Model", "model_image.jpg", 44.4);
        _shop.create_new_robot_part(&head1);
        Locomotor Loc1("Test Loco", 33443, 33.4, "Test Desc", "Test_image.png", 44.3);
        Torso Tor1("Torso_test1", 23323, 34.45, "Test Model", "model_image.jpg", 2, 2);
        Battery Bat1("Battery_test1", 23323, 34.45, "Test Model", "model_image.jpg", 22.2, 33.3);
        Arm arm1("Arm_test1", 23323, 34.45, "Test Model", "model_image.jpg", 33.43);
        Robot_model Tesla("Tesla1", 001, Tor1, head1, Loc1, arm1, Bat1);
        cout << head1.to_string() << endl;
        Tesla.print();
    }
    if(_cmd == 5)
    {
        int part = _view.part_menu();
    }
    if(_cmd == 10)
    {
        
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
        rtn = cmd(main_shop, _view, _view.menu());
    }
    
    //Tesla.print();
    
    return 0;
}

