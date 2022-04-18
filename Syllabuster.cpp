//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>

//--------------------------------------DEVEN & ZHIQIN CODE--------------------------------
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
//---------------------------------------------------------------------------
USEFORM("StudentSurvey.cpp", StudentsSurvey);
USEFORM("SignUp.cpp", SignUpForm);
USEFORM("SignIn.cpp", SignInForm);
USEFORM("Dashboard.cpp", DashboardForm);
USEFORM("FinalSyllabus.cpp", FinalSyllabusForm);
//---------------------------------------------------------------------------
vector<string> fileParse(string filename) {//returns a vector of the objectives the user wants to compare against
	vector<string> result;
	string line;
	ifstream MyFile(filename);
	if (MyFile.is_open()) {
		while (getline(MyFile, line)) {
			result.push_back(line);
		}
		MyFile.close();
	}
	else {
		throw runtime_error("objective file cannot be opened!");
	}
	return result;
}


vector<string> rankObj(vector<string> csvVec, vector<string> fileVec) { //returns the filevec in order
	map<string, int> rankmap;
    for (string obj : fileVec) { //puts every objective in the map
        rankmap.emplace(obj, 0);
    }
    for (string obj : fileVec) {
        for (string s : csvVec) {
            if (obj.find(s) != string::npos) { //checking if the input string is in the course objective
                if (rankmap.find(obj)->second != 0) { //checking if that objective has been marked
                    int temp = rankmap.find(obj)->second;//increases the objectives rank
                    rankmap.erase(obj);
                    rankmap.emplace(obj, temp + 1);
                }
                else {
                    rankmap.erase(obj);
                    rankmap.emplace(obj, 1); //marks objective as used
                }
            }
        }
    }
    vector<string> result;
    while (!rankmap.empty()) {
        string max;
        int maxInt = -1;
        for (auto iter = rankmap.begin(); iter != rankmap.end(); iter++) {
            if (iter->second > maxInt) {
                max = iter->first;
                maxInt = iter->second;
            }
        }
        result.push_back(max);
        rankmap.erase(max);
    }
    return result;
}
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

		// Extracting the student and teacher input files, and running the analysis algorithm
		// TODO Implement bool variables that check whether there are inputs in the form
		// TODO Implement relative paths
		string studentsResFile = "C:\\Users\\Beatrice Ndalichako\\Documents\\Syllabuster\\StudentsResponses.txt";
		string teacherResFile = "C:\\Users\\Beatrice Ndalichako\\Documents\\Syllabuster\\TeacherResponse.txt";

		vector<string> rankedObj = rankObj(fileParse(studentsResFile), fileParse(teacherResFile));
		// Outputting final syllabus into a file
		ofstream finalTopics("FinalSyllabus.txt");
		for (string topic : rankedObj) {
			finalTopics << topic << endl;
		}

		finalTopics.close();

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
