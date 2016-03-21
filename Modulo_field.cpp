    #include"Modulo_field.h"
    modulo_Field::modulo_Field(int modulo)
    {
        modulo_Adition *aditive_law=new modulo_Adition(modulo);
        modulo_Multiplication *multiplicative_law=new modulo_Multiplication(modulo);
        moduloAditive_Group *fag=new moduloAditive_Group(aditive_law);
        Aditive_Group=fag;
        moduloMultiplicative_Group *fmg=new moduloMultiplicative_Group(multiplicative_law);
        Multiplicative_Group=fmg;
    }
    modulo_Field::~modulo_Field()
    {
        delete Aditive_Group;
        delete Multiplicative_Group;
    }
    bool modulo_Field::Distributive()
    {
        return true;
    }
    bool modulo_Field::Is_Field()
    {
        return Multiplicative_Group->Inversible(Aditive_Group->Get_neutral());
    }
