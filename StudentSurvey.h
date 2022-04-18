//---------------------------------------------------------------------------

#ifndef StudentSurveyH
#define StudentSurveyH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TStudentsSurvey : public TForm
{
__published:	// IDE-managed Components
	TLabel *inputLabel;
	TEdit *topicEdit;
	TButton *addButton;
	TLabel *savedTopicsLabel;
	TListBox *savedTopicsList;
	TButton *submitButton;
	TButton *backToMainButton;
	TLabel *inputErrLabel;
	void __fastcall addButtonClick(TObject *Sender);
	void __fastcall savedTopicsListItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall submitButtonClick(TObject *Sender);
	void __fastcall backToMainButtonClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TStudentsSurvey(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStudentsSurvey *StudentsSurvey;
//---------------------------------------------------------------------------
#endif
