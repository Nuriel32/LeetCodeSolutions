#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        if (s.empty()) return true;  

        stack<char> stk;
        unordered_map<char, char> matchingBrackets = {
            {')', '('}, 
            {'}', '{'}, 
            {']', '['}
        };

        for (char c : s) {
            if (matchingBrackets.count(c)) {
                if (stk.empty() || stk.top() != matchingBrackets[c]) {
                    return false; 
                }
                stk.pop();  
            } else {
                stk.push(c);  
            }
        }

        return stk.empty();  
    }
};

