#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

// Gurveen Nanua
//301546459
//Indexed Priority Queue Class


template < class T , int initQueueCapacity = 10 > //intial queue capaacity
class IPQ 
{ 
public:

    //constuctors:

    //makes an empty PQ
    IPQ(){
        heap = new minHeap(initQueueCapacity);
    }

    //constructs a PQ containing a set of strings and ints
    // passed to the constructor as vectors. 
    IPQ(vector<T> &vect1, vector<int> &vect2){ 
        heap = new minHeap(vect1.size()+1);
    
        for(int i=0; i<vect1.size(); i++){
            insert(vect1[i], vect2[i]);
        }
    }

    //functions

    //Insert task ID tid with priority p.
    void insert( const std::string & tid, int p ) {
        if(heap->size==heap->capacity)
            reserve(2 * heap->capacity + 1);
         
        heap->heap[heap->size].id = tid;
        heap->heap[heap->size].priority = p;

        //update index
        int indx = heap->size;
        map[tid] = indx; 
        heap->per_up(indx);
        heap->size++;
    }

    //Remove and return (a reference to) a task ID with smallest priority.
    const T & deleteMin() {
        T &temp = heap->heap[0].id; //reference to
        
        map.erase(temp);
        heap->size--;
        heap->heap[0] = heap->heap[heap->size]; //make it the last leaf
        map[heap->heap[0].id] = 0; //update map
        heap->per_down(0);
        
        return temp; 
    }

    //Return (a reference to) a task ID with the smallest priority.
    T & getMin() {
        T &ref = heap->heap[0].id;
        return ref; 
    }

    //change the priority for task tid to p.
    void updatePriority( const std::string & tid, int p ) {
        if(map.find(tid) == map.end()){
            return;
        }

        int old_pri = heap->heap[map.at(tid)].priority; 
        heap->heap[map.at(tid)].priority = p;
    
        //fix the order
        if(p < old_pri){
            heap->per_up(map.at(tid));
        }
        
        else if(p > old_pri){
            heap->per_down(map.at(tid));
        }
    }

    //remove the task with ID tid from the PQ
    void remove( const std::string & tid ) {
        // the taks is not in the heap
        if(map.find(tid) == map.end()){
            return;
        }

        //change with last leaf
        heap->size--;
        int indx = map[tid]; 
        heap->heap[indx] = heap->heap[heap->size];
        map[heap->heap[indx].id] = indx; 
        map.erase(tid);
        
        //fix the heap
        heap->per_down(indx);
    }

    //Return true if the PQ is empty, otherwise false.
    bool isEmpty() { return heap->size==0; }

    //Return the number of tasks in the PQ
    int size() { return heap->size; }

    //Remove all tasks from the PQ.
    void clear() { heap->size=0; }

    //Changes the heap array size to be max{i,10}.
    void reserve(int i) {
        if(i > heap->capacity)
            heap->reserve(i);
    }

private:
    //set id and priority
    class HeapPair {
        public:

        HeapPair(){
            id = T();
            priority = 0;
        }

        T id; 
        int priority;
        
    };
    
     class minHeap {
        public:

        HeapPair* heap; 
        int size; 
        int capacity; //capacity of array/heap

        minHeap(int initcap){
            capacity = initcap;
            heap = new HeapPair[capacity]; //make the array with id and priority
            size = 0;
        }

        //percolate up
        //while v is not a root and key(v) < key(parent(v)), then swap positions
        //left child = 2i+1
        //right child = 2i+2
        //parent = (index-1) / 2 backwards
       void per_up(int index){
            
            int parent = (index-1) / 2;
        
           //if it is the root
            if(index==0)
                return; //base case

            if(heap[index].priority < heap[parent].priority){
                swap(index, parent); //so index is now the parent
                per_up(parent);
            }
        }
        

        //percolcate down
        //while i is not a leaaf
        void per_down(int index){
            //if child is not a leaf
            if(2*index+1 > size)
                return;
            
            int child = 2*index+1; //left child
            if(2*index+2 <= size && heap[2*index+2].priority < heap[child].priority){
                child = 2*index+2; 
            }
            //order is voilated
            if(heap[child].priority < heap[index].priority){ 
                swap(child, index);
                per_down(child); //percolate down from the next child 
            }
        }

        //changes the keys
        void swap(int index1, int index2 ){
            HeapPair temp = heap[index1]; //heap[indx1].priority;
            heap[index2] = heap[index1];
            temp = heap[index2];
        }

        void reserve(int newCapacity) {
            HeapPair* newHeap = new HeapPair[newCapacity];
            for (int i = 0; i < size; ++i) {
                newHeap[i] = heap[i];
            }
            capacity = newCapacity;
            delete[] heap;
            heap = newHeap;
        }

        //destuctor 
        ~minHeap(){
            delete [] heap;
        }

     };

     minHeap *heap; //for public
     unordered_map<string, int> map; 

};