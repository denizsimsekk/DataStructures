#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include<iostream>
#include "Dugum.hpp"
#include "DogruKuyrugu.hpp"
#include "OncelikliKuyruk.hpp"
using namespace std;

class AVLAgaci
{
public:

	AVLAgaci();
	~AVLAgaci();
	int yukseklik();
	void yazdir();
	void postorder(OncelikliKuyruk* oncelikli);
	void noktaEkle(Nokta* nokta);
	int enBuyukDeger(Nokta* nokta);
private:
	Dugum* noktaEkle(Nokta* nokta,Dugum* aktifDugum);
	int dengesizlikYonu(Dugum* aktif);
	Dugum* solaDondur(Dugum* dugum);
	Dugum* sagaDondur(Dugum* dugum);
	void postorder(Dugum* index,OncelikliKuyruk* oncelikli);
	int yukseklik(Dugum* aktifDugum);
	Dugum* kok;
};
#endif