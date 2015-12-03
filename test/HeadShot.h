#ifndef HEADSHOT_H
#define HEADSHOT_H
#include <stdio.h>
#include <iostream>
#include <math.h>   
/**
**klasa reprezentujacd wektor 3D doubli
**
**/
class Vector3d{
public:
    //konstruktory
    Vector3d();
    Vector3d(double x,double y, double z);
    Vector3d(double x,double y, double z,double kx,double ky, double kz);
    Vector3d(double tab[3]);
    //funkcje
    
    //zwraca wspolrzedne w 2D
    bool get2D(double tab[4]);
    // zwraca wartosc ok
    bool isOk();
    //zwraca dlugosc wektora
    double Length();
    //zwraca roznice miedzy najdluzszym i najkrotszym wektorem
    double DiffLength();
    //wypisuje wektor
    void Print();
    //ustawia wartosc poczatku wektora
    void setStart(double x, double y, double z);
    //ustawia wartosc konca wektora
    void setEnd(double x, double y, double z);
    //zwraca wartosc poczatku wektora
    bool getStart(double boom[3]);
    //zwraca wartosc konca wektora
    bool getEnd(double boom[3]);
    //getery poczatku 
    double getPX();
    double getPY();
    double getPZ();
    //konca
    double getKX();
    double getKY();
    double getKZ();
    //pozwala ustawic konkretne pole danych i pole, val dane
    void set(int i, double val);
    //pozwala pobrac konkretne pole danych i pole, val dane
    double get(int i) const;
private:
    //pierwsze 3 wspolrzedne to poczatek, kolejne 3 to koniec, o 2 dluzszy bo byly jakies magie z mnozeniem przez ta macierz poczatek : x,y,z,d i koniec : x,y,z,d
    double cord[8];
    //okresla czy wektor jest kompletny
    bool ok;
    //zwraca dlugosc najdluzszego wektora
    static double maxVec(Vector3d vec[]);
    //zwraca dlugosc najkrotszego wektora
    static double minVec(Vector3d vec[]);

};

/**
**Klasa zapozyczona z laboratoriów dr Jacka Tarasiuka http://home.agh.edu.pl/~tarasiuk/dydaktyka/
**
**/
class Matrix4{
public:
    friend class Vector3d;
    double data[4][4];
    Matrix4()
    {
     data[0][0]=1.0; data[0][1]=0.0; data[0][2]=0.0; data[0][3]=0.0;
     data[1][0]=0.0; data[1][1]=1.0; data[1][2]=0.0; data[1][3]=0.0;
     data[2][0]=0.0; data[2][1]=0.0; data[2][2]=1.0; data[2][3]=0.0;
     data[3][0]=0.0; data[3][1]=0.0; data[3][2]=0.0; data[3][3]=1.0;
    }
    
    void Print(void)
    {
     printf("\n|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n",data[0][0], data[0][1], data[0][2], data[0][3]);
     printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n",data[1][0], data[1][1], data[1][2], data[1][3]);
     printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n",data[2][0], data[2][1], data[2][2], data[2][3]);
     printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n",data[3][0], data[3][1], data[3][2], data[2][3]);
    }
    
    Matrix4 operator* (const Matrix4 gMatrix)
    {
     int i,j,k;
     Matrix4 tmp;
    
     for (i=0;i<4;i++)
        for (j=0;j<4;j++)
         {
          tmp.data[i][j]=0.0;
          for (k=0;k<4;k++)
           tmp.data[i][j]=tmp.data[i][j]+(this->data[i][k]*gMatrix.data[k][j]);
         }
     return tmp;
    }
    //mnozymy macierz razy wektor zeby otrzymac wektor
    Vector3d operator* (const Vector3d gVector)
    {
     unsigned int i,j;
     Vector3d tmp;
    
     for (i=0;i<4;i++)
      {
       for (j=0;j<4;j++){
             tmp.set(i,tmp.get(i)+(this->data[i][j]*gVector.get(j)));
             tmp.set(i+4,tmp.get(i+4)+(this->data[i][j]*gVector.get(j+4)));
       }
      }
     return tmp;
    }
};
///////////////////////////////////////////////////////////////////////////////////////
#endif
