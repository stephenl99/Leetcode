1class Solution {
2public:
3    int minimumOperations(vector<int>& nums) {
4        int total2 = nums.size() / 2;
5        int total1 = nums.size() / 2;
6        if (nums.size() % 2 != 0) {
7            total1++;
8        }
9        unordered_map<int, int> s1;
10        unordered_map<int, int> s2;
11        int max1 = 0;
12        int max2 = 0;
13        int argmax1 = 0;
14        int argmax2 = 0;
15        for (int i = 0; i < nums.size(); i++) {
16            if (i % 2 == 0) {
17                s1[nums[i]]++;
18                if (s1[nums[i]] > max1) {
19                    max1 = s1[nums[i]];
20                    argmax1 = nums[i];
21                }
22            } else {
23                s2[nums[i]]++;
24                if (s2[nums[i]] > max2) {
25                    max2 = s2[nums[i]];
26                    argmax2 = nums[i];
27                }
28            }
29        }
30        if (argmax1 != argmax2) {
31            return total1 + total2 - max1 - max2;
32        }
33        int orig = argmax1;
34        int oldmax1 = max1;
35        int oldmax2 = max2;
36        max1 = 0;
37        max2 = 0;
38        argmax1 = 0;
39        argmax2 = 0;
40        for (int i = 0; i < nums.size(); i++) {
41            if (nums[i] == orig) {
42                continue;
43            }
44            if (i % 2 == 0) {
45                if (s1[nums[i]] > max1) {
46                    max1 = s1[nums[i]];
47                    argmax1 = nums[i];
48                }
49            } else {
50                if (s2[nums[i]] > max2) {
51                    max2 = s2[nums[i]];
52                    argmax2 = nums[i];
53                }
54            }
55        }
56        return min(total1 - oldmax1 + total2 - max2, total1 - max1 + total2 - oldmax2);
57    }
58};