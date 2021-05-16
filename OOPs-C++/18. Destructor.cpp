#include<iostream>
using namespace std;
class Employee{
public:
	// Default Contructor
	Employee(){
		cout<<"Contructor Invoked"<<endl;
	}
	// Destructor
	~Employee(){
		cout<<"Destructor Invoked"<<endl;
	}
};
int main(){
	// creating the instance for the class: Employee
	Employee e1;
	Employee e2;
	return 0;
}