//---------------------------------------------------------------------------

#ifndef SignInH
#define SignInH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
//---------------------------------------------------------------------------
class TSignInForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *emailEdit;
	TLabel *emailLabel;
	TEdit *passwordEdit;
	TLabel *passwordLabel;
	TButton *signInButton;
	TLabel *signUpLink;
	TLabel *loginError;
	void __fastcall signUpLinkClick(TObject *Sender);
	void __fastcall signInButtonClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TSignInForm(TComponent* Owner);
	vector<string> parseDataline(string dataline);
};
//---------------------------------------------------------------------------
extern PACKAGE TSignInForm *SignInForm;
//---------------------------------------------------------------------------
#endif
