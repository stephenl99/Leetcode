class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        unordered_set<int> wallSet;
        unordered_set<int> guardSet;
        unordered_set<int> visited;

        for (auto& w : walls)
            wallSet.insert(w[0] * n + w[1]);

        for (auto& g : guards)
            guardSet.insert(g[0] * n + g[1]);

        int count = m * n - guards.size() - walls.size();

        for (auto& guard : guards) {
            int x = guard[0];
            int y = guard[1];

            // down
            for (int i = x + 1; i < m; i++) {
                int pos = i * n + y;

                if (guardSet.contains(pos) || wallSet.contains(pos))
                    break;

                visited.insert(pos);
            }

            // right
            for (int j = y + 1; j < n; j++) {
                int pos = x * n + j;

                if (guardSet.contains(pos) || wallSet.contains(pos))
                    break;

                visited.insert(pos);
            }

            // up
            for (int i = x - 1; i >= 0; i--) {
                int pos = i * n + y;

                if (guardSet.contains(pos) || wallSet.contains(pos))
                    break;

                visited.insert(pos);
            }

            // left
            for (int j = y - 1; j >= 0; j--) {
                int pos = x * n + j;

                if (guardSet.contains(pos) || wallSet.contains(pos))
                    break;

                visited.insert(pos);
            }
        }

        return count - visited.size();
    }
};