//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "FinalSyllabus.h"
#include "Dashboard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFinalSyllabusForm *FinalSyllabusForm;
//---------------------------------------------------------------------------
__fastcall TFinalSyllabusForm::TFinalSyllabusForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFinalSyllabusForm::backToDashboardButtonClick(TObject *Sender)
{
	// Hiding the survey form, and clearing the fields
	Hide();
	topicsList->Items->Clear();
	DashboardForm->Show();
}
//---------------------------------------------------------------------------
