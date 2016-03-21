    #include "Rational_adition.h"
    int Rational_Adition::Count()
    {
        return -1;
    }
    rational_value Rational_Adition::Return_composite(rational_value First_value,rational_value Second_value)
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
