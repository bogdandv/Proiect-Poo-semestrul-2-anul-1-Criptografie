#ifndef __Rational_Aditive_Group_h__
#define __Rational_Aditive_Group_h__
#include "Rational_adition.h"
class Rational_Aditive_Group:public Aditive_Group_interface<rational_value>
{public:
    Rational_Aditive_Group(Rational_Adition *add_law);
    ~Rational_Aditive_Group();
    rational_value Reverse(rational_value value);
    rational_value Get_neutral();
    bool Closed();
    bool Asociative();
    bool Neutral_element();
    bool Comutative();
    bool Inversible();
};
#endif
