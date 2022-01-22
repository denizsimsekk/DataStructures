/** 
* @file g201210042DenizSimsekVeriYapilari
* @description dosyadan okunanlara göre avl agacina ve oncelikli kuyruga atamak
* @course İkinci Öğretim C Grubu
* @assignment 2. Odev
* @date 20.12.2021
* @author Deniz Şimşek deniz.simsek1@ogr.sakarya.edu.tr
*/

#include "Nokta.hpp"
#include <iostream>
#include<iomanip>
#include <cmath>
 
 Nokta:: Nokta(int xK,int yK,int zK)
    {
        this->x = xK;
        this->y = yK;
        this->z = zK;
        sonraki=0;
    }
