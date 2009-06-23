/***************************************************************
 * Name:      simpleTuringMachineApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Jimmy Pinto Stelzer (jimmy.stelzer@gmail.com)
 * Created:   2009-05-31
 * Copyright: Jimmy Pinto Stelzer (http://insidemytruth.blogspot.com/)
 * License:
 **************************************************************/

#include "simpleTuringMachineApp.h"

//(*AppHeaders
#include "simpleTuringMachineMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(simpleTuringMachineApp);

bool simpleTuringMachineApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	simpleTuringMachineFrame* Frame = new simpleTuringMachineFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
