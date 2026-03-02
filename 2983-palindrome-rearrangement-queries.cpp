1class Solution {
2public:
3    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
4        int n = s.size();
5        vector<vector<int>> freqA(n/2 + 1, vector<int>(26, 0));
6        vector<vector<int>> freqB(n/2 + 1, vector<int>(26, 0));
7        vector<int> mismatches(n/2 + 1, 0);
8        for (int i = 0; i < n/2; i++) {
9            if (s[i] != s[n - 1 - i]) {
10                mismatches[i + 1] = mismatches[i] + 1;
11            } else {
12                mismatches[i + 1] = mismatches[i];
13            }
14        }
15        for (int i = 0; i < n / 2; i++) {
16            for (int j = 0; j < 26; j++) {
17                if (s[i] == char(j + 'a')) {
18                    freqA[i + 1][j] = freqA[i][j] + 1;
19                } else {
20                    freqA[i + 1][j] = freqA[i][j];
21                }
22            }
23        }
24        for (int i = 0; i < n / 2; i++) {
25            for (int j = 0; j < 26; j++) {
26                if (s[n - 1 - i] == char(j + 'a')) {
27                    freqB[i + 1][j] = freqB[i][j] + 1;
28                } else {
29                    freqB[i + 1][j] = freqB[i][j];
30                }
31            }
32        }
33        int from = 0;
34        int ii = 0;
35        while (ii <= n/2) {
36            if (s[ii] == s[n - 1 - ii]) {
37                from++;
38                ii++;
39            } else {
40                break;
41            }
42        }
43
44        int to = n/2 - 1;
45        int iii = 0;
46        while (iii < n/2) {
47            if (s[n/2 - 1 - iii] == s[n/2 + iii]) {
48                to--;
49                iii++;
50            } else {
51                break;
52            }
53        }
54
55        vector<bool> ans(queries.size(), false);
56        for (int i = 0; i < 26; i++) {
57            if (freqA[freqA.size() - 1][i] != freqB[freqB.size() - 1][i]) {
58                return ans;
59            }
60        }
61        ans = vector<bool>(queries.size(), true);
62        if (from > n/2) {
63            return ans;
64        }
65        for (int q = 0; q < queries.size(); q++) {
66            vector<int> query = queries[q];
67            int a = query[0];
68            int b = query[1];
69            int c = n - 1 - query[3];
70            int d = n - 1 - query[2];
71            if (min(a, c) > from + 1 || max(b, d) < to - 1) {
72                ans[q] = false;
73            }
74            vector<int> ab = freqA[b + 1];
75            for (int i = 0; i < 26; i++) {
76                ab[i] -= freqA[a][i];
77            }
78            vector<int> cd = freqB[d + 1];
79            for (int i = 0; i < 26; i++) {
80                cd[i] -= freqB[c][i];
81            }
82
83
84            if (b < c || d < a) {
85                if (a == b) {
86                    if (s[a] != s[n - 1 - a]) {
87                        ans[q] = false;
88                    }
89                } else {
90                    vector<int> abb = freqB[b + 1];
91                    for (int i = 0; i < 26; i++) {
92                        abb[i] -= freqB[a][i];
93                    }
94                    for (int i = 0; i < 26; i++) {
95                        if (ab[i] != abb[i]) {
96                            ans[q] = false;
97                        }
98                    }
99                }
100                if (c == d) {
101                    if (s[c] != s[n - 1 - c]) {
102                        ans[q] = false;
103                    }
104                } else {
105                    vector<int> cda = freqA[d + 1];
106                    for (int i = 0; i < 26; i++) {
107                        cda[i] -= freqA[c][i];
108                    }
109                    for (int i = 0; i < 26; i++) {
110                        if (cd[i] != cda[i]) {
111                            ans[q] = false;
112                        }
113                    }
114                }
115                if (b < c) {
116                    if (mismatches[c] - mismatches[b + 1] != 0) {
117                        ans[q] = false;
118                    }
119                }
120                if (d < a) {
121                    if (mismatches[a] - mismatches[d + 1] != 0) {
122                        ans[q] = false;
123                    }
124                }
125                continue;
126            }
127
128
129
130
131
132
133
134            if (a < c) {
135                vector<int> acb = freqB[c];
136                for (int i = 0; i < 26; i++) {
137                    acb[i] -= freqB[a][i];
138                }
139                for (int i = 0; i < 26; i++) {
140                    ab[i] -= acb[i];
141                    if (ab[i] < 0) {
142                        ans[q] = false;
143                    }
144                }
145            }
146            if (c < a) {
147                vector<int> aca = freqA[a];
148                for (int i = 0; i < 26; i++) {
149                    aca[i] -= freqA[c][i];
150                }
151                for (int i = 0; i < 26; i++) {
152                    cd[i] -= aca[i];
153                    if (cd[i] < 0) {
154                        ans[q] = false;
155                    }
156                }
157            }
158            if (b > d) {
159                vector<int> bdb = freqB[b + 1];
160                for (int i = 0; i < 26; i++) {
161                    bdb[i] -= freqB[d + 1][i];
162                }
163                for (int i = 0; i < 26; i++) {
164                    ab[i] -= bdb[i];
165                    if (ab[i] < 0) {
166                        ans[q] = false;
167                    }
168                }
169            }
170            if (d > b) {
171                vector<int> bda = freqA[d + 1];
172                for (int i = 0; i < 26; i++) {
173                    bda[i] -= freqA[b + 1][i];
174                }
175                for (int i = 0; i < 26; i++) {
176                    cd[i] -= bda[i];
177                    if (cd[i] < 0) {
178                        ans[q] = false;
179                    }
180                }
181            }
182            if (mismatches[n/2] - mismatches[max(b, d) + 1] != 0) {
183                ans[q] = false;
184            }
185            if (ab != cd) {
186                ans[q] = false;
187            }
188        }
189        return ans;
190    }
191};