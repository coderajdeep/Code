/*

Given an unsorted integer array, find a pair with the given sum in it.

• Each input can have multiple solutions. The output should match with either one of them.

Input : nums[] = [8, 7, 2, 5, 3, 1], target = 10
Output: (8, 2) or (7, 3)

• The solution can return pair in any order. If no pair with the given sum exists, the solution should return the pair (-1, -1).

Input : nums[] = [5, 2, 6, 8, 1, 9], target = 12
Output: (-1, -1)

*/

// https://techiedelight.com/practice/?id=PQw-

// leetcode 1
// Here we need to return the index

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        unordered_map<int, int>um;
        
        for(int i=0; i<n; ++i) {
            
            int firstNum = target - nums[i];
            
            if(um.find(firstNum)!=um.end()) {
                // same as {um[firstNum], i}
                return vector<int>{um[firstNum], i};
            }
            
            um[nums[i]] = i;
        }
        
        // same as return {}
        return vector<int>{};
    }
};