/** 
* @file g201210042DenizSimsekVeriYapilari
* @description dosyadan okunanlara göre avl agacina ve oncelikli kuyruga atamak
* @course İkinci Öğretim C Grubu
* @assignment 2. Odev
* @date 20.12.2021
* @author Deniz Şimşek deniz.simsek1@ogr.sakarya.edu.tr
*/

#include "DogruKuyrugu.hpp"
#include <iostream>
#include<iomanip>
#include <cmath>
#include <string>
DogruKuyrugu::DogruKuyrugu()
{
    ilk=son=0;
}
DogruKuyrugu::~DogruKuyrugu()
{
    while(ilk!=0)
    {
        Nokta* gec= ilk;
        ilk=ilk->sonraki;
        delete gec;
    }
}

int DogruKuyrugu::enBuyukGetir()
{
    Nokta* onceki = yukseginOncekiDugum();

    if(onceki)
        return onceki->sonraki->orijineUzaklik;
    if(ilk!=0)
        return ilk->orijineUzaklik;
    throw std::out_of_range("Kuyruk Bos");
}

int DogruKuyrugu::enBuyukSatiri()
{
    Nokta* onceki = yukseginOncekiDugum();

    if(onceki)
        return onceki->sonraki->satir;
    if(ilk!=0)
        return ilk->satir;
    throw std::out_of_range("Kuyruk Bos");
}
void DogruKuyrugu::ekle(int xKoor,int yKoor,int zKoor)
{
    	if(ilk==0)
		{
			ilk=new Nokta(xKoor,yKoor,zKoor);
			son= ilk;

		}
		else
		{
			Nokta* yeni = new Nokta(xKoor,yKoor,zKoor);
			son->sonraki = yeni;
			son = yeni;

        }
}
Nokta* DogruKuyrugu::yukseginOncekiDugum()
{
  	if(ilk==0)	return 0;

	Nokta* gec = ilk;
	Nokta*onceki=0;
	int enBuyuk = gec->orijineUzaklik;
	while(gec->sonraki!=0)//en yuksekten önceki dugume gider
	{
		if(gec->sonraki->orijineUzaklik<enBuyuk)
		{
			enBuyuk = gec->sonraki->orijineUzaklik;
			onceki = gec;
			
		}
		gec= gec->sonraki;
	}
	return onceki;
} 

void DogruKuyrugu::yazdir()
{
    Nokta* gec=ilk;
    while(gec!=0)
    {	
		cout<<"nokta"<<"->"<<gec->orijineUzaklik<<endl;
        gec=gec->sonraki;
    }
}
int DogruKuyrugu::dogruUzunlugu(int x,int y,int z)
{
	if(son!=0)
	{
		int uzunluk=sqrt(((x-(son->x))*(x-(son->x)))+((y-(son->y))*(y-(son->y)))+((z-(son->z))*(z-(son->z))));
		return uzunluk;
	}
	return 0;
}
int DogruKuyrugu::uzunlukAta(int uzunluk)
{

	son->toplamUzunluk=uzunluk;
	return uzunluk;
}
int DogruKuyrugu::orijineUzaklikHesapla(int x,int y,int z)
{
    int orijineUzak=sqrt(x*x+y*y+z*z);
	son->orijineUzaklik=orijineUzak;
    return orijineUzak;
}
int DogruKuyrugu::satirAta(int satir)
{
	son->satir=satir;
	return satir;
}
void DogruKuyrugu:: enYuksegiCikar()
{
	Nokta* onceki = yukseginOncekiDugum();
		if(onceki)
		{
			if(onceki->sonraki==son)
				son=onceki;
			Nokta* sil = onceki->sonraki;
			onceki->sonraki= sil->sonraki;
			delete sil;			
		}
		else
		{
			if(ilk==0)
				return;
			Nokta* sil= ilk;
			ilk=ilk->sonraki;
			delete sil;
		}
	
}
int DogruKuyrugu::noktaSayisiAta(int nokta)
{
	son->noktaSayisi=nokta;
	return nokta;
}
