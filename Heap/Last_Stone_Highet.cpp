class Solution {
    public:
        int lastStoneWeight(vector<int>& stones) {
            priority_queue<int> spq;
    
            for (int stone : stones) {
                spq.push(stone);
            }
    
            while (spq.size() > 1) {
                int x = spq.top(); spq.pop();
                int y = spq.top(); spq.pop();
    
                int gap = x - y;
                if (gap != 0) {
                    spq.push(gap);
                }
            }
    
            return spq.empty() ? 0 : spq.top();
        }
    };
    