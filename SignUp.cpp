//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#pragma hdrstop
using namespace std;

#include "SignUp.h"
#include "SignIn.h"
#include "Dashboard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TSignUpForm *SignUpForm;
//---------------------------------------------------------------------------
__fastcall TSignUpForm::TSignUpForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSignUpForm::signInLinkClick(TObject *Sender)
{
	// Resetting the registration form
	this->Hide();
	usernameEdit->Text = "";
	emailEdit->Text = "";
	newPasswordEdit->Text = "";
	confirmPasswordEdit->Text = "";
	studentRadio->IsChecked = false;
	teacherRadio->IsChecked = false;
	SignInForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TSignUpForm::signUpButtonClick(TObject *Sender)
{
	if (newPasswordEdit->Text != confirmPasswordEdit->Text) {
		passwordsMismatchErr->Visible=true;
	}
	else {
		passwordsMismatchErr->Visible=false;
		fstream database;
		database.open("registeredUsersDB.csv", ios::out | ios::app);

		if (database.is_open()) {
			AnsiString name = usernameEdit->Text;
			const char* nname = name.c_str();
			AnsiString email = emailEdit->Text.c_str();
			const char* nemail = email.c_str();
			AnsiString password = newPasswordEdit->Text.c_str();
			const char* nPassword = password.c_str();
			bool isStudent = studentRadio->IsChecked;
			bool isTeacher = teacherRadio->IsChecked;

			// TODO Implement a way that identifies student vs teacher

			const char* userType;
			if (isStudent) {
				string student = "S";
				userType =  student.c_str();
				DashboardForm->resInputButton->Text = "Suggest syllabus topics";
				DashboardForm->setUserType(student);
			}
			else {
				string teacher = "T";
				userType =  teacher.c_str();
				DashboardForm->resInputButton->Text = "Enter current syllabus topics";
				DashboardForm->setUserType(teacher);
			}

			database << nname << "," << nemail << "," << nPassword << "," << userType;
            database << "\n";
			database.close();

			DashboardForm->setUserName(nname);
			DashboardForm->setEmail(nemail);

			// Resetting the registration form
			// TODO Remove duplicate code
			this->Hide();
			usernameEdit->Text = "";
			emailEdit->Text = "";
			newPasswordEdit->Text = "";
			confirmPasswordEdit->Text = "";
			studentRadio->IsChecked = false;
			teacherRadio->IsChecked = false;

			// Redirecting the user to the dashboard
			DashboardForm->greeting->Text = name;
			DashboardForm->Show();
		}
	}
}
//---------------------------------------------------------------------------

