//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Dashboard.h"
#include "StudentSurvey.h"
#include "SignIn.h"

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TDashboardForm *DashboardForm;
//---------------------------------------------------------------------------
__fastcall TDashboardForm::TDashboardForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDashboardForm::resInputButtonClick(TObject *Sender)
{
	this->Hide();
	StudentsSurvey->Show();
}
//---------------------------------------------------------------------------
void __fastcall TDashboardForm::signOutButtonClick(TObject *Sender)
{
	// Hide the dashboard form, and display the sign in form
	Hide();
    SignInForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TDashboardForm::viewSyllabusButtonClick(TObject *Sender)
{
	// Outputting the final syllabus
	// TODO Implemet a relative path

	String finalSyllabus = "C:\\Users\\Beatrice Ndalichako\\Documents\\Syllabuster\\SyllabusterFinalSyllabus.pdf";
	ShellExecute(NULL, L"open", finalSyllabus.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
vector<string> TDashboardForm::parseDataline(string dataline)
{
	vector<string> res;
	stringstream s_stream(dataline);

	while (s_stream.good()) {
		string substr;
		getline(s_stream, substr, ',');
		res.push_back(substr);
	}

	return res;
}
//---------------------------------------------------------------------------

