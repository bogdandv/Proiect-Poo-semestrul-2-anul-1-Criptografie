#include "Real_aditive_group.h"
    Real_Aditive_Group::Real_Aditive_Group(Real_Adition *add_law)
    {
        Composition_law=add_law;
    }
    Real_Aditive_Group::~Real_Aditive_Group()
    {
        delete Composition_law;
    }
    double Real_Aditive_Group::Reverse(double value)
    {
        return -value;
    }
    double Real_Aditive_Group::Get_neutral()
    {
        return 0;
    }
    bool Real_Aditive_Group::Closed()
    {
        return true;
    }
    bool Real_Aditive_Group::Asociative()
    {
        return true;
    }
    bool Real_Aditive_Group::Neutral_element()
    {
        return true;
    }
    bool Real_Aditive_Group::Comutative()
    {
        return true;
    }
    bool Real_Aditive_Group::Inversible()
    {
    return true;
    }
