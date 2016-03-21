 #include "Moduo_multiplication.h"
 modulo_Multiplication::modulo_Multiplication(int mod)
    {
        modulo=mod;
    }
    int modulo_Multiplication::Count()
    {
        return modulo;
    }
    int modulo_Multiplication::Return_composite(int First_value,int Second_value)
    {
        return (First_value*Second_value)%modulo;
    }
