#include <iostream>
#include<list>
#include<cstring>
#include<stdlib.h>
using namespace std;

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

class Finite_Composition_law:public Composition_law_interface<int>
{
    int *Caylay_table;
    int Number_of_elements;
    public:
    int Count()
    {
        return Number_of_elements;
    }
    int Return_composite(int First_value,int Second_value)
    {
        return Caylay_table[First_value*Number_of_elements+Second_value];
    }
    Finite_Composition_law(int number_of_elements,int *caylay_table)
    {
        Number_of_elements=number_of_elements;
        Caylay_table=caylay_table;
    }
    ~Finite_Composition_law()
    {
        delete Caylay_table;
    }
};

class Finite_Aditive_Group:public Aditive_Group_interface<int>
{
private:
    int neutral_element=-1;
public:
    Finite_Aditive_Group(Finite_Composition_law *finite_law)
    {
        Composition_law=finite_law;
    }
    ~Finite_Aditive_Group()
    {
        delete Composition_law;
    }
    int Get_neutral()
    {
        Neutral_element();
        return neutral_element;
    }
     int Reverse(int value)
    {int temp=Get_neutral();
    if(temp==-1)
        {cout<<"!";
            //error
        }
    for(int i=0;i<Composition_law->Count() ;i++)
        if(Composition_law->Return_composite(i,value)==temp && Composition_law->Return_composite(value,i)==temp)
            return i;
    //error
    cout<<"!";
    return -1;
    }
    bool Closed()
    {
        for(int i=0;i<Composition_law->Count() ;i++)
            for(int j=0;j<Composition_law->Count() ;j++)
                if(Composition_law->Return_composite(i,j) <0 || Composition_law->Return_composite(i,j) >=Composition_law->Count())
                    return false;
        return true;
    }
    bool Asociative()
    {
        for(int i=0;i<Composition_law->Count() ;i++)
            for(int j=0;j<Composition_law->Count() ;j++)
                for(int k=0;k<Composition_law->Count();k++)
                {
                if(Composition_law->Return_composite(Composition_law->Return_composite(i,j),k) !=Composition_law->Return_composite(i,Composition_law->Return_composite(j,k)))
                    {
                    return false;
                    }
                }
        return true;
    }
    bool Neutral_element()
    {bool found=false;
        for(int i=0;i<Composition_law->Count() ;i++)
            {found=true;
            for(int j=0;j<Composition_law->Count() ;j++)
                {
                    if(Composition_law->Return_composite(i,j)!=j || Composition_law->Return_composite(j,i)!=j)
                        {found=false;
                        j=Composition_law->Count();
                        }
                }
            if(found==true)
                {
                 neutral_element=i;
                 return true;
                }
            }
        return false;
    }
    bool Comutative()
    {
        for(int i=0;i<Composition_law->Count() ;i++)
            for(int j=0;j<Composition_law->Count() ;j++)
                if(Composition_law->Return_composite(i,j)!=Composition_law->Return_composite(j,i))
                    return false;
        return true;
    }
    bool Inversible()
    {bool invers=true;
        if(!Neutral_element())
            return false;
        for(int i=0;i<Composition_law->Count() ;i++)
            {invers=false;
            for(int j=0;j<Composition_law->Count() ;j++)
                {
                if(Composition_law->Return_composite(i,j)==neutral_element && Composition_law->Return_composite(j,i)==neutral_element)
                    invers=true;
                }
            if(!invers)
                return false;
            }
    return true;
    }
};

class Finite_Multiplicative_Group:public Multiplcative_Group_interface<int>
{
private:
    int neutral_element;
public:
     int Get_neutral()
    {
        Neutral_element();
        return neutral_element;
    }
    int Reverse(int value,int zero)
    {
        int temp=Get_neutral();
        if(temp==-1 || value==zero)
        {
            //error
        cout<<"!";
        }
        for(int i=0;i<Composition_law->Count() ;i++)
            if(Composition_law->Return_composite(i,value)==temp && Composition_law->Return_composite(value,i)==temp)
                return i;
        //error
        cout<<"!";
        return -1;
    }
    Finite_Multiplicative_Group(Finite_Composition_law *finite_law)
    {
        Composition_law=finite_law;
    }
    ~Finite_Multiplicative_Group()
    {
        delete Composition_law;
    }
    bool Closed()
    {
        for(int i=0;i<Composition_law->Count() ;i++)
            for(int j=0;j<Composition_law->Count() ;j++)
                if(Composition_law->Return_composite(i,j) <0 || Composition_law->Return_composite(i,j) >=Composition_law->Count())
                    return false;
        return true;
    }
    bool Asociative()
    {
        for(int i=0;i<Composition_law->Count() ;i++)
            for(int j=0;j<Composition_law->Count() ;j++)
                for(int k=0;k<Composition_law->Count();k++)
                {
                if(Composition_law->Return_composite(Composition_law->Return_composite(i,j),k) !=Composition_law->Return_composite(i,Composition_law->Return_composite(j,k)))
                    {
                    return false;
                    }
                }
        return true;
    }
    bool Neutral_element()
    {bool found=false;
        for(int i=0;i<Composition_law->Count() ;i++)
            {found=true;
            for(int j=0;j<Composition_law->Count() ;j++)
                {
                    if(Composition_law->Return_composite(i,j)!=j || Composition_law->Return_composite(j,i)!=j)
                        {found=false;
                        j=Composition_law->Count();
                        }
                }
            if(found==true)
                {
                 neutral_element=i;
                 return true;
                }
            }
        return false;
    }
    bool Comutative()
    {
        for(int i=0;i<Composition_law->Count() ;i++)
            for(int j=0;j<Composition_law->Count() ;j++)
                if(Composition_law->Return_composite(i,j)!=Composition_law->Return_composite(j,i))
                    return false;
        return true;
    }
    bool Inversible(int zero)
    {bool invers=true;
        if(!Neutral_element())
            return false;
        for(int i=0;i<Composition_law->Count() ;i++)
            {if(i!=zero)
                {invers=false;
                for(int j=0;j<Composition_law->Count() ;j++)
                    {
                    if(Composition_law->Return_composite(i,j)==neutral_element && Composition_law->Return_composite(j,i)==neutral_element)
                        invers=true;
                    }
                if(!invers)
                    return false;
                }
            }
    return true;
    }
};

class Finite_Field:public Field_interface<int>
{
    public:
    Finite_Field(Finite_Composition_law *aditive_law,Finite_Composition_law *multiplicative_law)
    {
        Finite_Aditive_Group *fag=new Finite_Aditive_Group(aditive_law);
        Aditive_Group=fag;
        Finite_Multiplicative_Group *fmg=new Finite_Multiplicative_Group(multiplicative_law);
        Multiplicative_Group=fmg;
    }
    ~Finite_Field()
    {
        delete Aditive_Group;
        delete Multiplicative_Group;
    }
    bool Distributive()
    {
        for(int i=0;i<Aditive_Group->Composition_law->Count();i++)
            for(int j=0;j<Aditive_Group->Composition_law->Count();j++)
                for(int k=0;k<Aditive_Group->Composition_law->Count();k++)
                    {
                        if( Multiplicative_Group->Composition_law->Return_composite( Aditive_Group->Composition_law->Return_composite(i,j),k)
                           != Aditive_Group->Composition_law->Return_composite( Multiplicative_Group->Composition_law->Return_composite(i,k), Multiplicative_Group->Composition_law->Return_composite(j,k)) )
                            return false;
                        if( Multiplicative_Group->Composition_law->Return_composite(k, Aditive_Group->Composition_law->Return_composite(i,j))
                           != Aditive_Group->Composition_law->Return_composite( Multiplicative_Group->Composition_law->Return_composite(k,i), Multiplicative_Group->Composition_law->Return_composite(k,j)) )
                            return false;
                    }
        return true;
    }
    bool Is_Field()
    {
        if(!Aditive_Group->Closed())
            return false;
        if(!Aditive_Group->Asociative() ||!Aditive_Group->Comutative() ||! Aditive_Group->Neutral_element())
            return false;
        if(!Aditive_Group->Inversible())
            return false;
        if(!Multiplicative_Group->Closed())
            return false;
        if(!Multiplicative_Group->Asociative() ||!Multiplicative_Group->Comutative() ||! Multiplicative_Group->Neutral_element())
            return false;
        if(!Multiplicative_Group->Inversible(Aditive_Group->Get_neutral()))
            return false;
        if(!Distributive())
            return false;
        return true;
    }
};

class Real_Adition:public Composition_law_interface<double>
{
    int Count()
    {
        return -1;
    }
    double Return_composite(double First_value,double Second_value)
    {
        return First_value+Second_value;
    }
};

class Real_Multiplication:public Composition_law_interface<double>
{
    int Count()
    {
        return -1;
    }
    double Return_composite(double First_value,double Second_value)
    {
        return First_value*Second_value;
    }
};

class Real_Aditive_Group:public Aditive_Group_interface<double>
{public:
    Real_Aditive_Group(Real_Adition *add_law)
    {
        Composition_law=add_law;
    }
    ~Real_Aditive_Group()
    {
        delete Composition_law;
    }
    double Reverse(double value)
    {
        return -value;
    }
    double Get_neutral()
    {
        return 0;
    }
    bool Closed()
    {
        return true;
    }
    bool Asociative()
    {
        return true;
    }
    bool Neutral_element()
    {
        return true;
    }
    bool Comutative()
    {
        return true;
    }
    bool Inversible()
    {
    return true;
    }
};

class Real_Multiplicative_Group:public Multiplcative_Group_interface<double>
{
    public:
    Real_Multiplicative_Group(Real_Multiplication *mul_law)
    {
        Composition_law=mul_law;
    }
    ~Real_Multiplicative_Group()
    {
        delete Composition_law;
    }
    double Reverse(double value,double zero)
    {if(value!=0)
        return 1/value;
        else {cout<<"!";return 0;}
    }
    double Get_neutral()
    {
        return 1;
    }
    bool Closed()
    {
        return true;
    }
    bool Asociative()
    {
        return true;
    }
    bool Neutral_element()
    {
        return true;
    }
    bool Comutative()
    {
        return true;
    }
    bool Inversible(double Inexistent)
    {
    return true;
    }
};

class Real_Field:public Field_interface<double>
{
    public:
    Real_Field()
    {
        Real_Adition *aditive_law=new Real_Adition();
        Real_Multiplication *multiplicative_law=new Real_Multiplication();
        Real_Aditive_Group *fag=new Real_Aditive_Group(aditive_law);
        Aditive_Group=fag;
        Real_Multiplicative_Group *fmg=new Real_Multiplicative_Group(multiplicative_law);
        Multiplicative_Group=fmg;
    }
    ~Real_Field()
    {
        delete Multiplicative_Group;
        delete Aditive_Group;
    }
    bool Distributive()
    {
        return true;
    }
    bool Is_Field()
    {
        return true;
    }
};

struct rational_value
{
    int numitor;
    int numarator;
};

//rational
class Rational_Adition:public Composition_law_interface<rational_value>
{
    int Count()
    {
        return -1;
    }
    rational_value Return_composite(rational_value First_value,rational_value Second_value)
    {
        int remainder;
        rational_value temp;
        temp.numitor=First_value.numitor*Second_value.numitor;
        temp.numarator=First_value.numarator*Second_value.numitor+First_value.numitor*Second_value.numarator;
        int temp1,temp2;
        temp1=temp.numitor;
        temp2=temp.numarator;
        remainder=temp1%temp2;
        while(remainder)
        {
            temp1=temp2;
            temp2=remainder;
            remainder=temp1%temp2;
        }
        temp.numarator/=temp2;
        temp.numitor/=temp2;
        return temp;
    }
};

class Rational_Multiplication:public Composition_law_interface<rational_value>
{
    int Count()
    {
        return -1;
    }
    rational_value Return_composite(rational_value First_value,rational_value Second_value)
    {
        rational_value temp;
        temp.numarator=First_value.numarator*Second_value.numarator;
        temp.numitor=First_value.numitor*Second_value.numitor;
        int remainder;
        int temp1,temp2;
        temp1=temp.numitor;
        temp2=temp.numarator;
        remainder=temp1%temp2;
        while(remainder)
        {
            temp1=temp2;
            temp2=remainder;
            remainder=temp1%temp2;
        }
        temp.numarator/=temp2;
        temp.numitor/=temp2;
        return temp;
    }
};

class Rational_Aditive_Group:public Aditive_Group_interface<rational_value>
{public:
    Rational_Aditive_Group(Rational_Adition *add_law)
    {
        Composition_law=add_law;
    }
    ~Rational_Aditive_Group()
    {
        delete Composition_law;
    }
    rational_value Reverse(rational_value value)
    {
        value.numarator*=-1;
        return value;
    }
    rational_value Get_neutral()
    {
        rational_value temp;
        temp.numarator=0;
        temp.numitor=1;
        return temp;
    }
    bool Closed()
    {
        return true;
    }
    bool Asociative()
    {
        return true;
    }
    bool Neutral_element()
    {
        return true;
    }
    bool Comutative()
    {
        return true;
    }
    bool Inversible()
    {
    return true;
    }
};

class Rational_Multiplicative_Group:public Multiplcative_Group_interface<rational_value>
{
    public:
    Rational_Multiplicative_Group(Rational_Multiplication *mul_law)
    {
        Composition_law=mul_law;
    }
    ~Rational_Multiplicative_Group()
    {
        delete Composition_law;
    }
    rational_value Reverse(rational_value value,rational_value zero)
    {if(value.numarator!=0)
        {
            rational_value temp;
            temp.numarator=value.numitor;
            temp.numitor=value.numarator;
            return temp;
        }
        else {cout<<"!";}
    }
    rational_value Get_neutral()
    {
        rational_value temp;
        temp.numarator=1;
        temp.numitor=1;
        return temp;
    }
    bool Closed()
    {
        return true;
    }
    bool Asociative()
    {
        return true;
    }
    bool Neutral_element()
    {
        return true;
    }
    bool Comutative()
    {
        return true;
    }
    bool Inversible(rational_value Inexistent)
    {
    return true;
    }
};

class Rational_Field:public Field_interface<rational_value>
{
    public:
    Rational_Field()
    {
        Rational_Adition *aditive_law=new Rational_Adition();
        Rational_Multiplication *multiplicative_law=new Rational_Multiplication();
        Rational_Aditive_Group *fag=new Rational_Aditive_Group(aditive_law);
        Aditive_Group=fag;
        Rational_Multiplicative_Group *fmg=new Rational_Multiplicative_Group(multiplicative_law);
        Multiplicative_Group=fmg;
    }
    ~Rational_Field()
    {
        delete Aditive_Group;
        delete Multiplicative_Group;
    }
    bool Distributive()
    {
        return true;
    }
    bool Is_Field()
    {
        return true;
    }
};

// /rational

// modulo
class moduloAdition:public Composition_law_interface<int>
{
    int modulo;
    public:
    moduloAdition(int mod)
    {
        modulo=mod;
    }
    int Count()
    {
        return modulo;
    }
    int Return_composite(int First_value,int Second_value)
    {
        return (First_value+Second_value)%modulo;
    }
};

class moduloMultiplication:public Composition_law_interface<int>
{

    int modulo;
    public:
    moduloMultiplication(int mod)
    {
        modulo=mod;
    }
    int Count()
    {
        return modulo;
    }
    int Return_composite(int First_value,int Second_value)
    {
        return (First_value*Second_value)%modulo;
    }
};

class moduloAditive_Group:public Aditive_Group_interface<int>
{public:
    moduloAditive_Group(moduloAdition *add_law)
    {
        Composition_law=add_law;
    }
    ~moduloAditive_Group()
    {
        delete Composition_law;
    }
    int Reverse(int value)
    {
        while(value<0)
            value=Composition_law->Return_composite(Composition_law->Count(),value);
        value=value*(-1);
        while(value<0)
            value=Composition_law->Return_composite(Composition_law->Count(),value);
    }
    int Get_neutral()
    {
        return 0;
    }
    bool Closed()
    {
        return true;
    }
    bool Asociative()
    {
        return true;
    }
    bool Neutral_element()
    {
        return true;
    }
    bool Comutative()
    {
        return true;
    }
    bool Inversible()
    {
    return true;
    }
};

class moduloMultiplicative_Group:public Multiplcative_Group_interface<int>
{
    public:
    moduloMultiplicative_Group(moduloMultiplication *mul_law)
    {
        Composition_law=mul_law;
    }
    ~moduloMultiplicative_Group()
    {
        delete Composition_law;
    }
    int Reverse(int value,int zero)
    {if(value!=0)
        {
            for(int i=0;i<Composition_law->Count();i++)
            {
                if(Composition_law->Return_composite(i,value)==1)
                    return i;
            }
            cout<<"nu exista";
        }
        else {cout<<"!";return 0;}
    }
    int Get_neutral()
    {
        return 1;
    }
    bool Closed()
    {
        return true;
    }
    bool Asociative()
    {
        return true;
    }
    bool Neutral_element()
    {
        return true;
    }
    bool Comutative()
    {
        return true;
    }
    bool Inversible(int Inexistent)
    {int n=Composition_law->Count();
    if(n%2==0)
        return false;
    else
        {
            for(int i=3;i<n/2;i+=2)
                if(n%i==0)
                    return false;
        }
    }
};

class moduloField:public Field_interface<int>
{
    public:
    moduloField(int modulo)
    {
        moduloAdition *aditive_law=new moduloAdition(modulo);
        moduloMultiplication *multiplicative_law=new moduloMultiplication(modulo);
        moduloAditive_Group *fag=new moduloAditive_Group(aditive_law);
        Aditive_Group=fag;
        moduloMultiplicative_Group *fmg=new moduloMultiplicative_Group(multiplicative_law);
        Multiplicative_Group=fmg;
    }
    ~moduloField()
    {
        delete Aditive_Group;
        delete Multiplicative_Group;
    }
    bool Distributive()
    {
        return true;
    }
    bool Is_Field()
    {
        return Multiplicative_Group->Inversible(Aditive_Group->Get_neutral());
    }
};

// /modulo

struct complex_value
{
    double real_part;
    double imaginary_part;
};
//complexe

class complexe_Adition:public Composition_law_interface<complex_value>
{
    int Count()
    {
        return -1;
    }
    complex_value Return_composite(complex_value First_value,complex_value Second_value)
    {
        complex_value temp;
        temp.real_part=First_value.real_part+Second_value.real_part;
        temp.imaginary_part=First_value.imaginary_part+Second_value.imaginary_part;
        return temp;
    }
};

class complexe_Multiplication:public Composition_law_interface<complex_value>
{
    int Count()
    {
        return -1;
    }
    complex_value Return_composite(complex_value First_value,complex_value Second_value)
    {
        complex_value temp;
        temp.real_part=First_value.real_part*Second_value.real_part-First_value.imaginary_part*Second_value.imaginary_part;
        temp.imaginary_part=First_value.real_part*Second_value.imaginary_part+First_value.imaginary_part*Second_value.real_part;
        return temp;
    }
};

class complexe_Aditive_Group:public Aditive_Group_interface<complex_value>
{public:
    complexe_Aditive_Group(complexe_Adition *add_law)
    {
        Composition_law=add_law;
    }
    ~complexe_Aditive_Group()
    {
        delete Composition_law;
    }
    complex_value Reverse(complex_value value)
    {
        value.imaginary_part*=-1;
        value.real_part*=-1;
        return value;
    }
    complex_value Get_neutral()
    {
        complex_value temp;
        temp.imaginary_part=0;
        temp.real_part=0;
        return temp;
    }
    bool Closed()
    {
        return true;
    }
    bool Asociative()
    {
        return true;
    }
    bool Neutral_element()
    {
        return true;
    }
    bool Comutative()
    {
        return true;
    }
    bool Inversible()
    {
    return true;
    }
};

class complexe_Multiplicative_Group:public Multiplcative_Group_interface<complex_value>
{
    public:
    complexe_Multiplicative_Group(complexe_Multiplication *mul_law)
    {
        Composition_law=mul_law;
    }
    ~complexe_Multiplicative_Group()
    {
        delete Composition_law;
    }
    complex_value Reverse(complex_value value,complex_value zero)
    {if(value.imaginary_part!=0 || value.real_part!=0)
        {
            complex_value temp;
            temp.real_part=value.real_part/(value.real_part*value.real_part+value.imaginary_part*value.imaginary_part);
            temp.imaginary_part=-value.imaginary_part/(value.real_part*value.real_part+value.imaginary_part*value.imaginary_part);
            return temp;
        }
        else {cout<<"Zero Divide";
             complex_value temp;
             temp.imaginary_part=0;
             temp.real_part=0;
             return temp;
             }
    }
    complex_value Get_neutral()
    {
        complex_value temp;
        temp.imaginary_part=0;
        temp.real_part=1;
        return temp;
    }
    bool Closed()
    {
        return true;
    }
    bool Asociative()
    {
        return true;
    }
    bool Neutral_element()
    {
        return true;
    }
    bool Comutative()
    {
        return true;
    }
    bool Inversible(complex_value Inexistent)
    {
    return true;
    }
};

class complexe_Field:public Field_interface<complex_value>
{
    public:
    complexe_Field()
    {
        complexe_Adition *aditive_law=new complexe_Adition();
        complexe_Multiplication *multiplicative_law=new complexe_Multiplication();
        complexe_Aditive_Group *fag=new complexe_Aditive_Group(aditive_law);
        Aditive_Group=fag;
        complexe_Multiplicative_Group *fmg=new complexe_Multiplicative_Group(multiplicative_law);
        Multiplicative_Group=fmg;
    }
    ~complexe_Field()
    {
        delete Aditive_Group;
        delete Multiplicative_Group;
    }
    bool Distributive()
    {
        return true;
    }
    bool Is_Field()
    {
        return true;
    }
};

// /complexe


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
     element operator +( element second)
    {if(this->Field!=second.Field)
            cout<<"Corpuri diferite";
        Value_from_set rez;
        rez=this->Field->Aditive_Group->Composition_law->Return_composite(this->value,second.value);
         element temp (this->Field,rez);
        return temp;
    }
     element operator -()
    {
        Value_from_set rez;
        rez=this->Field->Aditive_Group->Reverse(this->value);
         element temp(this->Field,rez);
        return temp;
    }
     element operator -( element second)
    {
        return (*this)+-second;
    }
     element operator *( element second)
    {   if(this->Field!=second.Field)
            cout<<"Corpuri diferite";
        Value_from_set rez;
        rez=this->Field->Multiplicative_Group->Composition_law->Return_composite(this->value,second.value);
         element temp(this->Field,rez);
        return temp;
    }
     element operator /( element second)
    {   if(this->Field!=second.Field)
            cout<<"Corpuri diferite";
        Value_from_set rez;
        rez=this->Field->Multiplicative_Group->Reverse(second.value,this->Field->Aditive_Group->Get_neutral());
         element temp(this->Field,rez);
        return (*this)*temp;
    }
};
int main()
{
    cout<<"What kind of Field?";
    char *s=new char(1000);
    cin>>s;
    if(strcmp(s,"finite")==0)
    {int n,val,*vect,*vect1;
        cout<<"How many elements?";
        cin>>n;
        vect=new int(n*n+1);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cout<<i<<"+"<<j<<"=";
                cin>>val;
                *(vect+i*n+j)=val;
            }
        Finite_Composition_law *fcl=new Finite_Composition_law(n,vect);
        vect1=new int(n*n+1);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cout<<i<<"*"<<j<<"=";
                cin>>val;
                *(vect1+i*n+j)=val;
            }
        Finite_Composition_law *fcl1=new Finite_Composition_law(n,vect1);
        Finite_Field *ff=new Finite_Field(fcl,fcl1);
        if(!(*ff).Is_Field())
            cout<<"NOT A FIELD\n";
        else cout<<"Is a field\n";
        cin>>s;
        element<int> el1(ff,0),el2(ff,0),el3(ff,0);
        while(strcmp(s,"exit")!=0)
        {
            int fv=0,sv=0;
            int i=0;
            while(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/')
                  fv=fv*10+s[i++]-'0';

            int j=i+1;
            while('0'<=s[j] && s[j]<='9')
                  sv=sv*10+s[j++]-'0';
            el1.value=fv;
            el2.value=sv;
            if(s[i]=='+')
                {el3=el1+el2;
                 cout<<s<<el3.value;
                }
            if(s[i]=='-')
                {el3=el1-el2;
                 cout<<s<<el3.value;
                }
            if(s[i]=='*')
                {el3=el1*el2;
                 cout<<s<<el3.value;
                }
            if(s[i]=='/')
                {el3=el1+el2;
                 cout<<s<<el3.value;
                }
            s=new char(1000);
            cout<<'\n';
            cin>>s;
        }
    }
    return 0;
}
