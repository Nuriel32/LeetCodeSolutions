class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int N = matrix.size();
            if (N == 0) return false;
            int M = matrix[0].size();
            if (M == 0) return false;
    
            if (target < matrix[0][0] || target > matrix[N - 1][M - 1])
                return false;
    
            int lrow = 0, rrow = N - 1;
    
            while (lrow <= rrow) {
                int midrow = (lrow + rrow) / 2;
    
                if (target == matrix[midrow][0] || target == matrix[midrow][M - 1])
                    return true;
    
                if (target > matrix[midrow][0] && target < matrix[midrow][M - 1]) {
                    int left = 0, right = M - 1;
                    while (left <= right) {
                        int midcol = (left + right) / 2;
                        if (matrix[midrow][midcol] == target) return true;
                        else if (matrix[midrow][midcol] < target)
                            left = midcol + 1;
                        else
                            right = midcol - 1;
                    }
                    return false;
                } else if (target < matrix[midrow][0]) {
                    rrow = midrow - 1;
                } else {
                    lrow = midrow + 1;
                }
            }
    
            return false;
        }
    };
    