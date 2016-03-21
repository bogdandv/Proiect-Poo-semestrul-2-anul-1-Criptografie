#ifndef __Finite_aditive_group_h_included__
#define __Finite_aditive_group_h_included__
#include "Finite_composition_law.h"
class Finite_Aditive_Group:public Aditive_Group_interface<int>
{
private:
    int neutral_element=-1;
public:
    Finite_Aditive_Group(Finite_Composition_law *);
    ~Finite_Aditive_Group();
    int Get_neutral();
     int Reverse(int);
    bool Closed();
    bool Asociative();
    bool Neutral_element();
    bool Comutative();
    bool Inversible();
};
#endif
