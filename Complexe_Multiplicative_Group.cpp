    #include "Complexe_Multiplicative_Group.h"
    #include <iostream>
    using namespace std;
    complexe_Multiplicative_Group::complexe_Multiplicative_Group(complexe_Multiplication *mul_law)
    {
        Composition_law=mul_law;
    }
    complexe_Multiplicative_Group::~complexe_Multiplicative_Group()
    {
        delete Composition_law;
    }
    complex_value complexe_Multiplicative_Group::Reverse(complex_value value,complex_value zero)
    {if(value.imaginary_part!=0 || value.real_part!=0)
        {
            complex_value temp;
            temp.real_part=value.real_part/(value.real_part*value.real_part+value.imaginary_part*value.imaginary_part);
            temp.imaginary_part=-value.imaginary_part/(value.real_part*value.real_part+value.imaginary_part*value.imaginary_part);
            return temp;
        }
        else {cout<<"Zero Divide";
             complex_value temp;
             temp.imaginary_part=0;
             temp.real_part=0;
             return temp;
             }
    }
    complex_value complexe_Multiplicative_Group::Get_neutral()
    {
        complex_value temp;
        temp.imaginary_part=0;
        temp.real_part=1;
        return temp;
    }
    bool complexe_Multiplicative_Group::Closed()
    {
        return true;
    }
    bool complexe_Multiplicative_Group::Asociative()
    {
        return true;
    }
    bool complexe_Multiplicative_Group::Neutral_element()
    {
        return true;
    }
    bool complexe_Multiplicative_Group::Comutative()
    {
        return true;
    }
    bool complexe_Multiplicative_Group::Inversible(complex_value Inexistent)
    {
    return true;
    }
