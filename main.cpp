#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

vector<string> fileParse(string filename) {//returns a vector of the objectives the user wants to compare against

}

vector<pair<string, vector<int>>> csvParse(string filename) { //returns the responses of the students as a vector of strings
	vector<pair<string, vector<int>>> studentResponse; //Store the result.
	ifstream csvFile(filename); 

	if(!csvFile.is_open()) //Make sure if the file is opened.
		throw runtime_error("CSV file cannot be opened!"); 
	
	string line, colName;
	int val;

	if(csvFile.good()){
		getline(csvFile, line); //Extract the first line of the file.
		stringstream ss(line);
		while(getline(ss, colName, ',')) // Extract each column name
		{
            // Initialize and add <colname, int vector> pairs to result
            studentResponse.push_back({colName, vector<int> {}});
        }
	}

	 // Read data, line by line
    while(getline(csvFile, line))
    {
        // Create a stringstream of the current line
        stringstream ss(line);
        // Keep track of the current column index
        int colIdx = 0;
        // Extract each integer
        while(ss >> val){   
            // Add the current integer to the 'colIdx' column's values vector
            studentResponse.at(colIdx).second.push_back(val);  
            // If the next token is a comma, ignore it and move on
            if(ss.peek() == ',') ss.ignore();
            // Increment the column index
            colIdx++;
        }
    }
    // Close file
    csvFile.close();

    return studentResponse;
}

void rank(vector<string> csvVec, vector<string> fileVec) { //modifies the fileVec to be in order of the rank computed

}



int main() {
	cout << "Hello world!";
}