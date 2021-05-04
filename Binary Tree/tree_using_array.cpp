#include<bits/stdc++.h>
using namespace std;
char tree[10];
void root(char key){
   if(tree[0] != '\0')cout<<"Tree already has root key"<<endl;
   else tree[0] = key;
   return;
}
void set_right(char key,int parent){
     if(tree[parent] == '\0')cout<<"Can't set key to the parent, as parent is empty"<<endl;
     else tree[(2*parent)+2] = key;
     return;
}
void set_left(char key,int parent){
     if(tree[parent] == '\0')cout<<"Can't set key to the parent, as parent is empty"<<endl;
     else tree[(2*parent)+1] = key;
     return;
}
void print_tree(){
    for(int i = 0;i<10;i++){
    	if(tree[i]!='\0')cout<<tree[i]<<" ";
    	else {
    		cout<<endl;
    		return;
    	}
    }
}
int main(){
    root('A');
    set_left('B',0);
    set_right('C',0);
    set_left('D',1);
    set_right('E',1);
    set_left('F',2);
    set_right('G',2);
    print_tree();
	return 0;
}