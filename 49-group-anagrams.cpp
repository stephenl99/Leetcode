class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> indexing;
        vector<vector<string>> ans;
        for (string s : strs) {
            std::vector<char> vec(s.begin(), s.end());
            sort(vec.begin(), vec.end());
            string newS(vec.begin(), vec.end());
            if (indexing[newS] == 0) {
                ans.push_back({s});
                indexing[newS] = ans.size();
            } else {
                ans[indexing[newS] - 1].push_back(s);
            }
        }
        return ans;
    }
};