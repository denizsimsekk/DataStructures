#ifndef DogruKuyrugu_hpp
#define DogruKuyrugu_hpp
#include<iostream>
#include "Nokta.hpp"
using namespace std;

class DogruKuyrugu
{
    public:
        DogruKuyrugu();
        ~DogruKuyrugu();
        Nokta* yukseginOncekiDugum();
        void ekle(int xKoor,int yKoor,int zKoor);
        int enBuyukGetir();
        void yazdir();
        int orijineUzaklikHesapla(int x,int y,int z);
        int dogruUzunlugu(int x,int y,int z);
        int uzunlukAta(int uzunluk);
        int satirAta(int satir);
        void enYuksegiCikar();
        int enBuyukSatiri();
        int noktaSayisiAta(int sayi);
        Nokta* ilk;
        Nokta* son;
};

#endif