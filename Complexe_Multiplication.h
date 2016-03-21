#ifndef __Complexe_Multiplication_h__
#define __Complexe_Multiplication_h__
#include "interface.h"
class complexe_Multiplication:public Composition_law_interface<complex_value>
{
    int Count();
    complex_value Return_composite(complex_value First_value,complex_value Second_value);
};

#endif
