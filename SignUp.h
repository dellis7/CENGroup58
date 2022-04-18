//---------------------------------------------------------------------------

#ifndef SignUpH
#define SignUpH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TSignUpForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *usernameEdit;
	TLabel *usernameLabel;
	TEdit *emailEdit;
	TLabel *emailLabel;
	TEdit *newPasswordEdit;
	TLabel *newPasswordLabel;
	TEdit *confirmPasswordEdit;
	TLabel *confirmPasswordLabel;
	TButton *signUpButton;
	TLabel *signInLink;
	TLabel *passwordsMismatchErr;
	TRadioButton *studentRadio;
	TRadioButton *teacherRadio;
	void __fastcall signInLinkClick(TObject *Sender);
	void __fastcall signUpButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSignUpForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSignUpForm *SignUpForm;
//---------------------------------------------------------------------------
#endif
