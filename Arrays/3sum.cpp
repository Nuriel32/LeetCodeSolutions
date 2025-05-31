using namespace std;
#include <vector>
#include <algorithm>
// Problem: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>> sol;    
        for(int iterator = 0 ; iterator < nums.size();iterator++)
        {

            int left = iterator +1;
            int right = nums.size() -1;
            int total = nums[iterator];
            if(iterator > 0 && nums[iterator] == nums[iterator -1])
                continue;
            while(left < right)
            {
                int compute = total + ( nums[left]+nums[right]);
                if(compute == 0)
                {
                 sol.push_back({nums[iterator],nums[left],nums[right]});
                  while (left < right && nums[left] == nums[left + 1]) left++;
                  while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;

                }
            
                else{
                    if(compute > 0)
                    {
                        right --;
                    }
                    else
                    {
                        left++;
                    }

                }
            }
            

        }

     return sol;   
    }
};
