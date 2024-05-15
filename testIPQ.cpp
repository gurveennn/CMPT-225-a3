#include "IPQ.h" 

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// gurveen nanua
// 301546459
//testing Indexed Priority Queue

int main(){

    //mkae an empty heap
    cout << "\nMaking a empty heap called 'a'..." << endl; 
    IPQ<string> a;

    //checks if the heap is created and if its empty
    cout << "if heap is emtpy return true" << endl;
    if(a.isEmpty())
        cout << "\ntrue" << endl;
    else cout << "\nfalse" << endl; 

    //inserting items (task, priority) (T1,3), (T2,2), (T3,6) to test insert function 
    cout << "\ninserting task and prioirty into heap a: (T1,3), (T2,2), (T3,6)" << endl;
    a.insert("T1", 3);
    a.insert("T2", 2);
    a.insert("T3", 6);

    //checking the size of heap, should be size 3
    cout << "The size of heap a is: " << a.size() << endl; 

    //get value with the smallest priority to test getMin() and deleteMIN()
    cout << "\nMinimum task ID for a: " << a.getMin() << endl;
    cout << "Deleting and returing minimum task ID for a: " << a.deleteMin() << endl;
    cout << "Checking size of heap: " << a.size() << endl; 

    //insert more tasks
    cout << "\nInserting (T4,5), (T5,4) and (T6,7)" << endl;
    a.insert("T4", 5);
    a.insert("T5", 4);
    a.insert("T6", 7);

    cout << "Minimum task ID for a: " << a.getMin() << endl;
    cout << "Checking size of heap: " << a.size() << endl; 

    //remove tasks to test remove function
    cout << "\nRemoving T3 and T4:" << endl;
    a.remove("T3");
    a.remove("T4");

    cout << "Checking size of heap: " << a.size() << endl; 

    //update a task to priortity 1 to test updatePriority() function
    cout << "\nUpdating 'T5' to be priority 1" << endl;
    a.updatePriority("T5", 1); 

    //get the min task, should be updated task
    cout << "Minimum task ID for 'a' is: " << a.getMin() << endl;

    //clear the tasks to test clear() function
    cout << "\nRemoving all tasks from heap 'a'" << endl;
    a.clear();
    cout << "Checking size of heap: " << a.size() << endl; 



    //make a heap given a vector
    vector<string> v1; //{"t1", "t2", "t3", "t4", "t5", "t6"};
    vector<int> v2; // {2,3,4,5,6,1};

    v1.push_back("t1");
    v1.push_back("t2");
    v1.push_back("t3");
    v1.push_back("t4");
    v1.push_back("t5");
    v1.push_back("t6");

    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(1);

    //intialzing the heap by passing to the constructor 
    cout << "\nmaking a heap given vectors:" 
     "{t1, t2, t3, t4, t5, t6} and {2,3,4,5,6,1} called 'b'..." << endl;
    IPQ<string> b(v1, v2);

    //get min and delete min for b
    cout << "\nMinimum task ID for b: " << b.getMin() << endl;
    cout << "Checking size of heap: " << b.size() << endl; 

    //insert and remvove some tasks
    cout << "\nInserting (t7,7) and removing t1" << endl;
    b.insert("t7", 7);
    b.remove("t1");
    cout << "Checking size of heap: " << b.size() << endl;


    //end of test
    cout << "\nEnd of test :)" << endl;

    return 0; 

}