#ifndef __modulo_Multiplication_h__
#define __modulo_Multiplication_h__
#include "interface.h"
class modulo_Multiplication:public Composition_law_interface<int>
{

    int modulo;
    public:
    modulo_Multiplication(int);
    int Count();
    int Return_composite(int,int);
};
#endif // __modulo_Multiplication_h__
