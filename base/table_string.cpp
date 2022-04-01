#include "table_string.h"
std::ostream& operator<<(std::ostream& os, const TableString& ts)
{
    const char vert = 179, horiz = 196;
    const char left_up = 192, up = 193, rigth_up = 217;
    const char left_down = 218, down = 194, rigth_down = 191;
    const string name = "NAME OF POLYNOM", stroka = "POLYNOM";
    //console length = 120
    os << left_down;
    for (int i = 1; i < 17; i++)
        os << horiz;
      os << down;
    for (int i = 18; i < 119; i++)
          os << horiz;
      os << rigth_down;
      os << '\n';
      os << vert;
      os << ts.key << vert;
      os << ts.body.poly_string;
      for (int i = 0; i < 101 - stroka.size(); i++)
          os << ' ';
      os << vert;
      os << '\n';
      os << left_up;
    for (int i = 1; i < 17; i++)
        os << horiz;
    os << up;
    for (int i = 18; i < 119; i++)
          os << horiz;
      os << rigth_up;
      os << '\n';
}