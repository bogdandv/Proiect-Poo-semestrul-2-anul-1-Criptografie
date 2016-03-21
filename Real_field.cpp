#include "Real_field.h"
Real_Field::Real_Field()
    {
        Real_Adition *aditive_law=new Real_Adition();
        Real_Multiplication *multiplicative_law=new Real_Multiplication();
        Real_Aditive_Group *fag=new Real_Aditive_Group(aditive_law);
        Aditive_Group=fag;
        Real_Multiplicative_Group *fmg=new Real_Multiplicative_Group(multiplicative_law);
        Multiplicative_Group=fmg;
    }
    Real_Field::~Real_Field()
    {
        delete Multiplicative_Group;
        delete Aditive_Group;
    }
    bool Real_Field::Distributive()
    {
        return true;
    }
    bool Real_Field::Is_Field()
    {
        return true;
    }
