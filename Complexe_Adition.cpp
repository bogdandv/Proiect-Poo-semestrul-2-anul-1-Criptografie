#include "Complexe_Adition.h"
     int complexe_Adition::Count()
    {
        return -1;
    }
    complex_value complexe_Adition::Return_composite(complex_value First_value,complex_value Second_value)
    {
        complex_value temp;
        temp.real_part=First_value.real_part+Second_value.real_part;
        temp.imaginary_part=First_value.imaginary_part+Second_value.imaginary_part;
        return temp;
    }
