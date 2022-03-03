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
  double coef_;
  int degree_;
public:
    Monom() : coef_(0.0), degree_(0)
      {}

    Monom(double coef, int degree) : coef_(coef), degree_(degree)
      {}

    Monom(const Monom& other) = default;

    friend std::ostream& operator<<(std::ostream& os,  const Monom& mnm);
    friend std::istream& operator>>(std::istream& is,  Monom& mnm);


    Monom& operator=(const Monom& other) = default;
    Monom& operator+=(const Monom& other);
    Monom& operator*=(double num);
    Monom& operator-=(const Monom& other);
    Monom& operator*=(const Monom& other);

    bool operator<(const Monom& other) const;

    inline int GetDegree() const
    {
      return degree_;
    }

    inline double GetCoef() const
    {
      return coef_;
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

      void AddMonom(const Monom& monom);
      Polynom SortPolynom(const Polynom& pl) const;
      double CalculateInPoint(double x, double y, double z);
      void OptimizePolynom();

      Polynom& operator=(const Polynom& other) = default;
      Polynom& operator+=(const Polynom& other);
      Polynom& operator*=(const Polynom& other);
      Polynom& operator*=(double num);
      Polynom& operator-=(Polynom& other);

      void WriteToFile(std::string path) const;
      void ReadFromFile(std::string path);
};

Polynom operator+(const Polynom& lhs, const Polynom& rhs);
Polynom operator*(const Polynom& lhs, const Polynom& rhs);
Polynom operator*(const Polynom& lhs, double num);
Polynom operator*(double, const Polynom& rhs);
Polynom operator-(const Polynom& lhs, const Polynom& rhs);

#endif  //_POLYNOM_H_


