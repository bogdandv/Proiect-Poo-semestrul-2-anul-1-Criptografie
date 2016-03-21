    #include "Modulo_Multiplicative_Group.h"
    #include <iostream>
    using namespace std;
    moduloMultiplicative_Group::moduloMultiplicative_Group(modulo_Multiplication *mul_law)
    {
        Composition_law=mul_law;
    }
    moduloMultiplicative_Group::~moduloMultiplicative_Group()
    {
        delete Composition_law;
    }
    int moduloMultiplicative_Group::Reverse(int value,int zero)
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
    int moduloMultiplicative_Group::Get_neutral()
    {
        return 1;
    }
    bool moduloMultiplicative_Group::Closed()
    {
        return true;
    }
    bool moduloMultiplicative_Group::Asociative()
    {
        return true;
    }
    bool moduloMultiplicative_Group::Neutral_element()
    {
        return true;
    }
    bool moduloMultiplicative_Group::Comutative()
    {
        return true;
    }
    bool moduloMultiplicative_Group::Inversible(int Inexistent)
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
