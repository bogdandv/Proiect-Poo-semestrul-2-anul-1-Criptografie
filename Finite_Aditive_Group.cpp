#include"Finite_Aditive_Group.h"
#include<iostream>
using namespace std;
Finite_Aditive_Group::Finite_Aditive_Group(Finite_Composition_law *finite_law)
    {
        Composition_law=finite_law;
    }
Finite_Aditive_Group::~Finite_Aditive_Group()
    {
        delete Composition_law;
    }
int Finite_Aditive_Group::Get_neutral()
    {
        Neutral_element();
        return neutral_element;
    }
int Finite_Aditive_Group::Reverse(int value)
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
bool Finite_Aditive_Group::Closed()
    {
        for(int i=0;i<Composition_law->Count() ;i++)
            for(int j=0;j<Composition_law->Count() ;j++)
                if(Composition_law->Return_composite(i,j) <0 || Composition_law->Return_composite(i,j) >=Composition_law->Count())
                    return false;
        return true;
    }
bool Finite_Aditive_Group::Asociative()
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
bool Finite_Aditive_Group::Neutral_element()
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
bool Finite_Aditive_Group::Comutative()
    {
        for(int i=0;i<Composition_law->Count() ;i++)
            for(int j=0;j<Composition_law->Count() ;j++)
                if(Composition_law->Return_composite(i,j)!=Composition_law->Return_composite(j,i))
                    return false;
        return true;
    }
bool Finite_Aditive_Group::Inversible()
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
