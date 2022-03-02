#ifndef _LIST_H
#define _LIST_H

#include <string>

#include "polynom.h"

using std::string;

class TableString
{
private:
  Polynom pl_;

  std::string name_;
  std::string pl_str_;

  TableString(Polynom& pl, std::string name, std::string pl_str)
      : pl_(pl), name_(name), pl_str_(pl_str) { }

public:

};




#endif // _LIST_H
