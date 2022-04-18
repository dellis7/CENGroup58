//---------------------------------------------------------------------------

#include <fmx.h>
#include <string>
#pragma hdrstop

#include "StudentSurvey.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TStudentsSurvey *StudentsSurvey;
//---------------------------------------------------------------------------
__fastcall TStudentsSurvey::TStudentsSurvey(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStudentsSurvey::addButtonClick(TObject *Sender)
{
	if (topicEdit->Text == "") {
		inputErrLabel->Visible =  true;
	}
	else {
		inputErrLabel->Visible =  false;
        String topic = topicEdit->Text;
		savedTopicsList->Items->Add(topic);
		topicEdit->Text="";
	}
}
//---------------------------------------------------------------------------
void __fastcall TStudentsSurvey::savedTopicsListItemClick(TCustomListBox * const Sender,
          TListBoxItem * const Item)
{
	int i = Item->Index;
	savedTopicsList->Items->Delete(i);
}
//---------------------------------------------------------------------------
