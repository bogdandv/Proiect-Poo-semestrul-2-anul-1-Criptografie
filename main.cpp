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
    char *Buffer;
    Field_interface<Value_from_set> *field;
    int operator_priority(char op)
    {
        if(op=='*'||op=='/')
            return 2;
        if(op=='+'||op=='-')
            return 1;
        return 0;
    }
    void Buffer_to_postfix()
    {    stack<char> _stack;
        char t;
        istringstream _istringstream(Buffer);
        char *new_Buffer=new char(strlen(Buffer)*2+1);
        char *begining=new_Buffer;
        while(!_istringstream.eof())
        {
            _istringstream>>t;
            while(t==' ')
               {
               _istringstream>>t;
               }
            if(isdigit(t))
            {
                *new_Buffer=t;
                new_Buffer++;
                while(_istringstream.peek()!=' ' && _istringstream.peek()!='+' && _istringstream.peek()!='-' &&_istringstream.peek()!='*' && _istringstream.peek()!='/' && _istringstream.peek()!='(' && _istringstream.peek()!=')' && !_istringstream.eof())
                {  _istringstream>>t;
                   *new_Buffer=t;
                   new_Buffer++;
                   //cout<<_istringstream.peek()<<" ";
                }
                *new_Buffer=' ';
                new_Buffer++;
            }
            if(t=='(')
            {
                _stack.push(t);
            }
            if(t==')')
            {
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
            {//cout<<"W8";
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
        *new_Buffer='#';
        new_Buffer++;
        *new_Buffer='\0';
        Buffer=begining;
        cout<<Buffer<<"\n";
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
        Buffer=expression;
        Buffer_to_postfix();
        istringstream _istringstream(Buffer);
        int t1;
        //_istringstream>>t1;
        //cout<<t1<<"\n";
        while(!_istringstream.eof())
        {
            if(_istringstream.peek()=='#')
            {
                break;
            }
            if(isdigit(_istringstream.peek()))
            {
                Value_from_set el1;
                el1=field->Value_From_String(_istringstream);

                element<Value_from_set> temp(field,el1);
                _stack.push(temp);
            }
            if(_istringstream.peek()==' ')
            {
                //cout<<"!";
                _istringstream.ignore(1);
            }
            if(_istringstream.peek()=='+' || _istringstream.peek()=='-' || _istringstream.peek()=='*' || _istringstream.peek()=='/')
            {//cout<<"?";
                element<Value_from_set> op1(field),op2(field),temp(field);
                op1=_stack.top();
                _stack.pop();
                op2=_stack.top();
                _stack.pop();

                if(_istringstream.peek()=='+')
                    temp=op2+op1;
                if(_istringstream.peek()=='-')
                    temp=op2-op1;
                if(_istringstream.peek()=='*')
                    temp=op2*op1;
                if(_istringstream.peek()=='/')
                    temp=op2/op1;
                _stack.push(temp);
                char r;
                _istringstream>>r;
            }
        }
        return _stack.top();
    }
};

int main()
{
    cout<<"!";
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
        Expression_evaluater<int> my_expression_evaluater(ff);
        if(!(*ff).Is_Field())
            cout<<"NOT A FIELD\n";
        else cout<<"Is a field\n";
        cin.get();
        cin.get(s,1000);

        while(!strcmp(s,"exit")==0)
        {
            element<int> a=my_expression_evaluater.Evaluate(s);
            cout<<a.value<<"\n";
            cin.get();
            cin.get(s,1000);

        }
    }
    if(strcmp(s,"rational")==0)
    {
        Rational_Field *ff=new Rational_Field();
        Expression_evaluater<rational_value> my_expression_evaluater(ff);
        cin.get();
        cin.get(s,1000);
        while(!strcmp(s,"exit")==0)
        {
            element<rational_value> a=my_expression_evaluater.Evaluate(s);
            cout<<a.value.numarator<<"/"<<a.value.numitor<<"\n";
            cin.get();
            cin.get(s,1000);
        }
    }
    if(strcmp(s,"complexe")==0)
    {
        complexe_Field *ff=new complexe_Field();
        Expression_evaluater<complex_value> my_expression_evaluater(ff);
        cin.get();
        cin.get(s,1000);
        while(!strcmp(s,"exit")==0)
        {
            element<complex_value> a=my_expression_evaluater.Evaluate(s);
            cout<<a.value.real_part<<"+"<<a.value.imaginary_part<<"i\n";
            cin.get();
            cin.get(s,1000);
        }
    }
    if(strcmp(s,"real")==0)
    {
        Real_Field *ff=new Real_Field();
        Expression_evaluater<double> my_expression_evaluater(ff);
        cin.get();
        cin.get(s,1000);
        while(!strcmp(s,"exit")==0)
        {
            element<double> a=my_expression_evaluater.Evaluate(s);
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
        cin.get();
        cin.get(s,1000);
        while(!strcmp(s,"exit")==0)
        {
            element<int> a=my_expression_evaluater.Evaluate(s);
            cout<<a.value;
            cin.get();
            cin.get(s,1000);
        }
    }
    return 0;
}
