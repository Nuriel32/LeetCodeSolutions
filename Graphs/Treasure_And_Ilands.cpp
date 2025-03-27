#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        using Cell = pair<int, int>;
        using State = pair<Cell, int>;
        queue<State> msqueue;

        const int rows = grid.size();
        const int cols = grid[0].size();
        const int INF = INT_MAX;

        // Initialize BFS queue with all treasure chests (value == 0)
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    msqueue.push({{row, col}, 0});
                }
            }
        }

        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        // Multi-Source BFS
        while (!msqueue.empty()) {
            auto [cell, distance] = msqueue.front();
            msqueue.pop();
            int row = cell.first;
            int col = cell.second;

            for (auto [dr, dc] : directions) {
                int new_r = row + dr;
                int new_c = col + dc;

                if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols &&
                    grid[new_r][new_c] == INF) {
                    grid[new_r][new_c] = distance + 1;
                    msqueue.push({{new_r, new_c}, grid[new_r][new_c]});
                }
            }
        }
    }
};
