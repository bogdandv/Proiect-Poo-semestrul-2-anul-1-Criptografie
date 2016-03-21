#ifndef __Complexe_Multiplivative_Group_h__
#define __Complexe_Multiplivative_Group_h__
#include "Complexe_Multiplication.h"
class complexe_Multiplicative_Group:public Multiplcative_Group_interface<complex_value>
{
    public:
    complexe_Multiplicative_Group(complexe_Multiplication *mul_law);
    ~complexe_Multiplicative_Group();
    complex_value Reverse(complex_value,complex_value);
    bool Closed();
    bool Asociative();
    bool Neutral_element();
    bool Comutative();
    bool Inversible(complex_value);
    complex_value Get_neutral();
};

#endif // __Complexe_Multiplivative_Group_h__
