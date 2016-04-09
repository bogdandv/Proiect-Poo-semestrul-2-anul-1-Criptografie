#ifndef __interface_h_included__//__ ?
#define __interface_h_included__
#include<string>
#include<sstream>
class rational_value
{
    public:
    int numitor;
    int numarator;
    bool operator ==(rational_value op2)
    {
        if(this->numarator==op2.numarator && this->numitor==op2.numitor)
            return true;
        return false;
    }
};
class complex_value
{
    public:
    double real_part;
    double imaginary_part;
    bool operator ==(complex_value op2)
    {
    if(this->real_part==op2.real_part && this->imaginary_part==op2.imaginary_part)
            return true;
        return false;
    }
};
template <class Value_form_set>
class Composition_law_interface
{
    public:
    virtual Value_form_set Return_composite(Value_form_set First_value,Value_form_set Second_value)=0;
    virtual int Count()=0;
};

template <class Value_from_set>
class Aditive_Group_interface
{
    public:
    Composition_law_interface<Value_from_set> *Composition_law;
    virtual bool Closed()=0;
    virtual bool Asociative()=0;
    virtual bool Neutral_element()=0;
    virtual bool Comutative()=0;
    virtual bool Inversible()=0;
    virtual Value_from_set Get_neutral()=0;
    virtual Value_from_set Reverse(Value_from_set)=0;
};
template <class Value_from_set>
class Multiplcative_Group_interface
{
    public:
    Composition_law_interface<Value_from_set> *Composition_law;
    virtual bool Closed()=0;
    virtual bool Asociative()=0;
    virtual bool Neutral_element()=0;
    virtual bool Comutative()=0;
    virtual bool Inversible(Value_from_set)=0;
    virtual Value_from_set Get_neutral()=0;
    virtual Value_from_set Reverse(Value_from_set,Value_from_set)=0;
};

template <class Value_from_set>
class Field_interface
{
public:
Aditive_Group_interface<Value_from_set> *Aditive_Group;
Multiplcative_Group_interface<Value_from_set> *Multiplicative_Group;
virtual bool Distributive()=0;
virtual bool Is_Field()=0;
virtual Value_from_set Value_From_String(std::istringstream &s)=0;
};

template <class Value_from_set>
class element_interface
{
    public:
    Field_interface<Value_from_set> *Field;
    Value_from_set value;
    //overload +,-,*,:
};
#endif // __finite_h_included__
