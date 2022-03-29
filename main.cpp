#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

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

/*
vector<pair<string, vector<int>>> csvParse(string filename) { //returns the responses of the students as a vector of strings
    vector<pair<string, vector<int>>> studentResponse; //Store the result.
    ifstream csvFile(filename);

    if (!csvFile.is_open()) //Make sure if the file is opened.
        throw runtime_error("CSV file cannot be opened!");

    string line, colName;
    int val;

    if (csvFile.good()) {
        getline(csvFile, line); //Extract the first line of the file.
        stringstream ss(line);
        while (getline(ss, colName, ',')) // Extract each column name
        {
            // Initialize and add <colname, int vector> pairs to result
            studentResponse.push_back({ colName, vector<int> {} });
        }
    }

    // Read data, line by line
    while (getline(csvFile, line))
    {
        // Create a stringstream of the current line
        stringstream ss(line);
        // Keep track of the current column index
        int colIdx = 0;
        // Extract each integer
        while (ss >> val) {
            // Add the current integer to the 'colIdx' column's values vector
            studentResponse.at(colIdx).second.push_back(val);
            // If the next token is a comma, ignore it and move on
            if (ss.peek() == ',') ss.ignore();
            // Increment the column index
            colIdx++;
        }
    }
    // Close file
    csvFile.close();

    return studentResponse;
}
*/

vector<string> csvParse(string filename) {
    vector<string> result;
    string line;
    ifstream MyFile(filename);
    if (MyFile.is_open()) {
        while (getline(MyFile, line)) {
            int lastEntry = 0;
            string temp = line;
            for (int i = 0; i < line.size(); i++) {
                if (line.at(i) == ',') {
                    temp = line.substr(lastEntry, i - lastEntry);
                    lastEntry = i;
                    result.push_back(temp);
                }
                else if (i == line.size() - 1) {
                    result.push_back(temp);
                }
            }
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

int main() { //this will take in the parameters from the gui and generate the output

    //these varibles will be taken in via the gui
    //    |
    //    |
    //    V

    bool toFile = true; //default values until the gui is implemented
    string csvfileName = "test1.txt";
    string objfileName = "test2.txt";

    vector<string> rankedObj = rankObj(fileParse(csvfileName), fileParse(objfileName));

    if (toFile) {
        ofstream MyFile("output.txt");

        for (string s : rankedObj) {
            MyFile << s << endl;
        }

        MyFile.close();
    }

    //output to gui here

    return 0;

}

//test1.txt
//test
//test
//test
//nothing
//another objective
//haha also nothing

//test2.txt
//test
//other objectives
//even more objectives

//expected output:
//test
//another objectives
//other objectives

