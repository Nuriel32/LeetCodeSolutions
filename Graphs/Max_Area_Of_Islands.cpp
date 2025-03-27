#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int max_island = 0;

        // Helper BFS function
        auto bfs = [&](int r, int c) -> int {
            int island_size = 1;
            queue<pair<int, int>> q;
            q.push({r, c});
            visited[r][c] = true;

            vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

            while (!q.empty()) {
                auto [row, col] = q.front(); q.pop();
                for (auto [dr, dc] : directions) {
                    int new_r = row + dr;
                    int new_c = col + dc;

                    if (new_r >= 0 && new_r < rows &&
                        new_c >= 0 && new_c < cols &&
                        grid[new_r][new_c] == 1 &&
                        !visited[new_r][new_c]) {
                        visited[new_r][new_c] = true;
                        q.push({new_r, new_c});
                        island_size++;
                    }
                }
            }

            return island_size;
        };

        // Loop through all cells to start BFS
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    max_island = max(max_island, bfs(i, j));
                }
            }
        }

        return max_island;
    }
};