#include <iostream>
#include"Class.h"
#include"Exam.h"
#include<vector>
#include<string>

using namespace std;

void LayoutOfClassroom(Exam exam, vector<Classroom> classrooms) { // Set the classroom order using vector to store integers.
	int	examDay;
	int examHour;
	int numOfStu = exam.getNumberOfStudents(); //
	
	if (exam.getExamDate() == "Monday" || exam.getExamDate() == "monday")
	{
		examDay = 1;
	}
	else if (exam.getExamDate() == "Tuesday" || exam.getExamDate() == "tuesday")
	{
		examDay = 2;
	}
	else if (exam.getExamDate() == "Wednesday" || exam.getExamDate() == "wednesday")
	{
		examDay = 3;
	}
	else if (exam.getExamDate() == "Thursday" || exam.getExamDate() == "thursday")
	{
		examDay = 4;
	}
	else if (exam.getExamDate() == "Friday" || exam.getExamDate() == "friday")
	{
		examDay = 5;
	}
	else if (exam.getExamDate() == "Saturday" || exam.getExamDate() == "saturday")
	{
		examDay = 6;
	}
	else if (exam.getExamDate() == "Sunday" || exam.getExamDate() == "sunday")
	{
		examDay = 7;
	}

	if (exam.getExamHour() == "08:30" || exam.getExamHour() == "0830" || exam.getExamHour() == "8:30" || exam.getExamHour() == "830")
	{
		examHour = 1;
	}
	else if (exam.getExamHour() == "10:30" || exam.getExamHour() == "1030")
	{
		examHour = 2;
	}
	else if (exam.getExamHour() == "12:30" || exam.getExamHour() == "1230")
	{
		examHour = 3;
	}
	else if (exam.getExamHour() == "14:30" || exam.getExamHour() == "1430")
	{
		examHour = 4;
	}
	else if (exam.getExamHour() == "16:30" || exam.getExamHour() == "1630")
	{
		examHour = 5;
	}

	vector<Classroom> avaibleClasses;
	int avaibleCapacity = 0;


	for (int  i = 0; i < classrooms.size(); i++) 
	{
		if (classrooms.at(i).getProgram().at(examDay).at(examHour) == 0)
		{
			avaibleClasses.push_back(classrooms.at(i)); // show avaible classes in avaible timeline 
		}
	}

	for (int i = 0; i <avaibleClasses.size(); i++)
	{
		avaibleCapacity += avaibleClasses.at(i).getCapacity(); // Increase the current class capacity
	}
	if (numOfStu == avaibleCapacity) //If the number of students equals the current capacity, create an exam by the current class
	{
		for (int  i = 0; i < avaibleClasses.size(); i++)
		{
			exam.setClassroomName(avaibleClasses.at(i).getClassName());
		}
	}
	else
	{
		int largestClassroom = 0;
		int smallestClassrom = 0;

		for (int i = 0; i < avaibleClasses.size(); i++)
		{
			if (avaibleClasses.at(i).getCapacity() > avaibleClasses.at(largestClassroom).getCapacity())
			{
				largestClassroom = i; // define of largest capacity classroom.
				cout << "Largest classroom is : ";
				exam.setClassroomName(avaibleClasses.at(largestClassroom).getClassName());
				
				avaibleClasses.at(largestClassroom).updateProgram(examDay, examHour);
			}
			else
			{
				smallestClassrom = i; // define of smallest capacity classroom.
				cout << "Smallest classroom is : ";
				exam.setClassroomName(avaibleClasses.at(smallestClassrom).getClassName());
				
				avaibleClasses.at(smallestClassrom).updateProgram(examDay, examHour);
			}
		}
	}
	exam.makeFile(); 
}
void createExam(vector<Classroom> classrooms) {	 // Create a new exam.
	Exam examL;
	//LayoutOfClassroom(examL, classrooms);
}
void displayScheduleOfClass(vector<Classroom>classrooms) {
	string classChoice;
	bool found = false;

	cout << "Class Name : ";//for schedule
	cin >> classChoice;

	for (int i = 0; i < classrooms.size(); i++)
	{
		if (classrooms.at(i).getClassName()== classChoice) // If there is a class name in the name entered, show its program.
		{
			classrooms.at(i).printProgram();
			found = true;
		}
	}

	if (found==false)
	{
		cout << "No Classes. " << classChoice << endl;
	}
}

void showAvaibleClasses(vector<Classroom> classrooms) { // Display avaible classes
	int dayChoice;
	int hourChoice;

	cout << "Day choice (1 for Monday 2 for Tuesday...) : " << endl;
	cin >> dayChoice;
	cout << "Hour choice (1 at 08:30 2 at 10:30 ...) : " << endl;
	cin >> hourChoice;
	
	for (int i = 0; i < classrooms.size(); i++)
	{
		if (classrooms.at(i).getProgram().at(dayChoice).at(hourChoice) == 0) 
		{
			cout << classrooms.at(i).getClassName() << "  ";
		}
		cout << endl;
	}
}

void showAvaibleHours(vector<Classroom> classrooms) { //Display avaible hours

	string classChoice;
	bool flag = true;
	int dayChoice;
	int found = -1;

	cout << "Enter a class name : " << endl;
	cin >> classChoice;
	cout << "Day choice (1 for Monday 2 for Tuesday...) : " << endl;
	cin >> dayChoice;

	while (flag)
	{
		for (int i = 0; i < classrooms.size(); i++)
		{
			if (classrooms.at(i).getClassName() == classChoice);
			{
				found = i;
			}
		}
		if (found == -1)
		{
			cout << "Enter a valid classname : " << endl;
			cin >> classChoice;
		}
		else
		{
			flag = false;
		}
	}
	for (int i = 1; i < 6; i++)
	{
		if (classrooms.at(found).getProgram().at(dayChoice).at(i) == 0)
		{
			switch (i){
			case 1:
				cout << "08:30" ;
				break;
			case 2:
				cout << "10:30" ;
				break;
			case 3:
				cout << "12:30" ;
				break;
			case 4:
				cout << "14:30" ;
				break;
			case 5:
				cout << "16:30" ;
				break;
			}
		}
	}
	cout << endl;
}
void showAvaibleDays(vector<Classroom> classrooms) { //Display avaible days
	string classChoice;
	int found = -1;
	bool flag = true;
	int dayChoice, hourChoice;

	cout << "Enter a class name : " << endl;
	cin >> classChoice;
	cout << "Hour choice (1 at 08:30 2 at 10:30 ...)" << endl;
	cin >> hourChoice;

	while (flag)
	{
		for (int i = 0; i<classrooms.size(); i++)
		{
			if (classrooms.at(i).getClassName() == classChoice)
			{
				found = i;
			}
		}
		if (found == -1)
		{
			cout << "Enter a valid classname : " << endl;
			cin >> classChoice;
		}
		else
		{
			flag = false;
		}
	}
	for (int i = 1; i < 8; i++){
		if (classrooms.at(found).getProgram().at(i).at(hourChoice) == 0) {
			switch (i) {
			case 1:
				cout << "Monday";
				break;
			case 2:
				cout << "Tuesday";
				break;
			case 3:
				cout << "Wednesday";
				break;
			case 4:
				cout << "Thursday";
				break;
			case 5:
				cout << "Friday";
				break;
			case 6:
				cout << "Saturday";
				break;
			case 7:
				cout << "Sunday";
				break;
			}
		}
	}
	cout << endl;
}

int main() {

	Classroom D301("D301");
	Classroom D302("D302");
	Classroom D303("D303");
	Classroom D304("D304");
	Classroom D306("D306");
	Classroom D308("D308");
	Classroom D501("D501");
	Classroom D502("D502");
	Classroom D504("D504");
	Classroom D505("D505");
	Classroom D506("D506");


	vector<Classroom> classrooms { D301,D302,D303,D304,D306,D308,D501,D502,D504,D505,D506 };

	int menuChoice;
	bool exitMenu = false;

	while (!exitMenu)
	{
		cout << endl;
		cout << "(1) Create Exam " << endl;
		cout << "(2) Show Schedule of Class" << endl;
		cout << "(3) Show Avaible Class " << endl;
		cout << "(4) Show Avaible Days " << endl;
		cout << "(5) Show Avaible Hours " << endl;
		cout << "(0) Exit Menu " << endl;
		cin >> menuChoice;
		switch (menuChoice){
		case 1:
			createExam(classrooms);
		case 2:
			displayScheduleOfClass(classrooms);
			break;
		case 3:
			showAvaibleClasses(classrooms);
			break;
		case 4:
			showAvaibleDays(classrooms);
			break;
		case 5:
			showAvaibleHours(classrooms);
			break;
		case 0:
			exitMenu = true;
		}
	}
	return 0;
	system("pause");
}