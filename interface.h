#ifndef __interface_h_included__//__ ?
#define __interface_h_included__
struct rational_value
{
    int numitor;
    int numarator;
};
struct complex_value
{
    double real_part;
    double imaginary_part;
};
template <class Value_form_set>
class Composition_law_interface
{
    public:
    virtual Value_form_set Return_composite(Value_form_set First_value,Value_form_set Second_value){};
    virtual int Count(){};
};

template <class Value_from_set>
class Aditive_Group_interface
{
    public:
    Composition_law_interface<Value_from_set> *Composition_law;
    virtual bool Closed(){};
    virtual bool Asociative(){};
    virtual bool Neutral_element(){};
    virtual bool Comutative(){};
    virtual bool Inversible(){};
    virtual Value_from_set Get_neutral(){};
    virtual Value_from_set Reverse(Value_from_set){};
};
template <class Value_from_set>
class Multiplcative_Group_interface
{
    public:
    Composition_law_interface<Value_from_set> *Composition_law;
    virtual bool Closed(){};
    virtual bool Asociative(){};
    virtual bool Neutral_element(){};
    virtual bool Comutative(){};
    virtual bool Inversible(int){};
    virtual Value_from_set Get_neutral(){};
    virtual Value_from_set Reverse(Value_from_set,Value_from_set){};
};

template <class Value_from_set>
class Field_interface
{
public:
Aditive_Group_interface<Value_from_set> *Aditive_Group;
Multiplcative_Group_interface<Value_from_set> *Multiplicative_Group;
virtual bool Distributive(){};
virtual bool Is_Field(){};
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
