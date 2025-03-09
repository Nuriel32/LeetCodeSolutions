#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.empty()) return 0;
    
            int buyIndex = 0;  
            int profit = 0; 
    
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] < prices[buyIndex]) {
                    buyIndex = i;
                } else {
                    int tempProfit = prices[i] - prices[buyIndex];
                    profit = max(profit, tempProfit);
                }
            }
            return profit;
        }
    };