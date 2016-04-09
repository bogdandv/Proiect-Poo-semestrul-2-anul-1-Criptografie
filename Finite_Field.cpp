#include <string.h>
#include<sstream>
using namespace std;
#include "Finite_Field.h"
    Finite_Field::Finite_Field(Finite_Composition_law *aditive_law,Finite_Composition_law *multiplicative_law)
    {
        Finite_Aditive_Group *fag=new Finite_Aditive_Group(aditive_law);
        Aditive_Group=fag;
        Finite_Multiplicative_Group *fmg=new Finite_Multiplicative_Group(multiplicative_law);
        Multiplicative_Group=fmg;
    }
    Finite_Field::~Finite_Field()
    {
        delete Aditive_Group;
        delete Multiplicative_Group;
    }
    bool Finite_Field::Distributive()
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
    int Finite_Field::Value_From_String(std::istringstream &s)
    {
        int number;
        s>>number;
        return number;
    }
    bool Finite_Field::Is_Field()
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
