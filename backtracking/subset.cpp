/*Subsets
Given an array nums of unique integers, return all possible subsets of nums.

The solution set must not contain duplicate subsets. You may return the solution in any order.*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    
        vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        int index =0;
        helper(nums, subset, subsets, index);
        return subsets;
        }
    
    
    
    
        void helper(vector<int>& nums, vector<int>& subset, vector<vector<int>>& solutions, int i)
        {
            if( i >= nums.size())
                {   
                    solutions.push_back(subset);
                    return;
                }
            
           
                    subset.push_back(nums[i]);
                    helper(nums, subset, solutions, (i + 1));
                    subset.pop_back();
                    helper(nums, subset, solutions, (i + 1));
                    
        }
    };
    



    int main() {
        Solution s;
        vector<int> nums = {1, 2, 3};
    
        vector<vector<int>> result = s.subsets(nums);
    
        cout << "All subsets of [1, 2, 3]:" << endl;
        for (const auto& subset : result) {
            cout << "[ ";
            for (int num : subset)
                cout << num << " ";
            cout << "]" << endl;
        }
    
        return 0;
    }
