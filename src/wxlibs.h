#ifndef _WXLIBS_H
#define _WXLIBS_H

#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/artprov.h>
#include <wx/toolbar.h>
#include <wx/splitter.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/statbmp.h>
#include <wx/textctrl.h>
#include <wx/slider.h>
#include <wx/bmpbuttn.h>
#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/aboutdlg.h>
#include <wx/utils.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/busyinfo.h>
#include <wx/wxsqlite3.h>

const wxStandardPaths stdPath;

#ifdef __APPLE__
const wxString appLocation = wxT("");
#endif

#ifdef __LINUX__
const wxString appLocation = wxFileName(stdPath.GetExecutablePath()).GetPath()+wxT("/");
#endif

#endif