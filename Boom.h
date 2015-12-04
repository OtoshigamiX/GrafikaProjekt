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


static void boomLine(wxDC &dc,Vector3d vec, int R, int G, int B,Matrix4 mat){
     double tmp[4];
     if(vec.get2D(dc,tmp,mat)){
         dc.SetPen(wxPen(RGB(R,G,B),1,wxPENSTYLE_SOLID));
         dc.DrawLine(tmp[0],tmp[1],tmp[2],tmp[3]);
     }
}
#endif
