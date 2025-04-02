/*
Find the Duplicate Number
You are given an array of integers nums containing n + 1 integers. Each integer in nums is in the range [1, n] inclusive.

Every integer appears exactly once, except for one integer which appears two or more times.
 Return the integer that appears more than once.
*/
#include <vector>
using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int>& nums) { 

            if(nums.size() <2) return -1;
            int slowpointer = nums[0];
            int fastpointer = nums[0];


            while(true) {
                slowpointer = nums[slowpointer];
                fastpointer = nums[nums[fastpointer]];
                if(slowpointer == fastpointer) break;
            }


         
            int entry = nums[0];
            while(entry != slowpointer) {
                entry = nums[entry];
                slowpointer = nums[slowpointer];
            }
            return entry;
             

        }

         
        
         
        
    };
    