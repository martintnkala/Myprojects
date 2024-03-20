#include <iostream>
#include<vector>
#include<string>
using namespace std;
#include<deque>

int main()
{
    // default constructor
    deque<int> dq;

    // Non-default constructor
    deque<int>d(4);
    d.push_back(1);
    d.push_front(3);
    d[2] = 4;
    for (auto it = d.begin(); it != d.end(); ++it)
        cout << *it << " ";


    // Range Constructor
    char* p = "deque";
    deque<char> d1 (p, p+5);

    cout << " d1 size " << d1[1] << "\n";
    dq.push_front(10);
    dq.push_back(9);

    cout << "\nSubscript Operator" << "\n";
    cout << dq[9] << endl;
    cout << "at Operator" << "\n";
//    cout << dq.at(4) << endl;

   return 0;
}


