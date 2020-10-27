#include <iostream>
#include "linkedlist.h"

using namespace std;
void ProcessPrint(int t)
{
    cout << t << " ";
}
int main()
{
    cout << "This will create and traverse a linked list" << endl;
    LLinkedList<int> MyList;
    MyList.append(1);
    MyList.append(2);
    MyList.append(3);
    MyList.applyall(ProcessPrint);
    cout << endl
         << "Completed" << endl;
    return 0;
}