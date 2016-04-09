#ifndef __Finite_field_h__
#define __Finite_field_h__

#include "Finite_Aditive_Group.h"
#include "Finite_Multiplicative_Group.h"
#include "Finite_composition_law.h"
class Finite_Field:public Field_interface<int>
{
    public:
    Finite_Field(Finite_Composition_law*,Finite_Composition_law*);
    ~Finite_Field();
    bool Distributive();
    bool Is_Field();
    int Value_From_String(std::istringstream&);
};
#endif // __Finite_field_h__
