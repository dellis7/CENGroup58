//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#pragma hdrstop
using namespace std;

#include "SignIn.h"
#include "SignUp.h"
#include "Dashboard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TSignInForm *SignInForm;
//---------------------------------------------------------------------------
__fastcall TSignInForm::TSignInForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSignInForm::signUpLinkClick(TObject *Sender)
{
	// TODO Implement closing previous form when another form is opened
	this->Hide();
	Hide();
	emailEdit->Text = "";
	passwordEdit->Text = "";
	SignUpForm->Show();
}
//---------------------------------------------------------------------------
const char* toCharPtr(AnsiString str) {
	return str.c_str();
}
//---------------------------------------------------------------------------
void __fastcall TSignInForm::signInButtonClick(TObject *Sender)
{
	fstream database;
	database.open("registeredUsersDB.csv", ios::in);

	if (database.is_open()) {
		string dataline;
		bool loginSuccess = false;

		while (!loginSuccess && getline(database, dataline)) {
			vector<string> parsedDataline = this->parseDataline(dataline);
			const char* email = parsedDataline.at(1).c_str();

			if (strcmp(email, toCharPtr(emailEdit->Text))==0) {
				const char* password = parsedDataline.at(2).c_str();

				if (strcmp(password, toCharPtr(passwordEdit->Text))==0) {
					loginSuccess = true;
					Hide();
					emailEdit->Text = "";
					passwordEdit->Text = "";
					const char* nname = parsedDataline.at(0).c_str();
					DashboardForm->setUserName(nname);
					DashboardForm->setEmail(email);
					DashboardForm->setUserType(parsedDataline.at(3));
					DashboardForm->greeting->Text = nname;
					DashboardForm->Show();
				}
				else {
					// TODO Implement opening the respective  GUI based on the user type
					loginError->Visible = true;
					loginSuccess = false;
				}
			}
		}

		loginError->Visible = !loginSuccess;

		database.close();
	}
}
//---------------------------------------------------------------------------
vector<string> TSignInForm::parseDataline(string dataline)
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
