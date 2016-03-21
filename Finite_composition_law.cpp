#include "Finite_composition_law.h"
int Finite_Composition_law::Count()
    {
        return Number_of_elements;
    }
int Finite_Composition_law::Return_composite(int First_value,int Second_value)
    {
        return Caylay_table[First_value*Number_of_elements+Second_value];
    }
Finite_Composition_law::Finite_Composition_law(int number_of_elements,int *caylay_table)
    {
        Number_of_elements=number_of_elements;
        Caylay_table=caylay_table;
    }
Finite_Composition_law::~Finite_Composition_law()
    {
    delete[] Caylay_table;
    }
