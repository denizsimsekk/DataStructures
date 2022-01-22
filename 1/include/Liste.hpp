#ifndef Liste_hpp
#define Liste_hpp
#include <iostream>
#include <string>
#include "Dugum.hpp"
using namespace std;
class Liste
{

    public:
        Liste();
        ~Liste();
        void ekle(int indis,string eleman);
        void yazdir();
        void sil(int indis);
        Dugum* indisGetir(int indis);
    private:
        Dugum* ilk;
        int dugumSayisi;
};
#endif