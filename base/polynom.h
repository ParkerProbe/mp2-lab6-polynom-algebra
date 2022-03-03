#ifndef _POLYNOM_H_
#define _POLYNOM_H_

#include <iostream>
#include <string>
#include <type_traits>
#include "algorithm"

#include "list.h"

#define BASE 10


class Monom
{
private:
  double coef;
  int deg;
public:
    Monom() : coef(0.0), deg(0)
      {}

    Monom(double coef, int degree) : coef(coef), deg(degree)
      {}

    Monom(const Monom& other) = default;

    friend std::ostream& operator<<(std::ostream& os,  const Monom& mnm);
    friend std::istream& operator>>(std::istream& is,  Monom& mnm);

    Monom& integral();
    Monom& derivative(char param);
    Monom& operator=(const Monom& other) = default;
    Monom& operator+=(const Monom& other);
    Monom& operator*=(double num);
    Monom& operator-=(const Monom& other);
    Monom& operator*=(const Monom& other);

    bool operator<(const Monom& other) const;

    inline int get_deg() const
    {
      return deg;
    }

    inline double get_coef() const
    {
      return coef;
    }
  };

  Monom operator+(const Monom& lhs, const Monom& rhs);
  Monom operator*(const Monom& lhs, const Monom& rhs);
  Monom operator*(double lhs, const Monom& rhs);
  Monom operator*(const Monom& lhs, double rhs);
  Monom operator-(const Monom& lhs, const Monom& rhs);


  class Polynom
  {
  private:
      List<Monom> polynom;

  public:

      Polynom() : polynom() {}
      Polynom(const List<Monom>& pl) : polynom(pl) {}
      Polynom(std::string  polynom_str);
      Polynom(const Polynom& other) = default;

      friend std::ostream& operator<<(std::ostream& os,  const Polynom& pl);
      friend std::istream& operator>>(std::istream& is,  Polynom& pl);

      //Этот блок может быть сильно изменён

      void add_monom(const Monom& monom);
      Polynom sort(const Polynom& pl) const;
      double calculate_in_point(double x, double y, double z);
      void optimize_polynom();

      Polynom& integral();
      Polynom& derivative(char param);

      Polynom& operator=(const Polynom& other) = default;
      Polynom& operator+=(const Polynom& other);
      Polynom& operator*=(const Polynom& other);
      Polynom& operator*=(double num);
      Polynom& operator-=(Polynom& other);

      void write_to_file(std::string path) const;
      void read_from_file(std::string path);
};

Polynom operator+(const Polynom& lhs, const Polynom& rhs);
Polynom operator*(const Polynom& lhs, const Polynom& rhs);
Polynom operator*(const Polynom& lhs, double num);
Polynom operator*(double lhs, const Polynom& rhs);
Polynom operator-(const Polynom& lhs, const Polynom& rhs);

#endif  //_POLYNOM_H_


