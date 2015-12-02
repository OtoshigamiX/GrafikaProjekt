//---------------------------------------------------------------------------
//
// Name:        PolaWektoroweApp.cpp
// Author:      Grupa3Team
// Created:     12/2/2015 8:44:40 PM
// Description: 
//
//---------------------------------------------------------------------------

#include "PolaWektoroweApp.h"
#include "PolaWektoroweFrm.h"

IMPLEMENT_APP(PolaWektoroweFrmApp)

bool PolaWektoroweFrmApp::OnInit()
{
    PolaWektoroweFrm* frame = new PolaWektoroweFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int PolaWektoroweFrmApp::OnExit()
{
	return 0;
}
