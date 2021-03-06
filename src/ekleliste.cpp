/*
    This file is part of KaynakcaYonetimi.

    KaynakcaYonetimi is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    KaynakcaYonetimi is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with KaynakcaYonetimi.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ekleliste.h"

EkleListe::EkleListe(const wxString& title,const wxString& id)
	: wxDialog(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(500,300))
{
	
	wxImage::AddHandler(new wxPNGHandler);
	wxBitmap dialogLogo(srcLocation+wxT("resource/toolbar/list2.png"),wxBITMAP_TYPE_PNG);
	wxBitmap okButton(srcLocation+wxT("resource/toolbar/checkmark.png"),wxBITMAP_TYPE_PNG);
	wxBitmap cancelButton(srcLocation+wxT("resource/toolbar/cross.png"),wxBITMAP_TYPE_PNG);
	
	wxPanel *panel = new wxPanel(this,-1);
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
	
	wxStaticText *mainleft = new wxStaticText(panel,-1,wxT(" "));
	hbox->Add(mainleft,0,wxEXPAND);
	
	wxPanel *subpanel = new wxPanel(panel,-1);
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
	
	vbox->Add(-1,10);
	
	wxPanel *toppanel = new wxPanel(subpanel,-1);
	wxBoxSizer *tophbox = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *dialogtitle = new wxStaticText(toppanel, -1, wxT("Yeni Liste Ekle"));
	wxFont font = dialogtitle->GetFont();
	font.SetPointSize(18);
	font.SetWeight(wxFONTWEIGHT_BOLD);
	dialogtitle->SetFont(font);
	tophbox->Add(dialogtitle,1,wxALIGN_BOTTOM|wxEXPAND);
	wxStaticBitmap *dialoglogo = new wxStaticBitmap(toppanel,-1,dialogLogo);
	tophbox->Add(dialoglogo,0,wxALIGN_RIGHT);
	toppanel->SetSizer(tophbox);
	vbox->Add(toppanel,0,wxEXPAND);

	vbox->Add(new wxStaticLine(subpanel,-1,wxPoint(-1,-1),wxSize(-1,-1),wxLI_HORIZONTAL),0,wxEXPAND);
	
	vbox->Add(-1,10);
	wxPanel *mid1panel = new wxPanel(subpanel,-1);
	wxBoxSizer *mid1hbox = new wxBoxSizer(wxHORIZONTAL);
	mid1hbox->Add(new wxStaticText(mid1panel,-1,wxT("Liste Adı")),1,wxEXPAND);
	listname = new wxTextCtrl(mid1panel,-1,wxT(""),wxPoint(-1,-1),wxSize(300,-1));
	mid1hbox->Add(listname,0,wxALIGN_RIGHT);
	mid1panel->SetSizer(mid1hbox);
	vbox->Add(mid1panel,0,wxEXPAND);
	
	vbox->Add(-1,10);
	wxPanel *mid2panel = new wxPanel(subpanel,-1);
	wxBoxSizer *mid2hbox = new wxBoxSizer(wxHORIZONTAL);
	mid2hbox->Add(new wxStaticText(mid2panel,-1,wxT("Liste Açıklaması")),1,wxEXPAND);
	listdesc = new wxTextCtrl(mid2panel,-1,wxT(""),wxPoint(-1,-1),wxSize(300,-1));
	mid2hbox->Add(listdesc,0,wxALIGN_RIGHT);
	mid2panel->SetSizer(mid2hbox);
	vbox->Add(mid2panel,0,wxEXPAND);
	
	vbox->Add(-1,10);
	wxPanel *mid3panel = new wxPanel(subpanel,-1);
	wxBoxSizer *mid3hbox = new wxBoxSizer(wxHORIZONTAL);
	mid3hbox->Add(new wxStaticText(mid3panel,-1,wxT("Referans Stili")),1,wxEXPAND);
	liststyle = new wxTextCtrl(mid3panel,-1,wxT(""),wxPoint(-1,-1),wxSize(300,100),wxTE_MULTILINE);
	mid3hbox->Add(liststyle,0,wxALIGN_RIGHT);
	mid3panel->SetSizer(mid3hbox);
	vbox->Add(mid3panel,0,wxEXPAND);
	
	vbox->Add(-1,10);
	
	vbox->Add(new wxStaticText(subpanel,-1,wxT("")),1,wxEXPAND);
	vbox->Add(new wxStaticLine(subpanel,-1,wxPoint(-1,-1),wxSize(-1,-1),wxLI_HORIZONTAL),0,wxEXPAND);
	vbox->Add(-1,10);
	
	wxPanel *bottompanel = new wxPanel(subpanel,-1);
	wxBoxSizer *bottomhbox = new wxBoxSizer(wxHORIZONTAL);
	bottomhbox->Add(new wxStaticText(bottompanel,-1,wxT(" ")),0,wxEXPAND);
	wxArrayString liststyles;
	liststyles.Add(wxT("Hazır Liste Stilleri"));
	liststyles.Add(wxT("{yazarlar}, {yayıncı}, {cilt}({sayı}), {ilksayfa-sonsayfa} ({yıl})."));
	liststyles.Add(wxT("{yazarlar}, {yayıncı}, {cilt}({sayı}), {ilksayfa-sonsayfa} ({yıl}) {yenisatır} {başlık}."));
	liststyles.Add(wxT("{yazarlar}, {yayıncı}, {cilt} ({yıl}), {ilksayfa-sonsayfa}."));
	liststyles.Add(wxT("{yazarlar}, {yayıncı}, {cilt} ({yıl}), {ilksayfa-sonsayfa} {yenisatır} {başlık}."));
	liststyles.Add(wxT("{yazarlar}, {yıl}, {başlık}, {yayıncı}, {cilt}, {ilksayfa-sonsayfa}."));
	liststyles.Add(wxT("{yazarlar}, {yıl}, {yayıncı}, {cilt}, {ilksayfa-sonsayfa}."));
	liststylehelper = new wxChoice(bottompanel,-1,wxPoint(-1,-1),wxSize(180,-1),liststyles);
	bottomhbox->Add(liststylehelper,0,wxEXPAND);
	bottomhbox->Add(new wxStaticText(bottompanel,-1,wxT("")),1,wxEXPAND);
	bottomhbox->Add(new wxBitmapButton(bottompanel,wxID_CANCEL,cancelButton),0,wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT);
	bottomhbox->Add(new wxBitmapButton(bottompanel,wxID_OK,okButton),0,wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT);
	bottompanel->SetSizer(bottomhbox);
	vbox->Add(bottompanel,0,wxEXPAND);
	
	subpanel->SetSizer(vbox);
	hbox->Add(subpanel,1,wxEXPAND);
	hbox->Add(new wxStaticText(panel,-1,wxT(" ")),0,wxEXPAND);
	panel->SetSizer(hbox);

	Connect(liststylehelper->GetId(),wxEVT_COMMAND_CHOICE_SELECTED,wxCommandEventHandler(EkleListe::SetStyleFromHelper));
	
	//Centre();

	if(id != wxT(""))
		EkleListe::PrepareUpdate(id); 
}

void EkleListe::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

void EkleListe::SetStyleFromHelper(wxCommandEvent& event)
{
	if(liststylehelper->GetSelection() != 0)
		liststyle->SetValue(liststylehelper->GetString(liststylehelper->GetSelection()));
}

void EkleListe::PrepareUpdate(const wxString& id)
{
	wxSQLite3Database *prepareretriever = new wxSQLite3Database();
	prepareretriever->Open(appLocation+wxT("db/Kaynakca.db"));
	wxString prepareretrievesql;
	prepareretrievesql << wxT("SELECT * FROM lists WHERE id == '") << id << wxT("';");
	wxSQLite3ResultSet prepareretrieveSet = prepareretriever->ExecuteQuery(prepareretrievesql);
	listname->SetValue(prepareretrieveSet.GetAsString(wxT("name")));
	listdesc->SetValue(prepareretrieveSet.GetAsString(wxT("desc")));
	liststyle->SetValue(prepareretrieveSet.GetAsString(wxT("style")));
	prepareretrieveSet.Finalize();
	prepareretriever->Close();
	delete prepareretriever;
}

void EkleListe::UpdateList(const wxString& id)
{
	wxSQLite3Database *listsaver = new wxSQLite3Database();
	listsaver->Open(appLocation+wxT("db/Kaynakca.db"));
	wxSQLite3Statement listsaversql = listsaver->PrepareStatement(wxT("INSERT OR REPLACE INTO lists VALUES (?,?,?,?);"));
	listsaversql.Bind(1,id);
	listsaversql.Bind(2,listname->GetValue());
	listsaversql.Bind(3,listdesc->GetValue());
	listsaversql.Bind(4,liststyle->GetValue());
	listsaversql.ExecuteUpdate();
	listsaversql.ClearBindings();
	listsaversql.Reset();
	listsaver->Close();
	delete listsaver;
}

void EkleListe::SaveList()
{
	wxSQLite3Database *listsaver = new wxSQLite3Database();
	listsaver->Open(appLocation+wxT("db/Kaynakca.db"));
	wxSQLite3Statement listsaversql = listsaver->PrepareStatement(wxT("INSERT OR REPLACE INTO lists VALUES (NULL,?,?,?);"));
	listsaversql.Bind(1,listname->GetValue());
	listsaversql.Bind(2,listdesc->GetValue());
	listsaversql.Bind(3,liststyle->GetValue());
	listsaversql.ExecuteUpdate();
	listsaversql.ClearBindings();
	listsaversql.Reset();
	listsaver->Close();
	delete listsaver;
}
