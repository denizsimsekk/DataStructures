/** 
* @file g201210042DenizSimsekVeriYapilari
* @description dosyadan okunanlara göre avl agacina ve oncelikli kuyruga atamak
* @course İkinci Öğretim C Grubu
* @assignment 2. Odev
* @date 20.12.2021
* @author Deniz Şimşek deniz.simsek1@ogr.sakarya.edu.tr
*/



#include "AVLAgaci.hpp"
#include <cmath>
#include <iomanip>
#include<iostream>
#include<queue>
#include"DogruKuyrugu.hpp"
#include"Nokta.hpp"
#include"OncelikliKuyruk.hpp"
using namespace std;
AVLAgaci::AVLAgaci()
{
    kok= 0;
}
AVLAgaci::~AVLAgaci()
{

}

void AVLAgaci::noktaEkle(Nokta* ekleneceknokta)//agaca nokta ekler
{
    kok = noktaEkle(ekleneceknokta,kok);
}
int AVLAgaci::yukseklik() 
{
	return yukseklik(kok);
}

void AVLAgaci::postorder(OncelikliKuyruk* oncelik) {
	postorder(kok,oncelik);
}

void AVLAgaci::postorder(Dugum* aktif,OncelikliKuyruk* oncelik) 
{
	if(aktif)
    {
        postorder(aktif->sol,oncelik);
        postorder(aktif->sag,oncelik);
        oncelik->yazdir(aktif->satir);
        cout<<endl;
        
    }	
}

int AVLAgaci::yukseklik(Dugum* aktifDugum) 
{
	if(aktifDugum)
    {
        return 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
    }
    return -1;
}
Dugum* AVLAgaci::noktaEkle(Nokta* nokta,Dugum* aktifDugum)//agaca nokta ekler
{
    if(nokta->toplamUzunluk==0)//eger noktanun toplam uzunluk degeri 0 iste ekleme yapmaz
    {
        return aktifDugum;
    }
    if(aktifDugum==0)//ilk dugum yoksa ilk dugume atama yapar
    {
        return new Dugum(nokta);
        
    }
    else if(aktifDugum->uzunluk<nokta->toplamUzunluk)//saga ya da sola yerleştirmek için karşılaştırma
    {
        aktifDugum->sag=noktaEkle(nokta,aktifDugum->sag);
        if(yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
        {   
            if(nokta->toplamUzunluk>aktifDugum->sag->uzunluk)
                aktifDugum = solaDondur(aktifDugum);
                
            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum =solaDondur(aktifDugum);
            }
        }
    }
    else if(aktifDugum->uzunluk>=nokta->toplamUzunluk)//saga ya da sola yerleştirmek için karşılaştırma
    {
        aktifDugum->sol = noktaEkle(nokta,aktifDugum->sol);
        if(yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
        {

            if(nokta->toplamUzunluk<aktifDugum->sol->uzunluk)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum =sagaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}


Dugum* AVLAgaci::solaDondur(Dugum* buyukEbeveyn) 
{
	Dugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
Dugum* AVLAgaci::sagaDondur(Dugum* buyukEbeveyn) 
{
	Dugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}


int AVLAgaci::dengesizlikYonu(Dugum* aktif) 
{
    if(aktif==0)
        return 0;
    return yukseklik(aktif->sol)- yukseklik(aktif->sag);
}


void AVLAgaci::yazdir()
{
    Dugum* gec=kok;
    while(gec!=0)
    {	
		cout<<"veri"<<"->"<<gec->uzunluk<<endl;
        gec=gec->sag;
    }
}
