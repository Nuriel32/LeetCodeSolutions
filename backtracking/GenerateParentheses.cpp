#include <vector>
#include <string>
using namespace std;
// Problem: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Approach: Use backtracking to generate all combinations of parentheses.

class Solution {
private:
    void backtrack(int open, int close, int n, string current, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(open + 1, close, n, current + '(', result);
        }

        if (close < open) {
            backtrack(open, close + 1, n, current + ')', result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, n, "", result);
        return result;
    }
};
