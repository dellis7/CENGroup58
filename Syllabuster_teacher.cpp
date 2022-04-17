//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Syllabuster_teacher.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	String TheFile = "C:\\Users\\legos\\Desktop\\Syllabus.pdf";
	ShellExecute(NULL, L"open", TheFile.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
