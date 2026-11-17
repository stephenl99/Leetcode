class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        auto bfs =[grid](int i, int j, int building_count) {
            int n = grid[0].size();
            int m = grid.size();
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
            queue<tuple<int, int, int>> q;
            q.push(tuple(i, j, 0));
            int cost = 0;
            int count = 0;
            while (!q.empty()) {
                auto [x, y, d] = q.front();
                q.pop();
                for (auto& [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        if (grid[nx][ny] == 0) {
                            q.push({nx, ny, d + 1});
                        } else if (grid[nx][ny] == 1) {
                            cost += d + 1;
                            if (++count == building_count) {
                                return cost;
                            }
                        }
                    }
                }
            }
            return -1;
        };
        int min_cost = INT_MAX;
        int building_count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) { 
                if (grid[i][j] == 1) {
                    ++building_count;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    int cost = bfs(i, j, building_count);
                    if (cost != -1) {
                        min_cost = min(min_cost, cost);
                    }
                }
            }
        }
        return min_cost == INT_MAX ? -1 : min_cost;
    }
};