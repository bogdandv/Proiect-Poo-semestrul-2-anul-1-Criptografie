#include "Complexe_field.h"
    complexe_Field::complexe_Field()
    {
        complexe_Adition *aditive_law=new complexe_Adition();
        complexe_Multiplication *multiplicative_law=new complexe_Multiplication();
        complexe_Aditive_Group *fag=new complexe_Aditive_Group(aditive_law);
        Aditive_Group=fag;
        complexe_Multiplicative_Group *fmg=new complexe_Multiplicative_Group(multiplicative_law);
        Multiplicative_Group=fmg;
    }
    complexe_Field::~complexe_Field()
    {
        delete Aditive_Group;
        delete Multiplicative_Group;
    }
    bool complexe_Field::Distributive()
    {
        return true;
    }
    bool complexe_Field::Is_Field()
    {
        return true;
    }

