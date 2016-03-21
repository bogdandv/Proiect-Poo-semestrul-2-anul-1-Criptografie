#ifndef __Complexe_Adition_h__
#define __Complexe_Adition_h__
#include "interface.h"
class complexe_Adition:public Composition_law_interface<complex_value>
{
    int Count();
    complex_value Return_composite(complex_value First_value,complex_value Second_value);
};
#endif // __Complexe_Adition_h__
