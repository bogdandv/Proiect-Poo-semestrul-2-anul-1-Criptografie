#ifndef __Real_field_h__
#define __Real_field_h__

#include "Real_aditive_group.h"
#include "Real_multiplicative_group.h"
class Real_Field:public Field_interface<double>
{
    public:
    Real_Field();
    ~Real_Field();
    bool Distributive();
    bool Is_Field();
};
#endif // __Real_field_h__
