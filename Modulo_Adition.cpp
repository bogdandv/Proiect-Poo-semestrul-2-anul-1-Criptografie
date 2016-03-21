    #include "Modulo_Adition.h"
    modulo_Adition::modulo_Adition(int mod)
    {
        modulo=mod;
    }
    int modulo_Adition::Count()
    {
        return modulo;
    }
    int modulo_Adition::Return_composite(int First_value,int Second_value)
    {
        return (First_value+Second_value)%modulo;
    }
