#include <iostream>
#include <vector>

using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;

    int n, s;
    int freeSpot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N; // total number of stack we have top form in a single array
        s = S; // s is the size of the array

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // initializing top
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // initializing next
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }

        // update last index value to -1
        next[s - 1] = 1;

        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if (freeSpot == -1)
        {
            return false;
        }

        // find index
        int index = freeSpot;

        // insert element
        arr[index] = x;

        // update freeSpot
        freeSpot = next[index];

        // update next
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow
        if (top[m - 1] == -1)
        {
            return -1;
        }

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }
};

int main()
{
    vector<int> arr(2);

    // arr.push_back(0);
    // arr.push_back(1);

    arr[0] = 0;
    arr[1] = 1;
    // arr[2] = 2;
    // arr.push_back(2);

    for(auto i : arr){
        cout<<i<<endl;
    }

    return 0;
}