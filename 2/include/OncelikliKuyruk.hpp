#ifndef OncelikliKuyruk_hpp
#define OncelikliKuyruk_hpp
#include<iostream>
#include "OncelikliNokta.hpp"
using namespace std;

class OncelikliKuyruk
{
    public:
        OncelikliKuyruk();
        ~OncelikliKuyruk();
        void ekle(int veri,int satir);
        void yazdir(int satir);
        OncelikliNokta* ilk;
        OncelikliNokta* son;
};

#endif