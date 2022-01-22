#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>
using namespace std;
class Dugum
{
    public:
    Dugum(string eleman)
    {
        this->eleman=eleman;
        sonraki=onceki=0;
    }
    string eleman;
    Dugum* sonraki;
    Dugum* onceki;

};


#endif