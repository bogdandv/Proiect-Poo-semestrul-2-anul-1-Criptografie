#ifndef __modulo_Field_h__
#define __modulo_Field_h__
#include "Modulo_Aditive_Group.h"
#include "Modulo_Multiplicative_Group.h"
class modulo_Field:public Field_interface<int>
{
    public:
    modulo_Field(int modulo);
    ~modulo_Field();
    bool Distributive();
    bool Is_Field();
    int Value_From_String(std::istringstream &s);
};

#endif // __modulo_Field_h__

