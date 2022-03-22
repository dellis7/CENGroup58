#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

vector<string> fileParse(string filename) {//returns a vector of the objectives the user wants to compare against

}

vector<string> csvParse(string filename) { //returns the responses of the students as a vector of strings
	vector<pair<string, vector<int>>> studentResponse; //Store the result.
	ifstream csvFile(filename); 

	if(!csvFile.is_open()) //Make sure if the file is opened.
		throw runtime_error("CSV file cannot be opened!"); 
	
	string line;	
	if(csvFile.good()){
		getline(csvFile, line); //Extract the first line of the file.

	}

}

void rank(vector<string> csvVec, vector<string> fileVec) { //modifies the fileVec to be in order of the rank computed

}



int main() {
	cout << "Hello world!";
}