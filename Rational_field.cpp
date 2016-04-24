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
    rational_value Rational_Field::Value_From_String(char *&s)
    {
        int number;
        while(isdigit(*s))
        {
            number=number*10+*s-'0';
            s++;
        }
        rational_value rv;
        rv.numarator=number;
        rv.numitor=1;
        return rv;
    }
