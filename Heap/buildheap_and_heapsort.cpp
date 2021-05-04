#include<bits/stdc++.h>
using namespace std;
//T.C of max_heapify is O(h) or O(logn)
void max_heapify(int arr[],int i,int n){
	int l = 2*i+1;
	int r = 2*i+2;
	//we will find the index of node containing largest element
	int largest;
	if(l<n and arr[l]>arr[i])largest = l;
	else largest = i;
	if(r<n and arr[r]>arr[largest])largest = r;
	//if largest is not equal to the index on which max_heapify called
	//chances are that below nodes now are not in max_heap so we call
	//max_heap with the index we captured as the largest.
	if(largest != i){
		swap(arr[i],arr[largest]);
		max_heapify(arr,largest,n);
	}
	return;
}
//T.C. of build_max_heap is O(n) - Though you will think O(nlogn)
//For proof, you can watch this article: https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/
void build_max_heap(int arr[],int n){
	//we apply max_heapify at each intermediate node in the bottom up fashion 
	//that is, from n-1/2 to 0
	for(int i = (n-1)/2;i>=0;i--)max_heapify(arr,i,n);
	return;
}
void heap_sort(int arr[],int size){
	//buil max heap for the array
	build_max_heap(arr,size);
	//define heap_size;
	int heap_size = size-1;
	for(int i=size-1;i>=1;i--){
		//one element is going to be it's right position after this swap
		swap(arr[0],arr[i]);
		//we decrease the heapsize as one element is at it's correct position
		heap_size--;
		//we apply max_heapify at the root in the heapsize
        max_heapify(arr,0,heap_size);
	}
	return;
}
int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	//build_max_heap(arr,size);
	heap_sort(arr,size);
	for(int i=0;i<size;i++)cout<<arr[i]<<" ";
	return 0;
}