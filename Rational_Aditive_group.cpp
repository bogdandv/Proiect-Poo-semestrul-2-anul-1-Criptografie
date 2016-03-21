#include "Rational_Aditive_group.h"
    Rational_Aditive_Group::Rational_Aditive_Group(Rational_Adition *add_law)
    {
        Composition_law=add_law;
    }
    Rational_Aditive_Group::~Rational_Aditive_Group()
    {
        delete Composition_law;
    }
    rational_value Rational_Aditive_Group::Reverse(rational_value value)
    {
        value.numarator*=-1;
        return value;
    }
    rational_value Rational_Aditive_Group::Get_neutral()
    {
        rational_value temp;
        temp.numarator=0;
        temp.numitor=1;
        return temp;
    }
    bool Rational_Aditive_Group::Closed()
    {
        return true;
    }
    bool Rational_Aditive_Group::Asociative()
    {
        return true;
    }
    bool Rational_Aditive_Group::Neutral_element()
    {
        return true;
    }
    bool Rational_Aditive_Group::Rational_Aditive_Group::Comutative()
    {
        return true;
    }
    bool Rational_Aditive_Group::Inversible()
    {
    return true;
    }
