#ifndef OncelikliNokta_hpp
#define OncelikliNokta_hpp
class OncelikliNokta
{
public:
   
    OncelikliNokta(int eklenecekveri,int ekleneceksatir)
    {
        this->veri=eklenecekveri;
        this->satir=ekleneceksatir;
        sonraki=0;
    }
    int satir;
    OncelikliNokta* sonraki;
    int veri;
};

#endif