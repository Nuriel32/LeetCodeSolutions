#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            if (grid.empty() || grid[0].empty()) return 0;
    
            int rows = grid.size();
            int cols = grid[0].size();
            int island_count = 0;
    
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
            vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
            auto bfs = [&](int r, int c) {
                queue<pair<int, int>> q;
                q.push({r, c});
                visited[r][c] = true;
    
                while (!q.empty()) {
                    auto [row, col] = q.front(); q.pop();
    
                    for (auto [dr, dc] : directions) {
                        int new_r = row + dr;
                        int new_c = col + dc;
    
                        if (new_r >= 0 && new_r < rows &&
                            new_c >= 0 && new_c < cols &&
                            grid[new_r][new_c] == '1' &&
                            !visited[new_r][new_c]) {
                            visited[new_r][new_c] = true;
                            q.push({new_r, new_c});
                        }
                    }
                }
            };
    
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (grid[i][j] == '1' && !visited[i][j]) {
                        bfs(i, j);
                        island_count++;
                    }
                }
            }
    
            return island_count;
        }
    };