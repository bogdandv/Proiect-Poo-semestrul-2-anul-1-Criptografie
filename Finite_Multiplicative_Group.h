#ifndef __Finite_Multiplicative_Group_h__
#define __Finite_Multiplicative_Group_h__
#include "Finite_composition_law.h"
class Finite_Multiplicative_Group:public Multiplcative_Group_interface<int>
{
private:
    int neutral_element;
public:
     int Get_neutral();
    int Reverse(int,int);
    Finite_Multiplicative_Group(Finite_Composition_law *finite_law);
    ~Finite_Multiplicative_Group();
    bool Closed();
    bool Asociative();
    bool Neutral_element();
    bool Comutative();
    bool Inversible(int zero);
};

#endif // __Finite_Multiplicative_Group_h__
