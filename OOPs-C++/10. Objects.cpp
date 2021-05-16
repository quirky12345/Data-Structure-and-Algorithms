#include<iostream>
using namespace std;
// Create Class, name: Student
class Student{
	public:
	int id; //field(variable) and methods(functions)
	float salary; //field(variable) and methods(functions)
	string name; //field(variable) and methods(functions)
};

int main(){
    // Create object s1 of class Student
	Student s1;
	s1.id = 5;
	s1.name = "Chaitanya";
	s1.salary = 27895.4;
	cout<<s1.id<<" "<<s1.name<<" "<<s1.salary<<endl;
	return 0;
}