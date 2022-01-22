/** 
* @file main.cpp dosyası
* @description listeye ekleme verileri,listeden silme indisleri burada bulunur
* @course 2. ogretim C grubu
* @assignment 1. odev
* @date 5.11.2021
* @author Deniz Şimşek deniz.simsek1@ogr.sakarya.edu.tr
*/
#include<iostream>
#include<iomanip>
#include <fstream>
#include <sstream>
#include "Liste.hpp"
using namespace std;

int main()
{
    Liste* veriListesi=new Liste();//liste nesnesini olusturur
    ifstream dosyaOku("Veri.txt");
    string okunanVeri;
    
    while (getline (dosyaOku, okunanVeri)) //dosya okuyan dongu
    {
        char komut=okunanVeri[0];
        int indis;
        if(komut=='E')//ilk harf e ise ekleme yapılır
        {
            for (int i = 0; i < okunanVeri.length(); i++)//hashtage kadar olan kısmın indisi tutulur
            {
                if(okunanVeri[i]=='#')
                {
                    indis=i;
                }
            }
            int eklemeYapilacakIndis;
            string sayi= okunanVeri.substr(2,indis-2);
            stringstream ss;  
            ss << sayi;  
            ss >> eklemeYapilacakIndis;
            string eklenecekVeri=okunanVeri.substr(indis+1,okunanVeri.length()-indis-2);
            veriListesi->ekle(eklemeYapilacakIndis,eklenecekVeri);

        }
        else if(komut=='S')//ilk harf s ise silme yapılır
        {
            int silinecekIndis;
            string sayi= okunanVeri.substr(2,okunanVeri.length()-1);
            stringstream ss;  
            ss << sayi;  
            ss >> silinecekIndis;
            veriListesi->sil(silinecekIndis);
        }
    }

    veriListesi->yazdir();
    delete veriListesi;
    
}