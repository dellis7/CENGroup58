//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Dashboard.h"
#include "StudentSurvey.h"
#include "SignIn.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TDashboardForm *DashboardForm;
//---------------------------------------------------------------------------
__fastcall TDashboardForm::TDashboardForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDashboardForm::resInputButtonClick(TObject *Sender)
{
	this->Hide();
	StudentsSurvey->Show();
}
//---------------------------------------------------------------------------
void __fastcall TDashboardForm::signOutButtonClick(TObject *Sender)
{
	// Hide the dashboard form, and display the sign in form
	Hide();
    SignInForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TDashboardForm::viewSyllabusButtonClick(TObject *Sender)
{
	// Outputting the final syllabus
	if (studentsResDone && teacherResDone) {
		syllabusOutputErr->Visible = false;
		// Extracting the student and teacher input files, and running the analysis algorithm
		string studentsResFile = "studentsTopics.csv";
		string teacherResFile = "teacherTopics.csv";
		vector<string> rankedObj = rankObj(fileParse(studentsResFile), fileParse(teacherResFile));

		// Outputting final syllabus into a file
		ofstream finalTopics("FinalSyllabus.txt");
		int numTopics = rankedObj.size();
		for (int i = 1; i <= numTopics; i++) {
			string topic = rankedObj.at(i-1);
			finalTopics << i << ". " << topic << endl;
		}

		finalTopics.close();

		String finalSyllabus = "FinalSyllabus.txt";
		ShellExecute(NULL, L"open", finalSyllabus.c_str(), NULL, NULL, SW_SHOWNORMAL);
	}
	else if (!studentsResDone) {
		syllabusOutputErr->Text = "*Can't view final syllabus! Students have not submitted topics suggestions!";
		syllabusOutputErr->Visible = true;
	}
	else if (!teacherResDone) {
		syllabusOutputErr->Text = "*Can't view final syllabus! Teacher has not submitted topics suggestions!";
		syllabusOutputErr->Visible = true;
	}
}
//---------------------------------------------------------------------------
vector<string> TDashboardForm::parseDataline(string dataline)
{
	vector<string> res;
	stringstream s_stream(dataline);

	while (s_stream.good()) {
		string substr;
		getline(s_stream, substr, ',');
		res.push_back(substr);
	}

	return res;
}
//---------------------------------------------------------------------------
void TDashboardForm::setUserName(const char* name)
{
	currUser.fullName = name;
}
//---------------------------------------------------------------------------
void TDashboardForm::setEmail(const char* e)
{
	currUser.email = e;
}
//---------------------------------------------------------------------------
void TDashboardForm::setUserType(string type)
{
	currUser.userType = type;
}
//---------------------------------------------------------------------------
const char* TDashboardForm::getUserName()
{
	return currUser.fullName;
}
//---------------------------------------------------------------------------
const char* TDashboardForm::getEmail()
{
	return currUser.email;
}
//---------------------------------------------------------------------------
string TDashboardForm::getUserType()
{
	return currUser.userType;
}
//---------------------------------------------------------------------------
void TDashboardForm::setStudentResStatus(bool resIn)
{
	studentsResDone = resIn;
}
//---------------------------------------------------------------------------
void TDashboardForm::setTeacherResStatus(bool resIn)
{
	teacherResDone = resIn;
}
//---------------------------------------------------------------------------
bool TDashboardForm::getStudentResStatus()
{
	return studentsResDone;
}
//---------------------------------------------------------------------------
bool TDashboardForm::getTeacherResStatus()
{
	return teacherResDone;
}
//---------------------------------------------------------------------------
vector<string> TDashboardForm::fileParse(string filename) {//returns a vector of the objectives the user wants to compare against
	vector<string> result;
	string line;
	ifstream MyFile(filename);
	if (MyFile.is_open()) {
		getline(MyFile, line); // ignoring the title line of the csv file
		while (getline(MyFile, line)) {
			result.push_back(line);
		}
		MyFile.close();
	}
	else {
		throw runtime_error("file cannot be opened!");
	}
	return result;
}
//---------------------------------------------------------------------------
vector<string> TDashboardForm::rankObj(vector<string> csvVec, vector<string> fileVec) { //returns the filevec in order
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
