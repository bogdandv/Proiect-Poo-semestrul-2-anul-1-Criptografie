#ifndef __modulo_Adition_h__
#define __modulo_Adition_h__
#include "interface.h"
class modulo_Adition:public Composition_law_interface<int>
{
    int modulo;
    public:
    modulo_Adition(int);
    int Count();
    int Return_composite(int,int);
};
#endif // __modulo_Adition_h__
