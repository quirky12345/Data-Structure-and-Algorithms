#include<iostream>
using namespace std;
class Account{
public:
	int AccNo;
	string name;
	static int count;
	Account(int a,string n){
		this->AccNo = a;
		this->name = n;
		count++;
	}
	void display(){
		cout<<AccNo<<" "<<name<<endl;
	}
};
int Account::count = 0;
int main(){
	Account a1 = Account(1,"Chaitanya");
	Account a2 = Account(2,"Parismita");
	a1.display();
	a2.display();
	cout<<"No. of objects created: "<<Account::count<<endl;
	return 0;
}