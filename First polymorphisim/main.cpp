#include <iostream>
#include <string>
using namespace std;
class Person {
	string name;
	string cnic;
	static int no_of_person;
public:
	static int num_person();
	Person(string n = "", string c = "");
	virtual void setter();
	virtual void getter();
	virtual ~Person();
};
int Person::no_of_person = 0;
Person::Person(string n, string c) 
	: name(n), cnic(c) {
	no_of_person++;
}
int Person::num_person() {
	return no_of_person;
}
void Person::setter() {
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter cnic: ";
	cin >> cnic;
}
void Person::getter() {
	cout << "Name: " << name << "  cnic: " << cnic << endl;
}
Person::~Person() {
	no_of_person--;
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
void display_person() {
	cout << "No of Person: " << Person::num_person() << endl;
}
int main() {
	cout << "Menu\n"
		<< "1: Create Teacher\n"
		<< "2: Create Student\n"
		<< "3: Display All\n"
		<< "4: Dispaly number\n"
		<< "5: Exit" << endl;
	display_person();
	{
		Person obj1("Rehan", "81202-6816566-1");
		obj1.getter();
		display_person();
		Student obj2("Rehan", "81202-6816566-1", "SE", 3.5);
		obj2.getter();
		display_person();
	}
	Teacher obj3("Sir Nadeem", "918598", "SE", 2);
	Person* p1 = &obj3;
	p1->getter();
	display_person();
	return 0;
}