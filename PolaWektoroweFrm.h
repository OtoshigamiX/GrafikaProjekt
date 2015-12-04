///-----------------------------------------------------------------
///
/// @file      PolaWektoroweFrm.h
/// @author    Grupa3Team
/// Created:   12/2/2015 8:44:40 PM
/// @section   DESCRIPTION
///            PolaWektoroweFrm class declaration
///
///------------------------------------------------------------------

#ifndef __POLAWEKTOROWEFRM_H__
#define __POLAWEKTOROWEFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif
#include "Boom.h"
//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/scrolbar.h>
#include <wx/stattext.h>
#include <wx/tglbtn.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/dcbuffer.h>
////Header Include End

////Dialog Style Start
#undef PolaWektoroweFrm_STYLE
#define PolaWektoroweFrm_STYLE wxFULL_REPAINT_ON_RESIZE | wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class PolaWektoroweFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		PolaWektoroweFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("PolaWektorowe"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = PolaWektoroweFrm_STYLE);
		virtual ~PolaWektoroweFrm();
		void Rysuj(wxPaintEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxTextCtrl *WxEdit15;
		wxStaticText *WxStaticText21;
		wxTextCtrl *WxEdit14;
		wxStaticText *WxStaticText20;
		wxTextCtrl *WxEdit13;
		wxStaticText *WxStaticText19;
		wxCheckBox *WxCheckBox3;
		wxBoxSizer *WxBoxSizer13;
		wxButton *WxButton1;
		wxBoxSizer *WxBoxSizer12;
		wxCheckBox *WxCheckBox2;
		wxCheckBox *WxCheckBox1;
		wxBoxSizer *WxBoxSizer11;
		wxStaticText *WxStaticText18;
		wxScrollBar *WxScrollBar4;
		wxStaticText *WxStaticText17;
		wxBoxSizer *WxBoxSizer10;
		wxTextCtrl *WxEdit12;
		wxTextCtrl *WxEdit11;
		wxTextCtrl *WxEdit10;
		wxStaticText *WxStaticText16;
		wxBoxSizer *WxBoxSizer9;
		wxTextCtrl *WxEdit9;
		wxStaticText *WxStaticText15;
		wxTextCtrl *WxEdit8;
		wxStaticText *WxStaticText14;
		wxTextCtrl *WxEdit7;
		wxStaticText *WxStaticText13;
		wxBoxSizer *WxBoxSizer8;
		wxTextCtrl *WxEdit6;
		wxStaticText *WxStaticText12;
		wxTextCtrl *WxEdit5;
		wxStaticText *WxStaticText11;
		wxTextCtrl *WxEdit4;
		wxStaticText *WxStaticText10;
		wxBoxSizer *WxBoxSizer7;
		wxTextCtrl *WxEdit3;
		wxStaticText *WxStaticText9;
		wxTextCtrl *WxEdit2;
		wxStaticText *WxStaticText8;
		wxTextCtrl *WxEdit1;
		wxStaticText *WxStaticText7;
		wxBoxSizer *WxBoxSizer6;
		wxStaticText *WxStaticText6;
		wxScrollBar *WxScrollBar3;
		wxStaticText *WxStaticText5;
		wxBoxSizer *WxBoxSizer5;
		wxStaticText *WxStaticText4;
		wxScrollBar *WxScrollBar2;
		wxStaticText *WxStaticText3;
		wxBoxSizer *WxBoxSizer4;
		wxStaticText *WxStaticText2;
		wxScrollBar *WxScrollBar1;
		wxStaticText *WxStaticText1;
		wxBoxSizer *WxBoxSizer3;
		wxToggleButton *WxToggleButton4;
		wxToggleButton *WxToggleButton3;
		wxToggleButton *WxToggleButton2;
		wxToggleButton *WxToggleButton1;
		wxStaticBoxSizer *WxStaticBoxSizer1;
		wxBoxSizer *WxBoxSizer2;
		wxPanel *PicPlace;
		wxBoxSizer *WxBoxSizer14;
		wxBoxSizer *WxBoxSizer1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXEDIT15 = 1066,
			ID_WXSTATICTEXT21 = 1065,
			ID_WXEDIT14 = 1064,
			ID_WXSTATICTEXT20 = 1063,
			ID_WXEDIT13 = 1062,
			ID_WXSTATICTEXT19 = 1060,
			ID_WXCHECKBOX3 = 1059,
			ID_WXBUTTON1 = 1057,
			ID_WXCHECKBOX2 = 1055,
			ID_WXCHECKBOX1 = 1054,
			ID_WXSTATICTEXT18 = 1052,
			ID_WXSCROLLBAR4 = 1051,
			ID_WXSTATICTEXT17 = 1050,
			ID_WXEDIT12 = 1048,
			ID_WXEDIT11 = 1047,
			ID_WXEDIT10 = 1046,
			ID_WXSTATICTEXT16 = 1045,
			ID_WXEDIT9 = 1043,
			ID_WXSTATICTEXT15 = 1042,
			ID_WXEDIT8 = 1041,
			ID_WXSTATICTEXT14 = 1040,
			ID_WXEDIT7 = 1039,
			ID_WXSTATICTEXT13 = 1038,
			ID_WXEDIT6 = 1037,
			ID_WXSTATICTEXT12 = 1036,
			ID_WXEDIT5 = 1035,
			ID_WXSTATICTEXT11 = 1034,
			ID_WXEDIT4 = 1033,
			ID_WXSTATICTEXT10 = 1032,
			ID_WXEDIT3 = 1031,
			ID_WXSTATICTEXT9 = 1030,
			ID_WXEDIT2 = 1029,
			ID_WXSTATICTEXT8 = 1028,
			ID_WXEDIT1 = 1027,
			ID_WXSTATICTEXT7 = 1026,
			ID_WXSTATICTEXT6 = 1021,
			ID_WXSCROLLBAR3 = 1020,
			ID_WXSTATICTEXT5 = 1019,
			ID_WXSTATICTEXT4 = 1018,
			ID_WXSCROLLBAR2 = 1017,
			ID_WXSTATICTEXT3 = 1016,
			ID_WXSTATICTEXT2 = 1015,
			ID_WXSCROLLBAR1 = 1014,
			ID_WXSTATICTEXT1 = 1013,
			ID_WXTOGGLEBUTTON4 = 1009,
			ID_WXTOGGLEBUTTON3 = 1007,
			ID_WXTOGGLEBUTTON2 = 1006,
			ID_WXTOGGLEBUTTON1 = 1005,
			ID_PICPLACE = 1068,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
