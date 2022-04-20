//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>

//---------------------------------------------------------------------------
USEFORM("StudentSurvey.cpp", StudentsSurvey);
USEFORM("SignUp.cpp", SignUpForm);
USEFORM("SignIn.cpp", SignInForm);
USEFORM("Dashboard.cpp", DashboardForm);
USEFORM("FinalSyllabus.cpp", FinalSyllabusForm);
//---------------------------------------------------------------------------

extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TSignUpForm), &SignUpForm);
		Application->CreateForm(__classid(TStudentsSurvey), &StudentsSurvey);
		Application->CreateForm(__classid(TSignInForm), &SignInForm);
		Application->CreateForm(__classid(TDashboardForm), &DashboardForm);
		Application->CreateForm(__classid(TFinalSyllabusForm), &FinalSyllabusForm);
		Application->Run();

		return 0;
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
