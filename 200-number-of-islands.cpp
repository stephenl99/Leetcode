class Solution {
public:
    string to_string_pair(int i, int j) {
        return to_string(i) + "," + to_string(j);
    }

    int numIslands(vector<vector<char>>& grid) {
        unordered_set<string> visited;
        int count = 0;

        auto is_valid = [&](int i, int j) {
            return i >= 0 && j >= 0 &&
                   i < grid.size() && j < grid[0].size() &&
                   grid[i][j] == '1' &&
                   !visited.contains(to_string_pair(i, j));
        };

        auto explore = [&](this auto&& self, int i, int j) -> void {
            visited.insert(to_string_pair(i, j));

            int directions[4][2] = {
                {1, 0}, {0, 1}, {-1, 0}, {0, -1}
            };

            for (auto& direction : directions) {
                int ni = i + direction[0];
                int nj = j + direction[1];

                if (is_valid(ni, nj)) {
                    self(ni, nj);
                }
            }
        };

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' &&
                    !visited.contains(to_string_pair(i, j))) {
                    count++;
                    explore(i, j);
                }
            }
        }

        return count;
    }
};