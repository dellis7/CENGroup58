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
	this->CloseModal();
	SignUpForm->Show();
}
//---------------------------------------------------------------------------
const char* toCharPtr(AnsiString str) {
	return str.c_str();
}
//---------------------------------------------------------------------------
void __fastcall TSignInForm::signInButtonClick(TObject *Sender)
{
	fstream db;
	db.open("registeredUsersDB.txt", ios::in);

	if (db.is_open()) {
		string dataline;

		while (getline(db,dataline)) {
			vector<string> parsedLine = parseDataline(dataline);
			const char* email = parsedLine[1].c_str();

			if (strcmp(email, toCharPtr(emailEdit->Text))==0) {
				const char* password = parsedLine[2].c_str();

				if (strcmp(password, toCharPtr(passwordEdit->Text))==0) {
					const char* password = parsedLine[2].c_str();
					this->Hide();
				}
				else {
                    loginError->Visible = true;
                }
			}
		}
	}
}
//---------------------------------------------------------------------------
vector<string> TSignInForm::parseDataline(string dataline)
{
	vector<string> res;
	int l=0;
	int size = dataline.length();

	for (int i = 0; i < size; i++) {
		if (dataline[i] == ',') {
			res.push_back(dataline.substr(l,i-l));
			l=i+1;
		}
		else if (i+1==size) {
			res.push_back(dataline.substr(l,i+1-l));
		}
	}

	return res;
}
//--------------------------------------------------------------------------
