#include <iostream>
using namespace std;
 
void printNos(int initial, int last)
{
    if (initial <= last) {
        cout << initial << " ";
        printNos(initial + 1, last);
    }
}
 
int main()
{
    printNos(1, 100);
    return 0;
}

