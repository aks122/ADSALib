#include <iostream>
#include "searchalgo.h"

using namespace std;
using namespace algolib;
int main()
{
    int arr[] = {2, 4, 7,8,39, 10};
    cout << "The array is: ";
    for(auto& i : arr)
        cout << i << ' ';
    cout << endl << "Input a number to know it's first occurrence: ";
    int t;
    cin >> t;
    cout << "Index is: " << GetIndexLinearSearch(arr, t, sizeof(arr)/sizeof(int))<<endl;

    return 0;
}