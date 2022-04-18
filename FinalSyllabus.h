//---------------------------------------------------------------------------

#ifndef FinalSyllabusH
#define FinalSyllabusH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.ListView.Adapters.Base.hpp>
#include <FMX.ListView.Appearances.hpp>
#include <FMX.ListView.hpp>
#include <FMX.ListView.Types.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <vector>
#include <string>
using namespace std;
//---------------------------------------------------------------------------
class TFinalSyllabusForm : public TForm
{
__published:	// IDE-managed Components
	TListView *topicsList;
	TButton *backToDashboardButton;
	TLabel *greeting;
	void __fastcall backToDashboardButtonClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TFinalSyllabusForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFinalSyllabusForm *FinalSyllabusForm;
//---------------------------------------------------------------------------
#endif
