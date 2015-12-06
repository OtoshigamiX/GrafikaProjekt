///-----------------------------------------------------------------
///
/// @file      PolaWektoroweFrm.cpp
/// @author    Grupa3Team
/// Created:   12/2/2015 8:44:40 PM
/// @section   DESCRIPTION
///            PolaWektoroweFrm class implementation
///
///------------------------------------------------------------------

#include "PolaWektoroweFrm.h"
#include <stdlib.h>
#include <string> 
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// PolaWektoroweFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(PolaWektoroweFrm,wxFrame)
	////Manual Code Start
	EVT_PAINT(PolaWektoroweFrm::Rysuj)
	////Manual Code End
	
	EVT_CLOSE(PolaWektoroweFrm::OnClose)
	
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR3,PolaWektoroweFrm::WxScrollBar3Scroll)
	
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR2,PolaWektoroweFrm::WxScrollBar2Scroll)
	
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR1,PolaWektoroweFrm::WxScrollBar1Scroll)
	EVT_TOGGLEBUTTON(ID_WXTOGGLEBUTTON4,PolaWektoroweFrm::WxToggleButton4Click)
	EVT_TOGGLEBUTTON(ID_WXTOGGLEBUTTON3,PolaWektoroweFrm::WxToggleButton3Click)
	EVT_TOGGLEBUTTON(ID_WXTOGGLEBUTTON2,PolaWektoroweFrm::WxToggleButton2Click)
	EVT_TOGGLEBUTTON(ID_WXTOGGLEBUTTON1,PolaWektoroweFrm::WxToggleButton1Click)
	
	EVT_UPDATE_UI(ID_PICPLACE,PolaWektoroweFrm::PicPlaceUpdateUI)
END_EVENT_TABLE()
////Event Table End

PolaWektoroweFrm::PolaWektoroweFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

PolaWektoroweFrm::~PolaWektoroweFrm()
{
}

void PolaWektoroweFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxBoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer1->Add(WxBoxSizer14, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	PicPlace = new wxPanel(this, ID_PICPLACE, wxPoint(5, 5), wxSize(162, 36));
	WxBoxSizer14->Add(PicPlace, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_RIGHT | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer1_StaticBoxObj = new wxStaticBox(this, wxID_ANY, _("Wybor funkcji"));
	WxStaticBoxSizer1 = new wxStaticBoxSizer(WxStaticBoxSizer1_StaticBoxObj, wxHORIZONTAL);
	WxBoxSizer2->Add(WxStaticBoxSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton1 = new wxToggleButton(this, ID_WXTOGGLEBUTTON1, _("1"), wxPoint(10, 20), wxSize(23, 25), 0, wxDefaultValidator, _("WxToggleButton1"));
	WxStaticBoxSizer1->Add(WxToggleButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton2 = new wxToggleButton(this, ID_WXTOGGLEBUTTON2, _("2"), wxPoint(43, 20), wxSize(25, 25), 0, wxDefaultValidator, _("WxToggleButton2"));
	WxStaticBoxSizer1->Add(WxToggleButton2, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton3 = new wxToggleButton(this, ID_WXTOGGLEBUTTON3, _("3"), wxPoint(78, 20), wxSize(26, 25), 0, wxDefaultValidator, _("WxToggleButton3"));
	WxStaticBoxSizer1->Add(WxToggleButton3, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton4 = new wxToggleButton(this, ID_WXTOGGLEBUTTON4, _("4"), wxPoint(114, 20), wxSize(25, 25), 0, wxDefaultValidator, _("WxToggleButton4"));
	WxStaticBoxSizer1->Add(WxToggleButton4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText22 = new wxStaticText(this, ID_WXSTATICTEXT22, _("Wybrana funkcja"), wxPoint(149, 24), wxDefaultSize, 0, _("WxStaticText22"));
	WxStaticBoxSizer1->Add(WxStaticText22, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Rotacja X"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText1"));
	WxBoxSizer3->Add(WxStaticText1, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar1 = new wxScrollBar(this, ID_WXSCROLLBAR1, wxPoint(65, 5), wxSize(121, 16), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar1"));
	WxScrollBar1->Enable(false);
	WxBoxSizer3->Add(WxScrollBar1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("1"), wxPoint(196, 5), wxDefaultSize, 0, _("WxStaticText2"));
	WxBoxSizer3->Add(WxStaticText2, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Rotacja Y"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText3"));
	WxBoxSizer4->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar2 = new wxScrollBar(this, ID_WXSCROLLBAR2, wxPoint(65, 5), wxSize(121, 16), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar2"));
	WxScrollBar2->Enable(false);
	WxBoxSizer4->Add(WxScrollBar2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("1"), wxPoint(196, 5), wxDefaultSize, 0, _("WxStaticText4"));
	WxBoxSizer4->Add(WxStaticText4, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, _("Rotacja Z"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText5"));
	WxBoxSizer5->Add(WxStaticText5, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar3 = new wxScrollBar(this, ID_WXSCROLLBAR3, wxPoint(65, 5), wxSize(121, 16), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar3"));
	WxScrollBar3->Enable(false);
	WxBoxSizer5->Add(WxScrollBar3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText6 = new wxStaticText(this, ID_WXSTATICTEXT6, _("1"), wxPoint(196, 5), wxDefaultSize, 0, _("WxStaticText6"));
	WxBoxSizer5->Add(WxStaticText6, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer6, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText7 = new wxStaticText(this, ID_WXSTATICTEXT7, _("x0"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText7"));
	WxBoxSizer6->Add(WxStaticText7, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("0.0"), wxPoint(31, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit1"));
	WxBoxSizer6->Add(WxEdit1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText8 = new wxStaticText(this, ID_WXSTATICTEXT8, _("y0"), wxPoint(86, 6), wxDefaultSize, 0, _("WxStaticText8"));
	WxBoxSizer6->Add(WxStaticText8, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, _("0.0"), wxPoint(112, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit2"));
	WxBoxSizer6->Add(WxEdit2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText9 = new wxStaticText(this, ID_WXSTATICTEXT9, _("z0"), wxPoint(167, 6), wxDefaultSize, 0, _("WxStaticText9"));
	WxBoxSizer6->Add(WxStaticText9, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit3 = new wxTextCtrl(this, ID_WXEDIT3, _("0.0"), wxPoint(192, 5), wxSize(43, 19), 0, wxDefaultValidator, _("WxEdit3"));
	WxBoxSizer6->Add(WxEdit3, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer7, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText10 = new wxStaticText(this, ID_WXSTATICTEXT10, _("x1"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText10"));
	WxBoxSizer7->Add(WxStaticText10, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit4 = new wxTextCtrl(this, ID_WXEDIT4, _("100.0"), wxPoint(31, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit4"));
	WxBoxSizer7->Add(WxEdit4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText11 = new wxStaticText(this, ID_WXSTATICTEXT11, _("y1"), wxPoint(86, 6), wxDefaultSize, 0, _("WxStaticText11"));
	WxBoxSizer7->Add(WxStaticText11, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit5 = new wxTextCtrl(this, ID_WXEDIT5, _("100.0"), wxPoint(112, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit5"));
	WxBoxSizer7->Add(WxEdit5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText12 = new wxStaticText(this, ID_WXSTATICTEXT12, _("z1"), wxPoint(167, 6), wxDefaultSize, 0, _("WxStaticText12"));
	WxBoxSizer7->Add(WxStaticText12, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit6 = new wxTextCtrl(this, ID_WXEDIT6, _("100.0"), wxPoint(192, 5), wxSize(43, 19), 0, wxDefaultValidator, _("WxEdit6"));
	WxBoxSizer7->Add(WxEdit6, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer8, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText13 = new wxStaticText(this, ID_WXSTATICTEXT13, _("Krok x"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText13"));
	WxBoxSizer8->Add(WxStaticText13, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit7 = new wxTextCtrl(this, ID_WXEDIT7, _("10.0"), wxPoint(49, 5), wxSize(44, 19), 0, wxDefaultValidator, _("WxEdit7"));
	WxBoxSizer8->Add(WxEdit7, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText14 = new wxStaticText(this, ID_WXSTATICTEXT14, _("Krok y"), wxPoint(103, 6), wxDefaultSize, 0, _("WxStaticText14"));
	WxBoxSizer8->Add(WxStaticText14, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit8 = new wxTextCtrl(this, ID_WXEDIT8, _("10.0"), wxPoint(147, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit8"));
	WxBoxSizer8->Add(WxEdit8, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText15 = new wxStaticText(this, ID_WXSTATICTEXT15, _("Krok z"), wxPoint(202, 6), wxDefaultSize, 0, _("WxStaticText15"));
	WxBoxSizer8->Add(WxStaticText15, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit9 = new wxTextCtrl(this, ID_WXEDIT9, _("10.0"), wxPoint(245, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit9"));
	WxBoxSizer8->Add(WxEdit9, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer9, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText16 = new wxStaticText(this, ID_WXSTATICTEXT16, _("Wartosci swobodne funkcji:"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText16"));
	WxBoxSizer9->Add(WxStaticText16, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit10 = new wxTextCtrl(this, ID_WXEDIT10, _("1.0"), wxPoint(151, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit10"));
	WxBoxSizer9->Add(WxEdit10, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit11 = new wxTextCtrl(this, ID_WXEDIT11, _("1.0"), wxPoint(206, 5), wxSize(46, 19), 0, wxDefaultValidator, _("WxEdit11"));
	WxBoxSizer9->Add(WxEdit11, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit12 = new wxTextCtrl(this, ID_WXEDIT12, _("1.0"), wxPoint(262, 5), wxSize(46, 19), 0, wxDefaultValidator, _("WxEdit12"));
	WxBoxSizer9->Add(WxEdit12, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer10, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText17 = new wxStaticText(this, ID_WXSTATICTEXT17, _("Skala strzalek"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText17"));
	WxBoxSizer10->Add(WxStaticText17, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar4 = new wxScrollBar(this, ID_WXSCROLLBAR4, wxPoint(84, 5), wxSize(122, 16), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar4"));
	WxScrollBar4->Enable(false);
	WxBoxSizer10->Add(WxScrollBar4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText18 = new wxStaticText(this, ID_WXSTATICTEXT18, _("WxStaticText18"), wxPoint(216, 5), wxDefaultSize, 0, _("WxStaticText18"));
	WxBoxSizer10->Add(WxStaticText18, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer11, 0, wxALIGN_CENTER | wxALL, 5);

	WxCheckBox1 = new wxCheckBox(this, ID_WXCHECKBOX1, _("Autoskala"), wxPoint(5, 5), wxSize(97, 17), 0, wxDefaultValidator, _("WxCheckBox1"));
	WxBoxSizer11->Add(WxCheckBox1, 0, wxALIGN_CENTER | wxALL, 5);

	WxCheckBox2 = new wxCheckBox(this, ID_WXCHECKBOX2, _("Kolory"), wxPoint(112, 5), wxSize(97, 17), 0, wxDefaultValidator, _("WxCheckBox2"));
	WxBoxSizer11->Add(WxCheckBox2, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer12, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Zapisz obraz"), wxPoint(5, 5), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));
	WxBoxSizer12->Add(WxButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer13, 0, wxALIGN_CENTER | wxALL, 5);

	WxCheckBox3 = new wxCheckBox(this, ID_WXCHECKBOX3, _("Plaszczyzna"), wxPoint(5, 5), wxSize(97, 19), 0, wxDefaultValidator, _("WxCheckBox3"));
	WxBoxSizer13->Add(WxCheckBox3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText19 = new wxStaticText(this, ID_WXSTATICTEXT19, _("A"), wxPoint(112, 6), wxDefaultSize, 0, _("WxStaticText19"));
	WxBoxSizer13->Add(WxStaticText19, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit13 = new wxTextCtrl(this, ID_WXEDIT13, _("1.0"), wxPoint(133, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit13"));
	WxBoxSizer13->Add(WxEdit13, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText20 = new wxStaticText(this, ID_WXSTATICTEXT20, _("B"), wxPoint(188, 6), wxDefaultSize, 0, _("WxStaticText20"));
	WxBoxSizer13->Add(WxStaticText20, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit14 = new wxTextCtrl(this, ID_WXEDIT14, _("1.0"), wxPoint(208, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit14"));
	WxBoxSizer13->Add(WxEdit14, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText21 = new wxStaticText(this, ID_WXSTATICTEXT21, _("C"), wxPoint(263, 6), wxDefaultSize, 0, _("WxStaticText21"));
	WxBoxSizer13->Add(WxStaticText21, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit15 = new wxTextCtrl(this, ID_WXEDIT15, _("1.0"), wxPoint(284, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit15"));
	WxBoxSizer13->Add(WxEdit15, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("PolaWektorowe"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
	//Fullscreen tu instrukcja :http://docs.wxwidgets.org/trunk/toplevel_8h.html#afccd240f973cf154952fb917c9209719a4625145320cb6292879930fddaec9846
	//wxFrame::ShowFullScreen(true,wxFULLSCREEN_NOTOOLBAR );
	WxScrollBar1->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar1->Enable(true);
	WxScrollBar2->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar2->Enable(true);
	WxScrollBar3->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar3->Enable(true);
}
////////////////////////////////////////////////////////////Program wlasciwy////////////////////////////////////////////////////////////////////////////////////
void PolaWektoroweFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}
void PolaWektoroweFrm::Rysuj(wxPaintEvent& event) 
{
  Draw();
}
void  PolaWektoroweFrm::Draw(){
    Matrix4 mat;//mozna dodac w jakiej klasie sotrage
    Vector3d vecTab[10][10][10];
    wxClientDC clientDC(PicPlace);
    //jak siê w³¹czy bufferedDC to translate w funkcji rzutuj¹cej ma problem z GetSize(), bo buffered dc cache'uje wartosci, bug jest potwierdzony na stonie biblioteki
    wxBufferedDC dc(&clientDC);
    //poni¿sze tylko gdy chcemy obliczaæ w,h za kazdym razem i korzystamy w funkcji rzutuj¹cej tak, ¿e pobieramy w i h z Matrix4 mat
    int w,h;
    dc.Clear();
    PicPlace->GetSize(&w,&h);
    wxSize size;
    size=this->GetClientSize();
    mat.setWinW(size.GetWidth());
    mat.setWinH(size.GetHeight());
    ////tu koniec

    
    dc.SetBackground(wxBrush(RGB(255,255,255)));
    
    //wspolrzedna Z musi byæ jakos dzielona wzgledem x,y, najlepiej przez 100 chyba, bo rozmiary ekranu np 200x200 to x=y=200, ale z sie smiesznie skaluje i powinna byc rowna z=2
    //z min=0.6
   /* Vector3d test1(10,10,1,510,210,1);/////////////////testowe
    Vector3d test3(1,1,0.6,500,200,0.6);
    Vector3d test2(50,50,1,400,350,4);
    
    //argumenty (wxDC,Vector3d,R,G,B,Matrix4)
    boomLine(dc,test1,255,0,0,mat);
    boomLine(dc,test3,0,0,255,mat);
    dc.SetPen(wxPen(RGB(0,255,0),1,wxPENSTYLE_SOLID));
    dc.DrawLine(40,40,390,340);*/
    //kurwa dzia³a, ma³e linie siê pojawi³y xD
     double StartX,StartY,StartZ,ZakresX,ZakresY,ZakresZ, KrokX,KrokY, KrokZ;
    StartX=wxAtod(WxEdit1->GetValue());
    StartY=wxAtod(WxEdit2->GetValue());
    StartY=wxAtod(WxEdit3->GetValue());
    ZakresX=wxAtod(WxEdit4->GetValue());
    ZakresY=wxAtod(WxEdit5->GetValue());
    ZakresZ=wxAtod(WxEdit6->GetValue());
    KrokX=wxAtod(WxEdit7->GetValue());
    KrokY=wxAtod(WxEdit8->GetValue());
    KrokZ=wxAtod(WxEdit9->GetValue());
    
    //obrot z
    mat=translate(-ZakresX/2+5,-ZakresY/2+5,0,mat);
    mat=rotate(0,0,WxScrollBar3->GetThumbPosition(),mat);
    mat=translate(ZakresX/2-5,ZakresY/2-5,0,mat);
    //obrot x
    mat=translate(0,-ZakresY/2,-(0.7+ ZakresZ)/2,mat);
    mat=rotate(WxScrollBar1->GetThumbPosition(),0,0,mat);
    mat=translate(0,ZakresY/2,(0.7+ ZakresZ)/2,mat);
    //obrot y
    mat=translate(-ZakresX/2,0,-(0.7+ ZakresZ)/2,mat);
    mat=rotate(0,WxScrollBar2->GetThumbPosition(),0,mat);
    mat=translate(ZakresX/2,0,(0.7+ ZakresZ)/2,mat);
    
    mat=scale(w/150,w/150,1,mat);
    mat=translate(w/2-ZakresX*w/300,h/2-ZakresY*w/300+100,0,mat);
    
    
    // moja propozycja, ale nie dziala niestety, zawiera duze complexity
   /* for(double i=wxAtod(WxEdit1->GetValue());i<=wxAtod(WxEdit4->GetValue());i=i+wxAtod(WxEdit7->GetValue())){
        for(double j=wxAtod(WxEdit2->GetValue());j<=wxAtod(WxEdit5->GetValue());j=j+wxAtod(WxEdit8->GetValue())){
            for(double k=wxAtod(WxEdit3->GetValue());k<=wxAtod(WxEdit6->GetValue());k=k+wxAtod(WxEdit9->GetValue())){
                if(WxToggleButton1->GetValue()){
                    boomLine(dc,Vector3d(i,j,k,wxAtod(WxEdit10->GetValue())*i,wxAtod(WxEdit11->GetValue())*j,(wxAtod(WxEdit12->GetValue())*i)/10.0),255,0,0,mat);
                }
                if(WxToggleButton2->GetValue()){
                    boomLine(dc,Vector3d(2.0+i*5,2.0+j*5,3.0+(k*5.0)/10.0,2*i*5,2*j*5,2.0*k),i*25,j*25,k*25,mat);
                }
                if(WxToggleButton3->GetValue()){
                    boomLine(dc,Vector3d(i,j,k,2*i,2*j,(2.0*k)/10.0),i*25,j*25,k*25,mat);
                }
                if(WxToggleButton4->GetValue()){
                    boomLine(dc,Vector3d(i,j,k,2*i,2*j,(2.0*k)/10.0),255,0,0,mat);
                }
                // WxStaticText22->SetLabel("zzzzz");
            }
        }
    }
    
    */
    
    
    if(ZakresX<ZakresY)Matrix4::endZ=ZakresX;
    else Matrix4::endZ=ZakresY;
    for(double i=StartX;i<ZakresX;i+=KrokX){
        for(double j=StartY;j<ZakresY;j+=KrokY){
            for(double k=StartZ; k<ZakresZ;k+=KrokZ){
                //takie dziwne rzeczy porobione ¿eby wyœwietla³o w jakims normalnym po³o¿eniu, tzn to dodawanie i mno¿enie
                //vecTab[k][l][m].setStart(double (k*50),double (l*50)+200,double(m));
                //jakas tam funkcja, ale efekt jest :D
                //vecTab[k][l][m].setEnd(double ((k*50))*1.3,double (((l+1)*50)+170)*0.8,double(m));
                //boomLine(dc,Vector3d(k*5,l*5+20,m,k*5*1.3,(((l+1)*5)+17)*0.8,m),k*25,l*25,m*25,mat);
                if(WxToggleButton1->GetValue()){
                    boomLine(dc,Vector3d(i,j,k,wxAtod(WxEdit10->GetValue())*i,wxAtod(WxEdit11->GetValue())*j,(wxAtod(WxEdit12->GetValue())*i)),255,0,0,mat);
                }
                if(WxToggleButton2->GetValue()){
                    boomLine(dc,Vector3d(i,j,k,wxAtod(WxEdit10->GetValue())*sin(i),wxAtod(WxEdit11->GetValue())*cos(j),(wxAtod(WxEdit12->GetValue())*k)),i*25,j*25,k*25,mat);
                }
                if(WxToggleButton3->GetValue()){
                   boomLine(dc,Vector3d(i,j,k,wxAtod(WxEdit10->GetValue())*k,wxAtod(WxEdit11->GetValue())*i,(wxAtod(WxEdit12->GetValue())*j)),i*25,j*25,k*25,mat);
                }
                if(WxToggleButton4->GetValue()){
                   boomLine(dc,Vector3d(i,j,k,wxAtod(WxEdit10->GetValue())+i,wxAtod(WxEdit11->GetValue())+j,(wxAtod(WxEdit12->GetValue())+k)),i*25,j*25,k*25,mat);
                }
                
            }
        }
    } 

}

/*
 * PicPlaceUpdateUI
 */
void PolaWektoroweFrm::PicPlaceUpdateUI(wxUpdateUIEvent& event)
{
	Draw();
}

//Guziczki - nacisniesz, usuwa zaznaczenie innych i przy okazji pisze jakiej funkcji uzywamy.



/*
 * WxToggleButton1Click
 */
void PolaWektoroweFrm::WxToggleButton1Click(wxCommandEvent& event)
{
	WxToggleButton2->SetValue(false);
    WxToggleButton3->SetValue(false);
    WxToggleButton4->SetValue(false);
    WxStaticText22->SetLabel("x=ax,y=by,z=cx");
}



/*
 * WxToggleButton2Click
 */
void PolaWektoroweFrm::WxToggleButton2Click(wxCommandEvent& event)
{
    WxToggleButton1->SetValue(false);
    WxToggleButton3->SetValue(false);
    WxToggleButton4->SetValue(false);
    WxStaticText22->SetLabel("x=asin(x),y=bcos(y),z=cz");
}



/*
 * WxToggleButton3Click
 */
void PolaWektoroweFrm::WxToggleButton3Click(wxCommandEvent& event)
{
	WxToggleButton1->SetValue(false);
    WxToggleButton2->SetValue(false);
    WxToggleButton4->SetValue(false);
     WxStaticText22->SetLabel("x=az,y=bx,z=cy");
}



/*
 * WxToggleButton4Click
 */
void PolaWektoroweFrm::WxToggleButton4Click(wxCommandEvent& event)
{
	WxToggleButton1->SetValue(false);
    WxToggleButton2->SetValue(false);
    WxToggleButton3->SetValue(false);
    WxStaticText22->SetLabel("x=x+a,y=y+b,z=c+z");
}





/*
 * WxEdit14Updated
 */
void PolaWektoroweFrm::WxEdit14Updated(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * WxScrollBar1Scroll
 */
void PolaWektoroweFrm::WxScrollBar1Scroll(wxScrollEvent& event)
{
    wxString str;
    str<<(WxScrollBar1->GetThumbPosition());
    WxStaticText2->SetLabel(str);
    Draw();
}

/*
 * WxScrollBar2Scroll
 */
void PolaWektoroweFrm::WxScrollBar2Scroll(wxScrollEvent& event)
{
    wxString str;
    str<<(WxScrollBar2->GetThumbPosition());
    WxStaticText4->SetLabel(str);
    Draw();
}

/*
 * WxScrollBar3Scroll
 */
void PolaWektoroweFrm::WxScrollBar3Scroll(wxScrollEvent& event)
{
    wxString str;
    str<<(WxScrollBar3->GetThumbPosition());
    WxStaticText6->SetLabel(str);
    Draw();
}
