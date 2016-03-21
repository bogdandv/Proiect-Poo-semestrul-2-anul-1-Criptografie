#include <iostream>
#include<list>
#include<cstring>
#include<stdlib.h>
#include "Finite_Field.h"
#include "Real_Field.h"
#include "Rational_Field.h"
#include "Modulo_field.h"
#include "Complexe_field.h"
#include "item.h"
using namespace std;


int main()
{
    cout<<"What kind of Field?";
    char *s=new char(1000);
    cin>>s;
    if(strcmp(s,"finite")==0)
    {int n,val,vect[1000],vect1[1000];
        cout<<"How many elements?";
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cout<<i<<"+"<<j<<"=";
                cin>>val;
                vect[i*n+j]=val;
            }
        Finite_Composition_law *fcl=new Finite_Composition_law(n,vect);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cout<<i<<"*"<<j<<"=";
                cin>>val;
                vect1[i*n+j]=val;
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
                {el3=el1/el2;
                 cout<<s<<el3.value;
                }
            s=new char(1000);
            cout<<'\n';
            cin>>s;
        }
    }
    return 0;
}
