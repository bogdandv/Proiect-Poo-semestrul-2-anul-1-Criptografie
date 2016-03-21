#ifndef __Complexe_field_h__
#define __Complexe_field_h__
#include "Complexe_Aditive_Group.h"
#include "Complexe_Multiplicative_Group.h"
class complexe_Field:public Field_interface<complex_value>
{
    public:
    complexe_Field();
    ~complexe_Field();
    bool Distributive();
    bool Is_Field();
};

#endif // __Complexe_field_h__
