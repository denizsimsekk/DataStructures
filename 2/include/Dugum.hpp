#ifndef Dugum_hpp
#define Dugum_hpp
#include "Nokta.hpp"

class Dugum
{
public:
    Dugum(Nokta* Nokta);
    int uzunluk;
    int orijineUzaklik;
    int satir;
    int noktaSayi;
    Dugum* sol;
    Dugum* sag;
};

#endif