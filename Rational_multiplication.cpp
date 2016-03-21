    #include "Rational_multiplication.h"
    int Rational_Multiplication::Count()
    {
        return -1;
    }
    rational_value Rational_Multiplication::Return_composite(rational_value First_value,rational_value Second_value)
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
