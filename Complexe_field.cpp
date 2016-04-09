#include "Complexe_field.h"
#include<iostream>
    complexe_Field::complexe_Field()
    {
        complexe_Adition *aditive_law=new complexe_Adition();
        complexe_Multiplication *multiplicative_law=new complexe_Multiplication();
        complexe_Aditive_Group *fag=new complexe_Aditive_Group(aditive_law);
        Aditive_Group=fag;
        complexe_Multiplicative_Group *fmg=new complexe_Multiplicative_Group(multiplicative_law);
        Multiplicative_Group=fmg;
        //std::cout<<"!";
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

    complex_value complexe_Field::Value_From_String(std::istringstream &s)
    {
        char t;
        int first;
        s>>first;
        complex_value cv;
        if(s.peek()=='i')
        {
            s>>t;
            cv.imaginary_part=first;
            cv.real_part=0;
        }
        else
        {
            cv.imaginary_part=0;
            cv.real_part=first;
        }
        return cv;
    }

