// leetcode Binary Search Problem

/* Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int StartingIndex(vector<int> &nums, int target) // first occurence of target
{
    int left = 0;
    int right = (nums.size()) - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int midNum = nums[mid];
        if (target == midNum)
        {
            if ((mid > 0) && (nums[mid - 1] == target))
            {
                return mid - 1;
            }
            else
            {
                return mid;
            }
        }
        else if (target > midNum)
        {
            left = mid + 1;
        }
        else if (target < midNum)
        {
            right = mid - 1;
        }
    }
    return -1; // not found
}

// second occurence
int EndingIndex(vector<int> &nums, int target)
{
    int left = 0;
    int right = (nums.size()) - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int midNum = nums[mid];
        if (target == midNum)
        {
            if ((mid < (nums.size()) - 1) && (nums[mid + 1] == target))
            {
                return mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else if (target > midNum)
        {
            left = mid + 1;
        }
        else if (target < midNum)
        {
            right = mid - 1;
        }
    }
    return -1; // not found
}

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result;
        result.push_back(StartingIndex(nums, target));
        result.push_back(EndingIndex(nums, target));
        return result;
    }
};

int main()
{
    int element;
    int target;

    // populating the vector array
    vector<int> nums = {1, 1, 4, 4, 7, 9, 9};


    for (int num : nums)
    {
        cout << num << " ";
    }

    cout << endl;
    cout << "Enter the target element: " << endl;
    cin >> target;

    Solution s;
    vector<int> output = s.searchRange(nums, target);

    cout << "The starting and the ending positions of the target element is: ";
    cout << "[";
    for (int i = 0; i < (output.size()); i++)
    { // iterating throught the vector
        cout << output[i];
        if (i != (output.size())-1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
