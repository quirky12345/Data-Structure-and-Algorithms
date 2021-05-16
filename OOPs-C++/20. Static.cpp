#include<iostream>
using namespace std;
class Account{
public:
	int AccNo;
	string name;
	static float rateofInterest;
	Account(int a,string n){
		this->AccNo = a;
		this->name = n;
	}
	void display(){
		cout<<AccNo<<" "<<name<<" "<<rateofInterest<<endl;
	}
};
float Account::rateofInterest = 6.95;
int main(){
	Account a1 = Account(1,"Chaitanya");
	Account a2 = Account(2,"Parismita");
	a1.display();
	a2.display();
	return 0;
}