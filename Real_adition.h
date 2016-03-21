#ifndef __Real_adition_h__
#define __Real_adition_h__
#include "interface.h"
class Real_Adition:public Composition_law_interface<double>
{
    int Count();
    double Return_composite(double First_value,double Second_value);
};

#endif // __Real_adition_h__
