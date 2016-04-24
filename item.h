#ifndef __element_h__
#define __element_h__
#include "interface.h"
#include <iostream>
#include<string>
using namespace std;
template <class Value_from_set>
class  element:public element_interface<Value_from_set>
{
    public:
        void Set_value(Value_from_set t1)
        {
            this->value=t1;
        }
        Value_from_set Get_value()
        {
            return (this->value);
        }
        element(Field_interface<Value_from_set> *field)
    {
        this->Field= field;
    }
    element(Field_interface<Value_from_set> *field,Value_from_set value)
    {
        this->Field= field;
        this->value=value;
    }
    element(element<Value_from_set> const &el2)
    {
        this->Field=el2.Field;
        this->value=el2.value;
    }
      ~element()
    {
        //std::cout<<";"<<"\n";
        //delete this->Field;
    }
     element   operator +( element second)
    {
        if(this->Field!=second.Field)
            cout<<"Corpuri diferite";
        Value_from_set rez;
        rez=this->Field->Aditive_Group->Composition_law->Return_composite(this->value,second.value);
         element temp (this->Field,rez);
        return temp;
    }
     element   operator -()
    {
        Value_from_set rez;
        rez=this->Field->Aditive_Group->Reverse(this->value);
         element temp(this->Field,rez);
        return temp;
    }
     element   operator -( element second)
    {
        return (*this)+-second;
    }
     element   operator *( element second)
    {   if(this->Field!=second.Field)
            cout<<"Corpuri diferite";
        Value_from_set rez;
        rez=this->Field->Multiplicative_Group->Composition_law->Return_composite(this->value,second.value);
         element temp(this->Field,rez);
        return temp;
    }
     element   operator /( element second)
    {   if(this->Field!=second.Field)
            cout<<"Corpuri diferite";
        Value_from_set rez;
        if(second.value==this->Field->Aditive_Group->Get_neutral())
            {cout<<"nu divide cu 0!\n";
            return *this;
            }
        //cout<<"!";
        rez=this->Field->Multiplicative_Group->Reverse(second.value,this->Field->Aditive_Group->Get_neutral());
        rez=this->Field->Multiplicative_Group->Composition_law->Return_composite(this->value,rez);
         element temp(this->Field,rez);
        return temp;
    }
    element operator =(element second)
    {
        this->Field=second.Field;
        this->value=second.value;
    }
    void FromString(char *&s)
    {
        this->value=this->Field->Value_From_String(s);
    }
};
#endif // __element_h__
