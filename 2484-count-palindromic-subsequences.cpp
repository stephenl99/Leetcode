class Solution {
public:
    int countPalindromes(string s) {
        int count = 0;
        int mod = 1e9 + 7;
        static int dp[10005][10005][3];

        // vector<vector<vector<int>>> dp(s.size(), vector<vector<int>>(s.size(), vector<int>(3)));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i][0] = 1;
        }

        for (int fakej = 1; fakej < s.size(); fakej++) {
            for (int i = 0; i < s.size() - fakej; i++) {
                int j = i + fakej;
                int* inQuestion = dp[i][j];  // pointer to 3-int array

                if (i + 1 == j) {
                    inQuestion[0] = 2;
                    continue;
                }

                inQuestion[0] = (2 + dp[i + 1][j - 1][0]) % mod;

                int val3 = dp[i + 1][j - 1][1] % mod;
                inQuestion[1] = (val3 +
                    (dp[i][j - 1][1] - val3 + mod) % mod +
                    (dp[i + 1][j][1] - val3 + mod) % mod) % mod;

                int val5 = dp[i + 1][j - 1][2] % mod;
                long long temp = (
                    (long long)val5 +
                    (((long long)dp[i][j - 1][2] - val5 + mod) % mod) +
                    (((long long)dp[i + 1][j][2] - val5 + mod) % mod)
                ) % mod;
                inQuestion[2] = temp;

                if (s[i] == s[j]) {
                    inQuestion[1] += (dp[i + 1][j - 1][0] % mod);
                    inQuestion[1] %= mod;
                    inQuestion[2] += (dp[i + 1][j - 1][1] % mod);
                    inQuestion[2] %= mod;
                }
            }
        }

        return dp[0][s.size() - 1][2] % mod;
    }
};
