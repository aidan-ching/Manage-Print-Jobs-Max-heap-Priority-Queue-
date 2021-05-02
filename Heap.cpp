#include "Heap.h"
#include <iostream>
#include <algorithm>
using namespace std;
//collab with Aidan Ching
Heap::Heap(){
    numItems = 0;
}
void Heap::enqueue(PrintJob* abc){
    if(numItems == 0){ //if there's nothing in the array, 0th index stores first item.
        arr[0] = abc;
        numItems++;
    } else {
        if(numItems == 10){ //max amount of items is 10.
            return;
        }
        arr[numItems] = abc; //numItem index stores item.
        int parent = numItems; //using a temp variable since i dont want numItems to be manipulated.
        while(parent != 0 && arr[parent]->getPriority() > arr[(parent-1)/2]->getPriority()){ //if parent index has greater prio than (parent-1/2, the actual parent of the index), swap
            swap(arr[parent], arr[(parent-1)/2]);
            parent = (parent-1)/2; //keep checking till u get to the root if necessary
        }
        numItems++;
    }
    }
void Heap::dequeue(){
    PrintJob *temp = highest();
    if(temp == nullptr){ //if theres nothing in the heap, return.
        return;
    }
        swap(arr[0], arr[numItems-1]); //root goes to leaf, leaf goes to root
        delete arr[numItems-1]; //delete the leaf.
        numItems--;
        trickleDown(arr[0]->getPriority());
    
}

PrintJob* Heap::highest(){
    if(numItems == 0){ //nothing in heap, return.
        return nullptr;
    } else {
    PrintJob *highest = arr[0];
    return highest;
}
}

void Heap::print(){
    PrintJob *temp = highest();
    cout << "Priority: " << temp->getPriority() << ", Job Number: " << temp->getJobNumber() << ", Number of Pages: " << temp->getPages() << endl;
}
void Heap::trickleDown(int abc){
    int index = 0;
    while(index < numItems){ //index HAS to be less than numItems, dont wanna access a position that isnt filled.
        if( (2*index) + 1 >= numItems || (2*index) + 2 >= numItems) { //if childs dont exist
            return;
        }
        if(arr[(2*index)+1]->getPriority() > abc || arr[(2*index)+2]->getPriority() > abc){ //makes sure that atleast one of the index has greater prio.
            if(arr[(2*index)+2]->getPriority() > arr[(2*index)+1]->getPriority()) { //checks to see which child is has greater prio
                swap(arr[index], arr[(2*index)+2]); //swap if right
                index = (2*index)+2; //index is now the index that is swapped. repeat until child priorities are not greater than original priority.
        } else {
                swap(arr[index], arr[(2*index)+1]); //swap if left
                index = (2*index)+1; //index is now the index that is swapped. repeat until child priorities are not greater than original priority.
        }
        } 
}
}