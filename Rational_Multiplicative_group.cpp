#include "Rational_Multiplicative_group.h"
#include<iostream>
using namespace std;
    Rational_Multiplicative_Group::Rational_Multiplicative_Group(Rational_Multiplication *mul_law)
    {
        Composition_law=mul_law;
    }
    Rational_Multiplicative_Group::~Rational_Multiplicative_Group()
    {
        delete Composition_law;
    }
    rational_value Rational_Multiplicative_Group::Reverse(rational_value value,rational_value zero)
    {if(value.numarator!=0)
        {
            rational_value temp;
            temp.numarator=value.numitor;
            temp.numitor=value.numarator;
            return temp;
        }
        else {cout<<"!";}
    }
    rational_value Rational_Multiplicative_Group::Get_neutral()
    {
        rational_value temp;
        temp.numarator=1;
        temp.numitor=1;
        return temp;
    }
    bool Rational_Multiplicative_Group::Closed()
    {
        return true;
    }
    bool Rational_Multiplicative_Group::Asociative()
    {
        return true;
    }
    bool Rational_Multiplicative_Group::Neutral_element()
    {
        return true;
    }
    bool Rational_Multiplicative_Group::Comutative()
    {
        return true;
    }
    bool Rational_Multiplicative_Group::Inversible(rational_value Inexistent)
    {
    return true;
    }
