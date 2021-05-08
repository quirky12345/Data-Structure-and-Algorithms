#include<bits/stdc++.h>
using namespace std;
//max heap for the left half
priority_queue<double> s;
//min heap for the right half
priority_queue<double,vector<double>,greater<double> > g;
double med;
void insertHeap(int &x)
{
    if(s.size() == 0 && g.size() == 0)s.push(x);
    else if (s.size() > g.size()){
        if (x < med)
        {
            g.push(s.top());
            s.pop();
            s.push(x);
        }
        else
            g.push(x);

        med = (s.top() + g.top())/2.0;
    }
    // case2(both heaps are balanced)
    else if (s.size()==g.size()){
        if (x < med)
        {
            s.push(x);
            med = (double)s.top();
        }
        else
        {
            g.push(x);
            med = (double)g.top();
        }
    }
    // case3(right side heap has more elements)
    else
    {
        if (x > med)
        {
            s.push(g.top());
            g.pop();
            g.push(x);
        }
        else
            s.push(x);

        med = (s.top() + g.top())/2.0;
    }
    
}
double getMedian()
{
    if(s.size() == 1 && g.size() == 0){
        med = s.top();
        return med;
    }
    else return med;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		insertHeap(x);
		cout<<getMedian(x)<<endl;
	}
	return 0;
}