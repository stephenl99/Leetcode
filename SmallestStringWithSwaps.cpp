#include <string>
#include <unordered_map>
#include <queue>
#include <map>
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> parents(s.size());
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> map;
        for (int i = 0; i < s.size(); i++) {
            parents[i] = i;
        }
        for (int i = 0; i < pairs.size(); i++) {
            int x = pairs[i][0];
            int y = pairs[i][1];
            parents[find(x, parents)] = find(y, parents);
        }
        for (int i = 0; i < s.size(); i++) {
            map[find(i, parents)].push(s[i]);
        }
        for (int i = 0; i < s.size(); i++) {
            s[i] = map[find(i, parents)].top();
            map[find(i, parents)].pop();
        }
        return s;
    }
    int find(int curr, vector<int> &parents) {
        if (parents[curr] == curr) {
            return curr;
        }
        return parents[curr] = find(parents[curr], parents);
    }
};