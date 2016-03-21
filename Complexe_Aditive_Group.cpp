   #include "Complexe_Aditive_Group.h"
   complexe_Aditive_Group::complexe_Aditive_Group(complexe_Adition *add_law)
    {
        Composition_law=add_law;
    }
    complexe_Aditive_Group::~complexe_Aditive_Group()
    {
        delete Composition_law;
    }
    complex_value complexe_Aditive_Group::Reverse(complex_value value)
    {
        value.imaginary_part*=-1;
        value.real_part*=-1;
        return value;
    }
    complex_value complexe_Aditive_Group::Get_neutral()
    {
        complex_value temp;
        temp.imaginary_part=0;
        temp.real_part=0;
        return temp;
    }
    bool complexe_Aditive_Group::Closed()
    {
        return true;
    }
    bool complexe_Aditive_Group::Asociative()
    {
        return true;
    }
    bool complexe_Aditive_Group::Neutral_element()
    {
        return true;
    }
    bool complexe_Aditive_Group::Comutative()
    {
        return true;
    }
    bool complexe_Aditive_Group::Inversible()
    {
    return true;
    }
