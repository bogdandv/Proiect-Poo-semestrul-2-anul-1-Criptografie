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
#include<string>
#include<sstream>
#include<stack>
using namespace std;
template<class Value_from_set>
class Expression_evaluater
{
    //char *Buffer;
   char * Buffer=new char[100];
    Field_interface<Value_from_set> *field;
    int operator_priority(char op)
    {
        if(op=='*'||op=='/')
            return 2;
        if(op=='+'||op=='-')
            return 1;
        return 0;
    }

    istringstream _istringstream;
    void Buffer_to_postfix()
    {  stack<char> _stack;
        char t;
       // cout<<"<?";
        char *ori=Buffer;
       // cout<<"|?";
        char *new_Buffer=new char[100];
        char *begining=new_Buffer;
       // cout<<"@";
        while(*ori!='\0')
        {//cout<<"\" ";
            t=*ori;
            ori++;
            while(t==' ')
               {//cout<<"D0";
               if(*ori!='\0')
                {t=*ori;
                    ori++;
                }
               }
            if(isdigit(t))
            {  // cout<<"D1";
                *new_Buffer=t;
                new_Buffer++;
                while(*ori!='\0'&&*ori!=' ' && *ori!='+' && *ori!='-' &&*ori!='*' && *ori!='/' && *ori!='(' && *ori!=')')
                {  if(*ori!='\0')
                    {t=*ori;
                    ori++;
                    }
                   *new_Buffer=t;
                   new_Buffer++;
                }
                *new_Buffer=' ';
                new_Buffer++;
            }
            if(t=='(')
            {//cout<<"D2";
                _stack.push(t);
            }
            if(t==')')
            {//cout<<"D3";
                while(_stack.size()>0 &&_stack.top()!='(')
                {
                    *new_Buffer=_stack.top();
                    _stack.pop();
                    new_Buffer++;
                }
                if(_stack.size()>0)
                    _stack.pop();
            }
            if(t=='+' || t=='-'|| t=='*' ||t=='/' )
            {
            //cout<<"D4";
                if(_stack.size()==0)
                {
                    _stack.push(t);
                }
                else
                {
                    char tmp=_stack.top();
                    _stack.pop();
                    bool ok=1;
                    while( operator_priority(tmp)>=operator_priority(t) && ok)
                    {
                        *new_Buffer=tmp;
                        new_Buffer++;

                        if(_stack.size()>0)
                            {tmp=_stack.top();
                            _stack.pop();
                            }
                        else ok=0;
                    }
                    if(ok)
                        _stack.push(tmp);
                    _stack.push(t);
                }
            }
        }
        while(_stack.size())
        {
            *new_Buffer=_stack.top();
            _stack.pop();
            new_Buffer++;
        }
       // cout<<"HERE I AM";
        *new_Buffer='#';
        new_Buffer++;
        *new_Buffer='\0';
        Buffer=begining;
        //cout<<Buffer<<"\n";
        if(!_stack.empty())
            cout<<"HELLO";
    }
public:
    Expression_evaluater(Field_interface<Value_from_set> *myf)
    {
        field=myf;
    }
    element<Value_from_set> Evaluate(char *expression)
    {
        char t;
        stack<element<Value_from_set> > _stack;
        strcpy(Buffer,expression);
        Buffer_to_postfix();
        //cout<<"IOP";
        char *iter=Buffer;
        int t1;
        while(*iter!='\0')
        {//cout<<"L";
            if(*iter=='#')
            {
                break;
            }
            if(isdigit(*iter))
            {
                Value_from_set el1;
                //cout<<"beg ";
                el1=field->Value_From_String(iter);
                //cout<<" end\n";

                element<Value_from_set> temp(field,el1);
                _stack.push(temp);
            }
            if(*iter==' ')
            {
                //cout<<"!";
                iter++;
            }
            if(*iter=='+' || *iter=='-' || *iter=='*' || *iter=='/')
            {//cout<<"?";
                 element<Value_from_set>  op1(field),op2(field),temp(field);
                op1=_stack.top();
                _stack.pop();
                op2=_stack.top();
                _stack.pop();

                if(*iter=='+')
                    temp=op2+op1;
                if(*iter=='-')
                    temp=op2-op1;
                if(*iter=='*')
                    temp=op2*op1;
                if(*iter=='/')
                    temp=op2/op1;
                _stack.push(temp);
              //  cout<<"I am groot "<<*iter<<"\n";
                iter++;
                //cout<<*iter;
            }
        }
      //  cout<<"ok\n";
        element<Value_from_set> op1(field);
        op1.Set_value(_stack.top().Get_value());
        while(!_stack.empty())
            _stack.pop();
       // cout<<"ok1\n";
        *expression=NULL;
        *iter=NULL;
        return op1;
    }
};

int main()
{
    cout<<"!";
    cout<<"What kind of Field?";
    char *s=new char[1000];
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
        Expression_evaluater<int> my_expression_evaluater(ff);
        if(!(*ff).Is_Field())
            cout<<"NOT A FIELD\n";
        else cout<<"Is a field\n";
        cin.get();
        cin.get(s,1000);

        while(!strcmp(s,"exit")==0)
        {
            element<int> a=my_expression_evaluater.Evaluate(s);
            cout<<a.Get_value()<<"\n";
            cin.get();
            cin.get(s,1000);

        }
    }
    if(strcmp(s,"rational")==0)
    {
        Rational_Field *ff=new Rational_Field();
        Expression_evaluater<rational_value> my_expression_evaluater(ff);
        if(!(*ff).Is_Field())
            cout<<"NOT A FIELD\n";
        else cout<<"Is a field\n";
        cin.get();
        cin.get(s,1000);
        while(!strcmp(s,"exit")==0)
        {
            element<rational_value> a=my_expression_evaluater.Evaluate(s);
            cout<<a.Get_value().numarator<<"/"<<a.Get_value().numitor<<"\n";
            cin.get();
            cin.get(s,1000);
        }
    }
    if(strcmp(s,"complexe")==0)
    {
        complexe_Field *ff=new complexe_Field();
        Expression_evaluater<complex_value> my_expression_evaluater(ff);
        if(!(*ff).Is_Field())
            cout<<"NOT A FIELD\n";
        else cout<<"Is a field\n";
        cin.get();
        cin.get(s,1000);
        while(!strcmp(s,"exit")==0)
        {
            element<complex_value> a=my_expression_evaluater.Evaluate(s);
            cout<<a.Get_value().real_part<<"+"<<a.Get_value().imaginary_part<<"i\n";
            cin.get();
            cin.get(s,1000);
        }
    }
    if(strcmp(s,"real")==0)
    {
        Real_Field *ff=new Real_Field();
        Expression_evaluater<double> my_expression_evaluater(ff);
        if(!(*ff).Is_Field())
            cout<<"NOT A FIELD\n";
        else cout<<"Is a field\n";
        cin.get();
        cin.get(s,1000);
        while(!strcmp(s,"exit")==0)
        {
            element<double> a=my_expression_evaluater.Evaluate(s);
           // cout<<":";
            //cout<<":";
            cout<<a.value<<"\n";
            cin.get();
            cin.get(s,1000);
        }
    }
    if(strcmp(s,"modulo")==0)
    {
        int mod;
        cout<<"Modulo?\n";
        cin>>mod;
        modulo_Field *ff=new modulo_Field(mod);
        Expression_evaluater<int> my_expression_evaluater(ff);
        if(!(*ff).Is_Field())
            cout<<"NOT A FIELD\n";
        else cout<<"Is a field\n";
        cin.get();
        cin.get(s,1000);
        while(!strcmp(s,"exit")==0)
        {
            element<int> a=my_expression_evaluater.Evaluate(s);
            cout<<"::\n";
            cout<<a.Get_value();
            cin.get();
            cin.get(s,1000);
        }
    }
    return 0;
}
