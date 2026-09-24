class Solution {
public:
    vector<long long> countBlackBlocks(
        int m, int n, vector<vector<int>>& coordinates
    ) {
        vector<long long> ans(5, 0);

        unordered_map<long long, int> cnt;

        auto key = [&](int r, int c) -> long long {
            return 1LL * r * n + c;
        };

        for (auto& coord : coordinates) {
            int r = coord[0], c = coord[1];

            for (int dr = -1; dr <= 0; dr++) {
                for (int dc = -1; dc <= 0; dc++) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < m - 1 &&
                        nc >= 0 && nc < n - 1) {
                        cnt[key(nr, nc)]++;
                    }
                }
            }
        }

        for (auto& [k, v] : cnt) {
            ans[v]++;
        }

        ans[0] = 1LL * (m - 1) * (n - 1);

        for (int i = 1; i <= 4; i++) {
            ans[0] -= ans[i];
        }

        return ans;
    }
};