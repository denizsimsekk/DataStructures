/** 
* @file g201210042DenizSimsekVeriYapilari
* @description dosyadan okunanlara göre avl agacina ve oncelikli kuyruga atamak
* @course İkinci Öğretim C Grubu
* @assignment 2. Odev
* @date 20.12.2021
* @author Deniz Şimşek deniz.simsek1@ogr.sakarya.edu.tr
*/

#include "OncelikliKuyruk.hpp"
#include <iostream>
#include<iomanip>
#include <cmath>
#include <string>

OncelikliKuyruk::OncelikliKuyruk()
{
    ilk=son=0;
}

OncelikliKuyruk::~OncelikliKuyruk()
{
    while(ilk!=0)
    {
        OncelikliNokta* gec= ilk;
        ilk=ilk->sonraki;
        delete gec;
    }
}
void OncelikliKuyruk::ekle(int veri,int satir)
{
	if(ilk==0)
	{
		ilk=new OncelikliNokta(veri,satir);
		son= ilk;

	}
	else
	{
		OncelikliNokta* yeni = new OncelikliNokta(veri,satir);
		son->sonraki = yeni;
		son = yeni;

	}
}

void OncelikliKuyruk::yazdir(int satir)
{
    OncelikliNokta* gec=ilk;
    while(gec!=0)
    {	
		if(gec->satir==satir)
		{
			cout<<gec->veri<<" ";
		}
        gec=gec->sonraki;
    }
}

