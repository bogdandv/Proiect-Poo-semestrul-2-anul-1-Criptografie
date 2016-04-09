#include "Real_multiplicative_group.h"
#include<iostream>
using namespace std;
    Real_Multiplicative_Group::Real_Multiplicative_Group(Real_Multiplication *mul_law)
    {
        Composition_law=mul_law;
    }
    Real_Multiplicative_Group::~Real_Multiplicative_Group()
    {
        delete Composition_law;
    }
    double Real_Multiplicative_Group::Reverse(double value,double zero)
    {if(value!=0)
        return ((double)1)/value;
        else {cout<<"!";return 0;}
    }
    double Real_Multiplicative_Group::Get_neutral()
    {
        return 1;
    }
    bool Real_Multiplicative_Group::Closed()
    {
        return true;
    }
    bool Real_Multiplicative_Group::Asociative()
    {
        return true;
    }
    bool Real_Multiplicative_Group::Neutral_element()
    {
        return true;
    }
    bool Real_Multiplicative_Group::Comutative()
    {
        return true;
    }
    bool Real_Multiplicative_Group::Inversible(double Inexistent)
    {
    return true;
    }
