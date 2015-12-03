#include "HeadShot.h"

Vector3d::Vector3d(){
    std::fill(cord, cord+7, 0);
    cord[3]=1.0; cord[7]=1.0;
}
 
Vector3d::Vector3d(double x,double y, double z){
    std::fill(cord, cord+7, 0);
    cord[0]=x; cord[1]=y; cord[2]=z; cord[3]=1.0; cord[7]=1.0;
    ok=false;
}
Vector3d::Vector3d(double x,double y, double z,double kx,double ky, double kz){
    std::fill(cord, cord+7, 0);
    cord[0]=x; cord[1]=y; cord[2]=z; cord[3]=1.0 ;cord[4]=kx; cord[5]=ky; cord[6]=kz; cord[7]=1.0;
    ok=true;
}
Vector3d::Vector3d(double tab[3]){
    std::fill(cord, cord+7, 0);
    cord[0]=tab[0]; cord[1]=tab[1]; cord[2]=tab[2]; cord[3]=1.0; cord[7]=1.0;
    ok=false;
}


bool Vector3d::get2D(double tab[4]){
 //TODO funkcja zwracajace wsp 2D jak w lab5  

  return true;
}

bool  Vector3d::isOk(){
    return ok;
}

double  Vector3d::DiffLength(){
    return maxVec(this)-minVec(this);
}
double  Vector3d::Length(){
    return (sqrt(pow(getKX()-getPX(),2)+pow(getKY()-getPY(),2)+pow(getKZ()-getPZ(),2)));
}
void Vector3d::Print(){
    printf("(%2.3lf,%2.3lf,%2.3lf,%2.3lf,%2.3lf,%2.3lf)\n",cord[0],cord[1],cord[2],cord[4],cord[5],cord[6]);
}

void  Vector3d::setStart(double x, double y, double z){
        cord[0]=x; cord[1]=y; cord[2]=z;
    }

void  Vector3d::setEnd(double x, double y, double z){
    cord[4]=x; cord[5]=y; cord[6]=z;
}

bool  Vector3d::getStart(double boom[3]){
     boom[0]=cord[0]; boom[1]=cord[1]; boom[2]=cord[2];
    return true;
}

bool  Vector3d::getEnd(double boom[3]){
     boom[3]=cord[4]; boom[4]=cord[5]; boom[5]=cord[6];
    return true;
}

double  Vector3d::maxVec(Vector3d vec[]){
    double max= vec[0].Length();
    for(int i=0;i <(sizeof(vec)/sizeof(vec[0]));i++){
        if(max <vec[i].Length()) max =vec[i].Length();
    }
    return max;
}

double  Vector3d::minVec(Vector3d vec[]){
    double min= vec[0].Length();
    for(int i=0;i <(sizeof(vec)/sizeof(vec[0]));i++){
        if(min > vec[i].Length()) min =vec[i].Length();
    }
    return min;
}

double  Vector3d::getPX(){return cord[0];}
double  Vector3d::getPY(){return cord[1];}
double  Vector3d::getPZ(){return cord[2];}

double  Vector3d::getKX(){return cord[4];}
double  Vector3d::getKY(){return cord[5];}
double  Vector3d::getKZ(){return cord[6];}

void Vector3d::set(int i, double val){
    cord[i]=val;
}
double Vector3d::get(int i) const{
    return cord[i];
}
