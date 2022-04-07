#include "interface.h"
using std::string;
using std::cout;
using std::cin;
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
    const int k_com_num = 3;
    string commands[k_com_num] = { "1. OPERATIONS WITH POLYNOMS", "2. OPERATIONS WITH TABLES", "0. EXIT" };
    int input;
    for (int i = 0; i < k_com_num; i++)
        std::cout << commands[i];
    do {
        input = _getch();
        input -= '0';
        switch (input) {
        case 1: {
            polynom_menu();
        }
        case 2: {
            table_menu();
        }
        case 3: {
            if (are_sure())
                std::cout << "GOODBYE, HAVE A NICE DAY!\n";
            return;
        }
        default: {
            throw EqException(error_code::k_UNDEFINED_EXCEPTION);
        }
        }
    } while (true);
}
void Interface::table_menu()
{
    const int k_com_num = 5;
    string commands[k_com_num] = { "1. FIND ELEMENT", "2. INSERT ELEMENT", "3. DELETE ELEMENT", 
        "4. CHOOSE TABLE", "0. RETURN TO MAIN MENU" };
    int input;
    const int k_tables_num = 6;
    string tables[k_tables_num] = { "1. UNSORTED ARRAY TABLE", 
        "2. SORTED ARRAY TABLE","3. LIST TABLE", "4. RED-BLACK TREE", 
        "5. HASH TABLE (CHAIN METHOD)", "6. LIST HASH TABLE" };
    if (is_tab_not_chosen())
        goto choose_tab;
    for (int i = 0; i < k_com_num; i++)
        std::cout << commands[i] << "\n";
    int local_input;
    do {
        input = _getch();
        input -= '0';
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
        choose_tab:
            for (int i = 0; i < k_tables_num; i++)
                std::cout << tables[i] << "\n";
            do {
                local_input = _getch();
            } while (local_input - '0' < 1 || local_input - '0' > 6);
            local_input -= '0';//
            switch (local_input)
            {
            case 1: {
                mode = Table_num::k_ARRAY_TABLE;
                break;
            }
            case 2: {
                mode = Table_num::k_SORTED_ARRAY_TABLE;
                break;
            }
            case 3: {
                mode = Table_num::k_LIST_TABLE;
                break;
            }
            case 4: {
                mode = Table_num::k_RED_BLACK_TREE;
                break;
            }
            case 5: {
                mode = Table_num::k_CHAIN_HASH_TABLE;
                break;
            }
            case 6: {
                mode = Table_num::k_LIST_HASH_TABLE;
            }
            default: {
                throw EqException(error_code::k_UNDEFINED_EXCEPTION);
            }
            }
        }
        case 0: {
            break;
        }
        }
    } while (input != '0');
}
//const int k_com_num = 5;
//string commands[k_com_num];
//int input;
//do {
//    input = _getch();
//} while (input);

////////////////////////////////////////////////////////
void Interface::polynom_menu()
{
    const int k_com_num = 5;
    string commands[k_com_num] = { "1. ADD POLYNOM", "2. CALCULATE THE EXPRESSION", 
        "0. RETURN TO MAIN MENU" };
    for (int i = 0; i < k_com_num; i++)
        std::cout << commands[i] << "\n";
    int input;
    do {
        input = _getch();
        input -= '0';
        switch (input)
        {
        case 1: {
            string pol_str;
            std::cin >> pol_str;
            Polynom tmp(pol_str);
        }
        case 2: {
            string expression;
            cout << "ENTER EXPTRESSION WITHOUT SPACES AND DELIMITERS\n";
            cin >> expression;
            TPostfix postfix;
            postfix.set_infix(expression);
            Polynom tmp = postfix.calculate();
            cout << "THE RESULT IS " << tmp << endl;
            cout << "DO YOU WANT TO SAVE THE POLYNOM? Y - YES, ANYTHING ELSE - NO";
            if (are_sure())
            {
                TableBody save(tmp);
                cout<<"PRESS THE NAME OF POLYNOM. "
                for (int i = 0; i < Interface::k_table_size; i++)
                    tab[i]->insert();
            }
        }
        }
    } while (input);
}

void Interface::print_error(error_code ec)
{
    EqException tmp(ec);
    cout<<"ERROR NUMBER "<<tmp.get_error()<<". - "<<tmp.get_comment();
}