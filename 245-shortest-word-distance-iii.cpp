class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> w1;
        vector<int> w2;
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                w1.push_back(i);
            }
            if (wordsDict[i] == word2) {
                w2.push_back(i);
            }
        }
        int minn = INT_MAX;
        int i = 0; 
        int j = 0;
        while (i < w1.size() && j < w2.size()) {
            if (w1[i] < w2[j]) {
                minn = min(minn, w2[j] - w1[i]);
                i++;
            } else if (w2[j] < w1[i]) {
                minn = min(minn, w1[i] - w2[j]);
                j++;
            } else {
                i++;
            }
        }
        return minn;
    }
};