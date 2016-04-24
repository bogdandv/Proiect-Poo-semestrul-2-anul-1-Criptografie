#include "Real_field.h"
#include<sstream>
#include<string.h>
#include<iostream>
#include <stdlib.h>     /* atof */
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
    double Real_Field::Value_From_String(char *&s)
    {
        double number;
        //std::cout<<" b1 ";
        number=atof(s);
        while(isdigit(*s)|| *s=='e' || *s=='.')
            s++;
        //std::cout<<" b2 ";
        return number;
    }
    bool Real_Field::Is_Field()
    {
        return true;
    }
