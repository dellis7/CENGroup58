//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Syllabuster_parent.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  String TheFile = "C:\\Users\\legos\\Desktop\\Syllabus.pdf";
  ShellExecute(NULL, L"open", TheFile.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------



