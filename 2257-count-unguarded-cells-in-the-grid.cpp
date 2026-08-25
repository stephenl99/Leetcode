class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        // 0 = empty
        // 1 = guard
        // 2 = wall
        // 3 = guarded
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto& g : guards)
            grid[g[0]][g[1]] = 1;

        for (auto& w : walls)
            grid[w[0]][w[1]] = 2;

        // Left -> Right
        for (int i = 0; i < m; i++) {
            bool seenGuard = false;

            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    seenGuard = false;
                }
                else if (grid[i][j] == 1) {
                    seenGuard = true;
                }
                else if (seenGuard) {
                    grid[i][j] = 3;
                }
            }
        }

        // Right -> Left
        for (int i = 0; i < m; i++) {
            bool seenGuard = false;

            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 2) {
                    seenGuard = false;
                }
                else if (grid[i][j] == 1) {
                    seenGuard = true;
                }
                else if (seenGuard) {
                    grid[i][j] = 3;
                }
            }
        }

        // Top -> Bottom
        for (int j = 0; j < n; j++) {
            bool seenGuard = false;

            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 2) {
                    seenGuard = false;
                }
                else if (grid[i][j] == 1) {
                    seenGuard = true;
                }
                else if (seenGuard) {
                    grid[i][j] = 3;
                }
            }
        }

        // Bottom -> Top
        for (int j = 0; j < n; j++) {
            bool seenGuard = false;

            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 2) {
                    seenGuard = false;
                }
                else if (grid[i][j] == 1) {
                    seenGuard = true;
                }
                else if (seenGuard) {
                    grid[i][j] = 3;
                }
            }
        }

        int unguarded = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    unguarded++;
            }
        }

        return unguarded;
    }
};