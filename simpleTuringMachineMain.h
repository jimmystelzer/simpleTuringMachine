/***************************************************************
 * Name:      simpleTuringMachineMain.h
 * Purpose:   Defines Application Frame
 * Author:    Jimmy Pinto Stelzer (jimmy.stelzer@gmail.com)
 * Created:   2009-05-31
 * Copyright: Jimmy Pinto Stelzer (http://insidemytruth.blogspot.com/)
 * License:
 **************************************************************/

#ifndef SIMPLETURINGMACHINEMAIN_H
#define SIMPLETURINGMACHINEMAIN_H

//(*Headers(simpleTuringMachineFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class simpleTuringMachineFrame: public wxFrame
{
    public:

        simpleTuringMachineFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~simpleTuringMachineFrame();

    private:

        //(*Handlers(simpleTuringMachineFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnOpen(wxCommandEvent& event);
        void OnClose(wxCommandEvent& event);
        void OnExecClick(wxCommandEvent& event);
        void OnExecPassoClick(wxCommandEvent& event);
        void OnvelocidadeCmdScroll(wxScrollEvent& event);
        //*)

        //(*Identifiers(simpleTuringMachineFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICBITMAP2;
        static const long ID_STATICBITMAP3;
        static const long ID_STATICBITMAP1;
        static const long ID_STATICLINE2;
        static const long ID_STATICLINE3;
        static const long ID_STATICLINE1;
        static const long ID_TEXTCTRL7;
        static const long ID_TEXTCTRL8;
        static const long ID_TEXTCTRL9;
        static const long ID_VELOCIDADE;
        static const long ID_STATICTEXT1;
        static const long ID_EXEC;
        static const long ID_EXECPASSO;
        static const long ID_STATICTEXT2;
        static const long ID_PANEL1;
        static const long idMenuAbrir;
        static const long idMenuClose;
        static const long idMenuQuit;
        static const long idMenuEntrada;
        static const long idMenuExecutar;
        static const long idMenuExecutarPasso;
        static const long idMenuPause;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(simpleTuringMachineFrame)
        wxStaticBitmap* StaticBitmap2;
        wxPanel* panel1;
        wxMenuItem* MenuItem8;
        wxTextCtrl* tape1left;
        wxMenuItem* MenuItem7;
        wxTextCtrl* tape2left;
        wxMenuItem* MenuItem5;
        wxStaticText* StaticText2;
        wxTextCtrl* tape3centro;
        wxMenu* Menu3;
        wxStaticBitmap* StaticBitmap1;
        wxTextCtrl* tape1centro;
        wxMenuItem* MenuItem4;
        wxStaticText* StaticText1;
        wxStaticLine* StaticLine2;
        wxTextCtrl* tape1right;
        wxButton* Exec;
        wxTextCtrl* tape2centro;
        wxMenuItem* MenuItem3;
        wxTextCtrl* tape2right;
        wxStatusBar* StatusBar1;
        wxMenuItem* MenuItem6;
        wxStaticLine* StaticLine3;
        wxStaticLine* StaticLine1;
        wxSlider* velocidade;
        wxTextCtrl* tape3left;
        wxTextCtrl* tape3right;
        wxStaticBitmap* StaticBitmap3;
        wxButton* ExecPasso;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SIMPLETURINGMACHINEMAIN_H