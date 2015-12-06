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

	PicPlace = new wxPanel(this, ID_PICPLACE, wxPoint(5, 5), wxSize(186, 41));
	WxBoxSizer14->Add(PicPlace, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_RIGHT | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer1_StaticBoxObj = new wxStaticBox(this, wxID_ANY, _("Wybor funkcji"));
	WxStaticBoxSizer1 = new wxStaticBoxSizer(WxStaticBoxSizer1_StaticBoxObj, wxHORIZONTAL);
	WxBoxSizer2->Add(WxStaticBoxSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton1 = new wxToggleButton(this, ID_WXTOGGLEBUTTON1, _("1"), wxPoint(10, 20), wxSize(27, 29), 0, wxDefaultValidator, _("WxToggleButton1"));
	WxStaticBoxSizer1->Add(WxToggleButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton2 = new wxToggleButton(this, ID_WXTOGGLEBUTTON2, _("2"), wxPoint(47, 20), wxSize(29, 29), 0, wxDefaultValidator, _("WxToggleButton2"));
	WxStaticBoxSizer1->Add(WxToggleButton2, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton3 = new wxToggleButton(this, ID_WXTOGGLEBUTTON3, _("3"), wxPoint(86, 20), wxSize(30, 29), 0, wxDefaultValidator, _("WxToggleButton3"));
	WxStaticBoxSizer1->Add(WxToggleButton3, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton4 = new wxToggleButton(this, ID_WXTOGGLEBUTTON4, _("4"), wxPoint(126, 20), wxSize(29, 29), 0, wxDefaultValidator, _("WxToggleButton4"));
	WxStaticBoxSizer1->Add(WxToggleButton4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText22 = new wxStaticText(this, ID_WXSTATICTEXT22, _("Wybrana funkcja"), wxPoint(165, 25), wxDefaultSize, 0, _("WxStaticText22"));
	WxStaticBoxSizer1->Add(WxStaticText22, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Rotacja X"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText1"));
	WxBoxSizer3->Add(WxStaticText1, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar1 = new wxScrollBar(this, ID_WXSCROLLBAR1, wxPoint(68, 5), wxSize(140, 18), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar1"));
	WxScrollBar1->Enable(false);
	WxBoxSizer3->Add(WxScrollBar1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("WxStaticText2"), wxPoint(218, 5), wxDefaultSize, 0, _("WxStaticText2"));
	WxBoxSizer3->Add(WxStaticText2, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Rotacja Y"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText3"));
	WxBoxSizer4->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar2 = new wxScrollBar(this, ID_WXSCROLLBAR2, wxPoint(68, 5), wxSize(140, 18), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar2"));
	WxScrollBar2->Enable(false);
	WxBoxSizer4->Add(WxScrollBar2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("WxStaticText4"), wxPoint(218, 5), wxDefaultSize, 0, _("WxStaticText4"));
	WxBoxSizer4->Add(WxStaticText4, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, _("Rotacja Z"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText5"));
	WxBoxSizer5->Add(WxStaticText5, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar3 = new wxScrollBar(this, ID_WXSCROLLBAR3, wxPoint(68, 5), wxSize(140, 18), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar3"));
	WxScrollBar3->Enable(false);
	WxBoxSizer5->Add(WxScrollBar3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText6 = new wxStaticText(this, ID_WXSTATICTEXT6, _("WxStaticText6"), wxPoint(218, 5), wxDefaultSize, 0, _("WxStaticText6"));
	WxBoxSizer5->Add(WxStaticText6, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer6, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText7 = new wxStaticText(this, ID_WXSTATICTEXT7, _("x0"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText7"));
	WxBoxSizer6->Add(WxStaticText7, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("0.0"), wxPoint(30, 5), wxSize(52, 22), 0, wxDefaultValidator, _("WxEdit1"));
	WxBoxSizer6->Add(WxEdit1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText8 = new wxStaticText(this, ID_WXSTATICTEXT8, _("y0"), wxPoint(92, 6), wxDefaultSize, 0, _("WxStaticText8"));
	WxBoxSizer6->Add(WxStaticText8, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, _("0.0"), wxPoint(118, 5), wxSize(52, 22), 0, wxDefaultValidator, _("WxEdit2"));
	WxBoxSizer6->Add(WxEdit2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText9 = new wxStaticText(this, ID_WXSTATICTEXT9, _("z0"), wxPoint(180, 6), wxDefaultSize, 0, _("WxStaticText9"));
	WxBoxSizer6->Add(WxStaticText9, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit3 = new wxTextCtrl(this, ID_WXEDIT3, _("0.0"), wxPoint(205, 5), wxSize(50, 22), 0, wxDefaultValidator, _("WxEdit3"));
	WxBoxSizer6->Add(WxEdit3, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer7, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText10 = new wxStaticText(this, ID_WXSTATICTEXT10, _("x1"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText10"));
	WxBoxSizer7->Add(WxStaticText10, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit4 = new wxTextCtrl(this, ID_WXEDIT4, _("100.0"), wxPoint(30, 5), wxSize(52, 22), 0, wxDefaultValidator, _("WxEdit4"));
	WxBoxSizer7->Add(WxEdit4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText11 = new wxStaticText(this, ID_WXSTATICTEXT11, _("y1"), wxPoint(92, 6), wxDefaultSize, 0, _("WxStaticText11"));
	WxBoxSizer7->Add(WxStaticText11, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit5 = new wxTextCtrl(this, ID_WXEDIT5, _("100.0"), wxPoint(118, 5), wxSize(52, 22), 0, wxDefaultValidator, _("WxEdit5"));
	WxBoxSizer7->Add(WxEdit5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText12 = new wxStaticText(this, ID_WXSTATICTEXT12, _("z1"), wxPoint(180, 6), wxDefaultSize, 0, _("WxStaticText12"));
	WxBoxSizer7->Add(WxStaticText12, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit6 = new wxTextCtrl(this, ID_WXEDIT6, _("100.0"), wxPoint(205, 5), wxSize(50, 22), 0, wxDefaultValidator, _("WxEdit6"));
	WxBoxSizer7->Add(WxEdit6, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer8, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText13 = new wxStaticText(this, ID_WXSTATICTEXT13, _("Krok x"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText13"));
	WxBoxSizer8->Add(WxStaticText13, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit7 = new wxTextCtrl(this, ID_WXEDIT7, _("10.0"), wxPoint(51, 5), wxSize(50, 22), 0, wxDefaultValidator, _("WxEdit7"));
	WxBoxSizer8->Add(WxEdit7, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText14 = new wxStaticText(this, ID_WXSTATICTEXT14, _("Krok y"), wxPoint(111, 6), wxDefaultSize, 0, _("WxStaticText14"));
	WxBoxSizer8->Add(WxStaticText14, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit8 = new wxTextCtrl(this, ID_WXEDIT8, _("10.0"), wxPoint(158, 5), wxSize(52, 22), 0, wxDefaultValidator, _("WxEdit8"));
	WxBoxSizer8->Add(WxEdit8, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText15 = new wxStaticText(this, ID_WXSTATICTEXT15, _("Krok z"), wxPoint(220, 6), wxDefaultSize, 0, _("WxStaticText15"));
	WxBoxSizer8->Add(WxStaticText15, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit9 = new wxTextCtrl(this, ID_WXEDIT9, _("10.0"), wxPoint(266, 5), wxSize(52, 22), 0, wxDefaultValidator, _("WxEdit9"));
	WxBoxSizer8->Add(WxEdit9, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer9, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText16 = new wxStaticText(this, ID_WXSTATICTEXT16, _("Wartosci swobodne funkcji:"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText16"));
	WxBoxSizer9->Add(WxStaticText16, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit10 = new wxTextCtrl(this, ID_WXEDIT10, _("1.0"), wxPoint(165, 5), wxSize(52, 22), 0, wxDefaultValidator, _("WxEdit10"));
	WxBoxSizer9->Add(WxEdit10, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit11 = new wxTextCtrl(this, ID_WXEDIT11, _("1.0"), wxPoint(229, 5), wxSize(52, 22), 0, wxDefaultValidator, _("WxEdit11"));
	WxBoxSizer9->Add(WxEdit11, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit12 = new wxTextCtrl(this, ID_WXEDIT12, _("1.0"), wxPoint(289, 5), wxSize(53, 22), 0, wxDefaultValidator, _("WxEdit12"));
	WxBoxSizer9->Add(WxEdit12, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer10, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText17 = new wxStaticText(this, ID_WXSTATICTEXT17, _("Skala strzalek"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText17"));
	WxBoxSizer10->Add(WxStaticText17, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar4 = new wxScrollBar(this, ID_WXSCROLLBAR4, wxPoint(88, 5), wxSize(141, 18), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar4"));
	WxScrollBar4->Enable(false);
	WxBoxSizer10->Add(WxScrollBar4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText18 = new wxStaticText(this, ID_WXSTATICTEXT18, _("WxStaticText18"), wxPoint(239, 5), wxDefaultSize, 0, _("WxStaticText18"));
	WxBoxSizer10->Add(WxStaticText18, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer11, 0, wxALIGN_CENTER | wxALL, 5);

	WxCheckBox1 = new wxCheckBox(this, ID_WXCHECKBOX1, _("Autoskala"), wxPoint(5, 5), wxSize(112, 19), 0, wxDefaultValidator, _("WxCheckBox1"));
	WxBoxSizer11->Add(WxCheckBox1, 0, wxALIGN_CENTER | wxALL, 5);

	WxCheckBox2 = new wxCheckBox(this, ID_WXCHECKBOX2, _("Kolory"), wxPoint(127, 5), wxSize(112, 19), 0, wxDefaultValidator, _("WxCheckBox2"));
	WxBoxSizer11->Add(WxCheckBox2, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer12, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Zapisz obraz"), wxPoint(5, 5), wxSize(86, 29), 0, wxDefaultValidator, _("WxButton1"));
	WxBoxSizer12->Add(WxButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer13, 0, wxALIGN_CENTER | wxALL, 5);

	WxCheckBox3 = new wxCheckBox(this, ID_WXCHECKBOX3, _("Plaszczyzna"), wxPoint(5, 5), wxSize(112, 21), 0, wxDefaultValidator, _("WxCheckBox3"));
	WxBoxSizer13->Add(WxCheckBox3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText19 = new wxStaticText(this, ID_WXSTATICTEXT19, _("A"), wxPoint(127, 6), wxDefaultSize, 0, _("WxStaticText19"));
	WxBoxSizer13->Add(WxStaticText19, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit13 = new wxTextCtrl(this, ID_WXEDIT13, _("1.0"), wxPoint(149, 5), wxSize(52, 22), 0, wxDefaultValidator, _("WxEdit13"));
	WxBoxSizer13->Add(WxEdit13, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText20 = new wxStaticText(this, ID_WXSTATICTEXT20, _("B"), wxPoint(211, 6), wxDefaultSize, 0, _("WxStaticText20"));
	WxBoxSizer13->Add(WxStaticText20, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit14 = new wxTextCtrl(this, ID_WXEDIT14, _("1.0"), wxPoint(232, 5), wxSize(52, 22), 0, wxDefaultValidator, _("WxEdit14"));
	WxBoxSizer13->Add(WxEdit14, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText21 = new wxStaticText(this, ID_WXSTATICTEXT21, _("C"), wxPoint(294, 6), wxDefaultSize, 0, _("WxStaticText21"));
	WxBoxSizer13->Add(WxStaticText21, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit15 = new wxTextCtrl(this, ID_WXEDIT15, _("1.0"), wxPoint(316, 5), wxSize(52, 22), 0, wxDefaultValidator, _("WxEdit15"));
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
    PicPlace->GetSize(&w,&h);
    wxSize size;
    size=this->GetClientSize();
    mat.setWinW(size.GetWidth());
    mat.setWinH(size.GetHeight());
    ////tu koniec
    mat=rotate(0,0,0,mat);
    mat=translate(0,0,0,mat);
    mat=scale(1,1,1,mat);
    
    dc.SetBackground(wxBrush(RGB(255,255,255)));
    dc.Clear();
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
    
    
    // moja propozycja, ale nie dziala niestety, zawiera duze complexity
    for(double i=wxAtod(WxEdit1->GetValue());i<=wxAtod(WxEdit4->GetValue());i=i+wxAtod(WxEdit7->GetValue())){
        for(double j=wxAtod(WxEdit2->GetValue());j<=wxAtod(WxEdit5->GetValue());j=j+wxAtod(WxEdit8->GetValue())){
            for(double k=wxAtod(WxEdit3->GetValue());k<=wxAtod(WxEdit6->GetValue());k=k+wxAtod(WxEdit9->GetValue())){
                if(WxToggleButton1->GetValue()){
                    boomLine(dc,Vector3d(i,j,k,wxAtod(WxEdit10->GetValue())*i,wxAtod(WxEdit11->GetValue())*j,(wxAtod(WxEdit12->GetValue())*i)/10.0),255,0,0,mat);
                }
                if(WxToggleButton2->GetValue()){
                    boomLine(dc,Vector3d(2.0+i*5,2.0+j*5,3.0+(k*5.0)/10.0,2*i*5,2*j*5,3.0+(2.0*k)/10.0),i*25,j*25,k*25,mat);
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
    
    /*
    for(int k=0;k<10;k++){
        for(int l=0;l<10;l++){
            for(int m=0; m<10;m++){
                //takie dziwne rzeczy porobione ¿eby wyœwietla³o w jakims normalnym po³o¿eniu, tzn to dodawanie i mno¿enie
                vecTab[k][l][m].setStart(double (k*50)+50,double (l*50)+200,double(0.8+(m/10.0)));
                //jakas tam funkcja, ale efekt jest :D
                vecTab[k][l][m].setEnd(double ((k*50)+50.0)*1.3,double (((l+1)*50)+170)*0.8,double(0.8 +(m/10.0)));
                boomLine(dc,vecTab[k][l][m],k*25,l*25,m*25,mat);
            }
        }
    } */
    
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
