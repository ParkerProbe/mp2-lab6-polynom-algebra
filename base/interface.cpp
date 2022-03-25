#include "interface.h"
using std::string;
bool Interface::are_sure()
{
    int ans;
    std::cout << "Are you sure? Press Y if yes, press anything else if no\n";
    ans = _getch();
    if (ans == 'Y' || ans == 'y')
        return true;
    else
        return false;
}
bool Interface::is_tab_not_chosen()
{
    return mode != Table_num::k_TABLE;
}
void Interface::menu()
{

}
void Interface::table_menu()
{
    const int k_com_num = 5;
    string commands[k_com_num] = { "1 FIND ELEMENT", "2 INSERT ELEMENT", "3 DELETE ELEMENT", "4 CHOOSE TABLE",
        "0 EXIT" };
    int input;
    do {
        input = _getch();
        switch (input)
        {
        case 1: {
            Interface::find();
            break;
        }
        case 2: {
            Interface::insert();
            break;
        }
        case 3: {
            Interface::erase();
            break;
        }
        case 4: {
            string tables[6] = { "UNSORTED ARRAY TABLE", "SORTED ARRAY TABLE","LIST TABLE", "RED BLACK TREE",
                "HASH TABLE (CHAIN METHOD)",
                "LIST HASH TABLE" };
            int local_input;
            do {
                local_input = _getch();
            } while (local_input - '0' < 0 || local_input - '0' > 5);
            switch (local_input)
            {
            case 0: {
                mode = Table_num::k_ARRAY_TABLE;
                break;
            }
            case 1: {
                mode = Table_num::k_SORTED_ARRAY_TABLE;
                break;
            }
            case 2: {
                mode = Table_num::k_LIST_TABLE;
                break;
            }
            case 3: {
                mode = Table_num::k_RED_BLACK_TREE;
                break;
            }
            case 4: {
                mode = Table_num::k_CHAIN_HASH_TABLE;
                break;
            }
            case 5: {
                mode = Table_num::k_LIST_HASH_TABLE;
            default:
                throw EqException(error_code::k_NOT_FOUND);
            }
            }

        }
        case 0: {
            break;
        }
        }
    } while (input != '0');
}