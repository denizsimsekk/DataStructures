/** 
* @file Liste.cpp dosyası
* @description Liste icin ekleme,silme ve yazdirma fonksiyonlarını bulundurur
* @course 2. ogretim C grubu
* @assignment 1. odev
* @date 8.11.2021
* @author Deniz Şimşek deniz.simsek1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <iomanip>
#include <string>
#include<exception>
#include "Liste.hpp"
using namespace std;
Liste::Liste()
{
    ilk=0;
    dugumSayisi=0;
}
Liste::~Liste()
{
    Dugum* gecici=ilk;
    for (int i = 0; i < dugumSayisi; i++)
    {
        Dugum* silinecek=gecici;
        gecici=gecici->sonraki;
        delete silinecek;
        
    }
}

void Liste::ekle(int indis,string veri)
{
    
    Dugum* yeni=new Dugum(veri);
    if(ilk==0)//ekleme yapmak istenilen indis 0 ise ve hiç düğüm yoksa
    {
        ilk = new Dugum(veri);
    }
    else//dugum varsa
    {
        Dugum* gecici=ilk;
        while(gecici->sonraki!=0)//sona dugum eklenir
        {
            gecici=gecici->sonraki;
        }
        gecici->sonraki=yeni;
        yeni->onceki=gecici;
        if(indis<=dugumSayisi)//indis sayisi bulunuyorsa kaydırma yapılır
        {
            Dugum* gecici2=yeni;
            string yeniEleman=yeni->eleman;
            for(int i=0;i<dugumSayisi-indis;i++)
            {
                gecici2->eleman=gecici2->onceki->eleman;
                gecici2=gecici2->onceki;
            }
            gecici2->eleman=yeniEleman;
        }
    }
    dugumSayisi++;
}

void Liste::sil(int indis)
{
    
    if(ilk==0)//ekleme yapmak istenilen indis 0 ise ve hiç düğüm yoksa
        return;
    
    if(ilk->sonraki==0)//sadece bir düğüm varsa o düğüm silinir
    {
        delete ilk;
        ilk=0;
    }
    else if(indis>=dugumSayisi||indis==dugumSayisi-1)//aranan indis yoksa ya da indis son dugumde ise liste sonundan dugum silinir
    {
        Dugum* gecici=ilk;
         while(gecici->sonraki->sonraki!=0)
        {
            gecici=gecici->sonraki;
        }
        delete gecici->sonraki;
        gecici->sonraki=0;
    }
    else if(indis<dugumSayisi)//indis varsa liste sonuna taşınır ve sondan silinir
    {
        Dugum* gecici=ilk;
        int i=0;
        while(i!=indis+1)//silinecek elemanın bir sağına gider
        {
            gecici=gecici->sonraki;
            i++;
        }
        for (int i = 0; i < dugumSayisi-indis-2; i++)
        {
            gecici->onceki->eleman=gecici->eleman;
            gecici=gecici->sonraki;
            
        }
        gecici->onceki->eleman=gecici->eleman;
        gecici->onceki->sonraki=0;
        delete gecici;
    }
    dugumSayisi--;
}

void Liste::yazdir()
{
    using namespace std;
    Dugum* gecici = ilk;
    for (int i = 0; i < dugumSayisi; i++)
    {
        cout<<gecici->eleman<<"<--->";
        gecici=gecici->sonraki;
    }
          
}