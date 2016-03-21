#ifndef __Modulo_aditive_group_h__
#define __Modulo_aditive_group_h__
#include "Modulo_Adition.h"
class moduloAditive_Group:public Aditive_Group_interface<int>
{public:
    moduloAditive_Group(modulo_Adition *add_law);
    ~moduloAditive_Group();
    int Reverse(int value);
    int Get_neutral();
    bool Closed();
    bool Asociative();
    bool Neutral_element();
    bool Comutative();
    bool Inversible();
};
#endif // __Modulo_aditive_group_h__
