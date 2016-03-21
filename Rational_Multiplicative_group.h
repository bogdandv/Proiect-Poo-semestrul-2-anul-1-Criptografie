#ifndef __Rational_Multiplicative1_Group_h__
#define __Rational_Multiplicative1_Group_h__

#include "Rational_multiplication.h"
class Rational_Multiplicative_Group:public Multiplcative_Group_interface<rational_value>
{
    public:
    Rational_Multiplicative_Group(Rational_Multiplication *);
    ~Rational_Multiplicative_Group();
    rational_value Reverse(rational_value value,rational_value);
    rational_value Get_neutral();
    bool Closed();
    bool Asociative();
    bool Neutral_element();
    bool Comutative();
    bool Inversible(rational_value Inexistent);
};
#endif // __Rational_Multiplicative_Group_h__
