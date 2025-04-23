/*
Longest Substring Without Repeating Characters
Solved 
Given a string s, find the length of the longest substring without duplicate characters.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "zxyzxyz"

Output: 3
Explanation: The string "xyz" is the longest without duplicate characters.

Example 2:

Input: s = "xxxx"

Output: 1
Constraints:

0 <= s.length <= 1000
s may consist of printable ASCII characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> bucket;
        int left = 0, right = 0;
        int maxWindow = 0;
        int n = s.size();

        while (right < n) {
            if (bucket.find(s[right]) == bucket.end()) {
                bucket.insert(s[right]);
                maxWindow = max(maxWindow, right - left + 1);
                right++;
            } else {
                // תו כפול → הסר תווים מהתחלה עד שנפטרים ממנו
                bucket.erase(s[left]);
                left++;
            }
        }

        return maxWindow;
    }
};
