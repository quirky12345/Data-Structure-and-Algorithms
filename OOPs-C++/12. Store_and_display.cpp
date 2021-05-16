#include<iostream>
using namespace std;
class Employee{
	public:
		int id;
		string name;
		float salary;
		void insert(int i,string n,float s){
			id = i;
			name = n;
			salary = s; 
		}
		void display(){
			cout<<id<<" "<<name<<" "<<salary<<endl;
		}
};
int main(void){
	Employee e1; //creating an object of Employee   
    Employee e2; //creating an object of Employee  
    e1.insert(201, "Sonoo",990000);    
    e2.insert(202, "Nakul", 29000);    
    e1.display();    
    e2.display();    
	return 0;
}