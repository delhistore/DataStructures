/*
Q. WAP to implement heap when 3 queries have been given:

"1 e" - Add an element e to the heap.
"2 e" - Delete the element e from the heap.
"3" - Print the minimum of all the elements in the heap.
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

class MinHeap {
    int *heap_array;
    int capacity;
    int heap_size;
    
    public:
        MinHeap(int cap) {
            heap_size = 0;
            capacity = cap;
            heap_array = new int[cap];
        }
    
        //returns parent of node at i index
        int parent(int i) { return ( (i-1) / 2); }
        //returns left child of node at i index
        int left_child(int i) {return (2*i + 1);}
        //returns right child of node at i index
        int right_child(int i) {return (2*i + 2);}
         
        //swapping two nodes
        void swap(int *first, int *second) {
            int temp = *first;
            *first = *second;
            *second = temp;
        }
    
        //inserting a node O(log n)
        void insertElement(int e) {
            if(heap_size == capacity) {
                cout<<"Maximum heap size reached";
                return;
            }
            heap_size++;
            int i = heap_size - 1;
            heap_array[i] = e;
            
            while(i!=0 && (heap_array[parent(i)] > heap_array[i]) ) {
                swap(&heap_array[i], &heap_array[parent(i)]);
                i = parent(i);
            }
            //cout<<"top element now is"<<heap_array[0]<<endl;
        }
    
        //returning least element O(1)
        int least_element() {
            return heap_array[0];
        }
    
        //decrease value of node at index i to -infinity and moving it to top
        void decrease_value(int i, int neg_inf) {
            heap_array[i] = neg_inf;
            //moving element to be deleted to the top
            while(i!=0 && (heap_array[parent(i)] > heap_array[i]) ) {
                swap(&heap_array[i], &heap_array[parent(i)]);
                i = parent(i);
            }
        }
    
        //heapify (take element at index i and push it down to its right position)
        //this algorithm assumes all elements below i are already heapified
        void heapify(int i) {
            int l = left_child(i); 
            int r = right_child(i); 
            int smallest = i; 
            if (l < heap_size && heap_array[l] < heap_array[i]) 
                smallest = l; 
            if (r < heap_size && heap_array[r] < heap_array[smallest]) 
                smallest = r; 
            if (smallest != i) { 
                swap(&heap_array[i], &heap_array[smallest]); 
                heapify(smallest); 
            }
        }
    
        //deleting the element e and balancing heap O(log n)
        void delete_element(int e) {
            
            //finding index of element e
            int index = 0;
            while(index<heap_size) {
                if(heap_array[index] == e)  break;
                index++;
            }
            if(index==heap_size) {
                cout<<"element to be deleted not found in heap";
                return;
            }
            
            //moving element at index = index to the top
            decrease_value(index, INT32_MIN);
            
            //replacing root element(the element which is to be deleted) with last leaf node
            heap_array[0] = heap_array[heap_size-1];
            heap_size--;
            
            //calling a recursive heapify function to restore heap properties
            heapify(0);            
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n; cin>>n;
    MinHeap mh(n);
    
    while(n>0) {
        int choice; cin>> choice;
        switch(choice) {
            case 1: {
                int ele; cin>>ele;
                mh.insertElement(ele);
                break;
            }
            case 2: {
                int ele; cin>>ele;
                mh.delete_element(ele);
                break;
            }
            case 3: {
                cout<<mh.least_element()<<endl;
                break;
            }                
        }
        n--;
    }
    
    return 0;
}
