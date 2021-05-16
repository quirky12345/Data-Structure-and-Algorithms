#include<iostream>
using namespace std;
class A{
	public:
	int x;
	// Parameterized Constructor
	A(int a){
	   x = a;
	}
	// Copy Constructor
	// Syntax of Copy Constructor: Class_name(const class_name &old_object);  
	A(const A &B){
		x = B.x;
	}
};
int main(){
	A a1(20);// Calling the parameterized constructor.  
	A a2(a1);//  Calling the copy constructor.
	cout<<a2.x<<endl;
	return 0;
}