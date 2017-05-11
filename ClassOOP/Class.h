#pragma once
#include <iostream>
#include <string> //used to String Class(std::string).
#include <fstream> //used to read information from files.
#include <sstream> //used to both read strings and write data into strings.
#include<vector> //Vectors are sequence containers representing arrays that can change in size.

using namespace std;

class Classroom
{
private:
	string className; //Name of class.
	int capacity; //Student capacity in class.
	vector <vector<int> >Program; //declares a vector of integers.
public:
	Classroom(string c) { 
		setClassName(c);
		setProgram(c);
		setCapacity(c);
	}
	void setClassName(string c) {
		className = c;
	}
	void setCapacity(string c) {
		ifstream file(c + ".txt");
		string lineBuffer; //check whether there was any content in that line, if not skipped.
		vector<string> data; 

		while (file && getline(file, lineBuffer)) 
		{
			data.push_back(lineBuffer); //adds a new element at the end of the data vector.
		}
		capacity = stoi(data.at(0).substr(14, 16)); //number of capacity number between line 14 and line 16  
	}

	void setProgram(string c) {
		Program.resize(7, vector<int>(5)); // set size of program 7 days 5 timeline.
		ifstream file(c + ".txt");
		string lineBuffer;//check whether there was any content in that line, if not skipped.
		vector <string> data;

		while (file && getline(file, lineBuffer)) 
		{
			data.push_back(lineBuffer); //adds a new element at the end of the data vector.
		}
		for (int i = 2; i < data.size(); i++) { 			//read the txt files data line by line
			for (int j = 2; j < data.at(i).length(); j++) { 
				if (data.at(i).substr(j, j + 1)[0] < 58 && data.at(i).substr(j, j + 1)[0] > 47) {
					Program.at(i - 2).at(data.at(i).substr(j, j + 1)[0] - 49) = 1;
				}
			}
		}
	}

	void updateProgram(int day, int hour) { 
		Program.at(day).at(hour) = hour + 1 ;
	}
	vector<vector<int> >getProgram() {
		return Program;
	}
	int getCapacity() {
		return capacity;
	}
	string getClassName() {
		return className;
	}
	void printProgram() {
		for (int i =0; i <7; i++) // show days
		{
			cout << endl;
			cout << "Day" << i + 1 << endl;
			for (int j = 0; j <5 ; j++) // show hours
			{
				cout << "  " << Program.at(i).at(j) << "  ";
			}
		}
	}


};

