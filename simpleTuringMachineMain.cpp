/***************************************************************
 * Name:      simpleTuringMachineMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Jimmy Pinto Stelzer (jimmy.stelzer@gmail.com)
 * Created:   2009-05-31
 * Copyright: Jimmy Pinto Stelzer (http://insidemytruth.blogspot.com/)
 * License:
 **************************************************************/

#include "simpleTuringMachineMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(simpleTuringMachineFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(_T("Simple Turing Machine\n"));
    wxbuild << wxVERSION_STRING;
    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }
    wxbuild << _T("\n\nDeveloped by Jimmy Pinto Stelzer");
    wxbuild << _T("\n\nDistributed under GNU-GPL (Read COPYING and/or README files for informations).");

    return wxbuild;
}

//(*IdInit(simpleTuringMachineFrame)
const long simpleTuringMachineFrame::ID_TEXTCTRL1 = wxNewId();
const long simpleTuringMachineFrame::ID_TEXTCTRL2 = wxNewId();
const long simpleTuringMachineFrame::ID_TEXTCTRL3 = wxNewId();
const long simpleTuringMachineFrame::ID_TEXTCTRL4 = wxNewId();
const long simpleTuringMachineFrame::ID_TEXTCTRL5 = wxNewId();
const long simpleTuringMachineFrame::ID_TEXTCTRL6 = wxNewId();
const long simpleTuringMachineFrame::ID_STATICBITMAP2 = wxNewId();
const long simpleTuringMachineFrame::ID_STATICBITMAP3 = wxNewId();
const long simpleTuringMachineFrame::ID_STATICBITMAP1 = wxNewId();
const long simpleTuringMachineFrame::ID_STATICLINE2 = wxNewId();
const long simpleTuringMachineFrame::ID_STATICLINE3 = wxNewId();
const long simpleTuringMachineFrame::ID_STATICLINE1 = wxNewId();
const long simpleTuringMachineFrame::ID_TEXTCTRL7 = wxNewId();
const long simpleTuringMachineFrame::ID_TEXTCTRL8 = wxNewId();
const long simpleTuringMachineFrame::ID_TEXTCTRL9 = wxNewId();
const long simpleTuringMachineFrame::ID_VELOCIDADE = wxNewId();
const long simpleTuringMachineFrame::ID_STATICTEXT1 = wxNewId();
const long simpleTuringMachineFrame::ID_EXEC = wxNewId();
const long simpleTuringMachineFrame::ID_EXECPASSO = wxNewId();
const long simpleTuringMachineFrame::ID_STATICTEXT2 = wxNewId();
const long simpleTuringMachineFrame::ID_PANEL1 = wxNewId();
const long simpleTuringMachineFrame::idMenuAbrir = wxNewId();
const long simpleTuringMachineFrame::idMenuClose = wxNewId();
const long simpleTuringMachineFrame::idMenuQuit = wxNewId();
const long simpleTuringMachineFrame::idMenuEntrada = wxNewId();
const long simpleTuringMachineFrame::idMenuExecutar = wxNewId();
const long simpleTuringMachineFrame::idMenuExecutarPasso = wxNewId();
const long simpleTuringMachineFrame::idMenuPause = wxNewId();
const long simpleTuringMachineFrame::idMenuAbout = wxNewId();
const long simpleTuringMachineFrame::ID_STATUSBAR1 = wxNewId();
const long simpleTuringMachineFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(simpleTuringMachineFrame,wxFrame)
    //(*EventTable(simpleTuringMachineFrame)
    //*)
END_EVENT_TABLE()

simpleTuringMachineFrame::simpleTuringMachineFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(simpleTuringMachineFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, _("simple Turing Machine"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxCLOSE_BOX, _T("id"));
    SetClientSize(wxSize(514,244));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("./res/stm_16x16.png"))));
    	SetIcon(FrameIcon);
    }
    panel1 = new wxPanel(this, ID_PANEL1, wxPoint(32,80), wxSize(514,248), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    tape1left = new wxTextCtrl(panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(8,8), wxSize(240,27), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    tape1centro = new wxTextCtrl(panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(248,8), wxSize(18,27), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    tape1right = new wxTextCtrl(panel1, ID_TEXTCTRL3, wxEmptyString, wxPoint(266,8), wxSize(240,27), wxTE_LEFT, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    tape2left = new wxTextCtrl(panel1, ID_TEXTCTRL4, wxEmptyString, wxPoint(8,56), wxSize(240,27), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    tape2centro = new wxTextCtrl(panel1, ID_TEXTCTRL5, wxEmptyString, wxPoint(248,56), wxSize(18,27), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    tape2right = new wxTextCtrl(panel1, ID_TEXTCTRL6, wxEmptyString, wxPoint(266,56), wxSize(240,27), wxTE_LEFT, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    StaticBitmap2 = new wxStaticBitmap(panel1, ID_STATICBITMAP2, wxBitmap(wxImage(_T("./res/seta.png"))), wxPoint(249,36), wxDefaultSize, 0, _T("ID_STATICBITMAP2"));
    StaticBitmap3 = new wxStaticBitmap(panel1, ID_STATICBITMAP3, wxBitmap(wxImage(_T("./res/seta.png"))), wxPoint(249,84), wxDefaultSize, 0, _T("ID_STATICBITMAP3"));
    StaticBitmap1 = new wxStaticBitmap(panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("./res/seta.png"))), wxPoint(249,132), wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    StaticLine2 = new wxStaticLine(panel1, ID_STATICLINE2, wxPoint(8,53), wxSize(498,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    StaticLine3 = new wxStaticLine(panel1, ID_STATICLINE3, wxPoint(8,101), wxSize(498,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    StaticLine1 = new wxStaticLine(panel1, ID_STATICLINE1, wxPoint(8,149), wxSize(498,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    tape3left = new wxTextCtrl(panel1, ID_TEXTCTRL7, wxEmptyString, wxPoint(8,104), wxSize(240,27), wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    tape3centro = new wxTextCtrl(panel1, ID_TEXTCTRL8, wxEmptyString, wxPoint(248,104), wxSize(18,27), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    tape3right = new wxTextCtrl(panel1, ID_TEXTCTRL9, wxEmptyString, wxPoint(266,104), wxSize(240,27), wxTE_LEFT, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    velocidade = new wxSlider(panel1, ID_VELOCIDADE, 1, 1, 10, wxPoint(432,168), wxSize(72,19), 0, wxDefaultValidator, _T("ID_VELOCIDADE"));
    StaticText1 = new wxStaticText(panel1, ID_STATICTEXT1, _("Velocidade"), wxPoint(432,152), wxSize(72,19), 0, _T("ID_STATICTEXT1"));
    Exec = new wxButton(panel1, ID_EXEC, _("Executar"), wxPoint(8,152), wxSize(80,34), 0, wxDefaultValidator, _T("ID_EXEC"));
    ExecPasso = new wxButton(panel1, ID_EXECPASSO, _("Executar Passo"), wxPoint(88,152), wxSize(120,34), 0, wxDefaultValidator, _T("ID_EXECPASSO"));
    StaticText2 = new wxStaticText(panel1, ID_STATICTEXT2, _("\u03b4(q00,1)=(q3,0,R)"), wxPoint(216,160), wxSize(208,16), 0, _T("ID_STATICTEXT2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuAbrir, _("Abrir\tCtrl+O"), _("Abrir Maquina de Turing Codificada"), wxITEM_NORMAL);
    MenuItem3->SetBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),wxART_OTHER));
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuClose, _("Fechar\tCtrl+W"), _("Fechar Maquina de Turing codificada"), wxITEM_NORMAL);
    MenuItem4->SetBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CROSS_MARK")),wxART_OTHER));
    Menu1->Append(MenuItem4);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Sair\tAlt-F4"), _("Sair do aplicativo"), wxITEM_NORMAL);
    MenuItem1->SetBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUIT")),wxART_OTHER));
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Arquivo"));
    Menu3 = new wxMenu();
    MenuItem5 = new wxMenuItem(Menu3, idMenuEntrada, _("Entrada\tCtrl+S"), _("Defini a string de entrada da MT"), wxITEM_NORMAL);
    MenuItem5->SetBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW")),wxART_OTHER));
    Menu3->Append(MenuItem5);
    Menu3->AppendSeparator();
    MenuItem6 = new wxMenuItem(Menu3, idMenuExecutar, _("Executar\tCtrl+E"), _("Executa a MT."), wxITEM_NORMAL);
    MenuItem6->SetBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),wxART_OTHER));
    Menu3->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu3, idMenuExecutarPasso, _("Executar Passo\tCtrl+N"), _("Executa um passo na MT."), wxITEM_NORMAL);
    MenuItem7->SetBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),wxART_OTHER));
    Menu3->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu3, idMenuPause, _("Pausar\tCtrl+P"), _("Pausa um MT em execução."), wxITEM_NORMAL);
    MenuItem8->SetBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CROSS_MARK")),wxART_OTHER));
    Menu3->Append(MenuItem8);
    MenuBar1->Append(Menu3, _("&Controle"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Sobre\tF1"), _("Mostra informações sobre o applicativo"), wxITEM_NORMAL);
    MenuItem2->SetBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_HELP")),wxART_OTHER));
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(200, false);
    Center();

    Connect(ID_VELOCIDADE,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&simpleTuringMachineFrame::OnvelocidadeCmdScroll);
    Connect(ID_EXEC,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&simpleTuringMachineFrame::OnExecClick);
    Connect(ID_EXECPASSO,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&simpleTuringMachineFrame::OnExecPassoClick);
    Connect(idMenuAbrir,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&simpleTuringMachineFrame::OnOpen);
    Connect(idMenuClose,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&simpleTuringMachineFrame::OnClose);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&simpleTuringMachineFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&simpleTuringMachineFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&simpleTuringMachineFrame::OnTimer);
    //*)
}

simpleTuringMachineFrame::~simpleTuringMachineFrame()
{
    //(*Destroy(simpleTuringMachineFrame)
    //*)
}

void simpleTuringMachineFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void simpleTuringMachineFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Sobre sTM"));
}

void simpleTuringMachineFrame::OnOpen(wxCommandEvent& event)
{
    //Abrir
}

void simpleTuringMachineFrame::OnClose(wxCommandEvent& event)
{
    //Fechar
}

void simpleTuringMachineFrame::OnExecClick(wxCommandEvent& event)
{
    //Executar
}

void simpleTuringMachineFrame::OnExecPassoClick(wxCommandEvent& event)
{
    //Executar Passo
}

void simpleTuringMachineFrame::OnvelocidadeCmdScroll(wxScrollEvent& event)
{
    //Velocidade
}

void simpleTuringMachineFrame::OnTimer(wxTimerEvent& event)
{
    this->velocidade->SetValue(i++);
    if (i==11){
        i=1;
    }
}
