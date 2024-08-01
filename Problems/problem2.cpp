// Binary Search problem

/* You are given list of numbers, obtained by rotating a sorted list an unknown number of times.
Write a function to determine the minimum number of times the original sorted list was rotated to obtain the given list.
The list [5, 6, 9, 0, 2, 3, 4] was obtained by rotating the sorted list [0, 2, 3, 4, 5, 6, 9] 3 times.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Rotations(vector<int> list)
{ // counts the no of times the original list was rotated
    int left = 0;
    int right = (list.size()) - 1;
    int mid = (left + right) / 2;
    // check if the right-half is sorted
    for (int i = 1; i <= mid; i++)
    {
        if (mid < mid + i)
        {
            mid++;
        }
    }
}

int main()
{
    vector<int> list = {5, 6, 9, 0, 2, 3, 4};
}