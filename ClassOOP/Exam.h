#include "Class.h"

class Exam
{
	friend class Classroom; // Access the private and protected members of a Classroom class.
private:
	int numberStudent;  // Number of students in the class.
	string courseName; // Name of the course.
	string courseCode; // The number of the course.
	string examDate; // Date of exam.
	string examHour; // Hour of exam.
	vector <string> classrooms;
public:
	void setCourseName(string c) {
		courseName = c;
	}
	void setCourseCode(string c) {
		courseCode = c;
	}
	void setNumberOfStudents(int i) {
		numberStudent = i;
	}
	void setExamDate(string c) {
		examDate = c;
	}
	void setExamHour(string d) {
		examHour = d;
	}
	void setClassroomName(string c) { 
		cout << c << " ";
		classrooms.push_back(c); // adding the string name of classroom.
	}
	int getNumberOfClassrooms() {
		return classrooms.size();
	}
	string getClassroomName(int i) {
		return classrooms.at(i);
	}
	string getExamDate() {
		return examDate;
	}
	string getExamHour() {
		return examHour;
	}
	string getExamName() {
		return courseName;
	}
	int getNumberOfStudents() {
		return numberStudent;
	}
	string getCourseCode() {
		return courseCode;
	}
	Exam() {
		string name, code, day, hour; 
		int number; // Number of students in the class.

		cout << "Exam Course Code : "; 
		cin >> code;
		setCourseCode(code);

		cout << "Exam Name : ";
		cin.ignore();
		getline(cin, name);

		cout << "Number of Students :  ";
		cin >> number;
		setNumberOfStudents(number);

		cout << "Exam Day (Monday,Tuesday ... ) : ";
		cin >> day;
		setExamDate(day);

		cout << "Exam Hour (08:30, 10:30 ... ) : ";
		cin >> hour;
		setExamHour(hour);
	}
	void makeFile() {
		string filename = courseName + ".txt"; // used to create new exam file 
		ofstream newFile(filename); //used to write information to .txt file
		newFile << "exam name : " << getExamName() << endl; 
		newFile << "exam day : " << getExamDate() << endl;
		newFile << "exam hour : " << getExamHour() << endl;
		newFile << "exam classroom";
		for (int i = 0; i < getNumberOfClassrooms(); i++)
		{
			newFile << getClassroomName(i) << "  ";
		}
		newFile << endl;
		newFile.close(); 
	}
};
