#include "interface.h"
using std::string;
void Interface::table_menu()
{
    const int k_com_num = 5;
    string commands[k_com_num] = { "1 FIND ELEMENT", "2 INSERT ELEMENT", "3 DELETE ELEMENT", "4 CHANGE TABLE", "0 EXIT" };
    int input;
    do {
        input = _getch();
        switch (input)
        {
        case 1: {
            
        }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (input != '0');
}