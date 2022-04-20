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
#include <FMX.Ani.hpp>
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
	TLabel *syllabusOutputErr;
	void __fastcall resInputButtonClick(TObject *Sender);
	void __fastcall signOutButtonClick(TObject *Sender);
	void __fastcall viewSyllabusButtonClick(TObject *Sender);
private:	// User declarations
	struct User {
		const char* fullName;
		const char* email;
		string userType;
	};
	User currUser;
	bool studentsResDone = false;
	bool teacherResDone = false;
public:		// User declarations
	__fastcall TDashboardForm(TComponent* Owner);
	vector<string> parseDataline(string dataline);
	void setUserName(const char* name);
	void setEmail(const char* e);
	void setUserType(string type);
	const char* getUserName();
	const char* getEmail();
	string getUserType();
	void setStudentResStatus(bool resIn);
	void setTeacherResStatus(bool resIn);
	bool getStudentResStatus();
	bool getTeacherResStatus();
	vector<string> fileParse(string filename);
	vector<string> rankObj(vector<string> csvVec, vector<string> fileVec);
};
//---------------------------------------------------------------------------
extern PACKAGE TDashboardForm *DashboardForm;
//---------------------------------------------------------------------------
#endif
