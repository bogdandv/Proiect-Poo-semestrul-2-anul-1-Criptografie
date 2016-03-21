#ifndef __Real_multiplication_h__
#define __Real_multiplication_h__

#include "interface.h"
class Real_Multiplication:public Composition_law_interface<double>
{
    int Count();
    double Return_composite(double First_value,double Second_value);
};
#endif // __Real_multiplication_h__
