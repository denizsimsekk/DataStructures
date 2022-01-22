#ifndef Nokta_hpp
#define Nokta_hpp
class Nokta
{
public:
    Nokta(int xK,int yK,int zK);
    int satir;
    int noktaSayisi;
    int orijineUzaklik;
    int toplamUzunluk=0;
    Nokta* sonraki;
    int x,y,z;
};

#endif