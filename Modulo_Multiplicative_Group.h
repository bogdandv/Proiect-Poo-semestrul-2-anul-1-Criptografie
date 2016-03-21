#ifndef __modulo_Multiplicative_group_h__
#define __modulo_Multiplicative_group_h__
#include "Moduo_multiplication.h"
class moduloMultiplicative_Group:public Multiplcative_Group_interface<int>
{
    public:
    moduloMultiplicative_Group(modulo_Multiplication *mul_law);
    ~moduloMultiplicative_Group();
    int Reverse(int value,int zero);
    int Get_neutral();
    bool Closed();
    bool Asociative();
    bool Neutral_element();
    bool Comutative();
    bool Inversible(int Inexistent);
};
#endif // __modulo_Multiplicative_group_h__
