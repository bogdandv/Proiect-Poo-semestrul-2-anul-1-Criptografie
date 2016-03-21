#ifndef __Real_aditive_gropu_h__
#define __Real_aditive_gropu_h__
#include "Real_adition.h"
class Real_Aditive_Group:public Aditive_Group_interface<double>
{public:
    Real_Aditive_Group(Real_Adition *);
    ~Real_Aditive_Group();
    double Reverse(double);
    double Get_neutral();
    bool Closed();
    bool Asociative();
    bool Neutral_element();
    bool Comutative();
    bool Inversible();
};

#endif // __Real_aditive_gropu_h__
