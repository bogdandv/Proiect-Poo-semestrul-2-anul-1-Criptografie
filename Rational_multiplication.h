#ifndef __Rational_Multiplication_h__
#define __Rational_Multiplication_h__
#include "interface.h"
class Rational_Multiplication:public Composition_law_interface<rational_value>
{
    int Count();
    rational_value Return_composite(rational_value First_value,rational_value Second_value);
};
#endif // __RAtional_Multiplication_h__
