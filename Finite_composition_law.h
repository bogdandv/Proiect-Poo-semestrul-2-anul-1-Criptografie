#ifndef __Finite_composition_law_h_included__
#define __Finite_composition_law_h_included__
#include "interface.h"
class Finite_Composition_law:public Composition_law_interface<int>
{
    int *Caylay_table;
    int Number_of_elements;
    public:
    int Count();
    int Return_composite(int,int);
    Finite_Composition_law(int ,int *);
    ~Finite_Composition_law();
};
#endif // __Finite_composition_haw_h_included__
