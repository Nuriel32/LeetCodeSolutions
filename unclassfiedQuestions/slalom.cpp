#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    int N = A.size();
    if (N == 0) return 0;

    vector<vector<vector<int>>> dp(N, vector<vector<int>>(3, vector<int>(2, 0)));
    int result = 0;

    for (int i = 0; i < N; ++i) {
       
        dp[i][0][0] = 1;

        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j]) { 
                for (int k = 0; k < 3; ++k) {
                    if (dp[j][k][0] > 0)
                        dp[i][k][0] = max(dp[i][k][0], dp[j][k][0] + 1);
                    if (k > 0 && dp[j][k - 1][1] > 0)
                        dp[i][k][0] = max(dp[i][k][0], dp[j][k - 1][1] + 1);
                }
            }
            else if (A[i] < A[j]) { 
                for (int k = 0; k < 3; ++k) {
                    if (dp[j][k][1] > 0)
                        dp[i][k][1] = max(dp[i][k][1], dp[j][k][1] + 1);
                    if (k > 0 && dp[j][k - 1][0] > 0)
                        dp[i][k][1] = max(dp[i][k][1], dp[j][k - 1][0] + 1);
                }
            }
        }

        for (int k = 0; k < 3; ++k) {
            for (int d = 0; d < 2; ++d) {
                result = max(result, dp[i][k][d]);
            }
        }
    }

    return result;
}
