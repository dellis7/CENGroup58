//---------------------------------------------------------------------------

#ifndef DashboardH
#define DashboardH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
#include <string>
#include <vector>
using namespace std;
//---------------------------------------------------------------------------
class TDashboardForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *welcomeMSG;
	TLabel *greeting;
	TButton *resInputButton;
	TButton *viewSyllabusButton;
	TButton *signOutButton;
	void __fastcall resInputButtonClick(TObject *Sender);
	void __fastcall signOutButtonClick(TObject *Sender);
	void __fastcall viewSyllabusButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDashboardForm(TComponent* Owner);
    vector<string> parseDataline(string dataline);
};
//---------------------------------------------------------------------------
extern PACKAGE TDashboardForm *DashboardForm;
//---------------------------------------------------------------------------
#endif
