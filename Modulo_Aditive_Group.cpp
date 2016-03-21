#include "Modulo_Aditive_Group.h"
    moduloAditive_Group::moduloAditive_Group(modulo_Adition *add_law)
    {
        Composition_law=add_law;
    }
    moduloAditive_Group::~moduloAditive_Group()
    {
        delete Composition_law;
    }
    int moduloAditive_Group::Reverse(int value)
    {
        while(value<0)
            value=Composition_law->Return_composite(Composition_law->Count(),value);
        value=value*(-1);
        while(value<0)
            value=Composition_law->Return_composite(Composition_law->Count(),value);
    }
    int moduloAditive_Group::Get_neutral()
    {
        return 0;
    }
    bool moduloAditive_Group::Closed()
    {
        return true;
    }
    bool moduloAditive_Group::Asociative()
    {
        return true;
    }
    bool moduloAditive_Group::Neutral_element()
    {
        return true;
    }
    bool moduloAditive_Group::Comutative()
    {
        return true;
    }
    bool moduloAditive_Group::Inversible()
    {
    return true;
    }
