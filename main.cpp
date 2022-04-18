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
                }
                result.push_back(temp);
            }
        }
        MyFile.close();
    }
    else {
        throw runtime_error("objective file cannot be opened!");
    }
    return result;
}

vector<string> rankFunc(vector<string> csvVec, vector<string> fileVec) { //returns the filevec in order
    map<string, int> rankmap;
    for (string obj : fileVec) {
        for (string s : csvVec) {
            if (obj.find(s) != string::npos) {
                if (rankmap.find(obj) != rankmap.end()) {
                    int temp = rankmap.at(obj);
                    rankmap.emplace(obj, temp + 1);
                }
                else {
                    rankmap.emplace(obj, 1);
                }
            }else{
                rankmap.emplace(obj, 0);
            }
        }
    }
    vector<string> result;
    while(!rankmap.empty()){
        int maxNum = -1;
        string maxEl = "";
        for(auto iter : rankmap){
            if(iter.second > maxNum){
                maxNum = iter.second;
                maxEl = iter.first;
            }
        }
        result.push_back(maxEl);
        rankmap.erase(maxEl);
    }
    return result;
}

int main() { //this will take in the parameters from the gui and generate the output
    bool toFile = true; //default values until the gui is implemented
    string csvfileName = "test1.txt";
    string objfileName = "test2.txt";

    //add method to get the gui input here!!!

    vector<string> rankedObj = rankFunc(csvParse(csvfileName), fileParse(objfileName));

    if (toFile) {
        ofstream MyFile("output.txt");

        for (string s : rankedObj) {
            MyFile << s << endl;
        }

        MyFile.close();
    }
    
    //output to gui here
    
}

//test1.txt
//test
//test
//test
//nothing
//haha also nothing

//test2.txt
//test
//other objectives
//even more objectives
