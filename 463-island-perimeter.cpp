1class Solution {
2public:
3    int islandPerimeter(vector<vector<int>>& grid) {
4        int count = 0;
5        for (int i = 0; i < grid.size(); i++) {
6            for (int j = 0; j < grid[0].size(); j++) {
7                if (grid[i][j] == 1) {
8                    if (i == 0 || grid[i - 1][j] == 0) {
9                        count++;
10                    }
11                    if (i == grid.size() - 1 || grid[i + 1][j] == 0) {
12                        count++;
13                    }
14                    if (j == 0 || grid[i][j - 1] == 0) {
15                        count++;
16                    }
17                    if (j == grid[0].size() - 1 || grid[i][j + 1] == 0) {
18                        count++;
19                    }
20                }
21            }
22        }
23        return count;
24    }
25};