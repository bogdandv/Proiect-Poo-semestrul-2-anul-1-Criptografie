    #include "Rational_field.h"
    Rational_Field::Rational_Field()
    {
        Rational_Adition *aditive_law=new Rational_Adition();
        Rational_Multiplication *multiplicative_law=new Rational_Multiplication();
        Rational_Aditive_Group *fag=new Rational_Aditive_Group(aditive_law);
        Aditive_Group=fag;
        Rational_Multiplicative_Group *fmg=new Rational_Multiplicative_Group(multiplicative_law);
        Multiplicative_Group=fmg;
    }
    Rational_Field::~Rational_Field()
    {
        delete Aditive_Group;
        delete Multiplicative_Group;
    }
    bool Rational_Field::Distributive()
    {
        return true;
    }
    bool Rational_Field::Is_Field()
    {
        return true;
    }
