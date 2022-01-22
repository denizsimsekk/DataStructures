/** 
* @file g201210042DenizSimsekVeriYapilari
* @description dosyadan okunanlara göre avl agacina ve oncelikli kuyruga atamak
* @course İkinci Öğretim C Grubu
* @assignment 2. Odev
* @date 20.12.2021
* @author Deniz Şimşek deniz.simsek1@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
Dugum::Dugum(Nokta* nokta)
{
    this->uzunluk = nokta->toplamUzunluk;
    this->orijineUzaklik=nokta->orijineUzaklik;
    this->satir=nokta->satir;
    this->noktaSayi=nokta->noktaSayisi;
    sol=sag=0;
}