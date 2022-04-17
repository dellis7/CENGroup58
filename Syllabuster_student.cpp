//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Syllabuster_student.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	String TheFile = "C:\\Users\\legos\\Desktop\\Syllabus.pdf";
  	ShellExecute(NULL, L"open", TheFile.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
