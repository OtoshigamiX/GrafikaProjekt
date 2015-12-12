/**
**Funkcje do rysowania, nak³adka na wxWidgets
**/
#include "HeadShot.h"
#ifndef BOOM_H
#define BOOM_H
#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/scrolbar.h>
#include <wx/stattext.h>
#include <wx/tglbtn.h>
#include <wx/sizer.h>
#include <wx/colour.h>
//Parser doubli z wxStringa
static double wxAtod(wxString a){
        double value;
        a.ToDouble(&value);
        return value;
    /*std::string str= a.ToStdString();
    double n = atof(str.c_str());
    return n;*/
}

//Funkcja do przyciecia, bazuje na wartosciach progowych, robi wedlug tego co zawarte w pdfie
static double trim(double coord1,double coord2,double diff){
    return abs(coord2-coord1)<abs(diff) ? coord2 : coord1+diff;
}

static void boomLine(wxDC &dc,Vector3d vec, int R, int G, int B,Matrix4 &mat){
     double tmp[4];
     double atmp[4];
     if(vec.get2D(dc,tmp,atmp,mat)){
         dc.SetPen(wxPen(RGB(R,G,B),1,wxPENSTYLE_SOLID));
         dc.DrawLine(tmp[0],tmp[1],tmp[2],tmp[3]);
         dc.DrawLine(tmp[2],tmp[3],tmp[2]+2,tmp[3]);
         dc.DrawLine(tmp[2],tmp[3],tmp[2],tmp[3]+2);
         dc.DrawLine(tmp[2],tmp[3],tmp[2]-2,tmp[3]);
         dc.DrawLine(tmp[2],tmp[3],tmp[2],tmp[3]-2);
        // dc.DrawLine(atmp[0],atmp[1],tmp[2],tmp[3]);
        //dc.DrawLine(atmp[2],atmp[3],tmp[2],tmp[3]);
     }
}

static void boomLine(wxDC &dc,Vector3d vec, double col,double max,Matrix4 &mat){
     double tmp[4];
     double atmp[4];
     double force = col/max;
     if(force>1.0){force=1.0;}
     if(vec.get2D(dc,tmp,atmp,mat)){
            if(force<=0.5){
         dc.SetPen(wxPen(RGB(0,(force*2)*255,(1-force*2)*255),1,wxPENSTYLE_SOLID));}
         else{
        dc.SetPen(wxPen(RGB(255,(2-force*2)*255,0),1,wxPENSTYLE_SOLID));
            }
         dc.DrawLine(tmp[0],tmp[1],tmp[2],tmp[3]);
        // dc.DrawLine(atmp[0],atmp[1],tmp[2],tmp[3]);
        //dc.DrawLine(atmp[2],atmp[3],tmp[2],tmp[3]);
        dc.DrawLine(tmp[2],tmp[3],tmp[2]+2,tmp[3]);
         dc.DrawLine(tmp[2],tmp[3],tmp[2],tmp[3]+2);
         dc.DrawLine(tmp[2],tmp[3],tmp[2]-2,tmp[3]);
         dc.DrawLine(tmp[2],tmp[3],tmp[2],tmp[3]-2);
     }
}

//funkcje przekszta³caj¹ce z lab 5
static Matrix4 translate(double dx, double dy, double dz, Matrix4 &t) {
    Matrix4 tr;
    
    tr.data[0][0]=1;
    tr.data[1][1]=1;
    tr.data[2][2]=1;
    tr.data[0][3]=dx;
    tr.data[1][3]=dy;
    tr.data[2][3]=dz;

    t=tr*t;
    return t;
}
static Matrix4 scale(double sx, double sy, double sz, Matrix4 &t) {   
    Matrix4 tr;
    
    tr.data[0][0]=sx;
    tr.data[1][1]=sy;
    tr.data[2][2]=sz;
    
    t=tr*t;
    return t;
}
static Matrix4 rotate(double phi, double psi, double theta, Matrix4 &t) {
    phi *= M_PI/180.;  psi *= M_PI/180.;  theta *= M_PI/180.;

    Matrix4 rx;
    rx.data[0][0]=1;
    rx.data[1][1]=cos(phi);
    rx.data[1][2]=sin(phi);
    rx.data[2][1]=-sin(phi);
    rx.data[2][2]=cos(phi);

    Matrix4 ry;
    ry.data[0][0]=cos(psi);
    ry.data[0][2]=-sin(psi);
    ry.data[1][1]=1;
    ry.data[2][0]=sin(psi);
    ry.data[2][2]=cos(psi);
   
    Matrix4 rz;
    rz.data[0][0]=cos(theta);
    rz.data[0][1]=sin(theta);
    rz.data[1][0]=-sin(theta);
    rz.data[1][1]= cos(theta);
    rz.data[2][2]= 1;
    
    
        t=rz*t;
    t=ry*t;
t=rx*t;
return t;
}
#endif
