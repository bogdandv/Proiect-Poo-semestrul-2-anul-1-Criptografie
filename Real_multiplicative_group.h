#ifndef __Real_multiplicative_group_h__
#define __Real_multiplicative_group_h__
#include "Real_multiplication.h"
class Real_Multiplicative_Group:public Multiplcative_Group_interface<double>
{
    public:
    Real_Multiplicative_Group(Real_Multiplication *);
    ~Real_Multiplicative_Group();
    double Reverse(double,double);
    double Get_neutral();
    bool Closed();
    bool Asociative();
    bool Neutral_element();
    bool Comutative();
    bool Inversible(double);
};

#endif // __Real_multiplicative_group
