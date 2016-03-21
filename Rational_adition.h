#ifndef __Rational_Adition_h__
#define __Rational_Adition_h__
#include "interface.h"
class Rational_Adition:public Composition_law_interface<rational_value>
{
    int Count();
    rational_value Return_composite(rational_value ,rational_value);
};

#endif // __Rational_Adition_h__
