//---------------------------------------------------------------------------
//
// Name:        PolaWektoroweApp.h
// Author:      Grupa3Team
// Created:     12/2/2015 8:44:40 PM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __POLAWEKTOROWEFRMApp_h__
#define __POLAWEKTOROWEFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class PolaWektoroweFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
