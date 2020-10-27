#include <iostream>
#include "linkedlist.h"

using namespace std;

template<typename T>
void ProcessPrint(T t)
{
    cout << t << " ";
}
int main()
{
    cout << "UNSORTED LINKED LIST" << endl;
    LLinkedList<int> MyList;
    MyList.Append(1);
    MyList.Append(99);
    MyList.Append(3);
    MyList.Append(100);
    MyList.ApplyAll(ProcessPrint<int>);
    cout << endl;
    cout << "The count of the linked list items is "<<MyList.Count() << endl;

    cout << "\nSORTED ARRAY"<<endl;
    LLinkedList<double> SortedList(true);
    SortedList.Append(7837);
    SortedList.Append(23);
    SortedList.Append(-0.346);
    SortedList.Append(2);
    SortedList.Append(0.3655);
    SortedList.Append(2);
    SortedList.ApplyAll(ProcessPrint<double>);
    cout << endl;
    cout << "The count of the linked list items is "<<SortedList.Count() << endl;

    return 0;
}