class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> freqA(n/2 + 1, vector<int>(26, 0));
        vector<vector<int>> freqB(n/2 + 1, vector<int>(26, 0));
        vector<int> mismatches(n/2 + 1, 0);
        for (int i = 0; i < n/2; i++) {
            if (s[i] != s[n - 1 - i]) {
                mismatches[i + 1] = mismatches[i] + 1;
            } else {
                mismatches[i + 1] = mismatches[i];
            }
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < 26; j++) {
                if (s[i] == char(j + 'a')) {
                    freqA[i + 1][j] = freqA[i][j] + 1;
                } else {
                    freqA[i + 1][j] = freqA[i][j];
                }
            }
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < 26; j++) {
                if (s[n - 1 - i] == char(j + 'a')) {
                    freqB[i + 1][j] = freqB[i][j] + 1;
                } else {
                    freqB[i + 1][j] = freqB[i][j];
                }
            }
        }
        int from = 0;
        int ii = 0;
        while (ii <= n/2) {
            if (s[ii] == s[n - 1 - ii]) {
                from++;
                ii++;
            } else {
                break;
            }
        }

        int to = n/2 - 1;
        int iii = 0;
        while (iii < n/2) {
            if (s[n/2 - 1 - iii] == s[n/2 + iii]) {
                to--;
                iii++;
            } else {
                break;
            }
        }

        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < 26; i++) {
            if (freqA[freqA.size() - 1][i] != freqB[freqB.size() - 1][i]) {
                return ans;
            }
        }
        ans = vector<bool>(queries.size(), true);
        if (from > n/2) {
            return ans;
        }
        for (int q = 0; q < queries.size(); q++) {
            vector<int> query = queries[q];
            int a = query[0];
            int b = query[1];
            int c = n - 1 - query[3];
            int d = n - 1 - query[2];
            if (min(a, c) > from + 1 || max(b, d) < to - 1) {
                ans[q] = false;
            }
            vector<int> ab = freqA[b + 1];
            for (int i = 0; i < 26; i++) {
                ab[i] -= freqA[a][i];
            }
            vector<int> cd = freqB[d + 1];
            for (int i = 0; i < 26; i++) {
                cd[i] -= freqB[c][i];
            }


            if (b < c || d < a) {
                if (a == b) {
                    if (s[a] != s[n - 1 - a]) {
                        ans[q] = false;
                    }
                } else {
                    vector<int> abb = freqB[b + 1];
                    for (int i = 0; i < 26; i++) {
                        abb[i] -= freqB[a][i];
                    }
                    for (int i = 0; i < 26; i++) {
                        if (ab[i] != abb[i]) {
                            ans[q] = false;
                        }
                    }
                }
                if (c == d) {
                    if (s[c] != s[n - 1 - c]) {
                        ans[q] = false;
                    }
                } else {
                    vector<int> cda = freqA[d + 1];
                    for (int i = 0; i < 26; i++) {
                        cda[i] -= freqA[c][i];
                    }
                    for (int i = 0; i < 26; i++) {
                        if (cd[i] != cda[i]) {
                            ans[q] = false;
                        }
                    }
                }
                if (b < c) {
                    if (mismatches[c] - mismatches[b + 1] != 0) {
                        ans[q] = false;
                    }
                }
                if (d < a) {
                    if (mismatches[a] - mismatches[d + 1] != 0) {
                        ans[q] = false;
                    }
                }
                continue;
            }







            if (a < c) {
                vector<int> acb = freqB[c];
                for (int i = 0; i < 26; i++) {
                    acb[i] -= freqB[a][i];
                }
                for (int i = 0; i < 26; i++) {
                    ab[i] -= acb[i];
                    if (ab[i] < 0) {
                        ans[q] = false;
                    }
                }
            }
            if (c < a) {
                vector<int> aca = freqA[a];
                for (int i = 0; i < 26; i++) {
                    aca[i] -= freqA[c][i];
                }
                for (int i = 0; i < 26; i++) {
                    cd[i] -= aca[i];
                    if (cd[i] < 0) {
                        ans[q] = false;
                    }
                }
            }
            if (b > d) {
                vector<int> bdb = freqB[b + 1];
                for (int i = 0; i < 26; i++) {
                    bdb[i] -= freqB[d + 1][i];
                }
                for (int i = 0; i < 26; i++) {
                    ab[i] -= bdb[i];
                    if (ab[i] < 0) {
                        ans[q] = false;
                    }
                }
            }
            if (d > b) {
                vector<int> bda = freqA[d + 1];
                for (int i = 0; i < 26; i++) {
                    bda[i] -= freqA[b + 1][i];
                }
                for (int i = 0; i < 26; i++) {
                    cd[i] -= bda[i];
                    if (cd[i] < 0) {
                        ans[q] = false;
                    }
                }
            }
            if (mismatches[n/2] - mismatches[max(b, d) + 1] != 0) {
                ans[q] = false;
            }
            if (ab != cd) {
                ans[q] = false;
            }
        }
        return ans;
    }
};