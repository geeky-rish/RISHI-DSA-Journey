/*
✅ Problem: Longest Harmonious Subsequence  
🔖 Tags: Hash Table, Sorting, Frequency Count, Two-Pointer  
📈 Level: Easy (because of subtle logic)
🧠 Pattern: Count + Pairwise Matching

We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

Input: nums = [1,3,2,2,5,2,3,7]

Output: 5

Explanation:

The longest harmonious subsequence is [3,2,2,2,3].
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Step 1: sort the array

        int maxLen = 0;
        int start = 0;  // start index of a group of same numbers

        for (int i = 0; i < nums.size(); ++i) {
            // Move start until the difference is <= 1
            while (nums[i] - nums[start] > 1) {
                start++;
            }
            // If difference is exactly 1, consider this subsequence
            if (nums[i] - nums[start] == 1) {
                maxLen = max(maxLen, i - start + 1);
            }
        }

        return maxLen;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << "Length of longest harmonious subsequence: " << sol.findLHS(nums) << endl; // Output: 5
    return 0;
}
