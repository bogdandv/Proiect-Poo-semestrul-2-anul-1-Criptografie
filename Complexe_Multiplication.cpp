#include "Complexe_Multiplication.h"
 int complexe_Multiplication::Count()
    {
        return -1;
    }
    complex_value complexe_Multiplication::Return_composite(complex_value First_value,complex_value Second_value)
    {
        complex_value temp;
        temp.real_part=First_value.real_part*Second_value.real_part-First_value.imaginary_part*Second_value.imaginary_part;
        temp.imaginary_part=First_value.real_part*Second_value.imaginary_part+First_value.imaginary_part*Second_value.real_part;
        return temp;
    }
