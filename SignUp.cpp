//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#pragma hdrstop
using namespace std;

#include "SignUp.h"
#include "SignIn.h"
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
	// TODO Implement closing previous form when another form is opened
	this->CloseModal();
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
		database.open("registeredUsersDB.txt", ios::app);

		if (database.is_open()) {
			AnsiString name = usernameEdit->Text;
			AnsiString email = emailEdit->Text;
			AnsiString newPassword = newPasswordEdit->Text;
			AnsiString confirmPassword = confirmPasswordEdit->Text;

			database << name << "," << email << "," << newPassword << "\n";
			database.close();
			this->Close();
		}
	}
}
//---------------------------------------------------------------------------
