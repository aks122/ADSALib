#include <iostream>
#include "queueds.h"

using namespace std;
using namespace algolib;

#define SDEL(n) cout << "Deleted: " << n << endl

int main()
{
    Queue<int> MyQueue(5);
    MyQueue.Insert(1);
    MyQueue.Insert(2);
    MyQueue.Insert(3);
    SDEL(MyQueue.Delete());
    MyQueue.Insert(4);
    MyQueue.Insert(5);
    SDEL(MyQueue.Delete());
    SDEL(MyQueue.Delete());
    MyQueue.Insert(6);
    SDEL(MyQueue.Delete());
    MyQueue.Insert(7);
    MyQueue.Insert(8);
    SDEL(MyQueue.Delete());
    SDEL(MyQueue.Delete());
    MyQueue.Insert(9);
    SDEL(MyQueue.Delete());
    SDEL(MyQueue.Delete());
    SDEL(MyQueue.Delete());
    
    return 0;
}