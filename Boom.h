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


static void boomLine(wxDC &dc,Vector3d vec, int R, int G, int B,Matrix4 &mat){
     double tmp[4];
     if(vec.get2D(dc,tmp,mat)){
         dc.SetPen(wxPen(RGB(R,G,B),1,wxPENSTYLE_SOLID));
         dc.DrawLine(tmp[0],tmp[1],tmp[2],tmp[3]);
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
