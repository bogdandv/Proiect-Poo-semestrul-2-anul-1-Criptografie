#ifndef __Rational_field_h__
#define __Rational_field_h__
#include "Rational_Aditive_group.h"
#include "Rational_Multiplicative_group.h"
class Rational_Field:public Field_interface<rational_value>
{
    public:
    Rational_Field();
    ~Rational_Field();
    bool Distributive();
    bool Is_Field();
    rational_value Value_From_String(std::istringstream &s);
};

#endif // __Rational_field_h__
