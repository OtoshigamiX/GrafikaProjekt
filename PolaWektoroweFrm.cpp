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
	////Manual Code End
	
	EVT_CLOSE(PolaWektoroweFrm::OnClose)
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

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(5, 60), wxSize(335, 93));
	WxBoxSizer1->Add(WxPanel1, 1, wxEXPAND | wxALL, 5);

	WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_RIGHT | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer1_StaticBoxObj = new wxStaticBox(this, wxID_ANY, _("Wybor funkcji"));
	WxStaticBoxSizer1 = new wxStaticBoxSizer(WxStaticBoxSizer1_StaticBoxObj, wxHORIZONTAL);
	WxBoxSizer2->Add(WxStaticBoxSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton1 = new wxToggleButton(this, ID_WXTOGGLEBUTTON1, _("1"), wxPoint(10, 20), wxSize(25, 25), 0, wxDefaultValidator, _("WxToggleButton1"));
	WxStaticBoxSizer1->Add(WxToggleButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton2 = new wxToggleButton(this, ID_WXTOGGLEBUTTON2, _("2"), wxPoint(45, 20), wxSize(25, 25), 0, wxDefaultValidator, _("WxToggleButton2"));
	WxStaticBoxSizer1->Add(WxToggleButton2, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton3 = new wxToggleButton(this, ID_WXTOGGLEBUTTON3, _("3"), wxPoint(80, 20), wxSize(25, 25), 0, wxDefaultValidator, _("WxToggleButton3"));
	WxStaticBoxSizer1->Add(WxToggleButton3, 0, wxALIGN_CENTER | wxALL, 5);

	WxToggleButton4 = new wxToggleButton(this, ID_WXTOGGLEBUTTON4, _("4"), wxPoint(115, 20), wxSize(25, 25), 0, wxDefaultValidator, _("WxToggleButton4"));
	WxStaticBoxSizer1->Add(WxToggleButton4, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer3, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer4, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Rotacja X"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText1"));
	WxBoxSizer3->Add(WxStaticText1, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar1 = new wxScrollBar(this, ID_WXSCROLLBAR1, wxPoint(65, 5), wxSize(121, 16), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar1"));
	WxScrollBar1->Enable(false);
	WxBoxSizer3->Add(WxScrollBar1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("WxStaticText2"), wxPoint(196, 5), wxDefaultSize, 0, _("WxStaticText2"));
	WxBoxSizer3->Add(WxStaticText2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Rotacja Y"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText3"));
	WxBoxSizer4->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar2 = new wxScrollBar(this, ID_WXSCROLLBAR2, wxPoint(65, 5), wxSize(121, 16), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar2"));
	WxScrollBar2->Enable(false);
	WxBoxSizer4->Add(WxScrollBar2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("WxStaticText4"), wxPoint(196, 5), wxDefaultSize, 0, _("WxStaticText4"));
	WxBoxSizer4->Add(WxStaticText4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, _("Rotacja Z"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText5"));
	WxBoxSizer5->Add(WxStaticText5, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar3 = new wxScrollBar(this, ID_WXSCROLLBAR3, wxPoint(65, 5), wxSize(121, 16), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar3"));
	WxScrollBar3->Enable(false);
	WxBoxSizer5->Add(WxScrollBar3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText6 = new wxStaticText(this, ID_WXSTATICTEXT6, _("WxStaticText6"), wxPoint(196, 5), wxDefaultSize, 0, _("WxStaticText6"));
	WxBoxSizer5->Add(WxStaticText6, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer6, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer7, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer8, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText7 = new wxStaticText(this, ID_WXSTATICTEXT7, _("x0"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText7"));
	WxBoxSizer6->Add(WxStaticText7, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("WxEdit1"), wxPoint(31, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit1"));
	WxBoxSizer6->Add(WxEdit1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText8 = new wxStaticText(this, ID_WXSTATICTEXT8, _("y0"), wxPoint(86, 6), wxDefaultSize, 0, _("WxStaticText8"));
	WxBoxSizer6->Add(WxStaticText8, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, _("WxEdit2"), wxPoint(112, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit2"));
	WxBoxSizer6->Add(WxEdit2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText9 = new wxStaticText(this, ID_WXSTATICTEXT9, _("z0"), wxPoint(167, 6), wxDefaultSize, 0, _("WxStaticText9"));
	WxBoxSizer6->Add(WxStaticText9, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit3 = new wxTextCtrl(this, ID_WXEDIT3, _("WxEdit3"), wxPoint(192, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit3"));
	WxBoxSizer6->Add(WxEdit3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText10 = new wxStaticText(this, ID_WXSTATICTEXT10, _("x1"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText10"));
	WxBoxSizer7->Add(WxStaticText10, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit4 = new wxTextCtrl(this, ID_WXEDIT4, _("WxEdit4"), wxPoint(31, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit4"));
	WxBoxSizer7->Add(WxEdit4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText11 = new wxStaticText(this, ID_WXSTATICTEXT11, _("y1"), wxPoint(86, 6), wxDefaultSize, 0, _("WxStaticText11"));
	WxBoxSizer7->Add(WxStaticText11, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit5 = new wxTextCtrl(this, ID_WXEDIT5, _("WxEdit5"), wxPoint(112, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit5"));
	WxBoxSizer7->Add(WxEdit5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText12 = new wxStaticText(this, ID_WXSTATICTEXT12, _("z1"), wxPoint(167, 6), wxDefaultSize, 0, _("WxStaticText12"));
	WxBoxSizer7->Add(WxStaticText12, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit6 = new wxTextCtrl(this, ID_WXEDIT6, _("WxEdit6"), wxPoint(192, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit6"));
	WxBoxSizer7->Add(WxEdit6, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText13 = new wxStaticText(this, ID_WXSTATICTEXT13, _("Krok x"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText13"));
	WxBoxSizer8->Add(WxStaticText13, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit7 = new wxTextCtrl(this, ID_WXEDIT7, _("WxEdit7"), wxPoint(49, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit7"));
	WxBoxSizer8->Add(WxEdit7, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText14 = new wxStaticText(this, ID_WXSTATICTEXT14, _("Krok y"), wxPoint(104, 6), wxDefaultSize, 0, _("WxStaticText14"));
	WxBoxSizer8->Add(WxStaticText14, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit8 = new wxTextCtrl(this, ID_WXEDIT8, _("WxEdit8"), wxPoint(148, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit8"));
	WxBoxSizer8->Add(WxEdit8, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText15 = new wxStaticText(this, ID_WXSTATICTEXT15, _("Krok z"), wxPoint(203, 6), wxDefaultSize, 0, _("WxStaticText15"));
	WxBoxSizer8->Add(WxStaticText15, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit9 = new wxTextCtrl(this, ID_WXEDIT9, _("WxEdit9"), wxPoint(246, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit9"));
	WxBoxSizer8->Add(WxEdit9, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer9, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText16 = new wxStaticText(this, ID_WXSTATICTEXT16, _("Wartosci swobodne funkcji:"), wxPoint(5, 6), wxDefaultSize, 0, _("WxStaticText16"));
	WxBoxSizer9->Add(WxStaticText16, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit10 = new wxTextCtrl(this, ID_WXEDIT10, _("WxEdit10"), wxPoint(151, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit10"));
	WxBoxSizer9->Add(WxEdit10, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit11 = new wxTextCtrl(this, ID_WXEDIT11, _("WxEdit11"), wxPoint(206, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit11"));
	WxBoxSizer9->Add(WxEdit11, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit12 = new wxTextCtrl(this, ID_WXEDIT12, _("WxEdit12"), wxPoint(261, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit12"));
	WxBoxSizer9->Add(WxEdit12, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer10, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText17 = new wxStaticText(this, ID_WXSTATICTEXT17, _("Skala strzalek"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText17"));
	WxBoxSizer10->Add(WxStaticText17, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar4 = new wxScrollBar(this, ID_WXSCROLLBAR4, wxPoint(84, 5), wxSize(121, 16), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar4"));
	WxScrollBar4->Enable(false);
	WxBoxSizer10->Add(WxScrollBar4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText18 = new wxStaticText(this, ID_WXSTATICTEXT18, _("WxStaticText18"), wxPoint(215, 5), wxDefaultSize, 0, _("WxStaticText18"));
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

	WxCheckBox3 = new wxCheckBox(this, ID_WXCHECKBOX3, _("Plaszczyzna"), wxPoint(5, 6), wxSize(97, 17), 0, wxDefaultValidator, _("WxCheckBox3"));
	WxBoxSizer13->Add(WxCheckBox3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText19 = new wxStaticText(this, ID_WXSTATICTEXT19, _("A"), wxPoint(112, 6), wxDefaultSize, 0, _("WxStaticText19"));
	WxBoxSizer13->Add(WxStaticText19, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit13 = new wxTextCtrl(this, ID_WXEDIT13, _("WxEdit13"), wxPoint(133, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit13"));
	WxBoxSizer13->Add(WxEdit13, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText20 = new wxStaticText(this, ID_WXSTATICTEXT20, _("B"), wxPoint(188, 6), wxDefaultSize, 0, _("WxStaticText20"));
	WxBoxSizer13->Add(WxStaticText20, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit14 = new wxTextCtrl(this, ID_WXEDIT14, _("WxEdit14"), wxPoint(208, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit14"));
	WxBoxSizer13->Add(WxEdit14, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText21 = new wxStaticText(this, ID_WXSTATICTEXT21, _("C"), wxPoint(263, 6), wxDefaultSize, 0, _("WxStaticText21"));
	WxBoxSizer13->Add(WxStaticText21, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit15 = new wxTextCtrl(this, ID_WXEDIT15, _("WxEdit15"), wxPoint(284, 5), wxSize(45, 19), 0, wxDefaultValidator, _("WxEdit15"));
	WxBoxSizer13->Add(WxEdit15, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("PolaWektorowe"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
}

void PolaWektoroweFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}
