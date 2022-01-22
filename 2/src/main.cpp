/** 
* @file g201210042DenizSimsekVeriYapilari
* @description dosyadan okunanlara göre avl agacina ve oncelikli kuyruga atamak
* @course İkinci Öğretim C Grubu
* @assignment 2. Odev
* @date 20.12.2021
* @author Deniz Şimşek deniz.simsek1@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include "DogruKuyrugu.hpp"
#include "AVLAgaci.hpp"
#include "OncelikliKuyruk.hpp"
using namespace std;

int main()
{
    ifstream dosyaOku("Noktalar.txt");
    string okunanSayi;
    DogruKuyrugu kuyruk;
    AVLAgaci agac;
    OncelikliKuyruk* oncelik=new OncelikliKuyruk();
    int dosyaSatir=0;
    int nokta=0;
    while (getline (dosyaOku, okunanSayi)) //dosya okuyan dongu
    {
        int bosluksayisi=0;
        int satirSayisi=0;
        for (int i = 0; i < okunanSayi.length(); i++)
        {
            if(okunanSayi[i]==' ')
            {
                bosluksayisi++;
            }
        }
        string stringvalues = okunanSayi;
        istringstream iss (stringvalues);
        int koordinatlar[3];
        int diziIndisi=0;
        int dogruUzunluk=0;
        for (int n=0; n<bosluksayisi; n++)//nokta sayısı kadar döner
        {
            int val;
            iss >> val;
            koordinatlar[diziIndisi]=val;
            diziIndisi++;
            if(diziIndisi==3)
            {
                diziIndisi=0;
               if(satirSayisi>0)
                {
                    dogruUzunluk+=kuyruk.dogruUzunlugu(koordinatlar[0],koordinatlar[1],koordinatlar[2]);
                }
                kuyruk.ekle(koordinatlar[0],koordinatlar[1],koordinatlar[2]);
                nokta++;
                kuyruk.noktaSayisiAta(bosluksayisi/3);
                kuyruk.satirAta(dosyaSatir);
                kuyruk.orijineUzaklikHesapla(koordinatlar[0],koordinatlar[1],koordinatlar[2]);
                satirSayisi++;
            }
            
        }
        
        kuyruk.uzunlukAta(dogruUzunluk);
        agac.noktaEkle(kuyruk.son);
        dosyaSatir++;
    }
    for (int i = 0; i < nokta; i++)//kuyruktaki nesneleri oncelikli kuyruga atar
    {
        oncelik->ekle(kuyruk.enBuyukGetir(),kuyruk.enBuyukSatiri());
        kuyruk.enYuksegiCikar();
    }

    agac.postorder(oncelik);
    

}