/*
Last Stone Weight
You are given an array of integers stones where stones[i] represents the weight of the ith stone.

We want to run a simulation on the stones as follows:

At each step we choose the two heaviest stones, with weight x and y and smash them togethers
If x == y, both stones are destroyed
If x < y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
Continue the simulation until there is no more than one stone remaining.

Return the weight of the last remaining stone or return 0 if none remain.

Example 1:
*/


class Solution {
    public:
        int lastStoneWeight(vector<int>& stones) {
            priority_queue<int> spq;
    
            for(int stone : stones)
            {
                spq.push(stone);
            }
    
    
    
          while (!pq.empty()) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        int gap = x - y;
    
        if (gap != 0) {pq.push(gap);}
        }
    
    
        return spq.top();
        }
    };
    