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

#include "main.h"
#include "kaynakcayonetimi.h"

IMPLEMENT_APP(KaynakcaYonetimiApp)

bool KaynakcaYonetimiApp::OnInit()
{
	KaynakcaYonetimi *kaynakcayonetimi = new KaynakcaYonetimi(wxT("Kaynakça Yönetimi"));
	kaynakcayonetimi->Show(true);
	
	return true;
}
