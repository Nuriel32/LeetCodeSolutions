/**
 * @brief Calculates the minimum cost to reach the top of the staircase.
 * 
 * Each step has an associated cost. You can climb either 1 or 2 steps at a time.
 * You can start at step 0 or step 1.
 *
 * The function builds a dynamic programming (DP) array `min` where each index `i`
 * represents the minimum cost to reach step `i`.
 *
 * @param cost A vector of integers where cost[i] is the cost of stepping on the i-th stair.
 * @return The minimum cost to reach the top (one step beyond the last stair).
 *
 * Example:
 * Input: cost = [10, 15, 20]
 * Output: 15 (Take step 1 → step 3)
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        if(cost.size() <2) { return -1;}


        vector<int> min(cost.size() +1);

        for(int i = 2 ; i < min.size();i++)
        {
            min[i] =  (min[i-1] +cost[i-1] < min[i-2] +cost[i-2])?min[i-1] +cost[i-1] :min[i-2] +cost[i-2];
        }
        return min[cost.size()];



        
        
    }
};