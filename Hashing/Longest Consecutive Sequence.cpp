#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());  // Fixed 'ends()' to 'end()'
        int longestConsec = 0;  // Fixed variable name typo

        for (int num : nums) {  // Fixed loop syntax (missing type for 'num')
            if (numSet.find(num - 1) == numSet.end()) {  // Check if it's the start of a sequence
                int length = 1;  // Fixed 'lenght' typo
                int currentNum = num;  // Store the starting number

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    length++;
                }

                longestConsec = max(length, longestConsec);
            }
        }
        return longestConsec;  // Fixed 'longsetconsec' typo
    }
};
