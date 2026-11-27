class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        unordered_map<int, bool> visited;
        queue<tuple<int, int, int>> q;

        if (grid[0][0] == 1) return -1;

        q.push({0, 0, 1});
        visited[0] = true;

        while (!q.empty()) {
            auto [x, y, len] = q.front();
            q.pop();

            if (x == n - 1 && y == m - 1) {
                return len;
            }

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                if (grid[nx][ny] == 1) continue;

                int idx = nx * m + ny;

                if (visited[idx]) continue;

                visited[idx] = true;
                q.push({nx, ny, len + 1});
            }
        }

        return -1;
    }
};