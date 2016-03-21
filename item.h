#ifndef __element_h__
#define __element_h__
#include "interface.h"
#include <iostream>
using namespace std;
template <class Value_from_set>
class  element:public element_interface<Value_from_set>
{
    public:
          element(Field_interface<Value_from_set> *field,Value_from_set value)
    {
        this->Field= field;
        this->value=value;
    }
      ~element()
    {
        //delete this->Field;
    }
     element   operator +( element second)
    {if(this->Field!=second.Field)
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
        cout<<"!";
        rez=this->Field->Multiplicative_Group->Reverse(second.value,this->Field->Aditive_Group->Get_neutral());
        rez=this->Field->Multiplicative_Group->Composition_law->Return_composite(this->value,rez);
         element temp(this->Field,rez);
        return (*this)*temp;
    }
};
#endif // __element_h__
