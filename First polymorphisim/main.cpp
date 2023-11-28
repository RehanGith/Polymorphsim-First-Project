#include <iostream>
#include <string>
#define MAX 100
using namespace std;
class Person {
protected:
	string name;
	string cnic;
public:
	Person(string n = "", string c = "");
	virtual void setter();
	virtual void getter();
	virtual ~Person();
};
Person::Person(string n, string c) 
	: name(n), cnic(c) {
	
}

void Person::setter() {
	cin.ignore();
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter cnic: ";
	cin.ignore();
	getline(cin, cnic);
}
void Person::getter() {
	cout << "Name: " << name << "  cnic: " << cnic << endl;
}
Person::~Person() {
	
}
class Student : virtual public Person {
	string degree_program;
	float cgpa;
public:
	Student(string n = "", string c = "", string d = 0, float g = 0.0);
	void setter();
	void getter();
	~Student();
};
Student::Student(string n, string c, string d, float g)
	: Person(n, c), degree_program(d), cgpa(g) {

}
void Student::setter() {
	Person::setter();
	cin.ignore();
	cout << "Enter degree Program: ";
	getline(cin, degree_program);
	cout << "Enter cgpa: ";
	cin >> cgpa;
}
void Student::getter() {
	Person::getter();
	cout << "Degree Program: " << degree_program << " cgpa: " << cgpa << endl;
}
Student::~Student() {
	
}
class Teacher : virtual public Person {
	string deperatment;
	int no_of_publication;
public:
	Teacher(string n = "", string c = "", string d = "", int no = 0);
	void setter();
	void getter();
	~Teacher();
};
Teacher::Teacher(string n, string c, string d, int no)
	: Person(n, c), deperatment(d), no_of_publication(no) {

}
void Teacher::setter() {
	Person::setter();
	cin.ignore();
	cout << "Enter Department: ";
	getline(cin, deperatment);
	cout << "NO of Publication: ";
	cin >> no_of_publication;
}
void Teacher::getter() {
	Person::getter();
	cout << "Department: " << deperatment << "  no of Publication: " << no_of_publication << endl;
}
Teacher::~Teacher() {

}

int main() {
	int choice{}, n{};
	char loop;
	Person* arr[MAX];
	while (true) {
		cout << "Menu\n"
			<< "1: Create Teacher\n"
			<< "2: Create Student\n"
			<< "3: Display All\n"
			<< "4: Dispaly number\n"
			<< "5: Exit" << endl;
		cout << "Which option you wants to choose: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			arr[n] = new Teacher;
			arr[n]->setter();
			n++;
			break;
		}
		case 2: {
			arr[n] = new Student;
			arr[n]->setter();
			n++;
			break;
		}
		case 3: {
			break;
		}
		case 5:
			for (int i = 0; i < n; i++) {
				delete[] arr;
			}
			return 0;
		default:
			cout << "You enter wrong choice" << endl;
			break;
		}
	}
	return 0;
}