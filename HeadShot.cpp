#include "HeadShot.h"
#include"Boom.h"
#include "PolaWektoroweFrm.h"
int Matrix4::endZ=0;
double Matrix4::arrowLen=1;
int  Matrix4::mouseDelta=1;
wxPoint Matrix4::stP=wxPoint(0,0),Matrix4::enP=wxPoint(0,0);
Vector3d::Vector3d(){
    std::fill(cord, cord+7, 0);
    cord[3]=1.0; cord[7]=1.0;
    ok=false;
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


bool Vector3d::get2D(wxDC &dc,double tab[4],double atab[4],Matrix4 &mat){
    static const double d = 0.5;
    Matrix4 pr,tmp;
    // ze strony http://wazniak.mimuw.edu.pl/index.php?title=GKIW_Modu%C5%82_5_-_Reprezentacja_przestrzeni_tr%C3%B3jwymiarowej_na_p%C5%82aszczy%C5%BAnie
    // nie dzia³a jak powinna >.<
  /*  pr.data[0][0]=1;
    pr.data[1][1]=1;
    pr.data[2][2]=1.0/(1.0-d);
    pr.data[2][3]=-d/(1.0-d);
    pr.data[3][3]=0;
    pr.data[3][2]=1;
    
    mat=pr*mat;
    *this=mat*(*this);
    
    this->set(0,(this->getPX())/this->get(3));
    this->set(1,(this->getPY())/this->get(3));
    this->set(2,(this->get(3)-d)/(this->get(3)*(1.0-d)));
    this->set(3,1);
    this->set(4,(this->getKX())/this->get(7));
    this->set(5,(this->getKY())/this->get(7));
    this->set(6,(this->get(3)-d)/(this->get(7)*(1.0-d)));
    this->set(7,1);*/
    
    //z jakiejs smiesznej strony, tyle, ¿e traktuje punkt 0,0 jako srodek ekranu, zreszta to z wykladu tak samo
    //Vector3d tmp1(this->getPX(),this->getPY(),this->getPZ(),this->get(3),this->getKX(),this->getKY(),this->getKZ(),this->get(7));
    int w,h;
    double atmp[8];
    //this->set(4,this->get(4)*Matrix4::arrowLen);
    //this->set(5,this->get(5)*Matrix4::arrowLen);
    //this->set(6,this->get(6)*Matrix4::arrowLen);
    getArrowhead(); //do strzalek
    
    *this=mat*(*this);
    dc.GetSize(&w,&h);
    pr.data[0][0]=1;
    pr.data[1][1]=1;
    pr.data[2][2]=1;
    pr.data[3][3]=0;
    pr.data[3][2]=1.0/d;
    this->set(2,0.7+ this->getPZ()/ (Matrix4::endZ*1.5));
    this->set(6,0.7+ this->getKZ()/ (Matrix4::endZ*1.5));
    
    //do strzalek
    std::fill(atmp, atmp+7, 0);
    for (unsigned int i=0;i<4;i++)
      {
      atmp[i]=0.0;
       for (unsigned int j=0;j<4;j++){
            atmp[i]=atmp[i]+(mat.data[i][j]*arrowh[j]);
            atmp[i+4]=atmp[i+4]+(mat.data[i][j]*arrowh[j+4]);
       }
      }
          arrowh[0]=atmp[0];
      arrowh[1]=atmp[1];
      arrowh[2]=atmp[2];
      arrowh[3]=atmp[3];
      arrowh[4]=atmp[4];
      arrowh[5]=atmp[5];
      arrowh[6]=atmp[6];
      arrowh[7]=atmp[7];
    //do strzalek end
    
    //arrowh[2]=0.7+ arrowh[2]/ (Matrix4::endZ*1.5);
    //arrowh[6]=0.7+ arrowh[6]/ (Matrix4::endZ*1.5);
    //mat = scale(w/4, h/4, 1, mat);
    //zrobiony translate podwojny bo rzutowanie sie odbywa tak jakby widz by³ w punkcie 0,0,0.5, a my chcemy w œrodku ekranu
    //ponizsze u¿ywa globalnego width i height zapisanego w klasie Matrix4
    /*mat=translate(-mat.getWinW()/2,-mat.getWinH()/2,0,mat);
    mat=pr*mat;
    mat=translate(mat.getWinW()/2,mat.getWinH()/2,0,mat);*/


//mno¿enie macierzy jednostkwej przez macierz projekcji
   
    tmp=pr*tmp;
    double scr=1;
     scr+= double(Matrix4::mouseDelta)/10;
    tmp=scale(w/150*scr,w/150*scr,1,tmp);
    tmp=translate(w/2-w/4*scr,h/2-h/4*scr,0,tmp);
    
    
    *this=tmp*(*this);
    this->set(0,(this->getPX()*d)/this->getPZ());
    this->set(1,(this->getPY()*d)/this->getPZ());
    this->set(2,(d));
    this->set(3,1);
    this->set(4,(this->getKX()*d)/this->getKZ());
    this->set(5,(this->getKY()*d)/this->getKZ());
    this->set(6,(d));
    this->set(7,1);
    
    //do strzalek START
    std::fill(atmp, atmp+7, 0);
    
    for (unsigned int i=0;i<4;i++)
      {
      atmp[i]=0.0;
       for (unsigned int j=0;j<4;j++){
            atmp[i]=atmp[i]+(tmp.data[i][j]*arrowh[j]);
            atmp[i+4]=atmp[i+4]+(tmp.data[i][j]*arrowh[j+4]);
       }
      }
      arrowh[0]=atmp[0];
      arrowh[1]=atmp[1];
      arrowh[2]=atmp[2];
      arrowh[3]=atmp[3];
      arrowh[4]=atmp[4];
      arrowh[5]=atmp[5];
      arrowh[6]=atmp[6];
      arrowh[7]=atmp[7];
    
    
    arrowh[0]=(arrowh[0]*d)/arrowh[2];
    arrowh[1]=(arrowh[1]*d)/arrowh[2];
    arrowh[2]=d;
    arrowh[3]=1;
    arrowh[4]=(arrowh[4]*d)/arrowh[6];
    arrowh[5]=(arrowh[5]*d)/arrowh[6];
    arrowh[6]=d;
    arrowh[7]=1;
    //do strzalek END
    
    tab[0]=this->getPX();
    tab[1]=this->getPY();
    tab[2]=this->getKX();
    tab[3]=this->getKY();
    
    //do strzalek START
    atab[0]=arrowh[0];
    atab[1]=arrowh[1];
    atab[2]=arrowh[4];
    atab[3]=arrowh[5];
    //do strzalek END
    //z wykladu
    /*tab[0]=(this->getPX()*d)/this->getPZ();
    tab[1]=(this->getPY()*d)/this->getPZ();
    tab[2]=(this->getKX()*d)/this->getKZ();
    tab[3]=(this->getKY()*d)/this->getKZ();*/

  return true;
}

bool  Vector3d::isOk(){
    return ok;
}

double  Vector3d::DiffLength(Vector3d vec[],int len){
    return maxVec(vec,len )-minVec(vec,len);
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
    ok=true;
}

bool  Vector3d::getStart(double boom[3]){
     boom[0]=cord[0]; boom[1]=cord[1]; boom[2]=cord[2];
    return true;
}

bool  Vector3d::getEnd(double boom[3]){
    if(ok){
     boom[0]=cord[4]; boom[1]=cord[5]; boom[2]=cord[6];
    return true;
    }
    return false;
}

double  Vector3d::maxVec(Vector3d vec[],int len){
    double max= vec[0].Length();
    for(int i=1;i <len;i++){
        if(max <vec[i].Length()) max =vec[i].Length();
    }
    return max;
}

double  Vector3d::minVec(Vector3d vec[],int len){
    double min= vec[0].Length();
    for(int i=1;i <len;i++){
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

//Funkcja normalize nie przyjmuje nic, zwraca obiekt Vector3d - dokonuje on normalizacji, na wektorze, z którego wykonana zostala
// ta funkcja, a nastepnie zwraca otrzymany, znormalizowany nowy wektor.
Vector3d Vector3d::normalize(){
    //Vector3d vec;
    double len = this->Length();
    double start[3];
    double end[3];
    this->getStart(start);
    this->getEnd(end);
    if(len != 0){
        Vector3d vec(start[0],start[1],start[2],((end[0]-start[0])/len)+start[0],((end[1]-start[1])/len)+start[1],((end[2]-start[2])/len)+start[2]);
		//vec.setStart(start[0],start[1],start[2]);
	//	vec.setEnd(end[0]/len,end[1]/len,end[2]/len);
	   return vec;
	}
	return Vector3d();
	
}


Vector3d Vector3d::arrowLength(double arrowLen){
    //Vector3d vec;
    double start[3];
    double end[3];
    this->getStart(start);
    this->getEnd(end);
    if(arrowLen != 0){
        Vector3d vec(start[0],start[1],start[2],((end[0]-start[0])*arrowLen)+start[0],((end[1]-start[1])*arrowLen)+start[1],((end[2]-start[2])*arrowLen)+start[2]);
		//vec.setStart(start[0],start[1],start[2]);
	//	vec.setEnd(end[0]/len,end[1]/len,end[2]/len);
	   return vec;
	}
	return Vector3d();
	
}

//Funkcja getArrowhead() nic nie zwraca, miala za zadanie uzupelnic lokalizacje punktow grotow strzalki, ale nie dziala
//Zapisuje ona wyniki dzialan w tablicy arrowh, ktora jest w kazdym obiekcie Vector3d. Nie przyjmuje zadnych argumentow.
void Vector3d::getArrowhead(){
    double h = 0.2*sqrt(3);double w=0.1;
    Vector3d U = normalize();
    arrowh[0]=getKX()-h*(U.getKX()-U.getPX())-w*(U.getKY()-U.getPY());
    arrowh[1]=getKY()-h*(U.getKY()-U.getPY())+w*(U.getKX()-U.getPX());
    arrowh[2]=getKZ()-h*(U.getKZ()-U.getPZ());
    arrowh[3]=1.0;
    arrowh[4]=getKX()-h*(U.getKX()-U.getPX())+w*(U.getKY()-U.getPY());
    arrowh[5]=getKY()-h*(U.getKY()-U.getPY())-w*(U.getKX()-U.getPX());
    arrowh[6]=getKZ()-h*(U.getKZ()-U.getPZ());
    arrowh[7]=1.0;
}
