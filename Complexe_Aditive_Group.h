#ifndef __Complexe_Aditive_Group__
#define __Complexe_Aditive_Group__
#include "Complexe_Adition.h"
class complexe_Aditive_Group:public Aditive_Group_interface<complex_value>
{public:
    complexe_Aditive_Group(complexe_Adition *add_law);
    ~complexe_Aditive_Group();
    complex_value Reverse(complex_value value);
    complex_value Get_neutral();
    bool Closed();
    bool Asociative();
    bool Neutral_element();
    bool Comutative();
    bool Inversible();
};
#endif // __Complexe_Aditive_Group__
