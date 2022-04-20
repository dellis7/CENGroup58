//---------------------------------------------------------------------------

#include <fmx.h>
#include <string>
#include <fstream>
#pragma hdrstop

#include "StudentSurvey.h"
#include "Dashboard.h"
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
		AnsiString topic = topicEdit->Text;
		savedTopicsList->Items->Add(topic);
		topicsInput.push_back(topic);
		topicEdit->Text="";
	}
}
//---------------------------------------------------------------------------
void __fastcall TStudentsSurvey::submitButtonClick(TObject *Sender)
{
	// Outputting the topics suggested into a csv file
	fstream responses;
	string userType =  DashboardForm->getUserType();
	if (userType.compare("S") == 0) {
		responses.open("studentsTopics.csv", ios::out | ios::app);
		DashboardForm->setStudentResStatus(true);
	}
	else if (userType.compare("T") == 0) {
		responses.open("teacherTopics.csv", ios::out | ios::app);
        DashboardForm->setTeacherResStatus(true);
	}

	if (responses.is_open()) {
		int numTopics = topicsInput.size();
		for (int i = 0; i < numTopics; i++) {
			AnsiString topic = topicsInput.at(i);
			const char* nTopic = topic.c_str();
			responses << nTopic << endl;
		}
		responses.close();
	}

	// Hiding the survey form after submit, and clearing the fields
	Hide();
	savedTopicsList->Items->Clear();
	DashboardForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TStudentsSurvey::backToMainButtonClick(TObject *Sender)
{
	// Hiding the survey form, and clearing the fields
	Hide();
	savedTopicsList->Items->Clear();
	DashboardForm->Show();
}
//---------------------------------------------------------------------------

