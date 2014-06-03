#include "has_arithmetic_operators.hpp"
#include <iostream>
#include <cassert>

struct has_em
{
  has_em operator+(const has_em&)
  {
    return has_em();
  }

  has_em operator-(const has_em&)
  {
    return has_em();
  }

  has_em operator*(const has_em&)
  {
    return has_em();
  }

  has_em operator/(const has_em&)
  {
    return has_em();
  }

  has_em& operator+=(const has_em&)
  {
    return *this;
  }

  has_em& operator-=(const has_em&)
  {
    return *this;
  }

  has_em& operator*=(const has_em&)
  {
    return *this;
  }

  has_em& operator/=(const has_em&)
  {
    return *this;
  }
};

struct doesnt_have_em_all
{
  doesnt_have_em_all operator+(const doesnt_have_em_all&)
  {
    return doesnt_have_em_all();
  }

  doesnt_have_em_all& operator+=(const doesnt_have_em_all&)
  {
    return *this;
  }
};

int main()
{
  std::cout << "int has arithmetic operators: " << has_arithmetic_operators<int>::value << std::endl;
  assert(has_arithmetic_operators<int>::value);

  std::cout << "float has arithmetic operators: " << has_arithmetic_operators<float>::value << std::endl;
  assert(has_arithmetic_operators<float>::value);

  std::cout << "has_em has arithmetic operators: " << has_arithmetic_operators<has_em>::value << std::endl;
  assert(has_arithmetic_operators<has_em>::value);

  std::cout << "doesnt_have_em_all does not have all arithmetic operators: " << has_arithmetic_operators<doesnt_have_em_all>::value << std::endl;
  assert(!has_arithmetic_operators<doesnt_have_em_all>::value);

  std::cout << "doesnt_have_em_all has operator plus: " << has_operator_plus<doesnt_have_em_all>::value << std::endl;
  assert(has_operator_plus<doesnt_have_em_all>::value);

  std::cout << "doesnt_have_em_all has operator plus assign: " << has_operator_plus_assign<doesnt_have_em_all>::value << std::endl;
  assert(has_operator_plus_assign<doesnt_have_em_all>::value);

  std::cout << "doesnt_have_em_all does not have operator divides: " << has_operator_divides<doesnt_have_em_all>::value << std::endl;
  assert(!has_operator_divides<doesnt_have_em_all>::value);

  return 0;
}

